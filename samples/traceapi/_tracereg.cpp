#include "MyDS.cpp"
#include <atlbase.h>

BOOL (WINAPI * Real_CopyFileExA)(LPCSTR a0,
                                 LPCSTR a1,
                                 LPPROGRESS_ROUTINE a2,
                                 LPVOID a3,
                                 LPBOOL a4,
                                 DWORD a5)
    = CopyFileExA;

BOOL (WINAPI * Real_CopyFileExW)(LPCWSTR a0,
                                 LPCWSTR a1,
                                 LPPROGRESS_ROUTINE a2,
                                 LPVOID a3,
                                 LPBOOL a4,
                                 DWORD a5)
    = CopyFileExW;

BOOL (WINAPI * Real_CreateDirectoryExW)(LPCWSTR a0,
                                        LPCWSTR a1,
                                        LPSECURITY_ATTRIBUTES a2)
    = CreateDirectoryExW;

BOOL (WINAPI * Real_CreateDirectoryW)(LPCWSTR a0,
                                      LPSECURITY_ATTRIBUTES a1)
    = CreateDirectoryW;

BOOL (WINAPI * Real_CreateProcessW)(LPCWSTR lpApplicationName,
                                    LPWSTR lpCommandLine,
                                    LPSECURITY_ATTRIBUTES lpProcessAttributes,
                                    LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                    BOOL bInheritHandles,
                                    DWORD dwCreationFlags,
                                    LPVOID lpEnvironment,
                                    LPCWSTR lpCurrentDirectory,
                                    LPSTARTUPINFOW lpStartupInfo,
                                    LPPROCESS_INFORMATION lpProcessInformation)
    = CreateProcessW;

BOOL (WINAPI * Real_DeleteFileA)(LPCSTR a0)
    = DeleteFileA;

BOOL (WINAPI * Real_DeleteFileW)(LPCWSTR a0)
    = DeleteFileW;

HANDLE (WINAPI * Real_FindFirstFileExA)(LPCSTR a0,
                                        FINDEX_INFO_LEVELS a1,
                                        LPVOID a2,
                                        FINDEX_SEARCH_OPS a3,
                                        LPVOID a4,
                                        DWORD a5)
    = FindFirstFileExA;

HANDLE (WINAPI * Real_FindFirstFileExW)(LPCWSTR a0,
                                        FINDEX_INFO_LEVELS a1,
                                        LPVOID a2,
                                        FINDEX_SEARCH_OPS a3,
                                        LPVOID a4,
                                        DWORD a5)
    = FindFirstFileExW;

DWORD (WINAPI * Real_GetFileAttributesW)(LPCWSTR a0)
    = GetFileAttributesW;


HMODULE (WINAPI * Real_LoadLibraryExW)(LPCWSTR a0,
                                       HANDLE a1,
                                       DWORD a2)
    = LoadLibraryExW;

BOOL (WINAPI * Real_MoveFileA)(LPCSTR a0,
                               LPCSTR a1)
    = MoveFileA;

BOOL (WINAPI * Real_MoveFileExA)(LPCSTR a0,
                                 LPCSTR a1,
                                 DWORD a2)
    = MoveFileExA;

BOOL (WINAPI * Real_MoveFileExW)(LPCWSTR a0,
                                 LPCWSTR a1,
                                 DWORD a2)
    = MoveFileExW;

BOOL (WINAPI * Real_MoveFileW)(LPCWSTR a0,
                               LPCWSTR a1)
    = MoveFileW;

HFILE (WINAPI * Real_OpenFile)(LPCSTR a0,
                               struct _OFSTRUCT* a1,
                               UINT a2)
    = OpenFile;

LONG (WINAPI * Real_RegCreateKeyExA)(HKEY a0,
                                     LPCSTR a1,
                                     DWORD a2,
                                     LPSTR a3,
                                     DWORD a4,
                                     REGSAM a5,
                                     LPSECURITY_ATTRIBUTES a6,
                                     PHKEY a7,
                                     LPDWORD a8)
    = RegCreateKeyExA;

LONG (WINAPI * Real_RegCreateKeyExW)(HKEY a0,
                                     LPCWSTR a1,
                                     DWORD a2,
                                     LPWSTR a3,
                                     DWORD a4,
                                     REGSAM a5,
                                     LPSECURITY_ATTRIBUTES a6,
                                     PHKEY a7,
                                     LPDWORD a8)
    = RegCreateKeyExW;

LONG (WINAPI * Real_RegDeleteKeyA)(HKEY a0,
                                   LPCSTR a1)
    = RegDeleteKeyA;

LONG (WINAPI * Real_RegDeleteKeyW)(HKEY a0,
                                   LPCWSTR a1)
    = RegDeleteKeyW;

LONG (WINAPI * Real_RegDeleteValueA)(HKEY a0,
                                     LPCSTR a1)
    = RegDeleteValueA;


LONG (WINAPI * Real_RegDeleteValueW)(HKEY a0,
                                     LPCWSTR a1)
    = RegDeleteValueW;

LONG (WINAPI * Real_RegEnumKeyExA)(HKEY a0,
                                   DWORD a1,
                                   LPSTR a2,
                                   LPDWORD a3,
                                   LPDWORD a4,
                                   LPSTR a5,
                                   LPDWORD a6,
                                   struct _FILETIME* a7)
    = RegEnumKeyExA;

LONG (WINAPI * Real_RegEnumKeyExW)(HKEY a0,
                                   DWORD a1,
                                   LPWSTR a2,
                                   LPDWORD a3,
                                   LPDWORD a4,
                                   LPWSTR a5,
                                   LPDWORD a6,
                                   struct _FILETIME* a7)
    = RegEnumKeyExW;

LONG (WINAPI * Real_RegEnumValueA)(HKEY a0,
                                   DWORD a1,
                                   LPSTR a2,
                                   LPDWORD a3,
                                   LPDWORD a4,
                                   LPDWORD a5,
                                   LPBYTE a6,
                                   LPDWORD a7)
    = RegEnumValueA;

LONG (WINAPI * Real_RegEnumValueW)(HKEY a0,
                                   DWORD a1,
                                   LPWSTR a2,
                                   LPDWORD a3,
                                   LPDWORD a4,
                                   LPDWORD a5,
                                   LPBYTE a6,
                                   LPDWORD a7)
    = RegEnumValueW;

LONG (WINAPI * Real_RegOpenKeyExA)(HKEY a0,
                                   LPCSTR a1,
                                   DWORD a2,
                                   REGSAM a3,
                                   PHKEY a4)
    = RegOpenKeyExA;

LONG (WINAPI * Real_RegOpenKeyExW)(HKEY a0,
                                   LPCWSTR a1,
                                   DWORD a2,
                                   REGSAM a3,
                                   PHKEY a4)
    = RegOpenKeyExW;

LONG (WINAPI * Real_RegQueryInfoKeyA)(HKEY a0,
                                      LPSTR a1,
                                      LPDWORD a2,
                                      LPDWORD a3,
                                      LPDWORD a4,
                                      LPDWORD a5,
                                      LPDWORD a6,
                                      LPDWORD a7,
                                      LPDWORD a8,
                                      LPDWORD a9,
                                      LPDWORD a10,
                                      struct _FILETIME* a11)
    = RegQueryInfoKeyA;

LONG (WINAPI * Real_RegQueryInfoKeyW)(HKEY a0,
                                      LPWSTR a1,
                                      LPDWORD a2,
                                      LPDWORD a3,
                                      LPDWORD a4,
                                      LPDWORD a5,
                                      LPDWORD a6,
                                      LPDWORD a7,
                                      LPDWORD a8,
                                      LPDWORD a9,
                                      LPDWORD a10,
                                      struct _FILETIME* a11)
    = RegQueryInfoKeyW;

LONG (WINAPI * Real_RegQueryValueExA)(HKEY a0,
                                      LPCSTR a1,
                                      LPDWORD a2,
                                      LPDWORD a3,
                                      LPBYTE a4,
                                      LPDWORD a5)
    = RegQueryValueExA;

LONG (WINAPI * Real_RegQueryValueExW)(HKEY a0,
                                      LPCWSTR a1,
                                      LPDWORD a2,
                                      LPDWORD a3,
                                      LPBYTE a4,
                                      LPDWORD a5)
    = RegQueryValueExW;

LONG (WINAPI * Real_RegSetValueExA)(HKEY a0,
                                    LPCSTR a1,
                                    DWORD a2,
                                    DWORD a3,
                                    const BYTE* a4,
                                    DWORD a5)
    = RegSetValueExA;

LONG (WINAPI * Real_RegSetValueExW)(HKEY a0,
                                    LPCWSTR a1,
                                    DWORD a2,
                                    DWORD a3,
                                    const BYTE* a4,
                                    DWORD a5)
    = RegSetValueExW;

HFILE (WINAPI * Real__lcreat)(LPCSTR a0,
                              int a1)
    = _lcreat;

HFILE (WINAPI * Real__lopen)(LPCSTR a0,
                             int a1)
    = _lopen;

/////////////////////////////////////////////////////////////
// Detours
//

BOOL WINAPI Mine_CreateProcessW(LPCWSTR lpApplicationName,
                                LPWSTR lpCommandLine,
                                LPSECURITY_ATTRIBUTES lpProcessAttributes,
                                LPSECURITY_ATTRIBUTES lpThreadAttributes,
                                BOOL bInheritHandles,
                                DWORD dwCreationFlags,
                                LPVOID lpEnvironment,
                                LPCWSTR lpCurrentDirectory,
                                LPSTARTUPINFOW lpStartupInfo,
                                LPPROCESS_INFORMATION lpProcessInformation)
{
	LoadedApi("CreateProcessW");
    _PrintEnter("CreateProcessW(%ls,%ls,%p,%p,%x,%x,%p,%ls,%p,%p)\n",
                lpApplicationName,
                lpCommandLine,
                lpProcessAttributes,
                lpThreadAttributes,
                bInheritHandles,
                dwCreationFlags,
                lpEnvironment,
                lpCurrentDirectory,
                lpStartupInfo,
                lpProcessInformation);

    _Print("Calling DetourCreateProcessWithDllExW(,%hs)\n", s_szDllPath);

    BOOL rv = 0;
    __try {
        rv = DetourCreateProcessWithDllExW(lpApplicationName,
                                           lpCommandLine,
                                           lpProcessAttributes,
                                           lpThreadAttributes,
                                           bInheritHandles,
                                           dwCreationFlags,
                                           lpEnvironment,
                                           lpCurrentDirectory,
                                           lpStartupInfo,
                                           lpProcessInformation,
                                           s_szDllPath,
                                           Real_CreateProcessW);
    } __finally {
        _PrintExit("CreateProcessW(,,,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

//
//////////////////////////////////////////////////////////////////////////////

BOOL WINAPI Mine_CopyFileExA(LPCSTR a0,
                             LPCSTR a1,
                             LPPROGRESS_ROUTINE a2,
                             LPVOID a3,
                             LPBOOL a4,
                             DWORD a5)
{
	LoadedApi("CopyFileExA");
    _PrintEnter("CopyFileExA(%hs,%hs,%p,%p,%p,%x)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_CopyFileExA(a0, a1, a2, a3, a4, a5);
    } __finally {
        _PrintExit("CopyFileExA(,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL WINAPI Mine_CopyFileExW(LPCWSTR a0,
                             LPCWSTR a1,
                             LPPROGRESS_ROUTINE a2,
                             LPVOID a3,
                             LPBOOL a4,
                             DWORD a5)
{
	LoadedApi("CopyFileExW");
    _PrintEnter("CopyFileExW(%ls,%ls,%p,%p,%p,%x)\n", a0, a1, a2, a3, a4, a5);

    BOOL rv = 0;
    __try {
        rv = Real_CopyFileExW(a0, a1, a2, a3, a4, a5);
    } __finally {
        _PrintExit("CopyFileExW(,,,,,) -> %x\n", rv);
    };
    return rv;
}

BOOL WINAPI Mine_CreateDirectoryExW(LPCWSTR a0,
                                    LPCWSTR a1,
                                    LPSECURITY_ATTRIBUTES a2)
{
	LoadedApi("CreateDirectoryExW");
    _PrintEnter("CreateDirectoryExW(%ls,%ls,%p)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_CreateDirectoryExW(a0, a1, a2);
    } __finally {
        _PrintExit("CreateDirectoryExW(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL WINAPI Mine_CreateDirectoryW(LPCWSTR a0,
                                  LPSECURITY_ATTRIBUTES a1)
{
	LoadedApi("CreateDirectoryW");
    _PrintEnter("CreateDirectoryW(%ls,%p)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_CreateDirectoryW(a0, a1);
    } __finally {
        _PrintExit("CreateDirectoryW(,) -> %x\n", rv);
    };
    return rv;
}


BOOL WINAPI Mine_DeleteFileA(LPCSTR a0)
{
	LoadedApi("DeleteFileA");
    _PrintEnter("DeleteFileA(%hs)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteFileA(a0);
    } __finally {
        _PrintExit("DeleteFileA() -> %x\n", rv);
    };
    return rv;
}

BOOL WINAPI Mine_DeleteFileW(LPCWSTR a0)
{
	LoadedApi("DeleteFileW");
    _PrintEnter("DeleteFileW(%ls)\n", a0);

    BOOL rv = 0;
    __try {
        rv = Real_DeleteFileW(a0);
    } __finally {
        _PrintExit("DeleteFileW() -> %x\n", rv);
    };
    return rv;
}

HANDLE WINAPI Mine_FindFirstFileExA(LPCSTR a0,
                                    FINDEX_INFO_LEVELS a1,
                                    LPVOID a2,
                                    FINDEX_SEARCH_OPS a3,
                                    LPVOID a4,
                                    DWORD a5)
{
	LoadedApi("FindFirstFileExA");
    _PrintEnter("FindFirstFileExA(%hs,%p,%p,%x,%p,%x)\n", a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_FindFirstFileExA(a0, a1, a2, a3, a4, a5);
    } __finally {
        _PrintExit("FindFirstFileExA(,,,,,) -> %p\n", rv);
    };
    return rv;
}

HANDLE WINAPI Mine_FindFirstFileExW(LPCWSTR a0,
                                    FINDEX_INFO_LEVELS a1,
                                    LPVOID a2,
                                    FINDEX_SEARCH_OPS a3,
                                    LPVOID a4,
                                    DWORD a5)
{
	LoadedApi("FindFirstFileExW");
    _PrintEnter("FindFirstFileExW(%ls,%x,%p,%x,%p,%x)\n",
                   a0, a1, a2, a3, a4, a5);

    HANDLE rv = 0;
    __try {
        rv = Real_FindFirstFileExW(a0, a1, a2, a3, a4, a5);
    } __finally {
        _PrintExit("FindFirstFileExW(%ls,%x,%p,%x,%p,%x) -> %p\n",
                   a0, a1, a2, a3, a4, a5, rv);
    };
    return rv;
}

DWORD WINAPI Mine_GetFileAttributesW(LPCWSTR a0)
{
	LoadedApi("GetFileAttributesW");
    _PrintEnter("GetFileAttributesW(%ls)\n", a0);

    DWORD rv = 0;
    __try {
        rv = Real_GetFileAttributesW(a0);
    } __finally {
        _PrintExit("GetFileAttributesW(%ls) -> %x\n", a0, rv);
    };
    return rv;
}

HMODULE WINAPI Mine_LoadLibraryExW(LPCWSTR a0,
                                   HANDLE a1,
                                   DWORD a2)
{
	LoadedApi("LoadLibraryExW");
    _PrintEnter("LoadLibraryExW(%ls,%p,%x)\n", a0, a1, a2);
    LoadedApi("LoadLibraryExW");
    
    HMODULE rv = 0;
    __try {
        rv = Real_LoadLibraryExW(a0, a1, a2);
    } __finally {
        _PrintExit("LoadLibraryExW(,,) -> %p\n", rv);
        if (rv) {
            InstanceEnumerate(rv);
        }
    };
    return rv;
}

BOOL WINAPI Mine_MoveFileA(LPCSTR a0,
                           LPCSTR a1)
{
	LoadedApi("MoveFileA");
    _PrintEnter("MoveFileA(%hs,%hs)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_MoveFileA(a0, a1);
    } __finally {
        _PrintExit("MoveFileA(,) -> %x\n", rv);
    };
    return rv;
}

BOOL WINAPI Mine_MoveFileExA(LPCSTR a0,
                             LPCSTR a1,
                             DWORD a2)
{
	LoadedApi("MoveFileExA");
    _PrintEnter("MoveFileExA(%hs,%hs,%x)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_MoveFileExA(a0, a1, a2);
    } __finally {
        _PrintExit("MoveFileExA(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL WINAPI Mine_MoveFileExW(LPCWSTR a0,
                             LPCWSTR a1,
                             DWORD a2)
{
	LoadedApi("MoveFileExW");
    _PrintEnter("MoveFileExW(%ls,%ls,%x)\n", a0, a1, a2);

    BOOL rv = 0;
    __try {
        rv = Real_MoveFileExW(a0, a1, a2);
    } __finally {
        _PrintExit("MoveFileExW(,,) -> %x\n", rv);
    };
    return rv;
}

BOOL WINAPI Mine_MoveFileW(LPCWSTR a0,
                           LPCWSTR a1)
{
	LoadedApi("MoveFileW");
    _PrintEnter("MoveFileW(%ls,%ls)\n", a0, a1);

    BOOL rv = 0;
    __try {
        rv = Real_MoveFileW(a0, a1);
    } __finally {
        _PrintExit("MoveFileW(,) -> %x\n", rv);
    };
    return rv;
}

HFILE WINAPI Mine_OpenFile(LPCSTR a0,
                           LPOFSTRUCT a1,
                           UINT a2)
{
	LoadedApi("OpenFile");
    _PrintEnter("OpenFile(%hs,%p,%x)\n", a0, a1, a2);

    HFILE rv = 0;
    __try {
        rv = Real_OpenFile(a0, a1, a2);
    } __finally {
        _PrintExit("OpenFile(,,) -> %p\n", rv);
    };
    return rv;
}

LONG WINAPI Mine_RegCreateKeyExA(HKEY a0,
                                 LPCSTR a1,
                                 DWORD a2,
                                 LPSTR a3,
                                 DWORD a4,
                                 REGSAM a5,
                                 LPSECURITY_ATTRIBUTES a6,
                                 PHKEY a7,
                                 LPDWORD a8)
{
	// LoadedApi("RegCreateKeyExA");
    LoadedRegs(a1, NULL);
    _PrintEnter("RegCreateKeyExA(%p,%hs,%x,%hs,%x,%x,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7, a8);

    LONG rv = 0;
    __try {
        rv = Real_RegCreateKeyExA(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    } __finally {
        _PrintExit("RegCreateKeyExA(,,,,,,,,) -> %x\n", rv);
    };
    return rv;
}

LONG WINAPI Mine_RegCreateKeyExW(HKEY a0,
                                 LPCWSTR a1,
                                 DWORD a2,
                                 LPWSTR a3,
                                 DWORD a4,
                                 REGSAM a5,
                                 LPSECURITY_ATTRIBUTES a6,
                                 PHKEY a7,
                                 LPDWORD a8)
{
	// LoadedApi("RegCreateKeyExW");
    LoadedRegs(NULL, a1);
    _PrintEnter("RegCreateKeyExW(%p,%ls,%x,%ls,%x,%x,%p,%p,%p)\n",
                   a0, a1, a2, a3, a4, a5, a6, a7, a8);
    LONG rv = 0;
    __try {
        rv = Real_RegCreateKeyExW(a0, a1, a2, a3, a4, a5, a6, a7, a8);
    } __finally {
        _PrintExit("RegCreateKeyExW(%p,%ls,%x,%ls,%x,%x,%p,%p,%p) -> %x\n",
                   a0, a1, a2, a3, a4, a5, a6, a7, a8, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegDeleteKeyA(HKEY a0,
                               LPCSTR a1)
{
	// LoadedApi("RegDeleteKeyA");
    LoadedRegs(a1, NULL);
    _PrintEnter("RegDeleteKeyA(%p,%hs)\n", a0, a1);
    LONG rv = 0;
    __try {
        rv = Real_RegDeleteKeyA(a0, a1);
    } __finally {
        _PrintExit("RegDeleteKeyA(%p,%hs) -> %x\n", a0, a1, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegDeleteKeyW(HKEY a0,
                               LPCWSTR a1)
{
	// LoadedApi("RegDeleteKeyW");
    LoadedRegs(NULL, a1);
    _PrintEnter("RegDeleteKeyW(%p,%ls)\n", a0, a1);
    LONG rv = 0;
    __try {
        rv = Real_RegDeleteKeyW(a0, a1);
    } __finally {
        _PrintExit("RegDeleteKeyW(%p,%ls) -> %x\n", a0, a1, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegDeleteValueA(HKEY a0,
                                 LPCSTR a1)
{
	// LoadedApi("RegDeleteValueA");
    LoadedRegs(a1, NULL);
    _PrintEnter("RegDeleteValueA(%p,%hs)\n", a0, a1);

    LONG rv = 0;
    __try {
        rv = Real_RegDeleteValueA(a0, a1);
    } __finally {
        _PrintExit("RegDeleteValueA(,) -> %x\n", rv);
    };
    return rv;
}

LONG WINAPI Mine_RegDeleteValueW(HKEY a0,
                                 LPCWSTR a1)
{
	// LoadedApi("RegDeleteValueW");
    LoadedRegs(NULL, a1);
    _PrintEnter("RegDeleteValueW(%p,%ls)\n", a0, a1);

    LONG rv = 0;
    __try {
        rv = Real_RegDeleteValueW(a0, a1);
    } __finally {
        _PrintExit("RegDeleteValueW(,) -> %x\n", rv);
    };
    return rv;
}

LONG WINAPI Mine_RegEnumKeyExA(HKEY a0,
                               DWORD a1,
                               LPSTR a2,
                               LPDWORD a3,
                               LPDWORD a4,
                               LPSTR a5,
                               LPDWORD a6,
                               LPFILETIME a7)
{
	LoadedApi("RegEnumKeyExA");
    _PrintEnter("RegEnumKeyExA(%p,%x,%p,%p,%p,%hs,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    LONG rv = 0;
    __try {
        rv = Real_RegEnumKeyExA(a0, a1, a2, a3, a4, a5, a6, a7);
    } __finally {
        _PrintExit("RegEnumKeyExA(,,%hs,,,%hs,,) -> %x\n", a2, a5, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegEnumKeyExW(HKEY a0,
                               DWORD a1,
                               LPWSTR a2,
                               LPDWORD a3,
                               LPDWORD a4,
                               LPWSTR a5,
                               LPDWORD a6,
                               struct _FILETIME* a7)
{
	LoadedApi("RegEnumKeyExW");
    _PrintEnter("RegEnumKeyExW(%p,%x,%p,%p,%p,%ls,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    LONG rv = 0;
    __try {
        rv = Real_RegEnumKeyExW(a0, a1, a2, a3, a4, a5, a6, a7);
    } __finally {
        _PrintExit("RegEnumKeyExW(,,%ls,,,%ls,,) -> %x\n", a2, a5, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegEnumValueA(HKEY a0,
                               DWORD a1,
                               LPSTR a2,
                               LPDWORD a3,
                               LPDWORD a4,
                               LPDWORD a5,
                               LPBYTE a6,
                               LPDWORD a7)
{
	LoadedApi("RegEnumValueA");
    _PrintEnter("RegEnumValueA(%p,%x,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    LONG rv = 0;
    __try {
        rv = Real_RegEnumValueA(a0, a1, a2, a3, a4, a5, a6, a7);
    } __finally {
        _PrintExit("RegEnumValueA(,,%hs,,,,,) -> %x\n", a2, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegEnumValueW(HKEY a0,
                               DWORD a1,
                               LPWSTR a2,
                               LPDWORD a3,
                               LPDWORD a4,
                               LPDWORD a5,
                               LPBYTE a6,
                               LPDWORD a7)
{
	LoadedApi("RegEnumValueW");
    _PrintEnter("RegEnumValueW(%p,%x,%p,%p,%p,%p,%p,%p)\n", a0, a1, a2, a3, a4, a5, a6, a7);

    LONG rv = 0;
    __try {
        rv = Real_RegEnumValueW(a0, a1, a2, a3, a4, a5, a6, a7);
    } __finally {
        _PrintExit("RegEnumValueW(,,%ls,,,,,) -> %x\n", a2, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegOpenKeyExA(HKEY a0,
                               LPCSTR a1,
                               DWORD a2,
                               REGSAM a3,
                               PHKEY a4)
{
	// LoadedApi("RegOpenKeyExA");
    LoadedRegs(a1, NULL);
    _PrintEnter("RegOpenKeyExA(%p,%hs,%x,%x,%p)\n",a0, a1, a2, a3, a4);

    LONG rv = 0;
    __try {
        rv = Real_RegOpenKeyExA(a0, a1, a2, a3, a4);
    } __finally {
        _PrintExit("RegOpenKeyExA(%p,%hs,%x,%x,%p) -> %x\n",
                   a0, a1, a2, a3, a4, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegOpenKeyExW(HKEY a0,
                               LPCWSTR a1,
                               DWORD a2,
                               REGSAM a3,
                               PHKEY a4)
{
	// LoadedApi("RegOpenKeyExW");
    LoadedRegs(NULL, a1);
    _PrintEnter("RegOpenKeyExW(%p,%ls,%x,%x,%p)\n",
                   a0, a1, a2, a3, a4);

    LONG rv = 0;
    __try {
        rv = Real_RegOpenKeyExW(a0, a1, a2, a3, a4);
    } __finally {
        _PrintExit("RegOpenKeyExW(%p,%ls,%x,%x,%p) -> %x\n",
                   a0, a1, a2, a3, a4, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegQueryInfoKeyA(HKEY a0,
                                  LPSTR a1,
                                  LPDWORD a2,
                                  LPDWORD a3,
                                  LPDWORD a4,
                                  LPDWORD a5,
                                  LPDWORD a6,
                                  LPDWORD a7,
                                  LPDWORD a8,
                                  LPDWORD a9,
                                  LPDWORD a10,
                                  LPFILETIME a11)
{
	LoadedApi("RegQueryInfoKeyA");
    _PrintEnter("RegQueryInfoKeyA(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n",
                a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    LONG rv = 0;
    __try {
        rv = Real_RegQueryInfoKeyA(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    } __finally {
        _PrintExit("RegQueryInfoKeyA(,%hs,,,,,,,,,,) -> %x\n", a1, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegQueryInfoKeyW(HKEY a0,
                                  LPWSTR a1,
                                  LPDWORD a2,
                                  LPDWORD a3,
                                  LPDWORD a4,
                                  LPDWORD a5,
                                  LPDWORD a6,
                                  LPDWORD a7,
                                  LPDWORD a8,
                                  LPDWORD a9,
                                  LPDWORD a10,
                                  LPFILETIME a11)
{
	LoadedApi("RegQueryInfoKeyW");
    _PrintEnter("RegQueryInfoKeyW(%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p,%p)\n",
                a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);

    LONG rv = 0;
    __try {
        rv = Real_RegQueryInfoKeyW(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    } __finally {
        _PrintExit("RegQueryInfoKeyW(,%ls,,,,,,,,,,) -> %x\n", a1, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegQueryValueExA(HKEY a0,
                                  LPCSTR a1,
                                  LPDWORD a2,
                                  LPDWORD a3,
                                  LPBYTE a4,
                                  LPDWORD a5)
{
	// LoadedApi("RegQueryValueExA");
    LoadedRegs(a1, NULL);
    _PrintEnter("RegQueryValueExA(%p,%hs,%p,%p,%p,%p)\n",
                   a0, a1, a2, a3, a4, a5);

    LONG rv = 0;
    __try {
        rv = Real_RegQueryValueExA(a0, a1, a2, a3, a4, a5);
    } __finally {
        _PrintExit("RegQueryValueExA(%p,%hs,%p,%p,%p,%p) -> %x\n",
                   a0, a1, a2, a3, a4, a5, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegQueryValueExW(HKEY a0,
                                  LPCWSTR a1,
                                  LPDWORD a2,
                                  LPDWORD a3,
                                  LPBYTE a4,
                                  LPDWORD a5)
{
	// LoadedApi("RegQueryValueExW");
    LoadedRegs(NULL, a1);
    _PrintEnter("RegQueryValueExW(%p,%ls,%p,%p,%p,%p)\n",
                    a0, a1, a2, a3, a4, a5);
    LONG rv = 0;
    __try {
        rv = Real_RegQueryValueExW(a0, a1, a2, a3, a4, a5);
    } __finally {
        _PrintExit("RegQueryValueExW(%p,%ls,%p,%p,%p,%p) -> %x\n",
                    a0, a1, a2, a3, a4, a5, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegSetValueExA(HKEY a0,
                                LPCSTR a1,
                                DWORD a2,
                                DWORD a3,
                                BYTE* a4,
                                DWORD a5)
{
	// LoadedApi("RegSetValueExA");
    LoadedRegs(a1, NULL);
    _PrintEnter("RegSetValueExA(%p,%hs,%x,%x,%p,%x)\n",
                   a0, a1, a2, a3, a4, a5);
    LONG rv = 0;
    __try {
        rv = Real_RegSetValueExA(a0, a1, a2, a3, a4, a5);
    } __finally {
        _PrintExit("RegSetValueExA(%p,%hs,%x,%x,%p,%x) -> %x\n",
                   a0, a1, a2, a3, a4, a5, rv);
    };
    return rv;
}

LONG WINAPI Mine_RegSetValueExW(HKEY a0,
                                   LPCWSTR a1,
                                   DWORD a2,
                                   DWORD a3,
                                   BYTE* a4,
                                   DWORD a5)
{
	// LoadedApi("RegSetValueExW");
    LoadedRegs(NULL, a1);
    _PrintEnter("RegSetValueExW(%p,%ls,%x,%x,%p,%x)\n",
                   a0, a1, a2, a3, a4, a5);
    LONG rv = 0;
    __try {
        rv = Real_RegSetValueExW(a0, a1, a2, a3, a4, a5);
    } __finally {
        _PrintExit("RegSetValueExW(%p,%ls,%x,%x,%p,%x) -> %x\n",
                   a0, a1, a2, a3, a4, a5, rv);
    };
    return rv;
}

HFILE WINAPI Mine__lcreat(LPCSTR a0, int a1)
{
	LoadedApi("lcreat");
    _PrintEnter("_lcreat(%hs,%x)\n", a0, a1);
    HFILE rv = 0;
    __try {
        rv = Real__lcreat(a0, a1);
    } __finally {
        _PrintExit("_lcreat(%hs,%x) -> %p\n", a0, a1, rv);
    };
    return rv;
}

HFILE WINAPI Mine__lopen(LPCSTR a0, int a1)
{
	LoadedApi("lopen");
    _PrintEnter("_lopen(%hs,%x)\n", a0, a1);
    HFILE rv = 0;
    __try {
        rv = Real__lopen(a0, a1);
    } __finally {
        _PrintEnter("_lopen(%hs,%x) -> %p\n", a0, a1, rv);
    };
    return rv;
}