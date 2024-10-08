# Detour

+ Uses [Microsoft Detours](https://github.com/microsoft/Detours) to intercept functions
+ `Detour.exe` injects a dll `DetouredApis.dll` into target process which hooks APIs
+ Logs are emitted using `OutputDebugString` and can be viewed using [Sysinternals DebugView](https://learn.microsoft.com/en-us/sysinternals/downloads/debugview)

## Setup

+ clone the repo
+ setup vcpkg as described [here](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started-msbuild?pivots=shell-cmd)
+ open the solution on VS 22, and hit `Ctrl+Shift+B` to build

## Usage

+ `Detour.exe <targetprocess.exe> detouredapis.dll`
+ e.g.: `Detour.exe" PerfCounterCpp.exe DetouredApis.dll`
+ it expects the dll `detouredapis.dll` to be in the same directory as `Detour.exe`
+ If there are more instances of target exe, only one will be picked
