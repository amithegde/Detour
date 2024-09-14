#pragma once

#include "DetourUtils.h"

// Real function pointers for advapi32 functions
BOOL(__stdcall* Real_AbortSystemShutdownA)(LPSTR) = AbortSystemShutdownA;
BOOL(__stdcall* Real_AbortSystemShutdownW)(LPWSTR) = AbortSystemShutdownW;
DWORD(__stdcall* Real_InitiateShutdownA)(LPSTR, LPSTR, DWORD, DWORD, DWORD) = InitiateShutdownA;
DWORD(__stdcall* Real_InitiateShutdownW)(LPWSTR, LPWSTR, DWORD, DWORD, DWORD) = InitiateShutdownW;
BOOL(__stdcall* Real_InitiateSystemShutdownA)(LPSTR, LPSTR, DWORD, BOOL, BOOL) = InitiateSystemShutdownA;
BOOL(__stdcall* Real_InitiateSystemShutdownExA)(LPSTR, LPSTR, DWORD, BOOL, BOOL, DWORD) = InitiateSystemShutdownExA;
BOOL(__stdcall* Real_InitiateSystemShutdownExW)(LPWSTR, LPWSTR, DWORD, BOOL, BOOL, DWORD) = InitiateSystemShutdownExW;
BOOL(__stdcall* Real_InitiateSystemShutdownW)(LPWSTR, LPWSTR, DWORD, BOOL, BOOL) = InitiateSystemShutdownW;
LSTATUS(__stdcall* Real_RegCloseKey)(HKEY) = RegCloseKey;
LSTATUS(__stdcall* Real_RegConnectRegistryA)(LPCSTR, HKEY, PHKEY) = RegConnectRegistryA;
LSTATUS(__stdcall* Real_RegConnectRegistryW)(LPCWSTR, HKEY, PHKEY) = RegConnectRegistryW;
LSTATUS(__stdcall* Real_RegCopyTreeA)(HKEY, LPCSTR, HKEY) = RegCopyTreeA;
LSTATUS(__stdcall* Real_RegCopyTreeW)(HKEY, LPCWSTR, HKEY) = RegCopyTreeW;
LSTATUS(__stdcall* Real_RegCreateKeyA)(HKEY, LPCSTR, PHKEY) = RegCreateKeyA;
LSTATUS(__stdcall* Real_RegCreateKeyExA)(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD) = RegCreateKeyExA;
LSTATUS(__stdcall* Real_RegCreateKeyExW)(HKEY, LPCWSTR, DWORD, LPWSTR, DWORD, REGSAM, LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD) = RegCreateKeyExW;
LSTATUS(__stdcall* Real_RegCreateKeyTransactedA)(HKEY, LPCSTR, DWORD, LPSTR, DWORD, REGSAM, LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID) = RegCreateKeyTransactedA;
LSTATUS(__stdcall* Real_RegCreateKeyTransactedW)(HKEY, LPCWSTR, DWORD, LPWSTR, DWORD, REGSAM, LPSECURITY_ATTRIBUTES, PHKEY, LPDWORD, HANDLE, PVOID) = RegCreateKeyTransactedW;
LSTATUS(__stdcall* Real_RegCreateKeyW)(HKEY, LPCWSTR, PHKEY) = RegCreateKeyW;
LSTATUS(__stdcall* Real_RegDeleteKeyA)(HKEY, LPCSTR) = RegDeleteKeyA;
LSTATUS(__stdcall* Real_RegDeleteKeyExA)(HKEY, LPCSTR, REGSAM, DWORD) = RegDeleteKeyExA;
LSTATUS(__stdcall* Real_RegDeleteKeyExW)(HKEY, LPCWSTR, REGSAM, DWORD) = RegDeleteKeyExW;
LSTATUS(__stdcall* Real_RegDeleteKeyTransactedA)(HKEY, LPCSTR, REGSAM, DWORD, HANDLE, PVOID) = RegDeleteKeyTransactedA;
LSTATUS(__stdcall* Real_RegDeleteKeyTransactedW)(HKEY, LPCWSTR, REGSAM, DWORD, HANDLE, PVOID) = RegDeleteKeyTransactedW;
LSTATUS(__stdcall* Real_RegDeleteKeyValueA)(HKEY, LPCSTR, LPCSTR) = RegDeleteKeyValueA;
LSTATUS(__stdcall* Real_RegDeleteKeyValueW)(HKEY, LPCWSTR, LPCWSTR) = RegDeleteKeyValueW;
LSTATUS(__stdcall* Real_RegDeleteKeyW)(HKEY, LPCWSTR) = RegDeleteKeyW;
LSTATUS(__stdcall* Real_RegDeleteTreeA)(HKEY, LPCSTR) = RegDeleteTreeA;
LSTATUS(__stdcall* Real_RegDeleteTreeW)(HKEY, LPCWSTR) = RegDeleteTreeW;
LSTATUS(__stdcall* Real_RegDeleteValueA)(HKEY, LPCSTR) = RegDeleteValueA;
LSTATUS(__stdcall* Real_RegDeleteValueW)(HKEY, LPCWSTR) = RegDeleteValueW;
LSTATUS(__stdcall* Real_RegDisablePredefinedCache)() = RegDisablePredefinedCache;
LSTATUS(__stdcall* Real_RegDisablePredefinedCacheEx)() = RegDisablePredefinedCacheEx;
LSTATUS(__stdcall* Real_RegDisableReflectionKey)(HKEY) = RegDisableReflectionKey;
LSTATUS(__stdcall* Real_RegEnableReflectionKey)(HKEY) = RegEnableReflectionKey;
LSTATUS(__stdcall* Real_RegEnumKeyA)(HKEY, DWORD, LPSTR, DWORD) = RegEnumKeyA;
LSTATUS(__stdcall* Real_RegEnumKeyExA)(HKEY, DWORD, LPSTR, LPDWORD, LPDWORD, LPSTR, LPDWORD, PFILETIME) = RegEnumKeyExA;
LSTATUS(__stdcall* Real_RegEnumKeyExW)(HKEY, DWORD, LPWSTR, LPDWORD, LPDWORD, LPWSTR, LPDWORD, PFILETIME) = RegEnumKeyExW;
LSTATUS(__stdcall* Real_RegEnumKeyW)(HKEY, DWORD, LPWSTR, DWORD) = RegEnumKeyW;
LSTATUS(__stdcall* Real_RegEnumValueA)(HKEY, DWORD, LPSTR, LPDWORD, LPDWORD, LPDWORD, LPBYTE, LPDWORD) = RegEnumValueA;
LSTATUS(__stdcall* Real_RegEnumValueW)(HKEY, DWORD, LPWSTR, LPDWORD, LPDWORD, LPDWORD, LPBYTE, LPDWORD) = RegEnumValueW;
LSTATUS(__stdcall* Real_RegFlushKey)(HKEY) = RegFlushKey;
LSTATUS(__stdcall* Real_RegGetKeySecurity)(HKEY, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, LPDWORD) = RegGetKeySecurity;
LSTATUS(__stdcall* Real_RegGetValueA)(HKEY, LPCSTR, LPCSTR, DWORD, LPDWORD, PVOID, LPDWORD) = RegGetValueA;
LSTATUS(__stdcall* Real_RegGetValueW)(HKEY, LPCWSTR, LPCWSTR, DWORD, LPDWORD, PVOID, LPDWORD) = RegGetValueW;
LSTATUS(__stdcall* Real_RegLoadAppKeyA)(LPCSTR, PHKEY, REGSAM, DWORD, DWORD) = RegLoadAppKeyA;
LSTATUS(__stdcall* Real_RegLoadAppKeyW)(LPCWSTR, PHKEY, REGSAM, DWORD, DWORD) = RegLoadAppKeyW;
LSTATUS(__stdcall* Real_RegLoadKeyA)(HKEY, LPCSTR, LPCSTR) = RegLoadKeyA;
LSTATUS(__stdcall* Real_RegLoadKeyW)(HKEY, LPCWSTR, LPCWSTR) = RegLoadKeyW;
LSTATUS(__stdcall* Real_RegLoadMUIStringA)(HKEY, LPCSTR, LPSTR, DWORD, LPDWORD, DWORD, LPCSTR) = RegLoadMUIStringA;
LSTATUS(__stdcall* Real_RegLoadMUIStringW)(HKEY, LPCWSTR, LPWSTR, DWORD, LPDWORD, DWORD, LPCWSTR) = RegLoadMUIStringW;
LSTATUS(__stdcall* Real_RegNotifyChangeKeyValue)(HKEY, BOOL, DWORD, HANDLE, BOOL) = RegNotifyChangeKeyValue;
LSTATUS(__stdcall* Real_RegOpenCurrentUser)(REGSAM, PHKEY) = RegOpenCurrentUser;
LSTATUS(__stdcall* Real_RegOpenKeyA)(HKEY, LPCSTR, PHKEY) = RegOpenKeyA;
LSTATUS(__stdcall* Real_RegOpenKeyExA)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY) = RegOpenKeyExA;
LSTATUS(__stdcall* Real_RegOpenKeyExW)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY) = RegOpenKeyExW;
LSTATUS(__stdcall* Real_RegOpenKeyTransactedA)(HKEY, LPCSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID) = RegOpenKeyTransactedA;
LSTATUS(__stdcall* Real_RegOpenKeyTransactedW)(HKEY, LPCWSTR, DWORD, REGSAM, PHKEY, HANDLE, PVOID) = RegOpenKeyTransactedW;
LSTATUS(__stdcall* Real_RegOpenKeyW)(HKEY, LPCWSTR, PHKEY) = RegOpenKeyW;
LSTATUS(__stdcall* Real_RegOpenUserClassesRoot)(HANDLE, DWORD, REGSAM, PHKEY) = RegOpenUserClassesRoot;
LSTATUS(__stdcall* Real_RegOverridePredefKey)(HKEY, HKEY) = RegOverridePredefKey;
LSTATUS(__stdcall* Real_RegQueryInfoKeyA)(HKEY, LPSTR, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, PFILETIME) = RegQueryInfoKeyA;
LSTATUS(__stdcall* Real_RegQueryInfoKeyW)(HKEY, LPWSTR, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, LPDWORD, PFILETIME) = RegQueryInfoKeyW;
LSTATUS(__stdcall* Real_RegQueryMultipleValuesA)(HKEY, PVALENTA, DWORD, LPSTR, LPDWORD) = RegQueryMultipleValuesA;
LSTATUS(__stdcall* Real_RegQueryMultipleValuesW)(HKEY, PVALENTW, DWORD, LPWSTR, LPDWORD) = RegQueryMultipleValuesW;
LSTATUS(__stdcall* Real_RegQueryReflectionKey)(HKEY, LPBOOL) = RegQueryReflectionKey;
LSTATUS(__stdcall* Real_RegQueryValueA)(HKEY, LPCSTR, LPSTR, PLONG) = RegQueryValueA;
LSTATUS(__stdcall* Real_RegQueryValueExA)(HKEY, LPCSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD) = RegQueryValueExA;
LSTATUS(__stdcall* Real_RegQueryValueExW)(HKEY, LPCWSTR, LPDWORD, LPDWORD, LPBYTE, LPDWORD) = RegQueryValueExW;
LSTATUS(__stdcall* Real_RegQueryValueW)(HKEY, LPCWSTR, LPWSTR, PLONG) = RegQueryValueW;
LSTATUS(__stdcall* Real_RegRenameKey)(HKEY, LPCWSTR, LPCWSTR) = RegRenameKey;
LSTATUS(__stdcall* Real_RegReplaceKeyA)(HKEY, LPCSTR, LPCSTR, LPCSTR) = RegReplaceKeyA;
LSTATUS(__stdcall* Real_RegReplaceKeyW)(HKEY, LPCWSTR, LPCWSTR, LPCWSTR) = RegReplaceKeyW;
LSTATUS(__stdcall* Real_RegRestoreKeyA)(HKEY, LPCSTR, DWORD) = RegRestoreKeyA;
LSTATUS(__stdcall* Real_RegRestoreKeyW)(HKEY, LPCWSTR, DWORD) = RegRestoreKeyW;
LSTATUS(__stdcall* Real_RegSaveKeyA)(HKEY, LPCSTR, LPSECURITY_ATTRIBUTES) = RegSaveKeyA;
LSTATUS(__stdcall* Real_RegSaveKeyExA)(HKEY, LPCSTR, LPSECURITY_ATTRIBUTES, DWORD) = RegSaveKeyExA;
LSTATUS(__stdcall* Real_RegSaveKeyExW)(HKEY, LPCWSTR, LPSECURITY_ATTRIBUTES, DWORD) = RegSaveKeyExW;
LSTATUS(__stdcall* Real_RegSaveKeyW)(HKEY, LPCWSTR, LPSECURITY_ATTRIBUTES) = RegSaveKeyW;
LSTATUS(__stdcall* Real_RegSetKeySecurity)(HKEY, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR) = RegSetKeySecurity;
LSTATUS(__stdcall* Real_RegSetKeyValueA)(HKEY, LPCSTR, LPCSTR, DWORD, LPCVOID, DWORD) = RegSetKeyValueA;
LSTATUS(__stdcall* Real_RegSetKeyValueW)(HKEY, LPCWSTR, LPCWSTR, DWORD, LPCVOID, DWORD) = RegSetKeyValueW;
LSTATUS(__stdcall* Real_RegSetValueA)(HKEY, LPCSTR, DWORD, LPCSTR, DWORD) = RegSetValueA;
LSTATUS(__stdcall* Real_RegSetValueExA)(HKEY, LPCSTR, DWORD, DWORD, const BYTE*, DWORD) = RegSetValueExA;
LSTATUS(__stdcall* Real_RegSetValueExW)(HKEY, LPCWSTR, DWORD, DWORD, const BYTE*, DWORD) = RegSetValueExW;
LSTATUS(__stdcall* Real_RegSetValueW)(HKEY, LPCWSTR, DWORD, LPCWSTR, DWORD) = RegSetValueW;
LSTATUS(__stdcall* Real_RegUnLoadKeyA)(HKEY, LPCSTR) = RegUnLoadKeyA;
LSTATUS(__stdcall* Real_RegUnLoadKeyW)(HKEY, LPCWSTR) = RegUnLoadKeyW;

// Detoured functions
BOOL Mine_AbortSystemShutdownA(LPSTR lpMachineName) {
	LogScope logScope(L"AbortSystemShutdownA", (uintptr_t)lpMachineName);
	BOOL rv = Real_AbortSystemShutdownA(lpMachineName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL Mine_AbortSystemShutdownW(LPWSTR lpMachineName) {
	LogScope logScope(L"AbortSystemShutdownW", (uintptr_t)lpMachineName);
	BOOL rv = Real_AbortSystemShutdownW(lpMachineName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD Mine_InitiateShutdownA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwGracePeriod, DWORD dwShutdownFlags, DWORD dwReason) {
	LogScope logScope(L"InitiateShutdownA", (uintptr_t)lpMachineName, (uintptr_t)lpMessage, dwGracePeriod, dwShutdownFlags, dwReason);
	DWORD rv = Real_InitiateShutdownA(lpMachineName, lpMessage, dwGracePeriod, dwShutdownFlags, dwReason);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

DWORD Mine_InitiateShutdownW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwGracePeriod, DWORD dwShutdownFlags, DWORD dwReason) {
	LogScope logScope(L"InitiateShutdownW", (uintptr_t)lpMachineName, (uintptr_t)lpMessage, dwGracePeriod, dwShutdownFlags, dwReason);
	DWORD rv = Real_InitiateShutdownW(lpMachineName, lpMessage, dwGracePeriod, dwShutdownFlags, dwReason);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL Mine_InitiateSystemShutdownA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown) {
	LogScope logScope(L"InitiateSystemShutdownA", (uintptr_t)lpMachineName, (uintptr_t)lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
	BOOL rv = Real_InitiateSystemShutdownA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL Mine_InitiateSystemShutdownExA(LPSTR lpMachineName, LPSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason) {
	LogScope logScope(L"InitiateSystemShutdownExA", (uintptr_t)lpMachineName, (uintptr_t)lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
	BOOL rv = Real_InitiateSystemShutdownExA(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL Mine_InitiateSystemShutdownExW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown, DWORD dwReason) {
	LogScope logScope(L"InitiateSystemShutdownExW", (uintptr_t)lpMachineName, (uintptr_t)lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
	BOOL rv = Real_InitiateSystemShutdownExW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown, dwReason);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

BOOL Mine_InitiateSystemShutdownW(LPWSTR lpMachineName, LPWSTR lpMessage, DWORD dwTimeout, BOOL bForceAppsClosed, BOOL bRebootAfterShutdown) {
	LogScope logScope(L"InitiateSystemShutdownW", (uintptr_t)lpMachineName, (uintptr_t)lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
	BOOL rv = Real_InitiateSystemShutdownW(lpMachineName, lpMessage, dwTimeout, bForceAppsClosed, bRebootAfterShutdown);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegCloseKey(HKEY hKey) {
	LogScope logScope(L"RegCloseKey", (uintptr_t)hKey);
	LSTATUS rv = Real_RegCloseKey(hKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

// Detoured functions
LSTATUS Mine_RegConnectRegistryA(LPCSTR lpMachineName, HKEY hKey, PHKEY phkResult) {
	LogScope logScope(L"RegConnectRegistryA", (uintptr_t)lpMachineName, (uintptr_t)hKey, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegConnectRegistryA(lpMachineName, hKey, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegConnectRegistryW(LPCWSTR lpMachineName, HKEY hKey, PHKEY phkResult) {
	LogScope logScope(L"RegConnectRegistryW", (uintptr_t)lpMachineName, (uintptr_t)hKey, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegConnectRegistryW(lpMachineName, hKey, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegCopyTreeA(HKEY hKeySrc, LPCSTR lpSubKey, HKEY hKeyDest) {
	LogScope logScope(L"RegCopyTreeA", (uintptr_t)hKeySrc, (uintptr_t)lpSubKey, (uintptr_t)hKeyDest);
	LSTATUS rv = Real_RegCopyTreeA(hKeySrc, lpSubKey, hKeyDest);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegCopyTreeW(HKEY hKeySrc, LPCWSTR lpSubKey, HKEY hKeyDest) {
	LogScope logScope(L"RegCopyTreeW", (uintptr_t)hKeySrc, (uintptr_t)lpSubKey, (uintptr_t)hKeyDest);
	LSTATUS rv = Real_RegCopyTreeW(hKeySrc, lpSubKey, hKeyDest);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegCreateKeyA(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult) {
	LogScope logScope(L"RegCreateKeyA", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegCreateKeyA(hKey, lpSubKey, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegCreateKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition) {
	LogScope logScope(L"RegCreateKeyExA", (uintptr_t)hKey, (uintptr_t)lpSubKey, Reserved, (uintptr_t)lpClass, dwOptions, samDesired, (uintptr_t)lpSecurityAttributes, (uintptr_t)phkResult, (uintptr_t)lpdwDisposition);
	LSTATUS rv = Real_RegCreateKeyExA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegCreateKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition) {
	LogScope logScope(L"RegCreateKeyExW", (uintptr_t)hKey, (uintptr_t)lpSubKey, Reserved, (uintptr_t)lpClass, dwOptions, samDesired, (uintptr_t)lpSecurityAttributes, (uintptr_t)phkResult, (uintptr_t)lpdwDisposition);
	LSTATUS rv = Real_RegCreateKeyExW(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegCreateKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, DWORD Reserved, LPSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter) {
	LogScope logScope(L"RegCreateKeyTransactedA", (uintptr_t)hKey, (uintptr_t)lpSubKey, Reserved, (uintptr_t)lpClass, dwOptions, samDesired, (uintptr_t)lpSecurityAttributes, (uintptr_t)phkResult, (uintptr_t)lpdwDisposition, (uintptr_t)hTransaction, (uintptr_t)pExtendedParemeter);
	LSTATUS rv = Real_RegCreateKeyTransactedA(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition, hTransaction, pExtendedParemeter);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegCreateKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, DWORD Reserved, LPWSTR lpClass, DWORD dwOptions, REGSAM samDesired, LPSECURITY_ATTRIBUTES lpSecurityAttributes, PHKEY phkResult, LPDWORD lpdwDisposition, HANDLE hTransaction, PVOID pExtendedParemeter) {
	LogScope logScope(L"RegCreateKeyTransactedW", (uintptr_t)hKey, (uintptr_t)lpSubKey, Reserved, (uintptr_t)lpClass, dwOptions, samDesired, (uintptr_t)lpSecurityAttributes, (uintptr_t)phkResult, (uintptr_t)lpdwDisposition, (uintptr_t)hTransaction, (uintptr_t)pExtendedParemeter);
	LSTATUS rv = Real_RegCreateKeyTransactedW(hKey, lpSubKey, Reserved, lpClass, dwOptions, samDesired, lpSecurityAttributes, phkResult, lpdwDisposition, hTransaction, pExtendedParemeter);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegCreateKeyW(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult) {
	LogScope logScope(L"RegCreateKeyW", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegCreateKeyW(hKey, lpSubKey, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteKeyA(HKEY hKey, LPCSTR lpSubKey) {
	LogScope logScope(L"RegDeleteKeyA", (uintptr_t)hKey, (uintptr_t)lpSubKey);
	LSTATUS rv = Real_RegDeleteKeyA(hKey, lpSubKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteKeyExA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved) {
	LogScope logScope(L"RegDeleteKeyExA", (uintptr_t)hKey, (uintptr_t)lpSubKey, samDesired, Reserved);
	LSTATUS rv = Real_RegDeleteKeyExA(hKey, lpSubKey, samDesired, Reserved);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteKeyExW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved) {
	LogScope logScope(L"RegDeleteKeyExW", (uintptr_t)hKey, (uintptr_t)lpSubKey, samDesired, Reserved);
	LSTATUS rv = Real_RegDeleteKeyExW(hKey, lpSubKey, samDesired, Reserved);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, REGSAM samDesired, DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter) {
	LogScope logScope(L"RegDeleteKeyTransactedA", (uintptr_t)hKey, (uintptr_t)lpSubKey, samDesired, Reserved, (uintptr_t)hTransaction, (uintptr_t)pExtendedParameter);
	LSTATUS rv = Real_RegDeleteKeyTransactedA(hKey, lpSubKey, samDesired, Reserved, hTransaction, pExtendedParameter);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, REGSAM samDesired, DWORD Reserved, HANDLE hTransaction, PVOID pExtendedParameter) {
	LogScope logScope(L"RegDeleteKeyTransactedW", (uintptr_t)hKey, (uintptr_t)lpSubKey, samDesired, Reserved, (uintptr_t)hTransaction, (uintptr_t)pExtendedParameter);
	LSTATUS rv = Real_RegDeleteKeyTransactedW(hKey, lpSubKey, samDesired, Reserved, hTransaction, pExtendedParameter);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteKeyValueA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName) {
	LogScope logScope(L"RegDeleteKeyValueA", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpValueName);
	LSTATUS rv = Real_RegDeleteKeyValueA(hKey, lpSubKey, lpValueName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName) {
	LogScope logScope(L"RegDeleteKeyValueW", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpValueName);
	LSTATUS rv = Real_RegDeleteKeyValueW(hKey, lpSubKey, lpValueName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteKeyW(HKEY hKey, LPCWSTR lpSubKey) {
	LogScope logScope(L"RegDeleteKeyW", (uintptr_t)hKey, (uintptr_t)lpSubKey);
	LSTATUS rv = Real_RegDeleteKeyW(hKey, lpSubKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteTreeA(HKEY hKey, LPCSTR lpSubKey) {
	LogScope logScope(L"RegDeleteTreeA", (uintptr_t)hKey, (uintptr_t)lpSubKey);
	LSTATUS rv = Real_RegDeleteTreeA(hKey, lpSubKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteTreeW(HKEY hKey, LPCWSTR lpSubKey) {
	LogScope logScope(L"RegDeleteTreeW", (uintptr_t)hKey, (uintptr_t)lpSubKey);
	LSTATUS rv = Real_RegDeleteTreeW(hKey, lpSubKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteValueA(HKEY hKey, LPCSTR lpValueName) {
	LogScope logScope(L"RegDeleteValueA", (uintptr_t)hKey, (uintptr_t)lpValueName);
	LSTATUS rv = Real_RegDeleteValueA(hKey, lpValueName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDeleteValueW(HKEY hKey, LPCWSTR lpValueName) {
	LogScope logScope(L"RegDeleteValueW", (uintptr_t)hKey, (uintptr_t)lpValueName);
	LSTATUS rv = Real_RegDeleteValueW(hKey, lpValueName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDisablePredefinedCache() {
	LogScope logScope(L"RegDisablePredefinedCache");
	LSTATUS rv = Real_RegDisablePredefinedCache();
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDisablePredefinedCacheEx() {
	LogScope logScope(L"RegDisablePredefinedCacheEx");
	LSTATUS rv = Real_RegDisablePredefinedCacheEx();
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegDisableReflectionKey(HKEY hKey) {
	LogScope logScope(L"RegDisableReflectionKey", (uintptr_t)hKey);
	LSTATUS rv = Real_RegDisableReflectionKey(hKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegEnableReflectionKey(HKEY hKey) {
	LogScope logScope(L"RegEnableReflectionKey", (uintptr_t)hKey);
	LSTATUS rv = Real_RegEnableReflectionKey(hKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegEnumKeyA(HKEY hKey, DWORD dwIndex, LPSTR lpName, DWORD cchName) {
	LogScope logScope(L"RegEnumKeyA", (uintptr_t)hKey, dwIndex, (uintptr_t)lpName, cchName);
	LSTATUS rv = Real_RegEnumKeyA(hKey, dwIndex, lpName, cchName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegEnumKeyExA(HKEY hKey, DWORD dwIndex, LPSTR lpName, LPDWORD lpcchName, LPDWORD lpReserved, LPSTR lpClass, LPDWORD lpcchClass, PFILETIME lpftLastWriteTime) {
	LogScope logScope(L"RegEnumKeyExA", (uintptr_t)hKey, dwIndex, (uintptr_t)lpName, (uintptr_t)lpcchName, (uintptr_t)lpReserved, (uintptr_t)lpClass, (uintptr_t)lpcchClass, (uintptr_t)lpftLastWriteTime);
	LSTATUS rv = Real_RegEnumKeyExA(hKey, dwIndex, lpName, lpcchName, lpReserved, lpClass, lpcchClass, lpftLastWriteTime);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegEnumKeyExW(HKEY hKey, DWORD dwIndex, LPWSTR lpName, LPDWORD lpcName, LPDWORD lpReserved, LPWSTR lpClass, LPDWORD lpcClass, PFILETIME lpftLastWriteTime) {
	LogScope logScope(L"RegEnumKeyExW", (uintptr_t)hKey, dwIndex, (uintptr_t)lpName, (uintptr_t)lpcName, (uintptr_t)lpReserved, (uintptr_t)lpClass, (uintptr_t)lpcClass, (uintptr_t)lpftLastWriteTime);
	LSTATUS rv = Real_RegEnumKeyExW(hKey, dwIndex, lpName, lpcName, lpReserved, lpClass, lpcClass, lpftLastWriteTime);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegEnumKeyW(HKEY hKey, DWORD dwIndex, LPWSTR lpName, DWORD cchName) {
	LogScope logScope(L"RegEnumKeyW", (uintptr_t)hKey, dwIndex, (uintptr_t)lpName, cchName);
	LSTATUS rv = Real_RegEnumKeyW(hKey, dwIndex, lpName, cchName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegEnumValueA(HKEY hKey, DWORD dwIndex, LPSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
	LogScope logScope(L"RegEnumValueA", (uintptr_t)hKey, dwIndex, (uintptr_t)lpValueName, (uintptr_t)lpcchValueName, (uintptr_t)lpReserved, (uintptr_t)lpType, (uintptr_t)lpData, (uintptr_t)lpcbData);
	LSTATUS rv = Real_RegEnumValueA(hKey, dwIndex, lpValueName, lpcchValueName, lpReserved, lpType, lpData, lpcbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegEnumValueW(HKEY hKey, DWORD dwIndex, LPWSTR lpValueName, LPDWORD lpcchValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
	LogScope logScope(L"RegEnumValueW", (uintptr_t)hKey, dwIndex, (uintptr_t)lpValueName, (uintptr_t)lpcchValueName, (uintptr_t)lpReserved, (uintptr_t)lpType, (uintptr_t)lpData, (uintptr_t)lpcbData);
	LSTATUS rv = Real_RegEnumValueW(hKey, dwIndex, lpValueName, lpcchValueName, lpReserved, lpType, lpData, lpcbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegFlushKey(HKEY hKey) {
	LogScope logScope(L"RegFlushKey", (uintptr_t)hKey);
	LSTATUS rv = Real_RegFlushKey(hKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegGetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor, LPDWORD lpcbSecurityDescriptor) {
	LogScope logScope(L"RegGetKeySecurity", (uintptr_t)hKey, SecurityInformation, (uintptr_t)pSecurityDescriptor, (uintptr_t)lpcbSecurityDescriptor);
	LSTATUS rv = Real_RegGetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor, lpcbSecurityDescriptor);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegGetValueA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData) {
	LogScope logScope(L"RegGetValueA", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpValue, dwFlags, (uintptr_t)pdwType, (uintptr_t)pvData, (uintptr_t)pcbData);
	LSTATUS rv = Real_RegGetValueA(hKey, lpSubKey, lpValue, dwFlags, pdwType, pvData, pcbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegGetValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValue, DWORD dwFlags, LPDWORD pdwType, PVOID pvData, LPDWORD pcbData) {
	LogScope logScope(L"RegGetValueW", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpValue, dwFlags, (uintptr_t)pdwType, (uintptr_t)pvData, (uintptr_t)pcbData);
	LSTATUS rv = Real_RegGetValueW(hKey, lpSubKey, lpValue, dwFlags, pdwType, pvData, pcbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegLoadAppKeyA(LPCSTR lpFile, PHKEY phkResult, REGSAM samDesired, DWORD dwOptions, DWORD Reserved) {
	LogScope logScope(L"RegLoadAppKeyA", (uintptr_t)lpFile, (uintptr_t)phkResult, samDesired, dwOptions, Reserved);
	LSTATUS rv = Real_RegLoadAppKeyA(lpFile, phkResult, samDesired, dwOptions, Reserved);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegLoadAppKeyW(LPCWSTR lpFile, PHKEY phkResult, REGSAM samDesired, DWORD dwOptions, DWORD Reserved) {
	LogScope logScope(L"RegLoadAppKeyW", (uintptr_t)lpFile, (uintptr_t)phkResult, samDesired, dwOptions, Reserved);
	LSTATUS rv = Real_RegLoadAppKeyW(lpFile, phkResult, samDesired, dwOptions, Reserved);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegLoadKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpFile) {
	LogScope logScope(L"RegLoadKeyA", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpFile);
	LSTATUS rv = Real_RegLoadKeyA(hKey, lpSubKey, lpFile);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegLoadKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpFile) {
	LogScope logScope(L"RegLoadKeyW", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpFile);
	LSTATUS rv = Real_RegLoadKeyW(hKey, lpSubKey, lpFile);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegLoadMUIStringA(HKEY hKey, LPCSTR pszSubKey, LPSTR pszValue, DWORD cbValue, LPDWORD pcbData, DWORD Flags, LPCSTR pszDirectory) {
	LogScope logScope(L"RegLoadMUIStringA", (uintptr_t)hKey, (uintptr_t)pszSubKey, (uintptr_t)pszValue, cbValue, (uintptr_t)pcbData, Flags, (uintptr_t)pszDirectory);
	LSTATUS rv = Real_RegLoadMUIStringA(hKey, pszSubKey, pszValue, cbValue, pcbData, Flags, pszDirectory);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegLoadMUIStringW(HKEY hKey, LPCWSTR pszSubKey, LPWSTR pszValue, DWORD cbValue, LPDWORD pcbData, DWORD Flags, LPCWSTR pszDirectory) {
	LogScope logScope(L"RegLoadMUIStringW", (uintptr_t)hKey, (uintptr_t)pszSubKey, (uintptr_t)pszValue, cbValue, (uintptr_t)pcbData, Flags, (uintptr_t)pszDirectory);
	LSTATUS rv = Real_RegLoadMUIStringW(hKey, pszSubKey, pszValue, cbValue, pcbData, Flags, pszDirectory);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegNotifyChangeKeyValue(HKEY hKey, BOOL bWatchSubtree, DWORD dwNotifyFilter, HANDLE hEvent, BOOL fAsynchronous) {
	LogScope logScope(L"RegNotifyChangeKeyValue", (uintptr_t)hKey, bWatchSubtree, dwNotifyFilter, (uintptr_t)hEvent, fAsynchronous);
	LSTATUS rv = Real_RegNotifyChangeKeyValue(hKey, bWatchSubtree, dwNotifyFilter, hEvent, fAsynchronous);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegOpenCurrentUser(REGSAM samDesired, PHKEY phkResult) {
	LogScope logScope(L"RegOpenCurrentUser", samDesired, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegOpenCurrentUser(samDesired, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegOpenKeyA(HKEY hKey, LPCSTR lpSubKey, PHKEY phkResult) {
	LogScope logScope(L"RegOpenKeyA", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegOpenKeyA(hKey, lpSubKey, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegOpenKeyExA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult) {
	LogScope logScope(L"RegOpenKeyExA", (uintptr_t)hKey, (uintptr_t)lpSubKey, ulOptions, samDesired, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegOpenKeyExA(hKey, lpSubKey, ulOptions, samDesired, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegOpenKeyExW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult) {
	LogScope logScope(L"RegOpenKeyExW", (uintptr_t)hKey, (uintptr_t)lpSubKey, ulOptions, samDesired, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegOpenKeyExW(hKey, lpSubKey, ulOptions, samDesired, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegOpenKeyTransactedA(HKEY hKey, LPCSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParemeter) {
	LogScope logScope(L"RegOpenKeyTransactedA", (uintptr_t)hKey, (uintptr_t)lpSubKey, ulOptions, samDesired, (uintptr_t)phkResult, (uintptr_t)hTransaction, (uintptr_t)pExtendedParemeter);
	LSTATUS rv = Real_RegOpenKeyTransactedA(hKey, lpSubKey, ulOptions, samDesired, phkResult, hTransaction, pExtendedParemeter);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegOpenKeyTransactedW(HKEY hKey, LPCWSTR lpSubKey, DWORD ulOptions, REGSAM samDesired, PHKEY phkResult, HANDLE hTransaction, PVOID pExtendedParemeter) {
	LogScope logScope(L"RegOpenKeyTransactedW", (uintptr_t)hKey, (uintptr_t)lpSubKey, ulOptions, samDesired, (uintptr_t)phkResult, (uintptr_t)hTransaction, (uintptr_t)pExtendedParemeter);
	LSTATUS rv = Real_RegOpenKeyTransactedW(hKey, lpSubKey, ulOptions, samDesired, phkResult, hTransaction, pExtendedParemeter);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegOpenKeyW(HKEY hKey, LPCWSTR lpSubKey, PHKEY phkResult) {
	LogScope logScope(L"RegOpenKeyW", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegOpenKeyW(hKey, lpSubKey, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegOpenUserClassesRoot(HANDLE hToken, DWORD dwOptions, REGSAM samDesired, PHKEY phkResult) {
	LogScope logScope(L"RegOpenUserClassesRoot", (uintptr_t)hToken, dwOptions, samDesired, (uintptr_t)phkResult);
	LSTATUS rv = Real_RegOpenUserClassesRoot(hToken, dwOptions, samDesired, phkResult);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegOverridePredefKey(HKEY hKey, HKEY hNewHKey) {
	LogScope logScope(L"RegOverridePredefKey", (uintptr_t)hKey, (uintptr_t)hNewHKey);
	LSTATUS rv = Real_RegOverridePredefKey(hKey, hNewHKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegQueryInfoKeyA(HKEY hKey, LPSTR lpClass, LPDWORD lpcClass, LPDWORD lpReserved, LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime) {
	LogScope logScope(L"RegQueryInfoKeyA", (uintptr_t)hKey, (uintptr_t)lpClass, (uintptr_t)lpcClass, (uintptr_t)lpReserved, (uintptr_t)lpcSubKeys, (uintptr_t)lpcbMaxSubKeyLen, (uintptr_t)lpcbMaxClassLen, (uintptr_t)lpcValues, (uintptr_t)lpcbMaxValueNameLen, (uintptr_t)lpcbMaxValueLen, (uintptr_t)lpcbSecurityDescriptor, (uintptr_t)lpftLastWriteTime);
	LSTATUS rv = Real_RegQueryInfoKeyA(hKey, lpClass, lpcClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegQueryInfoKeyW(HKEY hKey, LPWSTR lpClass, LPDWORD lpcClass, LPDWORD lpReserved, LPDWORD lpcSubKeys, LPDWORD lpcbMaxSubKeyLen, LPDWORD lpcbMaxClassLen, LPDWORD lpcValues, LPDWORD lpcbMaxValueNameLen, LPDWORD lpcbMaxValueLen, LPDWORD lpcbSecurityDescriptor, PFILETIME lpftLastWriteTime) {
	LogScope logScope(L"RegQueryInfoKeyW", (uintptr_t)hKey, (uintptr_t)lpClass, (uintptr_t)lpcClass, (uintptr_t)lpReserved, (uintptr_t)lpcSubKeys, (uintptr_t)lpcbMaxSubKeyLen, (uintptr_t)lpcbMaxClassLen, (uintptr_t)lpcValues, (uintptr_t)lpcbMaxValueNameLen, (uintptr_t)lpcbMaxValueLen, (uintptr_t)lpcbSecurityDescriptor, (uintptr_t)lpftLastWriteTime);
	LSTATUS rv = Real_RegQueryInfoKeyW(hKey, lpClass, lpcClass, lpReserved, lpcSubKeys, lpcbMaxSubKeyLen, lpcbMaxClassLen, lpcValues, lpcbMaxValueNameLen, lpcbMaxValueLen, lpcbSecurityDescriptor, lpftLastWriteTime);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegQueryMultipleValuesA(HKEY hKey, PVALENTA val_list, DWORD num_vals, LPSTR lpValueBuf, LPDWORD ldwTotsize) {
	LogScope logScope(L"RegQueryMultipleValuesA", (uintptr_t)hKey, (uintptr_t)val_list, num_vals, (uintptr_t)lpValueBuf, (uintptr_t)ldwTotsize);
	LSTATUS rv = Real_RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegQueryMultipleValuesW(HKEY hKey, PVALENTW val_list, DWORD num_vals, LPWSTR lpValueBuf, LPDWORD ldwTotsize) {
	LogScope logScope(L"RegQueryMultipleValuesW", (uintptr_t)hKey, (uintptr_t)val_list, num_vals, (uintptr_t)lpValueBuf, (uintptr_t)ldwTotsize);
	LSTATUS rv = Real_RegQueryMultipleValuesW(hKey, val_list, num_vals, lpValueBuf, ldwTotsize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegQueryReflectionKey(HKEY hBase, BOOL* bIsReflectionDisabled) {
	LogScope logScope(L"RegQueryReflectionKey", (uintptr_t)hBase, (uintptr_t)bIsReflectionDisabled);
	LSTATUS rv = Real_RegQueryReflectionKey(hBase, bIsReflectionDisabled);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegQueryValueA(HKEY hKey, LPCSTR lpSubKey, LPSTR lpData, PLONG lpcbData) {
	LogScope logScope(L"RegQueryValueA", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpData, (uintptr_t)lpcbData);
	LSTATUS rv = Real_RegQueryValueA(hKey, lpSubKey, lpData, lpcbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegQueryValueExA(HKEY hKey, LPCSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
	LogScope logScope(L"RegQueryValueExA", (uintptr_t)hKey, (uintptr_t)lpValueName, (uintptr_t)lpReserved, (uintptr_t)lpType, (uintptr_t)lpData, (uintptr_t)lpcbData);
	LSTATUS rv = Real_RegQueryValueExA(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegQueryValueExW(HKEY hKey, LPCWSTR lpValueName, LPDWORD lpReserved, LPDWORD lpType, LPBYTE lpData, LPDWORD lpcbData) {
	LogScope logScope(L"RegQueryValueExW", (uintptr_t)hKey, (uintptr_t)lpValueName, (uintptr_t)lpReserved, (uintptr_t)lpType, (uintptr_t)lpData, (uintptr_t)lpcbData);
	LSTATUS rv = Real_RegQueryValueExW(hKey, lpValueName, lpReserved, lpType, lpData, lpcbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegQueryValueW(HKEY hKey, LPCWSTR lpSubKey, LPWSTR lpData, PLONG lpcbData) {
	LogScope logScope(L"RegQueryValueW", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpData, (uintptr_t)lpcbData);
	LSTATUS rv = Real_RegQueryValueW(hKey, lpSubKey, lpData, lpcbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegRenameKey(HKEY hKey, LPCWSTR lpSubKeyName, LPCWSTR lpNewKeyName) {
	LogScope logScope(L"RegRenameKey", (uintptr_t)hKey, (uintptr_t)lpSubKeyName, (uintptr_t)lpNewKeyName);
	LSTATUS rv = Real_RegRenameKey(hKey, lpSubKeyName, lpNewKeyName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegReplaceKeyA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpNewFile, LPCSTR lpOldFile) {
	LogScope logScope(L"RegReplaceKeyA", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpNewFile, (uintptr_t)lpOldFile);
	LSTATUS rv = Real_RegReplaceKeyA(hKey, lpSubKey, lpNewFile, lpOldFile);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegReplaceKeyW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpNewFile, LPCWSTR lpOldFile) {
	LogScope logScope(L"RegReplaceKeyW", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpNewFile, (uintptr_t)lpOldFile);
	LSTATUS rv = Real_RegReplaceKeyW(hKey, lpSubKey, lpNewFile, lpOldFile);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegRestoreKeyA(HKEY hKey, LPCSTR lpFile, DWORD dwFlags) {
	LogScope logScope(L"RegRestoreKeyA", (uintptr_t)hKey, (uintptr_t)lpFile, dwFlags);
	LSTATUS rv = Real_RegRestoreKeyA(hKey, lpFile, dwFlags);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegRestoreKeyW(HKEY hKey, LPCWSTR lpFile, DWORD dwFlags) {
	LogScope logScope(L"RegRestoreKeyW", (uintptr_t)hKey, (uintptr_t)lpFile, dwFlags);
	LSTATUS rv = Real_RegRestoreKeyW(hKey, lpFile, dwFlags);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSaveKeyA(HKEY hKey, LPCSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes) {
	LogScope logScope(L"RegSaveKeyA", (uintptr_t)hKey, (uintptr_t)lpFile, (uintptr_t)lpSecurityAttributes);
	LSTATUS rv = Real_RegSaveKeyA(hKey, lpFile, lpSecurityAttributes);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSaveKeyExA(HKEY hKey, LPCSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags) {
	LogScope logScope(L"RegSaveKeyExA", (uintptr_t)hKey, (uintptr_t)lpFile, (uintptr_t)lpSecurityAttributes, Flags);
	LSTATUS rv = Real_RegSaveKeyExA(hKey, lpFile, lpSecurityAttributes, Flags);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSaveKeyExW(HKEY hKey, LPCWSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD Flags) {
	LogScope logScope(L"RegSaveKeyExW", (uintptr_t)hKey, (uintptr_t)lpFile, (uintptr_t)lpSecurityAttributes, Flags);
	LSTATUS rv = Real_RegSaveKeyExW(hKey, lpFile, lpSecurityAttributes, Flags);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSaveKeyW(HKEY hKey, LPCWSTR lpFile, CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes) {
	LogScope logScope(L"RegSaveKeyW", (uintptr_t)hKey, (uintptr_t)lpFile, (uintptr_t)lpSecurityAttributes);
	LSTATUS rv = Real_RegSaveKeyW(hKey, lpFile, lpSecurityAttributes);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSetKeySecurity(HKEY hKey, SECURITY_INFORMATION SecurityInformation, PSECURITY_DESCRIPTOR pSecurityDescriptor) {
	LogScope logScope(L"RegSetKeySecurity", (uintptr_t)hKey, SecurityInformation, (uintptr_t)pSecurityDescriptor);
	LSTATUS rv = Real_RegSetKeySecurity(hKey, SecurityInformation, pSecurityDescriptor);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSetKeyValueA(HKEY hKey, LPCSTR lpSubKey, LPCSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData) {
	LogScope logScope(L"RegSetKeyValueA", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpValueName, dwType, (uintptr_t)lpData, cbData);
	LSTATUS rv = Real_RegSetKeyValueA(hKey, lpSubKey, lpValueName, dwType, lpData, cbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSetKeyValueW(HKEY hKey, LPCWSTR lpSubKey, LPCWSTR lpValueName, DWORD dwType, LPCVOID lpData, DWORD cbData) {
	LogScope logScope(L"RegSetKeyValueW", (uintptr_t)hKey, (uintptr_t)lpSubKey, (uintptr_t)lpValueName, dwType, (uintptr_t)lpData, cbData);
	LSTATUS rv = Real_RegSetKeyValueW(hKey, lpSubKey, lpValueName, dwType, lpData, cbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSetValueA(HKEY hKey, LPCSTR lpSubKey, DWORD dwType, LPCSTR lpData, DWORD cbData) {
	LogScope logScope(L"RegSetValueA", (uintptr_t)hKey, (uintptr_t)lpSubKey, dwType, (uintptr_t)lpData, cbData);
	LSTATUS rv = Real_RegSetValueA(hKey, lpSubKey, dwType, lpData, cbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSetValueExA(HKEY hKey, LPCSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE* lpData, DWORD cbData) {
	LogScope logScope(L"RegSetValueExA", (uintptr_t)hKey, (uintptr_t)lpValueName, Reserved, dwType, (uintptr_t)lpData, cbData);
	LSTATUS rv = Real_RegSetValueExA(hKey, lpValueName, Reserved, dwType, lpData, cbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSetValueExW(HKEY hKey, LPCWSTR lpValueName, DWORD Reserved, DWORD dwType, CONST BYTE* lpData, DWORD cbData) {
	LogScope logScope(L"RegSetValueExW", (uintptr_t)hKey, (uintptr_t)lpValueName, Reserved, dwType, (uintptr_t)lpData, cbData);
	LSTATUS rv = Real_RegSetValueExW(hKey, lpValueName, Reserved, dwType, lpData, cbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegSetValueW(HKEY hKey, LPCWSTR lpSubKey, DWORD dwType, LPCWSTR lpData, DWORD cbData) {
	LogScope logScope(L"RegSetValueW", (uintptr_t)hKey, (uintptr_t)lpSubKey, dwType, (uintptr_t)lpData, cbData);
	LSTATUS rv = Real_RegSetValueW(hKey, lpSubKey, dwType, lpData, cbData);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegUnLoadKeyA(HKEY hKey, LPCSTR lpSubKey) {
	LogScope logScope(L"RegUnLoadKeyA", (uintptr_t)hKey, (uintptr_t)lpSubKey);
	LSTATUS rv = Real_RegUnLoadKeyA(hKey, lpSubKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

LSTATUS Mine_RegUnLoadKeyW(HKEY hKey, LPCWSTR lpSubKey) {
	LogScope logScope(L"RegUnLoadKeyW", (uintptr_t)hKey, (uintptr_t)lpSubKey);
	LSTATUS rv = Real_RegUnLoadKeyW(hKey, lpSubKey);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

// Vector to store the function pointers and their detoured counterparts
std::vector<DetourFunction> advapi32DetourFunctions = {
	{ (PVOID*)&Real_AbortSystemShutdownA, Mine_AbortSystemShutdownA },
	{ (PVOID*)&Real_AbortSystemShutdownW, Mine_AbortSystemShutdownW },
	{ (PVOID*)&Real_InitiateShutdownA, Mine_InitiateShutdownA },
	{ (PVOID*)&Real_InitiateShutdownW, Mine_InitiateShutdownW },
	{ (PVOID*)&Real_InitiateSystemShutdownA, Mine_InitiateSystemShutdownA },
	{ (PVOID*)&Real_InitiateSystemShutdownExA, Mine_InitiateSystemShutdownExA },
	{ (PVOID*)&Real_InitiateSystemShutdownExW, Mine_InitiateSystemShutdownExW },
	{ (PVOID*)&Real_InitiateSystemShutdownW, Mine_InitiateSystemShutdownW },
	{ (PVOID*)&Real_RegCloseKey, Mine_RegCloseKey },
	{ (PVOID*)&Real_RegConnectRegistryA, Mine_RegConnectRegistryA },
	{ (PVOID*)&Real_RegConnectRegistryW, Mine_RegConnectRegistryW },
	{ (PVOID*)&Real_RegCopyTreeA, Mine_RegCopyTreeA },
	{ (PVOID*)&Real_RegCopyTreeW, Mine_RegCopyTreeW },
	{ (PVOID*)&Real_RegCreateKeyA, Mine_RegCreateKeyA },
	{ (PVOID*)&Real_RegCreateKeyExA, Mine_RegCreateKeyExA },
	{ (PVOID*)&Real_RegCreateKeyExW, Mine_RegCreateKeyExW },
	{ (PVOID*)&Real_RegCreateKeyTransactedA, Mine_RegCreateKeyTransactedA },
	{ (PVOID*)&Real_RegCreateKeyTransactedW, Mine_RegCreateKeyTransactedW },
	{ (PVOID*)&Real_RegCreateKeyW, Mine_RegCreateKeyW },
	{ (PVOID*)&Real_RegDeleteKeyA, Mine_RegDeleteKeyA },
	{ (PVOID*)&Real_RegDeleteKeyExA, Mine_RegDeleteKeyExA },
	{ (PVOID*)&Real_RegDeleteKeyExW, Mine_RegDeleteKeyExW },
	{ (PVOID*)&Real_RegDeleteKeyTransactedA, Mine_RegDeleteKeyTransactedA },
	{ (PVOID*)&Real_RegDeleteKeyTransactedW, Mine_RegDeleteKeyTransactedW },
	{ (PVOID*)&Real_RegDeleteKeyValueA, Mine_RegDeleteKeyValueA },
	{ (PVOID*)&Real_RegDeleteKeyValueW, Mine_RegDeleteKeyValueW },
	{ (PVOID*)&Real_RegDeleteKeyW, Mine_RegDeleteKeyW },
	{ (PVOID*)&Real_RegDeleteTreeA, Mine_RegDeleteTreeA },
	{ (PVOID*)&Real_RegDeleteTreeW, Mine_RegDeleteTreeW },
	{ (PVOID*)&Real_RegDeleteValueA, Mine_RegDeleteValueA },
	{ (PVOID*)&Real_RegDeleteValueW, Mine_RegDeleteValueW },
	{ (PVOID*)&Real_RegDisablePredefinedCache, Mine_RegDisablePredefinedCache },
	{ (PVOID*)&Real_RegDisablePredefinedCacheEx, Mine_RegDisablePredefinedCacheEx },
	{ (PVOID*)&Real_RegDisableReflectionKey, Mine_RegDisableReflectionKey },
	{ (PVOID*)&Real_RegEnableReflectionKey, Mine_RegEnableReflectionKey },
	{ (PVOID*)&Real_RegEnumKeyA, Mine_RegEnumKeyA },
	{ (PVOID*)&Real_RegEnumKeyExA, Mine_RegEnumKeyExA },
	{ (PVOID*)&Real_RegEnumKeyExW, Mine_RegEnumKeyExW },
	{ (PVOID*)&Real_RegEnumKeyW, Mine_RegEnumKeyW },
	{ (PVOID*)&Real_RegEnumValueA, Mine_RegEnumValueA },
	{ (PVOID*)&Real_RegEnumValueW, Mine_RegEnumValueW },
	{ (PVOID*)&Real_RegFlushKey, Mine_RegFlushKey },
	{ (PVOID*)&Real_RegGetKeySecurity, Mine_RegGetKeySecurity },
	{ (PVOID*)&Real_RegGetValueA, Mine_RegGetValueA },
	{ (PVOID*)&Real_RegGetValueW, Mine_RegGetValueW },
	{ (PVOID*)&Real_RegLoadAppKeyA, Mine_RegLoadAppKeyA },
	{ (PVOID*)&Real_RegLoadAppKeyW, Mine_RegLoadAppKeyW },
	{ (PVOID*)&Real_RegLoadKeyA, Mine_RegLoadKeyA },
	{ (PVOID*)&Real_RegLoadKeyW, Mine_RegLoadKeyW },
	{ (PVOID*)&Real_RegLoadMUIStringA, Mine_RegLoadMUIStringA },
	{ (PVOID*)&Real_RegLoadMUIStringW, Mine_RegLoadMUIStringW },
	{ (PVOID*)&Real_RegNotifyChangeKeyValue, Mine_RegNotifyChangeKeyValue },
	{ (PVOID*)&Real_RegOpenCurrentUser, Mine_RegOpenCurrentUser },
	{ (PVOID*)&Real_RegOpenKeyA, Mine_RegOpenKeyA },
	{ (PVOID*)&Real_RegOpenKeyExA, Mine_RegOpenKeyExA },
	{ (PVOID*)&Real_RegOpenKeyExW, Mine_RegOpenKeyExW },
	{ (PVOID*)&Real_RegOpenKeyTransactedA, Mine_RegOpenKeyTransactedA },
	{ (PVOID*)&Real_RegOpenKeyTransactedW, Mine_RegOpenKeyTransactedW },
	{ (PVOID*)&Real_RegOpenKeyW, Mine_RegOpenKeyW },
	{ (PVOID*)&Real_RegOpenUserClassesRoot, Mine_RegOpenUserClassesRoot },
	{ (PVOID*)&Real_RegOverridePredefKey, Mine_RegOverridePredefKey },
	{ (PVOID*)&Real_RegQueryInfoKeyA, Mine_RegQueryInfoKeyA },
	{ (PVOID*)&Real_RegQueryInfoKeyW, Mine_RegQueryInfoKeyW },
	{ (PVOID*)&Real_RegQueryMultipleValuesA, Mine_RegQueryMultipleValuesA },
	{ (PVOID*)&Real_RegQueryMultipleValuesW, Mine_RegQueryMultipleValuesW },
	{ (PVOID*)&Real_RegQueryReflectionKey, Mine_RegQueryReflectionKey },
	{ (PVOID*)&Real_RegQueryValueA, Mine_RegQueryValueA },
	{ (PVOID*)&Real_RegQueryValueExA, Mine_RegQueryValueExA },
	{ (PVOID*)&Real_RegQueryValueExW, Mine_RegQueryValueExW },
	{ (PVOID*)&Real_RegQueryValueW, Mine_RegQueryValueW },
	{ (PVOID*)&Real_RegRenameKey, Mine_RegRenameKey },
	{ (PVOID*)&Real_RegReplaceKeyA, Mine_RegReplaceKeyA },
	{ (PVOID*)&Real_RegReplaceKeyW, Mine_RegReplaceKeyW },
	{ (PVOID*)&Real_RegRestoreKeyA, Mine_RegRestoreKeyA },
	{ (PVOID*)&Real_RegRestoreKeyW, Mine_RegRestoreKeyW },
	{ (PVOID*)&Real_RegSaveKeyA, Mine_RegSaveKeyA },
	{ (PVOID*)&Real_RegSaveKeyExA, Mine_RegSaveKeyExA },
	{ (PVOID*)&Real_RegSaveKeyExW, Mine_RegSaveKeyExW },
	{ (PVOID*)&Real_RegSaveKeyW, Mine_RegSaveKeyW },
	{ (PVOID*)&Real_RegSetKeySecurity, Mine_RegSetKeySecurity },
	{ (PVOID*)&Real_RegSetKeyValueA, Mine_RegSetKeyValueA },
	{ (PVOID*)&Real_RegSetKeyValueW, Mine_RegSetKeyValueW },
	{ (PVOID*)&Real_RegSetValueA, Mine_RegSetValueA },
	{ (PVOID*)&Real_RegSetValueExA, Mine_RegSetValueExA },
	{ (PVOID*)&Real_RegSetValueExW, Mine_RegSetValueExW },
	{ (PVOID*)&Real_RegSetValueW, Mine_RegSetValueW },
	{ (PVOID*)&Real_RegUnLoadKeyA, Mine_RegUnLoadKeyA },
	{ (PVOID*)&Real_RegUnLoadKeyW, Mine_RegUnLoadKeyW }
};

const std::wstring advapi32ModuleName = L"advapi32.dll";

// Attach function
void AttachAdvapi32Detours() {
	AttachDetours(advapi32DetourFunctions, advapi32ModuleName);
}

// Detach function
void DetachAdvapi32Detours() {
	DetachDetours(advapi32DetourFunctions, advapi32ModuleName);
}
