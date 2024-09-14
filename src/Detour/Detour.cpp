#include "Logger.h"
#include <iostream>
#include <sstream>
#include <string>
#include <tlhelp32.h>
#include <windows.h>
#include <psapi.h>
#include <vector>

DWORD GetPidByProcessName(const std::wstring& processName) {
	DWORD pid = 0;
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 pe;
		pe.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hSnapshot, &pe)) {
			do {
				if (processName == pe.szExeFile) {
					pid = pe.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnapshot, &pe));
		}
		CloseHandle(hSnapshot);
	}
	return pid;
}

bool FileExists(const std::wstring& filePath) {
	DWORD fileAttributes = GetFileAttributesW(filePath.c_str());
	return (fileAttributes != INVALID_FILE_ATTRIBUTES &&
		!(fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}

bool Is64BitProcess(HANDLE hProcess) {
	BOOL bIsWow64 = FALSE;
	IsWow64Process(hProcess, &bIsWow64);
	return !bIsWow64;
}

class Detour {
private:
	Logger logger;
	DWORD targetPid;
	std::wstring dllPath;

public:
	Detour(DWORD pid, const std::wstring& path) : targetPid(pid), dllPath(path) {}

    bool CompareMemory(const void* originalData, const void* readData, SIZE_T dataSize, Logger& logger) {
        const BYTE* originalBytes = static_cast<const BYTE*>(originalData);
        const BYTE* readBytes = static_cast<const BYTE*>(readData);

        for (SIZE_T i = 0; i < dataSize; ++i) {
            if (originalBytes[i] != readBytes[i]) {
                std::wstringstream ss;
                ss << L"Data mismatch at byte " << i << L": original 0x" << std::hex << (int)originalBytes[i]
                    << L", read 0x" << std::hex << (int)readBytes[i];
                logger.LogError(ss.str());
                return false;
            }
        }
        return true;
    }

    HRESULT InjectDll() {
        logger.Log(L"Attempting to inject DLL: " + dllPath);

        if (!FileExists(dllPath)) {
            logger.LogError(L"DLL not found: " + dllPath);
            return HRESULT_FROM_WIN32(ERROR_FILE_NOT_FOUND);
        }
        logger.Log(L"DLL file exists");

        HMODULE hDll = LoadLibraryW(dllPath.c_str());
        if (hDll == NULL) {
            DWORD error = GetLastError();
            logger.LogError(L"Failed to load DLL in current process. Error: 0x" + std::to_wstring(error));
            return HRESULT_FROM_WIN32(error);
        }
        FreeLibrary(hDll);
        logger.Log(L"Successfully loaded DLL in current process");

        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, targetPid);
        if (hProcess == NULL) {
            DWORD error = GetLastError();
            logger.LogError(L"Failed to open target process. Error: 0x" + std::to_wstring(error));
            return HRESULT_FROM_WIN32(error);
        }
        logger.Log(L"Successfully opened target process");

        bool targetIs64Bit = Is64BitProcess(hProcess);
        bool injectorIs64Bit = Is64BitProcess(GetCurrentProcess());
        if (targetIs64Bit != injectorIs64Bit) {
            logger.LogError(L"Architecture mismatch between injector and target process");
            CloseHandle(hProcess);
            return E_FAIL;
        }
        logger.Log(L"Architecture check passed");

        LPVOID pRemoteBuffer = VirtualAllocEx(hProcess, NULL, (dllPath.size() + 1) * sizeof(wchar_t),
            MEM_COMMIT, PAGE_READWRITE);
        if (pRemoteBuffer == NULL) {
            DWORD error = GetLastError();
            logger.LogError(L"Failed to allocate memory in target process. Error: 0x" + std::to_wstring(error));
            CloseHandle(hProcess);
            return HRESULT_FROM_WIN32(error);
        }
        logger.Log(L"Successfully allocated memory in target process");

        SIZE_T bytesWritten;
        if (!WriteProcessMemory(hProcess, pRemoteBuffer, dllPath.c_str(),
            (dllPath.size() + 1) * sizeof(wchar_t), &bytesWritten)) {
            DWORD error = GetLastError();
            logger.LogError(L"Failed to write to target process memory. Error: 0x" + std::to_wstring(error));
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return HRESULT_FROM_WIN32(error);
        }
        logger.Log(L"Wrote " + std::to_wstring(bytesWritten) + L" bytes to target process memory");

        // Verify the written memory
        std::vector<wchar_t> buffer(dllPath.size() + 1);
        SIZE_T bytesRead;
        if (!ReadProcessMemory(hProcess, pRemoteBuffer, buffer.data(), (dllPath.size() + 1) * sizeof(wchar_t), &bytesRead)) {
            DWORD error = GetLastError();
            logger.LogError(L"Failed to read from target process memory. Error: 0x" + std::to_wstring(error));
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return HRESULT_FROM_WIN32(error);
        }
        logger.Log(L"Read " + std::to_wstring(bytesRead) + L" bytes from target process memory");

        if (!CompareMemory(dllPath.c_str(), buffer.data(), (dllPath.size() + 1) * sizeof(wchar_t), logger)) {
            logger.LogError(L"Data verification failed: written data does not match original data");
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return E_FAIL;
        }
        logger.Log(L"Data verification passed: written data matches original data");

        HMODULE hKernel32 = GetModuleHandle(L"Kernel32");
        if (hKernel32 == NULL) {
            DWORD error = GetLastError();
            logger.LogError(L"Failed to get Kernel32 handle. Error: 0x" + std::to_wstring(error));
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return HRESULT_FROM_WIN32(error);
        }

        LPTHREAD_START_ROUTINE pLoadLibraryW = (LPTHREAD_START_ROUTINE)GetProcAddress(hKernel32, "LoadLibraryW");
        if (pLoadLibraryW == NULL) {
            DWORD error = GetLastError();
            logger.Log(L"Failed to get LoadLibraryW address. Error: 0x" + std::to_wstring(error));
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return HRESULT_FROM_WIN32(error);
        }

        HMODULE hRemoteDll = GetRemoteModuleHandle(hProcess, dllPath.c_str());
        if (hRemoteDll != NULL) {
            logger.Log(L"DLL is already loaded in the target process");
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return S_OK;
        }

        HANDLE hRemoteThread = CreateRemoteThread(hProcess, NULL, 0, pLoadLibraryW, pRemoteBuffer, 0, NULL);
        if (hRemoteThread == NULL) {
            DWORD error = GetLastError();
            logger.Log(L"Failed to create remote thread. Error: 0x" + std::to_wstring(error));
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return HRESULT_FROM_WIN32(error);
        }
        logger.Log(L"Created remote thread");

        DWORD waitResult = WaitForSingleObject(hRemoteThread, 10000);  // Wait for up to 10 seconds
        if (waitResult != WAIT_OBJECT_0) {
            DWORD error = GetLastError();
            std::wstringstream ss;
            ss << L"Remote thread did not complete in time. Error: 0x" << std::hex << error;
            logger.Log(ss.str());

            CloseHandle(hRemoteThread);
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return E_FAIL;
        }

        DWORD exitCode = 0;
        if (!GetExitCodeThread(hRemoteThread, &exitCode)) {
            DWORD error = GetLastError();
            logger.Log(L"Failed to get thread exit code. Error: 0x" + std::to_wstring(error));
            CloseHandle(hRemoteThread);
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return HRESULT_FROM_WIN32(error);
        }

        if (exitCode == 0) {
            DWORD error = GetLastError();
            std::wstringstream ss;
            ss << L"LoadLibraryW failed in remote process. Last error: 0x" << std::hex << error;
            logger.Log(ss.str());

            CloseHandle(hRemoteThread);
            VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
            CloseHandle(hProcess);
            return E_FAIL;
        }

        logger.Log(L"DLL injected successfully");

        CloseHandle(hRemoteThread);
        VirtualFreeEx(hProcess, pRemoteBuffer, 0, MEM_RELEASE);
        CloseHandle(hProcess);

        return S_OK;
    }

	HMODULE GetRemoteModuleHandle(HANDLE hProcess, const wchar_t* moduleName) {
		HMODULE hMods[1024];
		DWORD cbNeeded;
		if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded)) {
			for (unsigned int i = 0; i < (cbNeeded / sizeof(HMODULE)); i++) {
				wchar_t szModName[MAX_PATH];
				if (GetModuleFileNameEx(hProcess, hMods[i], szModName, sizeof(szModName) / sizeof(wchar_t))) {
					if (_wcsicmp(szModName, moduleName) == 0) {
						return hMods[i];
					}
				}
			}
		}
		return NULL;
	}
};

void WaitForDebugger() {
	std::cout << "Waiting for debugger to attach..." << std::endl;
	while (!IsDebuggerPresent()) {
		Sleep(100);  // Sleep for 100 milliseconds before checking again
	}
	std::cout << "Debugger attached." << std::endl;
	DebugBreak();  // Trigger a breakpoint once the debugger is attached
}

int wmain(int argc, wchar_t* argv[]) {
	Logger logger;

	if (argc != 3) {
		logger.Log(L"Usage: " + std::wstring(argv[0]) + L" <PROCESS_NAME> <DLL_NAME>");
		return 1;
	}

	std::wstring processName = argv[1];
	if (processName.substr(processName.length() - 4) != L".exe") {
		processName += L".exe";
	}

	std::wstring dllName = argv[2];

	DWORD targetPid = GetPidByProcessName(processName);
	if (targetPid == 0) {
		logger.LogError(L"Could not find process: " + processName);
		return 1;
	}

	logger.Log(L"Found process: " + processName + L" with PID: " + std::to_wstring(targetPid));

	// Generate full DLL path
	wchar_t buffer[MAX_PATH];
	GetModuleFileNameW(NULL, buffer, MAX_PATH);
	std::wstring exePath(buffer);
	size_t lastBackslash = exePath.find_last_of(L"\\");
	std::wstring dllPath;
	if (lastBackslash != std::wstring::npos) {
		std::wstring exeDir = exePath.substr(0, lastBackslash + 1);
		dllPath = exeDir + dllName;
	}
	else {
		logger.LogError(L"Could not determine executable directory");
		return 1;
	}
	logger.Log(L"Full DLL path: " + dllPath);

	try {
		Detour injector(targetPid, dllPath);

		//WaitForDebugger();

		logger.Log(L"Attempting to inject DLL using CreateRemoteThread");
		HRESULT result = injector.InjectDll();
		if (SUCCEEDED(result)) {
			logger.Log(L"DLL injected successfully using CreateRemoteThread");
		}
		else {
			std::wstringstream ss;
			ss << L"DLL injection failed while using CreateRemoteThread. HRESULT: 0x" << std::hex << result;
			logger.LogError(ss.str());
		}
	}
	catch (const std::exception& e) {
		logger.LogError(L"Error: " + std::wstring(e.what(), e.what() + strlen(e.what())));
		return 1;
	}

	return 0;
}
