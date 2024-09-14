// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Logger.h"
#include "pdhDetours.h"
#include "kernel32Detours.h"
#include "advapi32Detours.h"

Logger logger;

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		logger.Log(L"DLL_PROCESS_ATTACH triggered");
		AttachPdhDetours();
		AttachKernel32Detours();
		AttachAdvapi32Detours();
		break;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}

	return TRUE;
}
