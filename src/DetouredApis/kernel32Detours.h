#pragma once

#include "DetourUtils.h"

// Real function pointers
BOOL(__stdcall* Real_SetEnvironmentStringsW)(LPWCH) = SetEnvironmentStringsW;
HANDLE(__stdcall* Real_GetStdHandle)(DWORD) = GetStdHandle;
BOOL(__stdcall* Real_SetStdHandle)(DWORD, HANDLE) = SetStdHandle;
BOOL(__stdcall* Real_SetStdHandleEx)(DWORD, HANDLE, PHANDLE) = SetStdHandleEx;
LPSTR(__stdcall* Real_GetCommandLineA)(VOID) = GetCommandLineA;
LPWSTR(__stdcall* Real_GetCommandLineW)(VOID) = GetCommandLineW;
LPWCH(__stdcall* Real_GetEnvironmentStringsW)(VOID) = GetEnvironmentStringsW;
BOOL(__stdcall* Real_FreeEnvironmentStringsA)(LPCH) = FreeEnvironmentStringsA;
BOOL(__stdcall* Real_FreeEnvironmentStringsW)(LPWCH) = FreeEnvironmentStringsW;
DWORD(__stdcall* Real_GetEnvironmentVariableA)(LPCSTR, LPSTR, DWORD) = GetEnvironmentVariableA;
DWORD(__stdcall* Real_GetEnvironmentVariableW)(LPCWSTR, LPWSTR, DWORD) = GetEnvironmentVariableW;
BOOL(__stdcall* Real_SetEnvironmentVariableA)(LPCSTR, LPCSTR) = SetEnvironmentVariableA;
BOOL(__stdcall* Real_SetEnvironmentVariableW)(LPCWSTR, LPCWSTR) = SetEnvironmentVariableW;
DWORD(__stdcall* Real_ExpandEnvironmentStringsA)(LPCSTR, LPSTR, DWORD) = ExpandEnvironmentStringsA;
DWORD(__stdcall* Real_ExpandEnvironmentStringsW)(LPCWSTR, LPWSTR, DWORD) = ExpandEnvironmentStringsW;
BOOL(__stdcall* Real_SetCurrentDirectoryA)(LPCSTR) = SetCurrentDirectoryA;
BOOL(__stdcall* Real_SetCurrentDirectoryW)(LPCWSTR) = SetCurrentDirectoryW;
DWORD(__stdcall* Real_GetCurrentDirectoryA)(DWORD, LPSTR) = GetCurrentDirectoryA;
DWORD(__stdcall* Real_GetCurrentDirectoryW)(DWORD, LPWSTR) = GetCurrentDirectoryW;
DWORD(__stdcall* Real_SearchPathA)(LPCSTR, LPCSTR, LPCSTR, DWORD, LPSTR, LPSTR*) = SearchPathA;
DWORD(__stdcall* Real_SearchPathW)(LPCWSTR, LPCWSTR, LPCWSTR, DWORD, LPWSTR, LPWSTR*) = SearchPathW;
BOOL(__stdcall* Real_NeedCurrentDirectoryForExePathA)(LPCSTR) = NeedCurrentDirectoryForExePathA;
BOOL(__stdcall* Real_NeedCurrentDirectoryForExePathW)(LPCWSTR) = NeedCurrentDirectoryForExePathW;

// Detoured functions
BOOL __stdcall Mine_SetEnvironmentStringsW(LPWCH NewEnvironment) {
	LogScope logScope(L"SetEnvironmentStringsW", NewEnvironment);
	BOOL rv = Real_SetEnvironmentStringsW(NewEnvironment);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

HANDLE __stdcall Mine_GetStdHandle(DWORD nStdHandle) {
	LogScope logScope(L"GetStdHandle", nStdHandle);
	HANDLE rv = Real_GetStdHandle(nStdHandle);
	logScope.SetResult(std::to_wstring((uintptr_t)rv));
	return rv;
}

BOOL __stdcall Mine_SetStdHandle(DWORD nStdHandle, HANDLE hHandle) {
	LogScope logScope(L"SetStdHandle", nStdHandle, (uintptr_t)hHandle);
	BOOL rv = Real_SetStdHandle(nStdHandle, hHandle);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL __stdcall Mine_SetStdHandleEx(DWORD nStdHandle, HANDLE hHandle, PHANDLE phPrevValue) {
	LogScope logScope(L"SetStdHandleEx", nStdHandle, (uintptr_t)hHandle, (uintptr_t)phPrevValue);
	BOOL rv = Real_SetStdHandleEx(nStdHandle, hHandle, phPrevValue);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LPSTR __stdcall Mine_GetCommandLineA() {
	LogScope logScope(L"GetCommandLineA");
	LPSTR rv = Real_GetCommandLineA();
	logScope.SetResult(std::to_wstring((uintptr_t)rv));
	return rv;
}

LPWSTR __stdcall Mine_GetCommandLineW() {
	LogScope logScope(L"GetCommandLineW");
	LPWSTR rv = Real_GetCommandLineW();
	logScope.SetResult(std::to_wstring((uintptr_t)rv));
	return rv;
}

LPWCH __stdcall Mine_GetEnvironmentStringsW() {
	LogScope logScope(L"GetEnvironmentStringsW");
	LPWCH rv = Real_GetEnvironmentStringsW();
	logScope.SetResult(std::to_wstring((uintptr_t)rv));
	return rv;
}

BOOL __stdcall Mine_FreeEnvironmentStringsA(LPCH penv) {
	LogScope logScope(L"FreeEnvironmentStringsA", (uintptr_t)penv);
	BOOL rv = Real_FreeEnvironmentStringsA(penv);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL __stdcall Mine_FreeEnvironmentStringsW(LPWCH penv) {
	LogScope logScope(L"FreeEnvironmentStringsW", (uintptr_t)penv);
	BOOL rv = Real_FreeEnvironmentStringsW(penv);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD __stdcall Mine_GetEnvironmentVariableA(LPCSTR lpName, LPSTR lpBuffer, DWORD nSize) {
	LogScope logScope(L"GetEnvironmentVariableA", lpName, (uintptr_t)lpBuffer, nSize);
	DWORD rv = Real_GetEnvironmentVariableA(lpName, lpBuffer, nSize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD __stdcall Mine_GetEnvironmentVariableW(LPCWSTR lpName, LPWSTR lpBuffer, DWORD nSize) {
	LogScope logScope(L"GetEnvironmentVariableW", lpName, (uintptr_t)lpBuffer, nSize);
	DWORD rv = Real_GetEnvironmentVariableW(lpName, lpBuffer, nSize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL __stdcall Mine_SetEnvironmentVariableA(LPCSTR lpName, LPCSTR lpValue) {
	LogScope logScope(L"SetEnvironmentVariableA", lpName, lpValue);
	BOOL rv = Real_SetEnvironmentVariableA(lpName, lpValue);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL __stdcall Mine_SetEnvironmentVariableW(LPCWSTR lpName, LPCWSTR lpValue) {
	LogScope logScope(L"SetEnvironmentVariableW", lpName, lpValue);
	BOOL rv = Real_SetEnvironmentVariableW(lpName, lpValue);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD __stdcall Mine_ExpandEnvironmentStringsA(LPCSTR lpSrc, LPSTR lpDst, DWORD nSize) {
	LogScope logScope(L"ExpandEnvironmentStringsA", lpSrc, (uintptr_t)lpDst, nSize);
	DWORD rv = Real_ExpandEnvironmentStringsA(lpSrc, lpDst, nSize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD __stdcall Mine_ExpandEnvironmentStringsW(LPCWSTR lpSrc, LPWSTR lpDst, DWORD nSize) {
	LogScope logScope(L"ExpandEnvironmentStringsW", lpSrc, (uintptr_t)lpDst, nSize);
	DWORD rv = Real_ExpandEnvironmentStringsW(lpSrc, lpDst, nSize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL __stdcall Mine_SetCurrentDirectoryA(LPCSTR lpPathName) {
	LogScope logScope(L"SetCurrentDirectoryA", lpPathName);
	BOOL rv = Real_SetCurrentDirectoryA(lpPathName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL __stdcall Mine_SetCurrentDirectoryW(LPCWSTR lpPathName) {
	LogScope logScope(L"SetCurrentDirectoryW", lpPathName);
	BOOL rv = Real_SetCurrentDirectoryW(lpPathName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD __stdcall Mine_GetCurrentDirectoryA(DWORD nBufferLength, LPSTR lpBuffer) {
	LogScope logScope(L"GetCurrentDirectoryA", nBufferLength, (uintptr_t)lpBuffer);
	DWORD rv = Real_GetCurrentDirectoryA(nBufferLength, lpBuffer);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD __stdcall Mine_GetCurrentDirectoryW(DWORD nBufferLength, LPWSTR lpBuffer) {
	LogScope logScope(L"GetCurrentDirectoryW", nBufferLength, lpBuffer);
	DWORD rv = Real_GetCurrentDirectoryW(nBufferLength, lpBuffer);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD __stdcall Mine_SearchPathA(LPCSTR lpPath, LPCSTR lpFileName, LPCSTR lpExtension, DWORD nBufferLength, LPSTR lpBuffer, LPSTR* lpFilePart) {
	LogScope logScope(L"SearchPathA", lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart);
	DWORD rv = Real_SearchPathA(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD __stdcall Mine_SearchPathW(LPCWSTR lpPath, LPCWSTR lpFileName, LPCWSTR lpExtension, DWORD nBufferLength, LPWSTR lpBuffer, LPWSTR* lpFilePart) {
	LogScope logScope(L"SearchPathW", lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart);
	DWORD rv = Real_SearchPathW(lpPath, lpFileName, lpExtension, nBufferLength, lpBuffer, lpFilePart);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL __stdcall Mine_NeedCurrentDirectoryForExePathA(LPCSTR ExeName) {
	LogScope logScope(L"NeedCurrentDirectoryForExePathA", ExeName);
	BOOL rv = Real_NeedCurrentDirectoryForExePathA(ExeName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL __stdcall Mine_NeedCurrentDirectoryForExePathW(LPCWSTR ExeName) {
	LogScope logScope(L"NeedCurrentDirectoryForExePathW", ExeName);
	BOOL rv = Real_NeedCurrentDirectoryForExePathW(ExeName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

// Vector to store the function pointers and their detoured counterparts
std::vector<DetourFunction> kernel32DetourFunctions = {
	{ (PVOID*)&Real_SetEnvironmentStringsW, (PVOID)Mine_SetEnvironmentStringsW },
	{ (PVOID*)&Real_GetStdHandle, (PVOID)Mine_GetStdHandle },
	{ (PVOID*)&Real_SetStdHandle, (PVOID)Mine_SetStdHandle },
	{ (PVOID*)&Real_SetStdHandleEx, (PVOID)Mine_SetStdHandleEx },
	{ (PVOID*)&Real_GetCommandLineA, (PVOID)Mine_GetCommandLineA },
	{ (PVOID*)&Real_GetCommandLineW, (PVOID)Mine_GetCommandLineW },
	{ (PVOID*)&Real_GetEnvironmentStringsW, (PVOID)Mine_GetEnvironmentStringsW },
	{ (PVOID*)&Real_FreeEnvironmentStringsA, (PVOID)Mine_FreeEnvironmentStringsA },
	{ (PVOID*)&Real_FreeEnvironmentStringsW, (PVOID)Mine_FreeEnvironmentStringsW },
	{ (PVOID*)&Real_GetEnvironmentVariableA, (PVOID)Mine_GetEnvironmentVariableA },
	{ (PVOID*)&Real_GetEnvironmentVariableW, (PVOID)Mine_GetEnvironmentVariableW },
	{ (PVOID*)&Real_SetEnvironmentVariableA, (PVOID)Mine_SetEnvironmentVariableA },
	{ (PVOID*)&Real_SetEnvironmentVariableW, (PVOID)Mine_SetEnvironmentVariableW },
	{ (PVOID*)&Real_ExpandEnvironmentStringsA, (PVOID)Mine_ExpandEnvironmentStringsA },
	{ (PVOID*)&Real_ExpandEnvironmentStringsW, (PVOID)Mine_ExpandEnvironmentStringsW },
	{ (PVOID*)&Real_SetCurrentDirectoryA, (PVOID)Mine_SetCurrentDirectoryA },
	{ (PVOID*)&Real_SetCurrentDirectoryW, (PVOID)Mine_SetCurrentDirectoryW },
	{ (PVOID*)&Real_GetCurrentDirectoryA, (PVOID)Mine_GetCurrentDirectoryA },
	{ (PVOID*)&Real_GetCurrentDirectoryW, (PVOID)Mine_GetCurrentDirectoryW },
	{ (PVOID*)&Real_SearchPathA, (PVOID)Mine_SearchPathA },
	{ (PVOID*)&Real_SearchPathW, (PVOID)Mine_SearchPathW },
	{ (PVOID*)&Real_NeedCurrentDirectoryForExePathA, (PVOID)Mine_NeedCurrentDirectoryForExePathA },
	{ (PVOID*)&Real_NeedCurrentDirectoryForExePathW, (PVOID)Mine_NeedCurrentDirectoryForExePathW }
};

const std::wstring kernel32ModuleName = L"kernel32.dll";

// Functions to attach and detach the detours
void AttachKernel32Detours() {
	AttachDetours(kernel32DetourFunctions, kernel32ModuleName);
}

void DetachKernel32Detours() {
	DetachDetours(kernel32DetourFunctions, kernel32ModuleName);
}
