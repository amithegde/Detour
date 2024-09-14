#pragma once

#include "DetourUtils.h"

// Real function pointers
PDH_STATUS(__stdcall* Real_PdhOpenQueryW)(LPCWSTR, DWORD_PTR, PDH_HQUERY*) = PdhOpenQueryW;
PDH_STATUS(__stdcall* Real_PdhAddCounterW)(PDH_HQUERY, LPCWSTR, DWORD_PTR, PDH_HCOUNTER*) = PdhAddCounterW;
PDH_STATUS(__stdcall* Real_PdhCollectQueryData)(PDH_HQUERY) = PdhCollectQueryData;
PDH_STATUS(__stdcall* Real_PdhCloseQuery)(PDH_HQUERY) = PdhCloseQuery;
PDH_STATUS(__stdcall* Real_PdhRemoveCounter)(PDH_HCOUNTER) = PdhRemoveCounter;
PDH_STATUS(__stdcall* Real_PdhGetFormattedCounterValue)(PDH_HCOUNTER, DWORD, LPDWORD, PPDH_FMT_COUNTERVALUE) = PdhGetFormattedCounterValue;
PDH_STATUS(__stdcall* Real_PdhGetRawCounterValue)(PDH_HCOUNTER, LPDWORD, PPDH_RAW_COUNTER) = PdhGetRawCounterValue;
PDH_STATUS(__stdcall* Real_PdhCalculateCounterFromRawValue)(PDH_HCOUNTER, DWORD, PPDH_RAW_COUNTER, PPDH_RAW_COUNTER, PPDH_FMT_COUNTERVALUE) = PdhCalculateCounterFromRawValue;
PDH_STATUS(__stdcall* Real_PdhGetCounterInfoW)(PDH_HCOUNTER, BOOLEAN, LPDWORD, PPDH_COUNTER_INFO_W) = PdhGetCounterInfoW;
PDH_STATUS(__stdcall* Real_PdhSetCounterScaleFactor)(PDH_HCOUNTER, LONG) = PdhSetCounterScaleFactor;
PDH_STATUS(__stdcall* Real_PdhConnectMachineW)(LPCWSTR) = PdhConnectMachineW;
PDH_STATUS(__stdcall* Real_PdhEnumObjectsW)(LPCWSTR, LPCWSTR, LPWSTR, LPDWORD, DWORD, BOOL) = PdhEnumObjectsW;
PDH_STATUS(__stdcall* Real_PdhEnumObjectItemsW)(LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, LPDWORD, LPWSTR, LPDWORD, DWORD, DWORD) = PdhEnumObjectItemsW;
PDH_STATUS(__stdcall* Real_PdhMakeCounterPathW)(PPDH_COUNTER_PATH_ELEMENTS_W, LPWSTR, LPDWORD, DWORD) = PdhMakeCounterPathW;
PDH_STATUS(__stdcall* Real_PdhParseCounterPathW)(LPCWSTR, PPDH_COUNTER_PATH_ELEMENTS_W, LPDWORD, DWORD) = PdhParseCounterPathW;
PDH_STATUS(__stdcall* Real_PdhValidatePathW)(LPCWSTR) = PdhValidatePathW;
PDH_STATUS(__stdcall* Real_PdhGetDefaultPerfObjectW)(LPCWSTR, LPCWSTR, LPWSTR, LPDWORD) = PdhGetDefaultPerfObjectW;
PDH_STATUS(__stdcall* Real_PdhGetDefaultPerfCounterW)(LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, LPDWORD) = PdhGetDefaultPerfCounterW;
PDH_STATUS(__stdcall* Real_PdhBrowseCountersW)(PPDH_BROWSE_DLG_CONFIG_W) = PdhBrowseCountersW;
PDH_STATUS(__stdcall* Real_PdhExpandCounterPathW)(LPCWSTR, LPWSTR, LPDWORD) = PdhExpandCounterPathW;
PDH_STATUS(__stdcall* Real_PdhLookupPerfNameByIndexW)(LPCWSTR, DWORD, LPWSTR, LPDWORD) = PdhLookupPerfNameByIndexW;
PDH_STATUS(__stdcall* Real_PdhLookupPerfIndexByNameW)(LPCWSTR, LPCWSTR, LPDWORD) = PdhLookupPerfIndexByNameW;
PDH_STATUS(__stdcall* Real_PdhOpenLogW)(LPCWSTR, DWORD, LPDWORD, PDH_HQUERY, DWORD, LPCWSTR, PDH_HLOG*) = PdhOpenLogW;
PDH_STATUS(__stdcall* Real_PdhUpdateLogW)(PDH_HLOG, LPCWSTR) = PdhUpdateLogW;
PDH_STATUS(__stdcall* Real_PdhCloseLog)(PDH_HLOG, DWORD) = PdhCloseLog;
PDH_STATUS(__stdcall* Real_PdhSelectDataSourceW)(HWND, DWORD, LPWSTR, LPDWORD) = PdhSelectDataSourceW;
BOOL(__stdcall* Real_PdhIsRealTimeQuery)(PDH_HQUERY) = PdhIsRealTimeQuery;
PDH_STATUS(__stdcall* Real_PdhSetQueryTimeRange)(PDH_HQUERY, PPDH_TIME_INFO) = PdhSetQueryTimeRange;
PDH_STATUS(__stdcall* Real_PdhGetDataSourceTimeRangeW)(LPCWSTR, LPDWORD, PPDH_TIME_INFO, LPDWORD) = PdhGetDataSourceTimeRangeW;
PDH_STATUS(__stdcall* Real_PdhCollectQueryDataEx)(PDH_HQUERY, DWORD, HANDLE) = PdhCollectQueryDataEx;
PDH_STATUS(__stdcall* Real_PdhFormatFromRawValue)(DWORD, DWORD, LONGLONG*, PPDH_RAW_COUNTER, PPDH_RAW_COUNTER, PPDH_FMT_COUNTERVALUE) = PdhFormatFromRawValue;
PDH_STATUS(__stdcall* Real_PdhGetCounterTimeBase)(PDH_HCOUNTER, LONGLONG*) = PdhGetCounterTimeBase;
PDH_STATUS(__stdcall* Real_PdhReadRawLogRecord)(PDH_HLOG, FILETIME, PPDH_RAW_LOG_RECORD, LPDWORD) = PdhReadRawLogRecord;
PDH_STATUS(__stdcall* Real_PdhSetDefaultRealTimeDataSource)(DWORD) = PdhSetDefaultRealTimeDataSource;

// Detoured functions
PDH_FUNCTION Mine_PdhOpenQueryW(LPCWSTR szDataSource, DWORD_PTR dwUserData, PDH_HQUERY* phQuery) {
	LogScope logScope(L"PdhOpenQueryW", szDataSource, dwUserData, (uintptr_t)phQuery);
	PDH_STATUS rv = Real_PdhOpenQueryW(szDataSource, dwUserData, phQuery);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhAddCounterW(PDH_HQUERY hQuery, LPCWSTR szFullCounterPath, DWORD_PTR dwUserData, PDH_HCOUNTER* phCounter) {
	LogScope logScope(L"PdhAddCounterW", (uintptr_t)hQuery, szFullCounterPath, dwUserData, (uintptr_t)phCounter);
	PDH_STATUS rv = Real_PdhAddCounterW(hQuery, szFullCounterPath, dwUserData, phCounter);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhCollectQueryData(PDH_HQUERY hQuery) {
	LogScope logScope(L"PdhCollectQueryData", (uintptr_t)hQuery);
	PDH_STATUS rv = Real_PdhCollectQueryData(hQuery);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhCloseQuery(PDH_HQUERY hQuery) {
	LogScope logScope(L"PdhCloseQuery", (uintptr_t)hQuery);
	PDH_STATUS rv = Real_PdhCloseQuery(hQuery);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhRemoveCounter(PDH_HCOUNTER hCounter) {
	LogScope logScope(L"PdhRemoveCounter", (uintptr_t)hCounter);
	PDH_STATUS rv = Real_PdhRemoveCounter(hCounter);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhGetFormattedCounterValue(PDH_HCOUNTER hCounter, DWORD dwFormat, LPDWORD lpdwType, PPDH_FMT_COUNTERVALUE pValue) {
	LogScope logScope(L"PdhGetFormattedCounterValue", (uintptr_t)hCounter, dwFormat, (uintptr_t)lpdwType, (uintptr_t)pValue);
	PDH_STATUS rv = Real_PdhGetFormattedCounterValue(hCounter, dwFormat, lpdwType, pValue);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhGetRawCounterValue(PDH_HCOUNTER hCounter, LPDWORD lpdwType, PPDH_RAW_COUNTER pValue) {
	LogScope logScope(L"PdhGetRawCounterValue", (uintptr_t)hCounter, (uintptr_t)lpdwType, (uintptr_t)pValue);
	PDH_STATUS rv = Real_PdhGetRawCounterValue(hCounter, lpdwType, pValue);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhCalculateCounterFromRawValue(PDH_HCOUNTER hCounter, DWORD dwFormat, PPDH_RAW_COUNTER rawValue1, PPDH_RAW_COUNTER rawValue2, PPDH_FMT_COUNTERVALUE fmtValue) {
	LogScope logScope(L"PdhCalculateCounterFromRawValue", (uintptr_t)hCounter, dwFormat, (uintptr_t)rawValue1, (uintptr_t)rawValue2, (uintptr_t)fmtValue);
	PDH_STATUS rv = Real_PdhCalculateCounterFromRawValue(hCounter, dwFormat, rawValue1, rawValue2, fmtValue);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhGetCounterInfoW(PDH_HCOUNTER hCounter, BOOLEAN bRetrieveExplainText, LPDWORD pdwBufferSize, PPDH_COUNTER_INFO_W lpBuffer) {
	LogScope logScope(L"PdhGetCounterInfoW", (uintptr_t)hCounter, bRetrieveExplainText, (uintptr_t)pdwBufferSize, (uintptr_t)lpBuffer);
	PDH_STATUS rv = Real_PdhGetCounterInfoW(hCounter, bRetrieveExplainText, pdwBufferSize, lpBuffer);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhSetCounterScaleFactor(PDH_HCOUNTER hCounter, LONG lFactor) {
	LogScope logScope(L"PdhSetCounterScaleFactor", (uintptr_t)hCounter, lFactor);
	PDH_STATUS rv = Real_PdhSetCounterScaleFactor(hCounter, lFactor);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhConnectMachineW(LPCWSTR szMachineName) {
	LogScope logScope(L"PdhConnectMachineW", szMachineName);
	PDH_STATUS rv = Real_PdhConnectMachineW(szMachineName);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhEnumObjectsW(LPCWSTR szDataSource, LPCWSTR szMachineName, LPWSTR mszObjectList, LPDWORD pcchBufferLength, DWORD dwDetailLevel, BOOL bRefresh) {
	LogScope logScope(L"PdhEnumObjectsW", szDataSource, szMachineName, (uintptr_t)mszObjectList, (uintptr_t)pcchBufferLength, dwDetailLevel, bRefresh);
	PDH_STATUS rv = Real_PdhEnumObjectsW(szDataSource, szMachineName, mszObjectList, pcchBufferLength, dwDetailLevel, bRefresh);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhEnumObjectItemsW(LPCWSTR szDataSource, LPCWSTR szMachineName, LPCWSTR szObjectName, LPWSTR mszCounterList, LPDWORD pcchCounterListLength, LPWSTR mszInstanceList, LPDWORD pcchInstanceListLength, DWORD dwDetailLevel, DWORD dwFlags) {
	LogScope logScope(L"PdhEnumObjectItemsW", szDataSource, szMachineName, szObjectName, (uintptr_t)mszCounterList, (uintptr_t)pcchCounterListLength, (uintptr_t)mszInstanceList, (uintptr_t)pcchInstanceListLength, dwDetailLevel, dwFlags);
	PDH_STATUS rv = Real_PdhEnumObjectItemsW(szDataSource, szMachineName, szObjectName, mszCounterList, pcchCounterListLength, mszInstanceList, pcchInstanceListLength, dwDetailLevel, dwFlags);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhMakeCounterPathW(PPDH_COUNTER_PATH_ELEMENTS_W pCounterPathElements, LPWSTR szFullPathBuffer, LPDWORD pcchBufferSize, DWORD dwFlags) {
	LogScope logScope(L"PdhMakeCounterPathW", (uintptr_t)pCounterPathElements, (uintptr_t)szFullPathBuffer, (uintptr_t)pcchBufferSize, dwFlags);
	PDH_STATUS rv = Real_PdhMakeCounterPathW(pCounterPathElements, szFullPathBuffer, pcchBufferSize, dwFlags);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhParseCounterPathW(LPCWSTR szFullPathBuffer, PPDH_COUNTER_PATH_ELEMENTS_W pCounterPathElements, LPDWORD pdwBufferSize, DWORD dwFlags) {
	LogScope logScope(L"PdhParseCounterPathW", szFullPathBuffer, (uintptr_t)pCounterPathElements, (uintptr_t)pdwBufferSize, dwFlags);
	PDH_STATUS rv = Real_PdhParseCounterPathW(szFullPathBuffer, pCounterPathElements, pdwBufferSize, dwFlags);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhValidatePathW(LPCWSTR szFullPathBuffer) {
	LogScope logScope(L"PdhValidatePathW", szFullPathBuffer);
	PDH_STATUS rv = Real_PdhValidatePathW(szFullPathBuffer);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhGetDefaultPerfObjectW(LPCWSTR szDataSource, LPCWSTR szMachineName, LPWSTR szDefaultObjectName, LPDWORD pcchBufferSize) {
	LogScope logScope(L"PdhGetDefaultPerfObjectW", szDataSource, szMachineName, (uintptr_t)szDefaultObjectName, (uintptr_t)pcchBufferSize);
	PDH_STATUS rv = Real_PdhGetDefaultPerfObjectW(szDataSource, szMachineName, szDefaultObjectName, pcchBufferSize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhGetDefaultPerfCounterW(LPCWSTR szDataSource, LPCWSTR szMachineName, LPCWSTR szObjectName, LPWSTR szDefaultCounterName, LPDWORD pcchBufferSize) {
	LogScope logScope(L"PdhGetDefaultPerfCounterW", szDataSource, szMachineName, szObjectName, (uintptr_t)szDefaultCounterName, (uintptr_t)pcchBufferSize);
	PDH_STATUS rv = Real_PdhGetDefaultPerfCounterW(szDataSource, szMachineName, szObjectName, szDefaultCounterName, pcchBufferSize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhBrowseCountersW(PPDH_BROWSE_DLG_CONFIG_W pBrowseDlgConfig) {
	LogScope logScope(L"PdhBrowseCountersW", (uintptr_t)pBrowseDlgConfig);
	PDH_STATUS rv = Real_PdhBrowseCountersW(pBrowseDlgConfig);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhExpandCounterPathW(LPCWSTR szWildCardPath, LPWSTR mszExpandedPathList, LPDWORD pcchPathListLength) {
	LogScope logScope(L"PdhExpandCounterPathW", szWildCardPath, (uintptr_t)mszExpandedPathList, (uintptr_t)pcchPathListLength);
	PDH_STATUS rv = Real_PdhExpandCounterPathW(szWildCardPath, mszExpandedPathList, pcchPathListLength);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhLookupPerfNameByIndexW(LPCWSTR szMachineName, DWORD dwNameIndex, LPWSTR szNameBuffer, LPDWORD pcchNameBufferSize) {
	LogScope logScope(L"PdhLookupPerfNameByIndexW", szMachineName, dwNameIndex, (uintptr_t)szNameBuffer, (uintptr_t)pcchNameBufferSize);
	PDH_STATUS rv = Real_PdhLookupPerfNameByIndexW(szMachineName, dwNameIndex, szNameBuffer, pcchNameBufferSize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhLookupPerfIndexByNameW(LPCWSTR szMachineName, LPCWSTR szNameBuffer, LPDWORD pdwIndex) {
	LogScope logScope(L"PdhLookupPerfIndexByNameW", szMachineName, szNameBuffer, (uintptr_t)pdwIndex);
	PDH_STATUS rv = Real_PdhLookupPerfIndexByNameW(szMachineName, szNameBuffer, pdwIndex);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhOpenLogW(LPCWSTR szLogFileName, DWORD dwAccessFlags, LPDWORD lpdwLogType, PDH_HQUERY hQuery, DWORD dwMaxSize, LPCWSTR szUserCaption, PDH_HLOG* phLog) {
	LogScope logScope(L"PdhOpenLogW", szLogFileName, dwAccessFlags, (uintptr_t)lpdwLogType, (uintptr_t)hQuery, dwMaxSize, szUserCaption, (uintptr_t)phLog);
	PDH_STATUS rv = Real_PdhOpenLogW(szLogFileName, dwAccessFlags, lpdwLogType, hQuery, dwMaxSize, szUserCaption, phLog);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhUpdateLogW(PDH_HLOG hLog, LPCWSTR szUserString) {
	LogScope logScope(L"PdhUpdateLogW", (uintptr_t)hLog, szUserString);
	PDH_STATUS rv = Real_PdhUpdateLogW(hLog, szUserString);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhCloseLog(PDH_HLOG hLog, DWORD dwFlags) {
	LogScope logScope(L"PdhCloseLog", (uintptr_t)hLog, dwFlags);
	PDH_STATUS rv = Real_PdhCloseLog(hLog, dwFlags);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhSelectDataSourceW(HWND hWndOwner, DWORD dwFlags, LPWSTR szDataSource, LPDWORD pcchBufferLength) {
	LogScope logScope(L"PdhSelectDataSourceW", (uintptr_t)hWndOwner, dwFlags, (uintptr_t)szDataSource, (uintptr_t)pcchBufferLength);
	PDH_STATUS rv = Real_PdhSelectDataSourceW(hWndOwner, dwFlags, szDataSource, pcchBufferLength);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhIsRealTimeQuery(PDH_HQUERY hQuery) {
	LogScope logScope(L"PdhIsRealTimeQuery", (uintptr_t)hQuery);
	BOOL rv = Real_PdhIsRealTimeQuery(hQuery);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhSetQueryTimeRange(PDH_HQUERY hQuery, PPDH_TIME_INFO pInfo) {
	LogScope logScope(L"PdhSetQueryTimeRange", (uintptr_t)hQuery, (uintptr_t)pInfo);
	PDH_STATUS rv = Real_PdhSetQueryTimeRange(hQuery, pInfo);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhGetDataSourceTimeRangeW(LPCWSTR szDataSource, LPDWORD pdwNumEntries, PPDH_TIME_INFO pInfo, LPDWORD pdwBufferSize) {
	LogScope logScope(L"PdhGetDataSourceTimeRangeW", szDataSource, (uintptr_t)pdwNumEntries, (uintptr_t)pInfo, (uintptr_t)pdwBufferSize);
	PDH_STATUS rv = Real_PdhGetDataSourceTimeRangeW(szDataSource, pdwNumEntries, pInfo, pdwBufferSize);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhCollectQueryDataEx(PDH_HQUERY hQuery, DWORD dwIntervalTime, HANDLE hNewDataEvent) {
	LogScope logScope(L"PdhCollectQueryDataEx", (uintptr_t)hQuery, dwIntervalTime, (uintptr_t)hNewDataEvent);
	PDH_STATUS rv = Real_PdhCollectQueryDataEx(hQuery, dwIntervalTime, hNewDataEvent);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhFormatFromRawValue(DWORD dwCounterType, DWORD dwFormat, LONGLONG* pTimeBase, PPDH_RAW_COUNTER pRawValue1, PPDH_RAW_COUNTER pRawValue2, PPDH_FMT_COUNTERVALUE pFmtValue) {
	LogScope logScope(L"PdhFormatFromRawValue", dwCounterType, dwFormat, (uintptr_t)pTimeBase, (uintptr_t)pRawValue1, (uintptr_t)pRawValue2, (uintptr_t)pFmtValue);
	PDH_STATUS rv = Real_PdhFormatFromRawValue(dwCounterType, dwFormat, pTimeBase, pRawValue1, pRawValue2, pFmtValue);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhGetCounterTimeBase(PDH_HCOUNTER hCounter, LONGLONG* pTimeBase) {
	LogScope logScope(L"PdhGetCounterTimeBase", (uintptr_t)hCounter, (uintptr_t)pTimeBase);
	PDH_STATUS rv = Real_PdhGetCounterTimeBase(hCounter, pTimeBase);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhReadRawLogRecord(PDH_HLOG hLog, FILETIME ftRecord, PPDH_RAW_LOG_RECORD pRawLogRecord, LPDWORD pdwBufferLength) {
	LogScope logScope(L"PdhReadRawLogRecord", (uintptr_t)hLog, (uintptr_t)&ftRecord, (uintptr_t)pRawLogRecord, (uintptr_t)pdwBufferLength);
	PDH_STATUS rv = Real_PdhReadRawLogRecord(hLog, ftRecord, pRawLogRecord, pdwBufferLength);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

PDH_FUNCTION Mine_PdhSetDefaultRealTimeDataSource(DWORD dwDataSource) {
	LogScope logScope(L"PdhSetDefaultRealTimeDataSource", dwDataSource);
	PDH_STATUS rv = Real_PdhSetDefaultRealTimeDataSource(dwDataSource);
	logScope.SetResult(std::to_wstring(rv));
	return rv;
}

// Vector to store the function pointers and their detoured counterparts
std::vector<DetourFunction> pdhDetourFunctions = {
	{ (PVOID*)&Real_PdhOpenQueryW, Mine_PdhOpenQueryW },
	{ (PVOID*)&Real_PdhAddCounterW, Mine_PdhAddCounterW },
	{ (PVOID*)&Real_PdhCollectQueryData, Mine_PdhCollectQueryData },
	{ (PVOID*)&Real_PdhCloseQuery, Mine_PdhCloseQuery },
	{ (PVOID*)&Real_PdhRemoveCounter, Mine_PdhRemoveCounter },
	{ (PVOID*)&Real_PdhGetFormattedCounterValue, Mine_PdhGetFormattedCounterValue },
	{ (PVOID*)&Real_PdhGetRawCounterValue, Mine_PdhGetRawCounterValue },
	{ (PVOID*)&Real_PdhCalculateCounterFromRawValue, Mine_PdhCalculateCounterFromRawValue },
	{ (PVOID*)&Real_PdhGetCounterInfoW, Mine_PdhGetCounterInfoW },
	{ (PVOID*)&Real_PdhSetCounterScaleFactor, Mine_PdhSetCounterScaleFactor },
	{ (PVOID*)&Real_PdhConnectMachineW, Mine_PdhConnectMachineW },
	{ (PVOID*)&Real_PdhEnumObjectsW, Mine_PdhEnumObjectsW },
	{ (PVOID*)&Real_PdhEnumObjectItemsW, Mine_PdhEnumObjectItemsW },
	{ (PVOID*)&Real_PdhMakeCounterPathW, Mine_PdhMakeCounterPathW },
	{ (PVOID*)&Real_PdhParseCounterPathW, Mine_PdhParseCounterPathW },
	{ (PVOID*)&Real_PdhValidatePathW, Mine_PdhValidatePathW },
	{ (PVOID*)&Real_PdhGetDefaultPerfObjectW, Mine_PdhGetDefaultPerfObjectW },
	{ (PVOID*)&Real_PdhGetDefaultPerfCounterW, Mine_PdhGetDefaultPerfCounterW },
	{ (PVOID*)&Real_PdhBrowseCountersW, Mine_PdhBrowseCountersW },
	{ (PVOID*)&Real_PdhExpandCounterPathW, Mine_PdhExpandCounterPathW },
	{ (PVOID*)&Real_PdhLookupPerfNameByIndexW, Mine_PdhLookupPerfNameByIndexW },
	{ (PVOID*)&Real_PdhLookupPerfIndexByNameW, Mine_PdhLookupPerfIndexByNameW },
	{ (PVOID*)&Real_PdhOpenLogW, Mine_PdhOpenLogW },
	{ (PVOID*)&Real_PdhUpdateLogW, Mine_PdhUpdateLogW },
	{ (PVOID*)&Real_PdhCloseLog, Mine_PdhCloseLog },
	{ (PVOID*)&Real_PdhSelectDataSourceW, Mine_PdhSelectDataSourceW },
	{ (PVOID*)&Real_PdhIsRealTimeQuery, Mine_PdhIsRealTimeQuery },
	{ (PVOID*)&Real_PdhSetQueryTimeRange, Mine_PdhSetQueryTimeRange },
	{ (PVOID*)&Real_PdhGetDataSourceTimeRangeW, Mine_PdhGetDataSourceTimeRangeW },
	{ (PVOID*)&Real_PdhCollectQueryDataEx, Mine_PdhCollectQueryDataEx },
	{ (PVOID*)&Real_PdhFormatFromRawValue, Mine_PdhFormatFromRawValue },
	{ (PVOID*)&Real_PdhGetCounterTimeBase, Mine_PdhGetCounterTimeBase },
	{ (PVOID*)&Real_PdhReadRawLogRecord, Mine_PdhReadRawLogRecord },
	{ (PVOID*)&Real_PdhSetDefaultRealTimeDataSource, Mine_PdhSetDefaultRealTimeDataSource }
};

const std::wstring pdhModuleName = L"pdh.dll";

// Attach function
void AttachPdhDetours() {
	AttachDetours(pdhDetourFunctions, pdhModuleName);
}

// Detach function
void DetachPdhDetours() {
	DetachDetours(pdhDetourFunctions, pdhModuleName);
}
