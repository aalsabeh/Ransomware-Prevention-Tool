#include<shlobj_core.h>

#include "_tracereg.cpp"

#include "_traceRohit.cpp"

#include "_traceRohit1.cpp"

#include <VersionHelpers.h>


/*  ********************** BEGIN HOOKING ***********************
************************************************************************************** */

DWORD (__stdcall * Real_GetModuleFileNameW)(HMODULE a0,
                                            LPWSTR a1,
                                            DWORD a2)
    = GetModuleFileNameW;

DWORD __stdcall Mine_GetModuleFileNameW(HMODULE a0,
                                        LPWSTR a1,
                                        DWORD a2)
{
	LoadedApi("GetModuleFileNameW");
    _PrintEnter("GetModuleFileNameW(%p,%p,%p)\n", a0, a1, a2);


    DWORD rv = 0;
    __try {
        rv = Real_GetModuleFileNameW(a0, a1, a2);
    } __finally {
        _PrintExit("GetModuleFileNameW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

LPSTR (__stdcall * Real_GetEnvironmentStrings)(void)
    = GetEnvironmentStrings;

LPSTR __stdcall Mine_GetEnvironmentStrings(void)
{
	LoadedApi("GetEnvironmentStrings");
    _PrintEnter("GetEnvironmentStrings()\n");

    LPSTR rv = 0;
    __try {
        rv = Real_GetEnvironmentStrings();
    } __finally {
        _PrintExit("GetEnvironmentStrings() -> %hs\n", rv);
    };
    return rv;
}

LPWSTR (__stdcall * Real_GetEnvironmentStringsW)(void)
    = GetEnvironmentStringsW;

LPWSTR __stdcall Mine_GetEnvironmentStringsW(void)
{
	LoadedApi("GetEnvironmentStringsW");
    _PrintEnter("GetEnvironmentStringsW()\n");

    LPWSTR rv = 0;
    __try {
        rv = Real_GetEnvironmentStringsW();
    } __finally {
        _PrintExit("GetEnvironmentStringsW() -> %ls\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_WriteFile)(HANDLE a0,
                                  LPCVOID a1,
                                  DWORD a2,
                                  LPDWORD a3,
                                  LPOVERLAPPED a4)
    = WriteFile;

BOOL __stdcall Mine_WriteFile(HANDLE a0,
                              LPCVOID a1,
                              DWORD a2,
                              LPDWORD a3,
                              LPOVERLAPPED a4)
{
	LoadedApi("WriteFile");
    _PrintEnter("WriteFile(%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_WriteFile(a0, a1, a2, a3, a4);
    } __finally {
        _PrintExit("WriteFile(,,,,) -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_FlushFileBuffers)(HANDLE a0)
    = FlushFileBuffers;

BOOL __stdcall Mine_FlushFileBuffers(HANDLE a0)
{
	LoadedApi("FlushFileBuffers");
    _PrintEnter("FlushFileBuffers(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_FlushFileBuffers(a0);
    } __finally {
        _PrintExit("FlushFileBuffers() -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_CloseHandle)(HANDLE a0)
    = CloseHandle;

BOOL __stdcall Mine_CloseHandle(HANDLE a0)
{
	LoadedApi("CloseHandle");
    _PrintEnter("CloseHandle(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_CloseHandle(a0);
    } __finally {
        _PrintExit("CloseHandle() -> %x\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_WaitNamedPipeW)(LPCWSTR a0,
                                       DWORD a1)
    = WaitNamedPipeW;

BOOL __stdcall Mine_WaitNamedPipeW(LPCWSTR a0,
                                   DWORD a1)
{
	LoadedApi("WaitNamedPipeW");
    _PrintEnter("WaitNamedPipeW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_WaitNamedPipeW(a0, a1);
    } __finally {
        _PrintExit("WaitNamedPipeW(,) -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_SetNamedPipeHandleState)(HANDLE a0,
                                                LPDWORD a1,
                                                LPDWORD a2,
                                                LPDWORD a3)
    = SetNamedPipeHandleState;

BOOL __stdcall Mine_SetNamedPipeHandleState(HANDLE a0,
                                            LPDWORD a1,
                                            LPDWORD a2,
                                            LPDWORD a3)
{
	LoadedApi("SetNamedPipeHandleState");
    _PrintEnter("SetNamedPipeHandleState(%p,%p,%p,%p)\n", a0, a1, a2, a3);

    BOOL rv = 0;
    __try {
        rv = Real_SetNamedPipeHandleState(a0, a1, a2, a3);
    } __finally {
        _PrintExit("SetNamedPipeHandleState(,,,) -> %p\n", rv);
    };
    return rv;
}

DWORD (__stdcall * Real_GetCurrentProcessId)(void)
    = GetCurrentProcessId;

DWORD __stdcall Mine_GetCurrentProcessId(void)
{
	LoadedApi("GetCurrentProcessId");
    _PrintEnter("GetCurrentProcessId()\n");

    DWORD rv = 0;
    __try {
        rv = Real_GetCurrentProcessId();
    } __finally {
        _PrintExit("GetCurrentProcessId() -> %p\n", rv);
    };
    return rv;
}

void (__stdcall * Real_OutputDebugStringA)(LPCSTR a0)
    = OutputDebugStringA;

void __stdcall Mine_OutputDebugStringA(LPCSTR a0)
{
	LoadedApi("OutputDebugStringA");
    _PrintEnter("OutputDebugStringA(%hs)\n", a0);

    __try {
        Real_OutputDebugStringA(a0);
    } __finally {
        _PrintExit("OutputDebugStringA() ->\n");
    };
}


/*  **********************Hooking GlobalMemoryStatusEx function***********************
***************************************************************************************/

static BOOL (WINAPI * Real_GlobalMemoryStatusEx)(LPMEMORYSTATUSEX lpBuffer) = GlobalMemoryStatusEx;

BOOL WINAPI Mine_GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpBuffer)
{
	LoadedApi("GlobalMemoryStatusEx");
    _PrintEnter("GlobalMemoryStatusEx\n");
    BOOL rv = 0;
    __try {
        rv = Real_GlobalMemoryStatusEx(lpBuffer);
    } __finally {
        _PrintExit("GlobalMemoryStatusEx() -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking IsDebuggerPresent function***********************
************************************************************************************** */
BOOL (__stdcall * Real_IsDebuggerPresent)(void)
    = IsDebuggerPresent;

BOOL __stdcall Mine_IsDebuggerPresent(void)
{
	LoadedApi("IsDebuggerPresent");
    _PrintEnter("IsDebuggerPresent()\n");

    BOOL rv = 0;
    __try {
        rv = Real_IsDebuggerPresent();
    } __finally {
        _PrintExit("IsDebuggerPresent() -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking FindWindow function***********************
************************************************************************************** */

HWND (__stdcall * Real_FindWindowA)(LPCSTR a0,
                                    LPCSTR a1)
    = FindWindowA;

HWND __stdcall Mine_FindWindowA(LPCSTR a0,
                                LPCSTR a1)
{
	LoadedApi("FindWindowA");
    _PrintEnter("FindWindowA(%hs,%hs)\n", a0, a1);

    HWND rv = 0;
    __try {
        rv = Real_FindWindowA(a0, a1);
    } __finally {
        _PrintExit("FindWindowA(,) -> %p\n", rv);
    };
    return rv;
}

HWND (__stdcall * Real_FindWindowExA)(HWND a0,
                                      HWND a1,
                                      LPCSTR a2,
                                      LPCSTR a3)
    = FindWindowExA;

HWND __stdcall Mine_FindWindowExA(HWND a0,
                                  HWND a1,
                                  LPCSTR a2,
                                  LPCSTR a3)
{
	LoadedApi("FindWindowExA");
    _PrintEnter("FindWindowExA(%p,%p,%hs,%hs)\n", a0, a1, a2, a3);

    HWND rv = 0;
    __try {
        rv = Real_FindWindowExA(a0, a1, a2, a3);
    } __finally {
        _PrintExit("FindWindowExA(,,,) -> %p\n", rv);
    };
    return rv;
}

HWND (__stdcall * Real_FindWindowExW)(HWND a0,
                                      HWND a1,
                                      LPCWSTR a2,
                                      LPCWSTR a3)
    = FindWindowExW;

HWND __stdcall Mine_FindWindowExW(HWND a0,
                                  HWND a1,
                                  LPCWSTR a2,
                                  LPCWSTR a3)
{
	LoadedApi("FindWindowExW");
    _PrintEnter("FindWindowExW(%p,%p,%ls,%ls)\n", a0, a1, a2, a3);

    HWND rv = 0;
    __try {
        rv = Real_FindWindowExW(a0, a1, a2, a3);
    } __finally {
        _PrintExit("FindWindowExW(,,,) -> %p\n", rv);
    };
    return rv;
}    

HWND (__stdcall * Real_FindWindowW)(LPCWSTR a0, LPCWSTR a1) = FindWindowW;

HWND __stdcall Mine_FindWindowW(LPCWSTR a0,
                                LPCWSTR a1)
{
	LoadedApi("FindWindowW");
    _PrintEnter("FindWindowW(%ls,%ls)\n", a0, a1);

    HWND rv = 0;
    __try {
        rv = Real_FindWindowW(a0, a1);
    } __finally {
        _PrintExit("FindWindowW(,) -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking EnumPrintersA & EnumPrintersW function***********************
************************************************************************************** */

BOOL (__stdcall * Real_EnumPrintersA)(_In_  DWORD   Flags, _In_  LPSTR  Name, _In_  DWORD   Level, _Out_ LPBYTE  pPrinterEnum, _In_  DWORD   cbBuf, _Out_ LPDWORD pcbNeeded, _Out_ LPDWORD pcReturned) = EnumPrintersA;

BOOL __stdcall Mine_EnumPrintersA(_In_  DWORD   Flags, _In_  LPSTR  Name, _In_  DWORD   Level, _Out_ LPBYTE  pPrinterEnum, _In_  DWORD   cbBuf, _Out_ LPDWORD pcbNeeded, _Out_ LPDWORD pcReturned)
{
	LoadedApi("EnumPrintersA");
    _PrintEnter("EnumPrintersA\n");

    BOOL rv = 0;
    __try {
        rv = Real_EnumPrintersA(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned);
    } __finally {
        _PrintExit("EnumPrintersA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_EnumPrintersW)(_In_  DWORD   Flags, _In_  LPWSTR  Name, _In_  DWORD   Level, _Out_ LPBYTE  pPrinterEnum, _In_  DWORD   cbBuf, _Out_ LPDWORD pcbNeeded, _Out_ LPDWORD pcReturned) = EnumPrintersW;

// //Function that will replace the hooked function (hooker)
BOOL __stdcall Mine_EnumPrintersW(_In_  DWORD   Flags, _In_  LPWSTR  Name, _In_  DWORD   Level, _Out_ LPBYTE  pPrinterEnum, _In_  DWORD   cbBuf, _Out_ LPDWORD pcbNeeded, _Out_ LPDWORD pcReturned)
{
	LoadedApi("EnumPrintersW");
    _PrintEnter("EnumPrintersW\n");

    BOOL rv = 0;
    __try {
        rv = Real_EnumPrintersW(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned);
    } __finally {
        _PrintExit("EnumPrintersW(,) -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking EnumServicesStatusA & EnumServicesStatusW & EnumServicesStatusExA & EnumServicesStatusExW  function***********************
************************************************************************************** */

BOOL (__stdcall * Real_EnumServicesStatusA)(SC_HANDLE hSCManager, DWORD dwServiceType, DWORD dwServiceState, LPENUM_SERVICE_STATUSA lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle) = EnumServicesStatusA;

BOOL __stdcall Mine_EnumServicesStatusA(SC_HANDLE hSCManager, DWORD dwServiceType, DWORD dwServiceState, LPENUM_SERVICE_STATUSA lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle)
{
	LoadedApi("EnumServicesStatusA");
    _PrintEnter("EnumServicesStatusA\n");

    BOOL rv = 0;
    __try {
        rv = Real_EnumServicesStatusA(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle);
    } __finally {
        _PrintExit("EnumServicesStatusA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_EnumServicesStatusW )(SC_HANDLE hSCManager, DWORD dwServiceType, DWORD dwServiceState, LPENUM_SERVICE_STATUSW lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle) = EnumServicesStatusW;

BOOL __stdcall Mine_EnumServicesStatusW (SC_HANDLE hSCManager, DWORD dwServiceType, DWORD dwServiceState, LPENUM_SERVICE_STATUSW lpServices, DWORD cbBufSize, LPDWORD pcbBytesNeeded, LPDWORD lpServicesReturned, LPDWORD lpResumeHandle)
{
	LoadedApi("EnumServicesStatusW");
    _PrintEnter("EnumServicesStatusW \n");

    BOOL rv = 0;
    __try {
        rv = EnumServicesStatusW(hSCManager, dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle);
    } __finally {
        _PrintExit("EnumServicesStatusW (,) -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_EnumServicesStatusExA )(SC_HANDLE    hSCManager,
                                                SC_ENUM_TYPE InfoLevel,
                                                DWORD        dwServiceType,
                                                DWORD        dwServiceState,
                                                LPBYTE       lpServices,
                                                DWORD        cbBufSize,
                                                LPDWORD      pcbBytesNeeded,
                                                LPDWORD      lpServicesReturned,
                                                LPDWORD      lpResumeHandle,
                                                LPCSTR       pszGroupName) = EnumServicesStatusExA ;

BOOL __stdcall Mine_EnumServicesStatusExA (SC_HANDLE    hSCManager,
                                                SC_ENUM_TYPE InfoLevel,
                                                DWORD        dwServiceType,
                                                DWORD        dwServiceState,
                                                LPBYTE       lpServices,
                                                DWORD        cbBufSize,
                                                LPDWORD      pcbBytesNeeded,
                                                LPDWORD      lpServicesReturned,
                                                LPDWORD      lpResumeHandle,
                                                LPCSTR       pszGroupName)
{
	LoadedApi("EnumServicesStatusExA");
    _PrintEnter("EnumServicesStatusExA \n");

    BOOL rv = 0;
    __try {
        rv = Real_EnumServicesStatusExA(hSCManager, InfoLevel,dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle, pszGroupName);
    } __finally {
        _PrintExit("EnumServicesStatusExA(,) -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_EnumServicesStatusExW )(SC_HANDLE    hSCManager,
                                                SC_ENUM_TYPE InfoLevel,
                                                DWORD        dwServiceType,
                                                DWORD        dwServiceState,
                                                LPBYTE       lpServices,
                                                DWORD        cbBufSize,
                                                LPDWORD      pcbBytesNeeded,
                                                LPDWORD      lpServicesReturned,
                                                LPDWORD      lpResumeHandle,
                                                LPCWSTR       pszGroupName) = EnumServicesStatusExW ;

BOOL __stdcall Mine_EnumServicesStatusExW (SC_HANDLE    hSCManager,
                                                SC_ENUM_TYPE InfoLevel,
                                                DWORD        dwServiceType,
                                                DWORD        dwServiceState,
                                                LPBYTE       lpServices,
                                                DWORD        cbBufSize,
                                                LPDWORD      pcbBytesNeeded,
                                                LPDWORD      lpServicesReturned,
                                                LPDWORD      lpResumeHandle,
                                                LPCWSTR       pszGroupName)
{
	LoadedApi("EnumServicesStatusExW");
    _PrintEnter("EnumServicesStatusExW \n");

    BOOL rv = 0;
    __try {
        rv = Real_EnumServicesStatusExW(hSCManager, InfoLevel,dwServiceType, dwServiceState, lpServices, cbBufSize, pcbBytesNeeded, lpServicesReturned, lpResumeHandle, pszGroupName);
    } __finally {
        _PrintExit("EnumServicesStatusExW(,) -> %p\n", rv);
    };
    return rv;
}
/*  **********************Hooking GetMonitorInfoA function***********************
************************************************************************************** */

BOOL (__stdcall * Real_GetMonitorInfoA)(HMONITOR hMonitor, LPMONITORINFO lpmi) = GetMonitorInfoA;

BOOL __stdcall Mine_GetMonitorInfoA(HMONITOR hMonitor, LPMONITORINFO lpmi)
{
	LoadedApi("GetMonitorInfoA");
    _PrintEnter("GetMonitorInfoA\n");

    BOOL rv = 0;
    __try {
        rv = Real_GetMonitorInfoA(hMonitor, lpmi);
    } __finally {
        _PrintExit("GetMonitorInfoA(,) -> %p\n", rv);
    };
    return rv;
}


/*  **********************Hooking GetLocalTime function***********************
************************************************************************************** */
void (__stdcall * Real_GetLocalTime)(LPSYSTEMTIME a0)
    = GetLocalTime;

void __stdcall Mine_GetLocalTime(LPSYSTEMTIME a0)
{
	LoadedApi("GetLocalTime");
    _PrintEnter("GetLocalTime(%p)\n", a0);

    __try {
        Real_GetLocalTime(a0);
    } __finally {
        _PrintExit("GetLocalTime() ->\n");
    };
}


/*  **********************Hooking GetVersion function***********************
************************************************************************************** */
DWORD (__stdcall * Real_GetVersion)(void)
    = GetVersion;

DWORD __stdcall Mine_GetVersion(void)
{
	LoadedApi("GetVersion");
    _PrintEnter("GetVersion()\n");

    DWORD rv = 0;
    __try {
        rv = Real_GetVersion();
    } __finally {
        _PrintExit("GetVersion() -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_GetVersionExA)(LPOSVERSIONINFOA a0)
    = GetVersionExA;

BOOL __stdcall Mine_GetVersionExA(LPOSVERSIONINFOA a0)
{
	LoadedApi("GetVersionExA");
    _PrintEnter("GetVersionExA(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetVersionExA(a0);
    } __finally {
        _PrintExit("GetVersionExA() -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_GetVersionExW)(LPOSVERSIONINFOW a0)
    = GetVersionExW;

BOOL __stdcall Mine_GetVersionExW(LPOSVERSIONINFOW a0)
{
	LoadedApi("GetVersionExW");
    _PrintEnter("GetVersionExW(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetVersionExW(a0);
    } __finally {
        _PrintExit("GetVersionExW() -> %p\n", rv);
    };
    return rv;
}

VERSIONHELPERAPI (__cdecl * Real_IsWindowsXPOrGreater)() = IsWindowsXPOrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindowsXPOrGreater()
{
	LoadedApi("IsWindowsXPOrGreater");
    _PrintEnter("IsWindowsXPOrGreater\n");
    return Real_IsWindowsXPOrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindowsXPSP1OrGreater)() = IsWindowsXPSP1OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindowsXPSP1OrGreater()
{
	LoadedApi("IsWindowsXPSP1OrGreater");
    _PrintEnter("IsWindowsXPSP1OrGreater\n");
    return Real_IsWindowsXPSP1OrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindowsXPSP2OrGreater)() = IsWindowsXPSP2OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindowsXPSP2OrGreater()
{
	LoadedApi("IsWindowsXPSP2OrGreater");
    _PrintEnter("IsWindowsXPSP2OrGreater\n");
    return Real_IsWindowsXPSP2OrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindowsXPSP3OrGreater)() = IsWindowsXPSP3OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindowsXPSP3OrGreater()
{
	LoadedApi("IsWindowsXPSP3OrGreater");
    _PrintEnter("IsWindowsXPSP3OrGreater\n");
    return Real_IsWindowsXPSP3OrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindowsVistaOrGreater)() = IsWindowsVistaOrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindowsVistaOrGreater()
{
	LoadedApi("IsWindowsVistaOrGreater");
     _PrintEnter("IsWindowsVistaOrGreater\n");
    return Real_IsWindowsVistaOrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindowsVistaSP1OrGreater)() = IsWindowsVistaSP1OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindowsVistaSP1OrGreater()
{
	LoadedApi("IsWindowsVistaSP1OrGreater");
    _PrintEnter("IsWindowsVistaSP1OrGreater\n");
    return Real_IsWindowsVistaSP1OrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindowsVistaSP2OrGreater)() = IsWindowsVistaSP2OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindowsVistaSP2OrGreater()
{
	LoadedApi("IsWindowsVistaSP2OrGreater");
     _PrintEnter("IsWindowsVistaSP2OrGreater\n");
    return Real_IsWindowsVistaSP2OrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindows7OrGreater)() = IsWindows7OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindows7OrGreater()
{
	LoadedApi("IsWindows7OrGreater");
     _PrintEnter("IsWindows7OrGreater\n");
    return Real_IsWindows7OrGreater();
}
VERSIONHELPERAPI (__cdecl * Real_IsWindows7SP1OrGreater)() = IsWindows7SP1OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindows7SP1OrGreater()
{
	LoadedApi("IsWindows7SP1OrGreater");
     _PrintEnter("IsWindows7SP1OrGreater\n");
    return Real_IsWindows7SP1OrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindows8OrGreater)() = IsWindows8OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindows8OrGreater()
{
	LoadedApi("IsWindows8OrGreater");
     _PrintEnter("IsWindows8OrGreater\n");
    return Real_IsWindows8OrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindows8Point1OrGreater)() = IsWindows8Point1OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindows8Point1OrGreater()
{
	LoadedApi("IsWindows8Point1OrGreater");
     _PrintEnter("IsWindows8Point1OrGreater\n");
    return Real_IsWindows8Point1OrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindows10OrGreater)() = IsWindows10OrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindows10OrGreater()
{
	LoadedApi("IsWindows10OrGreater");
     _PrintEnter("IsWindows10OrGreater\n");
    return Real_IsWindows10OrGreater();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindowsServer)() = IsWindowsServer;
VERSIONHELPERAPI __cdecl Mine_IsWindowsServer()
{
	LoadedApi("IsWindowsServer");
    _PrintEnter("IsWindowsServer\n");
    return Real_IsWindowsServer();
}

VERSIONHELPERAPI (__cdecl * Real_IsWindowsVersionOrGreater)(WORD wMajorVersion,
  WORD wMinorVersion,
  WORD wServicePackMajor) = IsWindowsVersionOrGreater;
VERSIONHELPERAPI __cdecl Mine_IsWindowsVersionOrGreater(WORD wMajorVersion,
  WORD wMinorVersion,
  WORD wServicePackMajor)
{
	LoadedApi("IsWindowsVersionOrGreater");
    _PrintEnter("IsWindowsVersionOrGreater\n");
    return Real_IsWindowsVersionOrGreater(wMajorVersion, wMinorVersion, wServicePackMajor);
}


/*  **********************Hooking GetUserDefaultUILanguage & GetUserDefaultLangID function***********************
************************************************************************************** */

LANGID (__stdcall * Real_GetUserDefaultUILanguage)(void)
    = GetUserDefaultUILanguage;

LANGID __stdcall Mine_GetUserDefaultUILanguage(void)
{
	LoadedApi("GetUserDefaultUILanguage");
    _PrintEnter("GetUserDefaultUILanguage()\n");

    LANGID rv = 0;
    __try {
        rv = Real_GetUserDefaultUILanguage();
    } __finally {
        _PrintExit("GetUserDefaultUILanguage() -> %p\n", rv);
    };
    return rv;
}

LANGID (__stdcall * Real_GetUserDefaultLangID)(void)
    = GetUserDefaultLangID;

LANGID __stdcall Mine_GetUserDefaultLangID(void)
{
	LoadedApi("GetUserDefaultLangID");
    _PrintEnter("GetUserDefaultLangID()\n");

    LANGID rv = 0;
    __try {
        rv = Real_GetUserDefaultLangID();
    } __finally {
        _PrintExit("GetUserDefaultLangID() -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking GetDiskFreeSpaceW function***********************
************************************************************************************** */
BOOL (__stdcall * Real_GetDiskFreeSpaceW)(LPCWSTR a0,
                                          LPDWORD a1,
                                          LPDWORD a2,
                                          LPDWORD a3,
                                          LPDWORD a4)
    = GetDiskFreeSpaceW;


BOOL __stdcall Mine_GetDiskFreeSpaceW(LPCWSTR a0,
                                      LPDWORD a1,
                                      LPDWORD a2,
                                      LPDWORD a3,
                                      LPDWORD a4)
{
	LoadedApi("GetDiskFreeSpaceW");
    _PrintEnter("GetDiskFreeSpaceW(%ls,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4);

    BOOL rv = 0;
    __try {
        rv = Real_GetDiskFreeSpaceW(a0, a1, a2, a3, a4);
    } __finally {
        _PrintExit("GetDiskFreeSpaceW(,,,,) -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking SHGetFolderPathW function***********************
************************************************************************************** */

HRESULT (__stdcall * Real_SHGetFolderPathW)(HWND   hwnd, int    csidl, HANDLE hToken, DWORD  dwFlags, LPWSTR pszPath) = SHGetFolderPathW; 

HRESULT __stdcall Mine_SHGetFolderPathW(HWND   hwnd,
  int    csidl,
  HANDLE hToken,
  DWORD  dwFlags,
  LPWSTR pszPath)
{
	LoadedApi("SHGetFolderPathW");
    _PrintEnter("SHGetFolderPathW\n");

    HRESULT rv = 0;
     __try {
        rv = Real_SHGetFolderPathW(hwnd ,csidl, hToken, dwFlags, pszPath);
    } __finally {
        _PrintExit("SHGetFolderPathW(,,,,) -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking GetComputerNameA & GetComputerNameW function***********************
************************************************************************************** */
BOOL (__stdcall * Real_GetComputerNameA)(LPSTR a0,
                                         LPDWORD a1)
    = GetComputerNameA;

BOOL __stdcall Mine_GetComputerNameA(LPSTR a0,
                                     LPDWORD a1)
{
	LoadedApi("GetComputerNameA");
    _PrintEnter("GetComputerNameA(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetComputerNameA(a0, a1);
    } __finally {
        _PrintExit("GetComputerNameA(%hs,) -> %p\n", a0, rv);
    };
    return rv;
}

BOOL (__stdcall * Real_GetComputerNameW)(LPWSTR a0,
                                         LPDWORD a1)
    = GetComputerNameW;

BOOL __stdcall Mine_GetComputerNameW(LPWSTR a0,
                                     LPDWORD a1)
{
	LoadedApi("GetComputerNameW");
    _PrintEnter("GetComputerNameW(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetComputerNameW(a0, a1);
    } __finally {
        _PrintExit("GetComputerNameW(%ls,) -> %p\n", a0, rv);
    };
    return rv;
}

/*  **********************Hooking GetWindowsDirectoryA & GetWindowsDirectoryW function***********************
************************************************************************************** */
UINT (__stdcall * Real_GetWindowsDirectoryA)(LPSTR a0,
                                             UINT a1)
    = GetWindowsDirectoryA;

UINT __stdcall Mine_GetWindowsDirectoryA(LPSTR a0,
                                         UINT a1)
{
	LoadedApi("GetWindowsDirectoryA");
    _PrintEnter("GetWindowsDirectoryA(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetWindowsDirectoryA(a0, a1);
    } __finally {
        _PrintExit("GetWindowsDirectoryA(%hs,) -> %p\n", a0, rv);
    };
    return rv;
}

UINT (__stdcall * Real_GetWindowsDirectoryW)(LPWSTR a0,
                                             UINT a1)
    = GetWindowsDirectoryW;

UINT __stdcall Mine_GetWindowsDirectoryW(LPWSTR a0,
                                         UINT a1)
{
	LoadedApi("GetWindowsDirectoryW");
    _PrintEnter("GetWindowsDirectoryW(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetWindowsDirectoryW(a0, a1);
    } __finally {
        _PrintExit("GetWindowsDirectoryW(%ls,) -> %p\n", a0, rv);
    };
    return rv;
}


/*  **********************Hooking GetSystemDirectoryA & GetSystemDirectoryW function***********************
************************************************************************************** */
UINT (__stdcall * Real_GetSystemDirectoryA)(LPSTR a0,
                                            UINT a1)
    = GetSystemDirectoryA;

UINT __stdcall Mine_GetSystemDirectoryA(LPSTR a0,
                                        UINT a1)
{
	LoadedApi("GetSystemDirectoryA");
    _PrintEnter("GetSystemDirectoryA(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetSystemDirectoryA(a0, a1);
    } __finally {
        _PrintExit("GetSystemDirectoryA(%hs,) -> %p\n", a0, rv);
    };
    return rv;
}

UINT (__stdcall * Real_GetSystemDirectoryW)(LPWSTR a0,
                                            UINT a1)
    = GetSystemDirectoryW;

UINT __stdcall Mine_GetSystemDirectoryW(LPWSTR a0,
                                        UINT a1)
{
	LoadedApi("GetSystemDirectoryW");
    _PrintEnter("GetSystemDirectoryW(%p,%p)\n", a0, a1);

    UINT rv = 0;
    __try {
        rv = Real_GetSystemDirectoryW(a0, a1);
    } __finally {
        _PrintExit("GetSystemDirectoryW(%ls,) -> %p\n", a0, rv);
    };
    return rv;
}

/*  **********************Hooking GetCurrentDirectoryA & GetCurrentDirectoryW function***********************
************************************************************************************** */

DWORD (__stdcall * Real_GetCurrentDirectoryA)(DWORD a0,
                                              LPSTR a1)
    = GetCurrentDirectoryA;

DWORD __stdcall Mine_GetCurrentDirectoryA(DWORD a0,
                                          LPSTR a1)
{
	LoadedApi("GetCurrentDirectoryA");
    _PrintEnter("GetCurrentDirectoryA(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetCurrentDirectoryA(a0, a1);
    } __finally {
        _PrintExit("GetCurrentDirectoryA(,%hs) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD (__stdcall * Real_GetCurrentDirectoryW)(DWORD a0,
                                              LPWSTR a1)
    = GetCurrentDirectoryW;

DWORD __stdcall Mine_GetCurrentDirectoryW(DWORD a0,
                                          LPWSTR a1)
{
	LoadedApi("GetCurrentDirectoryW");
    _PrintEnter("GetCurrentDirectoryW(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetCurrentDirectoryW(a0, a1);
    } __finally {
        _PrintExit("GetCurrentDirectoryW(,%ls) -> %p\n", a1, rv);
    };
    return rv;
}

/*  **********************Hooking GetKeyboardLayoutNameA & GetKeyboardLayoutNameW function***********************
************************************************************************************** */
BOOL (__stdcall * Real_GetKeyboardLayoutNameA)(LPSTR a0)
    = GetKeyboardLayoutNameA;

BOOL __stdcall Mine_GetKeyboardLayoutNameA(LPSTR a0)
{
	LoadedApi("GetKeyboardLayoutNameA");
    _PrintEnter("GetKeyboardLayoutNameA(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetKeyboardLayoutNameA(a0);
    } __finally {
        _PrintExit("GetKeyboardLayoutNameA(%hs) -> %p\n", a0, rv);
    };
    return rv;
}

BOOL (__stdcall * Real_GetKeyboardLayoutNameW)(LPWSTR a0)
    = GetKeyboardLayoutNameW;

BOOL __stdcall Mine_GetKeyboardLayoutNameW(LPWSTR a0)
{
	LoadedApi("GetKeyboardLayoutNameW");
    _PrintEnter("GetKeyboardLayoutNameW(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_GetKeyboardLayoutNameW(a0);
    } __finally {
        _PrintExit("GetKeyboardLayoutNameW(%ls) -> %p\n", a0, rv);
    };
    return rv;
}

/*  **********************Hooking GetDesktopWindow function***********************
************************************************************************************** */
HWND (__stdcall * Real_GetDesktopWindow)(void)
    = GetDesktopWindow;

HWND __stdcall Mine_GetDesktopWindow(void)
{
	LoadedApi("GetDesktopWindow");
    _PrintEnter("GetDesktopWindow()\n");

    HWND rv = 0;
    __try {
        rv = Real_GetDesktopWindow();
    } __finally {
        _PrintExit("GetDesktopWindow() -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking GetWindowRect function***********************
************************************************************************************** */
BOOL (__stdcall * Real_GetWindowRect)(HWND a0,
                                      LPRECT a1)
    = GetWindowRect;

BOOL __stdcall Mine_GetWindowRect(HWND a0,
                                  LPRECT a1)
{
	LoadedApi("GetWindowRect");
    _PrintEnter("GetWindowRect(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetWindowRect(a0, a1);
    } __finally {
        _PrintExit("GetWindowRect(,) -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking GetDC, GetDCEx, GetDCOrgEx function***********************
************************************************************************************** */
HDC (__stdcall * Real_GetDC)(HWND a0)
    = GetDC;

HDC __stdcall Mine_GetDC(HWND a0)
{
	LoadedApi("GetDC");
    _PrintEnter("GetDC(%p)\n", a0);

    HDC rv = 0;
    __try {
        rv = Real_GetDC(a0);
    } __finally {
        _PrintExit("GetDC() -> %p\n", rv);
    };
    return rv;
}

HDC (__stdcall * Real_GetDCEx)(HWND a0,
                               HRGN a1,
                               DWORD a2)
    = GetDCEx;

HDC __stdcall Mine_GetDCEx(HWND a0,
                           HRGN a1,
                           DWORD a2)
{
	LoadedApi("GetDCEx");
    _PrintEnter("GetDCEx(%p,%p,%p)\n", a0, a1, a2);

    HDC rv = 0;
    __try {
        rv = Real_GetDCEx(a0, a1, a2);
    } __finally {
        _PrintExit("GetDCEx(,,) -> %p\n", rv);
    };
    return rv;
}

BOOL (__stdcall * Real_GetDCOrgEx)(HDC a0,
                                   POINT* a1)
    = GetDCOrgEx;
BOOL __stdcall Mine_GetDCOrgEx(HDC a0,
                               POINT* a1)
{
	LoadedApi("GetDCOrgEx");
    _PrintEnter("GetDCOrgEx(%p,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_GetDCOrgEx(a0, a1);
    } __finally {
        _PrintExit("GetDCOrgEx(,) -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking GetDeviceCaps function***********************
************************************************************************************** */
int (__stdcall * Real_GetDeviceCaps)(HDC a0,
                                     int a1)
    = GetDeviceCaps;

int __stdcall Mine_GetDeviceCaps(HDC a0,
                                 int a1)
{
	LoadedApi("GetDeviceCaps");
    _PrintEnter("GetDeviceCaps(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_GetDeviceCaps(a0, a1);
    } __finally {
        _PrintExit("GetDeviceCaps(,) -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking ReleaseDC function***********************
************************************************************************************** */
int (__stdcall * Real_ReleaseDC)(HWND a0,
                                 HDC a1)
    = ReleaseDC;

int __stdcall Mine_ReleaseDC(HWND a0,
                             HDC a1)
{
	LoadedApi("ReleaseDC");
    _PrintEnter("ReleaseDC(%p,%p)\n", a0, a1);

    int rv = 0;
    __try {
        rv = Real_ReleaseDC(a0, a1);
    } __finally {
        _PrintExit("ReleaseDC(,) -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking GetEnvironmentVariableW function***********************
************************************************************************************** */
DWORD (__stdcall * Real_GetEnvironmentVariableA)(LPCSTR a0,
                                                 LPSTR a1,
                                                 DWORD a2)
    = GetEnvironmentVariableA;

DWORD __stdcall Mine_GetEnvironmentVariableA(LPCSTR a0,
                                             LPSTR a1,
                                             DWORD a2)
{
	LoadedApi("GetEnvironmentVariableA");
    _PrintEnter("GetEnvironmentVariableA(%hs,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetEnvironmentVariableA(a0, a1, a2);
    } __finally {
        _PrintExit("GetEnvironmentVariableA(,%hs,) -> %p\n", a1, rv);
    };
    return rv;
}

DWORD (__stdcall * Real_GetEnvironmentVariableW)(LPCWSTR a0,
                                                 LPWSTR a1,
                                                 DWORD a2)
    = GetEnvironmentVariableW;

DWORD __stdcall Mine_GetEnvironmentVariableW(LPCWSTR a0,
                                             LPWSTR a1,
                                             DWORD a2)
{
	LoadedApi("GetEnvironmentVariableW");
    _PrintEnter("GetEnvironmentVariableW(%ls,%p,%p)\n", a0, a1, a2);

    DWORD rv = 0;
    __try {
        rv = Real_GetEnvironmentVariableW(a0, a1, a2);
    } __finally {
        _PrintExit("GetEnvironmentVariableW(,%ls,) -> %p\n", a1, rv);
    };
    return rv;
}

/*  **********************Hooking GetUserNameW function***********************
************************************************************************************** */
BOOL (__stdcall * Real_GetUserNameW)(LPWSTR pwszKLID, LPDWORD pcbBuffer) = GetUserNameW;

BOOL WINAPI Mine_GetUserNameW(LPWSTR pwszKLID, LPDWORD pcbBuffer)
{
	LoadedApi("GetUserNameW");
    _PrintEnter("GetUSerNameW\n");
    BOOL rv = 0;
    __try{
        rv = Real_GetUserNameW(pwszKLID, pcbBuffer);
    } __finally {
        _PrintExit("GetUSerNameW(,,) -> %p\n", rv);
    };

    return rv;
}

/*  **********************Hooking CreateWindowExW function***********************
************************************************************************************** */
HWND (__stdcall * Real_CreateWindowExA)(DWORD a0,
                                        LPCSTR a1,
                                        LPCSTR a2,
                                        DWORD a3,
                                        int a4,
                                        int a5,
                                        int a6,
                                        int a7,
                                        HWND a8,
                                        HMENU a9,
                                        HINSTANCE a10,
                                        LPVOID a11)
    = CreateWindowExA;

HWND __stdcall Mine_CreateWindowExA(DWORD a0,
                                    LPCSTR a1,
                                    LPCSTR a2,
                                    DWORD a3,
                                    int a4,
                                    int a5,
                                    int a6,
                                    int a7,
                                    HWND a8,
                                    HMENU a9,
                                    HINSTANCE a10,
                                    LPVOID a11)
{
	LoadedApi("CreateWindowExA");
    _PrintEnter("CreateWindowExA(%p,%hs,%hs,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    HWND rv = 0;
    __try {
        rv = Real_CreateWindowExA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    } __finally {
        _PrintExit("CreateWindowExA(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

HWND (__stdcall * Real_CreateWindowExW)(DWORD a0,
                                        LPCWSTR a1,
                                        LPCWSTR a2,
                                        DWORD a3,
                                        int a4,
                                        int a5,
                                        int a6,
                                        int a7,
                                        HWND a8,
                                        HMENU a9,
                                        HINSTANCE a10,
                                        LPVOID a11)
    = CreateWindowExW;

HWND __stdcall Mine_CreateWindowExW(DWORD a0,
                                    LPCWSTR a1,
                                    LPCWSTR a2,
                                    DWORD a3,
                                    int a4,
                                    int a5,
                                    int a6,
                                    int a7,
                                    HWND a8,
                                    HMENU a9,
                                    HINSTANCE a10,
                                    LPVOID a11)
{
	LoadedApi("CreateWindowExW");
    _PrintEnter("CreateWindowExW(%p,%ls,%ls,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    HWND rv = 0;
    __try {
        rv = Real_CreateWindowExW(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    } __finally {
        _PrintExit("CreateWindowExW(,,,,,,,,,,,) -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking IsWindowVisible function***********************
************************************************************************************** */
BOOL (__stdcall * Real_IsWindowVisible)(HWND a0)
    = IsWindowVisible;

BOOL __stdcall Mine_IsWindowVisible(HWND a0)
{
	LoadedApi("IsWindowVisible");
    _PrintEnter("IsWindowVisible(%p)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_IsWindowVisible(a0);
    } __finally {
        _PrintExit("IsWindowVisible() -> %p\n", rv);
    };
    return rv;
}

/*  **********************Hooking MonitorFromPoint function***********************
************************************************************************************** */

HMONITOR (__stdcall * Real_MonitorFromPoint)(POINT pt, DWORD dwFlags) = MonitorFromPoint;

HMONITOR __stdcall Mine_MonitorFromPoint(POINT pt, DWORD dwFlags)
{
	LoadedApi("MonitorFromPoint");
    _PrintEnter("MonitorFromPoint\n");

    HMONITOR rv = 0;
    __try {
        rv = Real_MonitorFromPoint(pt, dwFlags);
    } __finally {
        _PrintExit("IsWindowVisible() -> %p\n", rv);
    };

    return rv;
}


/*  **********************Hooking GetSystemTimeAsFileTime function***********************
************************************************************************************** */
void (__stdcall * Real_GetSystemTimeAsFileTime)(LPFILETIME a0)
    = GetSystemTimeAsFileTime;

void __stdcall Mine_GetSystemTimeAsFileTime(LPFILETIME a0)
{
	LoadedApi("GetSystemTimeAsFileTime");
    _PrintEnter("GetSystemTimeAsFileTime(%p)\n", a0);

    __try {
        Real_GetSystemTimeAsFileTime(a0);
    } __finally {
        _PrintExit("GetSystemTimeAsFileTime() ->\n");
    };
}

/*  **********************Hooking GetProcessHeaps function***********************
************************************************************************************** */
DWORD (__stdcall * Real_GetProcessHeaps)(DWORD a0,
                                         PHANDLE a1)
    = GetProcessHeaps;

DWORD __stdcall Mine_GetProcessHeaps(DWORD a0,
                                     PHANDLE a1)
{
	LoadedApi("GetProcessHeaps");
    _PrintEnter("GetProcessHeaps(%p,%p)\n", a0, a1);

    DWORD rv = 0;
    __try {
        rv = Real_GetProcessHeaps(a0, a1);
    } __finally {
        _PrintExit("GetProcessHeaps(,) -> %p\n", rv);
    };
    return rv;
}


HANDLE (__stdcall * Real_CreateFileW)(LPCWSTR a0,
                                      DWORD a1,
                                      DWORD a2,
                                      LPSECURITY_ATTRIBUTES a3,
                                      DWORD a4,
                                      DWORD a5,
                                      HANDLE a6)
    = CreateFileW;

HANDLE __stdcall Mine_CreateFileW(LPCWSTR a0,
                                  DWORD a1,
                                  DWORD a2,
                                  LPSECURITY_ATTRIBUTES a3,
                                  DWORD a4,
                                  DWORD a5,
                                  HANDLE a6)
{
    if ( wcsstr(a0, L"pid.txt") )
        return Real_CreateFileW(a0, a1, a2, a3, a4, a5, a6);
    
	LoadedApi("CreateFileW");
    _PrintEnter("CreateFileW(%ls,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6);

    HANDLE rv = 0;
    __try {
        rv = Real_CreateFileW(a0, a1, a2, a3, a4, a5, a6);
    } __finally {
        _PrintExit("CreateFileW(,,,,,,) -> %p\n", rv);
    };
    return rv;
}

////////////////////////////////////////////////////////////// AttachDetours.
//
static PCHAR DetRealName(PCHAR psz)
{
    PCHAR pszBeg = psz;
    // Move to end of name.
    while (*psz) {
        psz++;
    }
    // Move back through A-Za-z0-9 names.
    while (psz > pszBeg &&
           ((psz[-1] >= 'A' && psz[-1] <= 'Z') ||
            (psz[-1] >= 'a' && psz[-1] <= 'z') ||
            (psz[-1] >= '0' && psz[-1] <= '9'))) {
        psz--;
    }
    return psz;
}

static VOID Dump(PBYTE pbBytes, LONG nBytes, PBYTE pbTarget)
{
    CHAR szBuffer[256];
    PCHAR pszBuffer = szBuffer;

    for (LONG n = 0; n < nBytes; n += 12) {
        pszBuffer += StringCchPrintfA(pszBuffer, sizeof(szBuffer), "  %p: ", pbBytes + n);
        for (LONG m = n; m < n + 12; m++) {
            if (m >= nBytes) {
                pszBuffer += StringCchPrintfA(pszBuffer, sizeof(szBuffer), "   ");
            }
            else {
                pszBuffer += StringCchPrintfA(pszBuffer, sizeof(szBuffer), "%02x ", pbBytes[m]);
            }
        }
        if (n == 0) {
            pszBuffer += StringCchPrintfA(pszBuffer, sizeof(szBuffer), "[%p]", pbTarget);
        }
        pszBuffer += StringCchPrintfA(pszBuffer, sizeof(szBuffer), "\n");
    }

    Syelog(SYELOG_SEVERITY_INFORMATION, "%s", szBuffer);
}

static VOID Decode(PBYTE pbCode, LONG nInst)
{
    PBYTE pbSrc = pbCode;
    PBYTE pbEnd;
    PBYTE pbTarget;
    for (LONG n = 0; n < nInst; n++) {
        pbTarget = NULL;
        pbEnd = (PBYTE)DetourCopyInstruction(NULL, NULL, (PVOID)pbSrc, (PVOID*)&pbTarget, NULL);
        Dump(pbSrc, (int)(pbEnd - pbSrc), pbTarget);
        pbSrc = pbEnd;

        if (pbTarget != NULL) {
            break;
        }
    }
}

VOID DetAttach(PVOID *ppvReal, PVOID pvMine, PCHAR psz)
{
    PVOID pvReal = NULL;
    if (ppvReal == NULL) {
        ppvReal = &pvReal;
    }

    LONG l = DetourAttach(ppvReal, pvMine);
    if (l != 0) {
        Syelog(SYELOG_SEVERITY_NOTICE,
               "Attach failed: `%s': error %d\n", DetRealName(psz), l);

        Decode((PBYTE)*ppvReal, 3);
    }
}

VOID DetDetach(PVOID *ppvReal, PVOID pvMine, PCHAR psz)
{
    LONG l = DetourDetach(ppvReal, pvMine);
    if (l != 0) {
#if 0
        Syelog(SYELOG_SEVERITY_NOTICE,
               "Detach failed: `%s': error %d\n", DetRealName(psz), l);
#else
        (void)psz;
#endif
    }
}

#define ATTACH(x)       DetAttach(&(PVOID&)Real_##x,Mine_##x,#x)
#define DETACH(x)       DetDetach(&(PVOID&)Real_##x,Mine_##x,#x)

LONG AttachDetours(VOID)
{
    
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    // For this many APIs, we'll ignore one or two can't be detoured.
    DetourSetIgnoreTooSmall(TRUE);

    //ATTACH(AbortDoc);
    ATTACH(GetModuleFileNameW);
    ATTACH(GetEnvironmentStrings);
    ATTACH(FlushFileBuffers);
    ATTACH(SetNamedPipeHandleState);
    ATTACH(GetCurrentProcessId);
    ATTACH(OutputDebugStringA);
    ATTACH(GetEnvironmentStringsW);
    ATTACH(WaitNamedPipeW);
    ATTACH(WriteFile);
    ATTACH(GlobalMemoryStatusEx);
    ATTACH(IsDebuggerPresent);
    ATTACH(FindWindowA);
    ATTACH(FindWindowExA);
    ATTACH(FindWindowExW);
    ATTACH(FindWindowW);
    ATTACH(GetLocalTime);
    ATTACH(GetVersion);
    ATTACH(GetVersionExA);
    ATTACH(GetVersionExW);
    ATTACH(GetUserDefaultLangID);
    ATTACH(GetDiskFreeSpaceW);
    ATTACH(SHGetFolderPathW);
    ATTACH(GetComputerNameA);
    ATTACH(GetComputerNameW);
    ATTACH(GetWindowsDirectoryA);
    ATTACH(GetWindowsDirectoryW);
    ATTACH(GetSystemDirectoryA);
    ATTACH(GetSystemDirectoryW);
    ATTACH(GetCurrentDirectoryA);
    ATTACH(GetCurrentDirectoryW);
    ATTACH(GetKeyboardLayoutNameA);
    ATTACH(GetKeyboardLayoutNameW);
    ATTACH(GetDesktopWindow);
    ATTACH(GetWindowRect);
    // ATTACH(GetDC);
    // ATTACH(GetDCEx);
    ATTACH(GetDCOrgEx);
    // ATTACH(GetDeviceCaps);
    ATTACH(ReleaseDC);
    ATTACH(GetEnvironmentVariableA);
    ATTACH(GetEnvironmentVariableW);
    ATTACH(CreateWindowExA);
    ATTACH(CreateWindowExW);
    ATTACH(IsWindowVisible);
    ATTACH(GetMonitorInfoA);
    ATTACH(MonitorFromPoint);
    ATTACH(GetSystemTimeAsFileTime);
    ATTACH(GetProcessHeaps);
    ATTACH(CreateFileW);
    ATTACH(EnumPrintersA);
    ATTACH(EnumPrintersW);
    ATTACH(EnumServicesStatusA);
    ATTACH(EnumServicesStatusW);
    ATTACH(EnumServicesStatusExA);
    ATTACH(EnumServicesStatusExW);
    ATTACH(GetUserDefaultUILanguage);
    ATTACH(GetUserNameW);
    ATTACH(IsWindowsXPOrGreater);
    ATTACH(IsWindowsXPSP1OrGreater);
    ATTACH(IsWindowsXPSP2OrGreater);
    ATTACH(IsWindowsXPSP3OrGreater);
    ATTACH(IsWindowsVistaOrGreater);
    ATTACH(IsWindowsVistaSP1OrGreater);
    ATTACH(IsWindowsVistaSP2OrGreater);
    ATTACH(IsWindows7OrGreater);
    ATTACH(IsWindows7SP1OrGreater);
    ATTACH(IsWindows8OrGreater);
    ATTACH(IsWindows8Point1OrGreater);
    ATTACH(IsWindows10OrGreater);
    ATTACH(IsWindowsServer);
    ATTACH(IsWindowsVersionOrGreater);

    //From _tracereg.cpp

    ATTACH(CloseHandle);
    ATTACH(CopyFileExA);
    ATTACH(CopyFileExW);
    ATTACH(CreateDirectoryExW);
    ATTACH(CreateDirectoryW);
    ATTACH(CreateProcessW);
    ATTACH(DeleteFileA);
    ATTACH(DeleteFileW);
    ATTACH(FindFirstFileExA);
    ATTACH(FindFirstFileExW);
    ATTACH(GetFileAttributesW);
    ATTACH(LoadLibraryExW);
    ATTACH(MoveFileA);
    ATTACH(MoveFileExA);
    ATTACH(MoveFileExW);
    ATTACH(MoveFileW);
    ATTACH(OpenFile);
    ATTACH(RegCreateKeyExA);
    ATTACH(RegCreateKeyExW);
    ATTACH(RegDeleteKeyA);
    ATTACH(RegDeleteKeyW);
    ATTACH(RegDeleteValueA);
    ATTACH(RegDeleteValueW);
    ATTACH(RegEnumKeyExA);
    ATTACH(RegEnumKeyExW);
    ATTACH(RegEnumValueA);
    ATTACH(RegEnumValueW);
    ATTACH(RegQueryInfoKeyW);
    ATTACH(RegOpenKeyExW);
    ATTACH(RegQueryValueExA);
    ATTACH(RegOpenKeyExA);
    ATTACH(RegQueryInfoKeyA);
    ATTACH(RegQueryValueExW);
    ATTACH(RegSetValueExA);
    ATTACH(RegSetValueExW);
    ATTACH(_lcreat);
    ATTACH(_lopen);

    // From _traceRohit.cpp
    ATTACH(EnumPrinterKey);
    ATTACH(GetThreadPreferredUILanguages);
    ATTACH(SHGetFolderPathAndSubDirA);
    ATTACH(RegGetValueA);
    ATTACH(GetComputerNameExW);
    ATTACH(EnumPrinterData);
    ATTACH(SHGetFileInfoA);
    ATTACH(RegQueryMultipleValuesW);
    ATTACH(GetDiskFreeSpaceExA);
    ATTACH(GetUILanguageInfo);
    ATTACH(RegOpenKeyTransactedW);
    ATTACH(MonitorFromRect);
    ATTACH(GetComputerNameExA);
    ATTACH(GetThreadUILanguage);
    ATTACH(GetKeyboardLayout);
    ATTACH(GetTimeZoneInformation);
    ATTACH(GetNativeSystemInfo);
    ATTACH(LocalFileTimeToFileTime);
    ATTACH(SHGetFileInfoW);
    ATTACH(RegQueryMultipleValuesA);
    ATTACH(EnumMonitors);
    ATTACH(EnumPrinterDataEx);
    ATTACH(GetWindowModuleFileNameA);
    ATTACH(EnumWindows);
    ATTACH(EnumPrintProcessorDatatypesA);
    ATTACH(GetFirmwareEnvironmentVariableA);
    ATTACH(GetSystemRegistryQuota);
    ATTACH(CreateFileTransactedW);
    ATTACH(CreateFileA);
    ATTACH(GetSystemWindowsDirectoryW);
    ATTACH(GetFirmwareType);
    ATTACH(RegOpenKeyTransactedA);
    ATTACH(GetSystemWindowsDirectoryA);
    ATTACH(GetFileMUIInfo);
    ATTACH(GetSystemTimes);
    ATTACH(GetFileMUIPath);
    ATTACH(GetProductInfo);
    ATTACH(RegLoadKeyW);
    ATTACH(GetTickCount64);
    ATTACH(GetProcessHeap);
    ATTACH(EnumPrintProcessors);
    ATTACH(GetSystemTimeAdjustment);
    ATTACH(GetUserNameA);

    // From _traceRohit1.cpp
    ATTACH(RegLoadKeyA);
    ATTACH(CreateFile2);
    ATTACH(EnumPrintProcessorDatatypes);
    ATTACH(GetSystemTimePreciseAsFileTime);
    ATTACH(GetDiskFreeSpaceExW);
    ATTACH(GetFirmwareEnvironmentVariableW);
    ATTACH(MonitorFromWindow);
    ATTACH(GetTickCount);
    ATTACH(GetSystemDefaultUILanguage);
    ATTACH(EnumDisplayMonitors);
    ATTACH(EnumPrinters);
    ATTACH(GetTimeZoneInformationForYear);
    ATTACH(EnumPorts);
    ATTACH(GetKeyState);
    ATTACH(RegGetValueW);
    ATTACH(GetUserPreferredUILanguages);
    // ATTACH(GetForegroundWindow);
    ATTACH(GetFileTime);
    ATTACH(CreateFileTransactedA);
    ATTACH(GetKeyboardLayoutList);
    ATTACH(GetSystemTime);
    ATTACH(GetDynamicTimeZoneInformation);
    ATTACH(SHGetDiskFreeSpaceExA);
    ATTACH(GetSystemInfo);
    ATTACH(SHGetDiskFreeSpaceExW);
    ATTACH(GetDiskFreeSpaceA);
    ATTACH(GetSystemPreferredUILanguages);
    ATTACH(GetSystemWow64DirectoryW);
    ATTACH(EnumPrinterDrivers);
    ATTACH(CompareFileTime);
    ATTACH(GetProcessPreferredUILanguages);
    ATTACH(GetSystemWow64DirectoryA);
    ATTACH(GetWindowInfo);
    ATTACH(SetProcessPreferredUILanguages);
    ATTACH(GetWindowModuleFileNameW);


    PVOID *ppbFailedPointer = NULL;
    LONG error = DetourTransactionCommitEx(&ppbFailedPointer);
    if (error != 0) {
        printf("traceapi.dll: Attach transaction failed to commit. Error %d (%p/%p)",
               error, ppbFailedPointer, *ppbFailedPointer);
        return error;
    }
    return 0;
}

LONG DetachDetours(VOID)
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    // For this many APIs, we'll ignore one or two can't be detoured.
    DetourSetIgnoreTooSmall(TRUE);

    //DETACH(AbortDoc);
    DETACH(GetModuleFileNameW);
    DETACH(GetEnvironmentStrings);
    DETACH(FlushFileBuffers);
    DETACH(SetNamedPipeHandleState);
    DETACH(GetCurrentProcessId);
    DETACH(OutputDebugStringA);
    DETACH(GetEnvironmentStringsW);
    DETACH(WaitNamedPipeW);
    DETACH(WriteFile);
    DETACH(GlobalMemoryStatusEx);
    DETACH(IsDebuggerPresent);
    DETACH(FindWindowA);
    DETACH(FindWindowExA);
    DETACH(FindWindowExW);
    DETACH(FindWindowW);
    DETACH(GetLocalTime);
    DETACH(GetVersion);
    DETACH(GetVersionExA);
    DETACH(GetVersionExW);
    DETACH(GetUserDefaultLangID);
    DETACH(GetDiskFreeSpaceW);
    DETACH(SHGetFolderPathW);
    DETACH(GetComputerNameA);
    DETACH(GetComputerNameW);
    DETACH(GetWindowsDirectoryA );
    DETACH(GetWindowsDirectoryA );
    DETACH(GetSystemDirectoryA);
    DETACH(GetSystemDirectoryW);
    DETACH(GetCurrentDirectoryA);
    DETACH(GetCurrentDirectoryW);
    DETACH(GetKeyboardLayoutNameA);
    DETACH(GetKeyboardLayoutNameA);
    DETACH(GetDesktopWindow);
    DETACH(GetWindowRect);
    // DETACH(GetDC);
    // DETACH(GetDCEx);
    DETACH(GetDCOrgEx);
    // DETACH(GetDeviceCaps);
    DETACH(ReleaseDC);
    DETACH(GetEnvironmentVariableA);
    DETACH(GetEnvironmentVariableW);
    DETACH(CreateWindowExA);
    DETACH(CreateWindowExW);
    DETACH(IsWindowVisible);
    DETACH(GetMonitorInfoA);
    DETACH(MonitorFromPoint);
    DETACH(GetSystemTimeAsFileTime);
    DETACH(GetProcessHeaps);
    DETACH(CreateFileW);
    DETACH(EnumPrintersA);
    DETACH(EnumPrintersW);
    DETACH(EnumServicesStatusA);
    DETACH(EnumServicesStatusW);
    DETACH(EnumServicesStatusExA);
    DETACH(EnumServicesStatusExW);
    DETACH(GetUserDefaultUILanguage);
    DETACH(GetUserNameW);
    DETACH(IsWindowsXPOrGreater);
    DETACH(IsWindowsXPSP1OrGreater);
    DETACH(IsWindowsXPSP2OrGreater);
    DETACH(IsWindowsXPSP3OrGreater);
    DETACH(IsWindowsVistaOrGreater);
    DETACH(IsWindowsVistaSP1OrGreater);
    DETACH(IsWindowsVistaSP2OrGreater);
    DETACH(IsWindows7OrGreater);
    DETACH(IsWindows7SP1OrGreater);
    DETACH(IsWindows8OrGreater);
    DETACH(IsWindows8Point1OrGreater);
    DETACH(IsWindows10OrGreater);
    DETACH(IsWindowsServer);
    DETACH(IsWindowsVersionOrGreater);

    //From _tracereg.cpp

    DETACH(CloseHandle);
    DETACH(CopyFileExA);
    DETACH(CopyFileExW);
    DETACH(CreateDirectoryExW);
    DETACH(CreateDirectoryW);
    DETACH(CreateProcessW);
    DETACH(DeleteFileA);
    DETACH(DeleteFileW);
    DETACH(FindFirstFileExA);
    DETACH(FindFirstFileExW);
    DETACH(GetFileAttributesW);
    DETACH(LoadLibraryExW);
    DETACH(MoveFileA);
    DETACH(MoveFileExA);
    DETACH(MoveFileExW);
    DETACH(MoveFileW);
    DETACH(OpenFile);
    DETACH(RegCreateKeyExA);
    DETACH(RegCreateKeyExW);
    DETACH(RegDeleteKeyA);
    DETACH(RegDeleteKeyW);
    DETACH(RegDeleteValueA);
    DETACH(RegDeleteValueW);
    DETACH(RegEnumKeyExA);
    DETACH(RegEnumKeyExW);
    DETACH(RegEnumValueA);
    DETACH(RegEnumValueW);
    DETACH(RegQueryInfoKeyW);
    DETACH(RegOpenKeyExW);
    DETACH(RegQueryValueExA);
    DETACH(RegOpenKeyExA);
    DETACH(RegQueryInfoKeyA);
    DETACH(RegQueryValueExW);
    DETACH(RegSetValueExA);
    DETACH(RegSetValueExW);
    DETACH(_lcreat);
    DETACH(_lopen);

    // From _traceRohit.cpp
    DETACH(EnumPrinterKey);
    DETACH(GetThreadPreferredUILanguages);
    DETACH(SHGetFolderPathAndSubDirA);
    DETACH(RegGetValueA);
    DETACH(GetComputerNameExW);
    DETACH(EnumPrinterData);
    DETACH(SHGetFileInfoA);
    DETACH(RegQueryMultipleValuesW);
    DETACH(GetDiskFreeSpaceExA);
    DETACH(GetUILanguageInfo);
    DETACH(RegOpenKeyTransactedW);
    DETACH(MonitorFromRect);
    DETACH(GetComputerNameExA);
    DETACH(GetThreadUILanguage);
    DETACH(GetKeyboardLayout);
    DETACH(GetTimeZoneInformation);
    DETACH(GetNativeSystemInfo);
    DETACH(LocalFileTimeToFileTime);
    DETACH(SHGetFileInfoW);
    DETACH(RegQueryMultipleValuesA);
    DETACH(EnumMonitors);
    DETACH(EnumPrinterDataEx);
    DETACH(GetWindowModuleFileNameA);
    DETACH(EnumWindows);
    DETACH(EnumPrintProcessorDatatypesA);
    DETACH(GetFirmwareEnvironmentVariableA);
    DETACH(GetSystemRegistryQuota);
    DETACH(CreateFileTransactedW);
    DETACH(CreateFileA);
    DETACH(GetSystemWindowsDirectoryW);
    DETACH(GetFirmwareType);
    DETACH(RegOpenKeyTransactedA);
    DETACH(GetSystemWindowsDirectoryA);
    DETACH(GetFileMUIInfo);
    DETACH(GetSystemTimes);
    DETACH(GetFileMUIPath);
    DETACH(GetProductInfo);
    DETACH(RegLoadKeyW);
    DETACH(GetTickCount64);
    DETACH(GetProcessHeap);
    DETACH(EnumPrintProcessors);
    DETACH(GetSystemTimeAdjustment);
    DETACH(GetUserNameA);

    // From _traceRohit1.cpp
    DETACH(RegLoadKeyA);
    DETACH(CreateFile2);
    DETACH(EnumPrintProcessorDatatypes);
    DETACH(GetSystemTimePreciseAsFileTime);
    DETACH(GetDiskFreeSpaceExW);
    DETACH(GetFirmwareEnvironmentVariableW);
    DETACH(MonitorFromWindow);
    DETACH(GetTickCount);
    DETACH(GetSystemDefaultUILanguage);
    DETACH(EnumDisplayMonitors);
    DETACH(EnumPrinters);
    DETACH(GetTimeZoneInformationForYear);
    DETACH(EnumPorts);
    DETACH(GetKeyState);
    DETACH(RegGetValueW);
    DETACH(GetUserPreferredUILanguages);
    // DETACH(GetForegroundWindow);
    DETACH(GetFileTime);
    DETACH(CreateFileTransactedA);
    DETACH(GetKeyboardLayoutList);
    DETACH(GetSystemTime);
    DETACH(GetDynamicTimeZoneInformation);
    DETACH(SHGetDiskFreeSpaceExA);
    DETACH(GetSystemInfo);
    DETACH(SHGetDiskFreeSpaceExW);
    DETACH(GetDiskFreeSpaceA);
    DETACH(GetSystemPreferredUILanguages);
    DETACH(GetSystemWow64DirectoryW);
    DETACH(EnumPrinterDrivers);
    DETACH(CompareFileTime);
    DETACH(GetProcessPreferredUILanguages);
    DETACH(GetSystemWow64DirectoryA);
    DETACH(GetWindowInfo);
    DETACH(SetProcessPreferredUILanguages);
    DETACH(GetWindowModuleFileNameW);
    

    if (DetourTransactionCommit() != 0) {
        PVOID *ppbFailedPointer = NULL;
        LONG error = DetourTransactionCommitEx(&ppbFailedPointer);

        printf("traceapi.dll: Detach transaction failed to commit. Error %d (%p/%p)",
               error, ppbFailedPointer, *ppbFailedPointer);
        return error;
    }
    return 0;
}
