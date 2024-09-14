#pragma once

#include <detours/detours.h>
#include <vector>
#include <utility>
#include "Logger.h"

// Structure to hold function pointers
struct DetourFunction {
	PVOID* realFunction;
	PVOID detouredFunction;
};

// Generic function to attach detours
void AttachDetours(const std::vector<DetourFunction>& detourFunctions, const std::wstring& moduleName) {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	for (const auto& func : detourFunctions) {
		DetourAttach(func.realFunction, func.detouredFunction);
	}
	LONG lError = DetourTransactionCommit();
	if (lError != NO_ERROR) {
		logger.Log(L"Could not add detours for " + moduleName + L". Error code: " + std::to_wstring(lError));
	}
	else {
		logger.Log(L"Detours added successfully for " + moduleName);
	}
}

// Generic function to detach detours
void DetachDetours(const std::vector<DetourFunction>& detourFunctions, const std::wstring& moduleName) {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	for (const auto& func : detourFunctions) {
		DetourDetach(func.realFunction, func.detouredFunction);
	}
	LONG lError = DetourTransactionCommit();
	if (lError != NO_ERROR) {
		logger.Log(L"Could not remove detours for " + moduleName + L". Error code: " + std::to_wstring(lError));
	}
	else {
		logger.Log(L"Detours removed successfully for " + moduleName);
	}
}
