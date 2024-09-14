# Detour

+ Uses Microsoft Detours to hook into functions
+ `Detour.exe` injects a dll `DetouredApis.dll` into target process which hooks APIs
+ Emits some logs using debug log which can be viewed using Sysinternals DebugView
+ Most logs will be written to a file: `C:\Windows\Temp\Detour_Output.txt`
+ uses https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-msbuild?pivots=shell-cmd to link detours library, setting up vcpkg is necessary to build the project

## Usage

+ `Detour.exe <targetprocess.exe> detouredapis.dll`
+ e.g.: `Detour.exe" PerfCounterCpp.exe DetouredApis.dll`
+ it expects the dll to be in the same directory as Detour.exe
+ If there are more instances of target exe, only one will be picked

## Troubleshooting

+ If dll is injected to a process executing with low privileges, it may fail to write logs to c:\windows\temp directory. Need to ensure that either log directory has access or use debug output.
