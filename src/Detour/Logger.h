#pragma once

#include <iostream>
#include <windows.h>
#include <string>

class Logger {
public:
	static void Log(const std::wstring& message) {
		std::wcout << L"[INFO] " << message << std::endl;
	}

	static void LogError(const std::wstring& message) {
		DWORD errorCode = GetLastError();
		std::wcout << L"[ERROR] " << message << L" (Error Code: " << std::hex << errorCode << L")" << std::endl;
		LogErrorString(errorCode);
	}

	static void LogErrorString(DWORD errorCode) {
		LPWSTR errorMsg = nullptr;
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			nullptr, errorCode, 0, (LPWSTR)&errorMsg, 0, nullptr);
		if (errorMsg) {
			std::wcout << L"[ERROR] " << errorMsg << std::endl;
			LocalFree(errorMsg);
		}
	}
};

