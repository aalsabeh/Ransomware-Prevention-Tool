//////////////////////////////////////////////////////////////////////////////
//
//  Detours Test Program (testapi.cpp of testapi.exe)
//
//  Microsoft Research Detours Package, Version 3.0.
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//
#include "trcapi.cpp"
#include <WbemIdl.h>
#include <malloc.h>
#if (_MSC_VER < 1299)
typedef ULONG * PULONG_PTR;
typedef ULONG ULONG_PTR;
typedef LONG * PLONG_PTR;
typedef LONG LONG_PTR;
#endif

#define TOTALBYTES    8192
#define BYTEINCREMENT 4096


VOID SyelogOpen(PCSTR pszIdentifier, BYTE nFacility)
{
    (void)pszIdentifier;
    (void)nFacility;
}

VOID SyelogExV(BOOL fTerminate, BYTE nSeverity, PCSTR pszMsgf, va_list args)
{
    (void)fTerminate;

    CHAR szBuffer[1024];
    PCHAR psz = szBuffer;
    BOOL fLf = FALSE;

    StringCchPrintfA(psz, szBuffer + sizeof(szBuffer) - psz, "--.%02x: ", nSeverity);
    while (*psz) {
        psz++;
    }

    StringCchVPrintfA(psz, szBuffer + sizeof(szBuffer) - psz, pszMsgf, args);
    for (psz = szBuffer; *psz; psz++) {
        if (*psz == '\n') {
            if (fLf) {
                *psz = '\0';
                break;
            }
            fLf = TRUE;
        }
    }
    if (!fLf) {
        *psz++ = '\n';
        *psz = '\0';
    }
    printf("%s", szBuffer);
    Real_OutputDebugStringA(szBuffer);
}

VOID SyelogV(BYTE nSeverity, PCSTR pszMsgf, va_list args)
{
    SyelogExV(FALSE, nSeverity, pszMsgf, args);
}

VOID Syelog(BYTE nSeverity, PCSTR pszMsgf, ...)
{
    va_list args;
    va_start(args, pszMsgf);
    SyelogExV(FALSE, nSeverity, pszMsgf, args);
    va_end(args);
}

VOID SyelogEx(BOOL fTerminate, BYTE nSeverity, PCSTR pszMsgf, ...)
{
    va_list args;
    va_start(args, pszMsgf);
    SyelogExV(fTerminate, nSeverity, pszMsgf, args);
    va_end(args);
}

VOID SyelogClose(BOOL fTerminate)
{
    (void)fTerminate;
}

void callAli();
void callReg();

DWORD main(int argc, char **argv)
{
    (void)argc; 
    (void)argv;
 
    printf("testapi: Starting\n");
    float f = 2.5;
    _PrintEnter("PrintEnter 2.5 %d\n", f);

    // callAli();

    // ProcessAttach(NULL);
    Sleep(100);
    // ProcessDetach(NULL);

    LPWSTR lpBuffer = L"";
    UINT uSize = 0;

    GetWindowsDirectoryW(lpBuffer, uSize);
    
    // int j;
    // scanf("%d\n",&j);
    // TerminateProcess(GetCurrentProcess(), 1);
    // ExitProcess(1);

    // callReg();

    return 0;
}

void callReg(){
    DWORD BufferSize = TOTALBYTES;
    DWORD cbData;
    DWORD dwRet;

    PPERF_DATA_BLOCK PerfData = (PPERF_DATA_BLOCK) malloc( BufferSize );
    cbData = BufferSize;

    printf("\nRetrieving the data...");
    
    dwRet = RegQueryValueEx( HKEY_PERFORMANCE_DATA,
                             TEXT("Global"),
                             NULL,
                             NULL,
                             (LPBYTE) PerfData,
                             &cbData );
    while( dwRet == ERROR_MORE_DATA )
    {
        // Get a buffer that is big enough.

        BufferSize += BYTEINCREMENT;
        PerfData = (PPERF_DATA_BLOCK) realloc( PerfData, BufferSize );
        cbData = BufferSize;

        printf(".");
        dwRet = RegQueryValueEx( HKEY_PERFORMANCE_DATA,
                         TEXT("Global"),
                         NULL,
                         NULL,
                         (LPBYTE) PerfData,
                         &cbData );
    }
    if( dwRet == ERROR_SUCCESS )
        printf("\n\nFinal buffer size is %d\n", BufferSize);
    else printf("\nRegQueryValueEx failed (%d)\n", dwRet);    
}
void callAli(){
    IWbemLocator *pIWbemLocator = NULL;

   CoCreateInstance (
                CLSID_WbemAdministrativeLocator,
                NULL ,
                CLSCTX_INPROC_SERVER | CLSCTX_LOCAL_SERVER , 
                IID_IUnknown ,
                ( void ** ) &pIWbemLocator
                ) ;

    IWbemServices *pWbemServices = NULL;

    __try {
            pIWbemLocator->ConnectServer(
                    L"root\\CIMV2",  // Namespace
                    NULL,          // Userid
                    NULL,           // PW
                    NULL,           // Locale
                    0,              // flags
                    NULL,           // Authority
                    NULL,           // Context
                    &pWbemServices
                    );
    }__finally {
       printf("shit\n");
    };

    // if (SUCCEEDED(hRes))
    // {
    //     printf("This was called\n");
    //     hRes = pIWbemLocator->ConnectServer(
    //                 L"root\\CIMV2",  // Namespace
    //                 NULL,          // Userid
    //                 NULL,           // PW
    //                 NULL,           // Locale
    //                 0,              // flags
    //                 NULL,           // Authority
    //                 NULL,           // Context
    //                 &pWbemServices
    //                 );

    // pIWbemLocator->Release(); // Free memory resources.

    // // Use pWbemServices

    // }

    // // Clean up
    // pWbemServices->Release();
}
//
//////////////////////////////////////////////////////////////////////////////
