 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetProductInfo)(
     DWORD  dwOSMajorVersion,
     DWORD  dwOSMinorVersion,
     DWORD  dwSpMajorVersion,
     DWORD  dwSpMinorVersion,
     PDWORD pdwReturnedProductType)
  = GetProductInfo;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetProductInfo(
     DWORD  dwOSMajorVersion,
     DWORD  dwOSMinorVersion,
     DWORD  dwSpMajorVersion,
     DWORD  dwSpMinorVersion,
     PDWORD pdwReturnedProductType)
{
	LoadedApi("GetProductInfo");
      _PrintEnter("GetProductInfo");
      return Real_GetProductInfo(dwOSMajorVersion, dwOSMinorVersion, dwSpMajorVersion, dwSpMinorVersion, pdwReturnedProductType);
}


 /*              ***Real***              */ 
LSTATUS (WINAPI * Real_RegLoadKeyW)(
     HKEY    hKey,
     LPCWSTR lpSubKey,
     LPCWSTR lpFile)
  = RegLoadKeyW;
 /*              ***Mine***              */ 
LSTATUS WINAPI  Mine_RegLoadKeyW(
     HKEY    hKey,
     LPCWSTR lpSubKey,
     LPCWSTR lpFile)
{
	LoadedApi("RegLoadKeyW");
      _PrintEnter("RegLoadKeyW");
      return Real_RegLoadKeyW(hKey, lpSubKey, lpFile);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetComputerNameExA)(
     COMPUTER_NAME_FORMAT NameType,
     LPSTR                lpBuffer,
     LPDWORD              nSize)
  = GetComputerNameExA;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetComputerNameExA(
     COMPUTER_NAME_FORMAT NameType,
     LPSTR                lpBuffer,
     LPDWORD              nSize)
{
	LoadedApi("GetComputerNameExA");
      _PrintEnter("GetComputerNameExA");
      return Real_GetComputerNameExA(NameType, lpBuffer, nSize);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetFileMUIPath)(
     DWORD      dwFlags,
     PCWSTR     pcwszFilePath,
     PWSTR      pwszLanguage,
     PULONG     pcchLanguage,
     PWSTR      pwszFileMUIPath,
     PULONG     pcchFileMUIPath,
     PULONGLONG pululEnumerator)
  = GetFileMUIPath;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetFileMUIPath(
     DWORD      dwFlags,
     PCWSTR     pcwszFilePath,
     PWSTR      pwszLanguage,
     PULONG     pcchLanguage,
     PWSTR      pwszFileMUIPath,
     PULONG     pcchFileMUIPath,
     PULONGLONG pululEnumerator)
{
	LoadedApi("GetFileMUIPath");
      _PrintEnter("GetFileMUIPath");
      return Real_GetFileMUIPath(dwFlags, pcwszFilePath, pwszLanguage, pcchLanguage, pwszFileMUIPath, pcchFileMUIPath, pululEnumerator);
}


 /*              ***Real***              */ 
DWORD (WINAPI * Real_GetTimeZoneInformation)(
     LPTIME_ZONE_INFORMATION lpTimeZoneInformation)
  = GetTimeZoneInformation;
 /*              ***Mine***              */ 
DWORD WINAPI  Mine_GetTimeZoneInformation(
     LPTIME_ZONE_INFORMATION lpTimeZoneInformation)
{
	LoadedApi("GetTimeZoneInformation");
      _PrintEnter("GetTimeZoneInformation");
      return Real_GetTimeZoneInformation(lpTimeZoneInformation);
}


 /*              ***Real***              */ 
HKL (WINAPI * Real_GetKeyboardLayout)(
     DWORD idThread)
  = GetKeyboardLayout;
 /*              ***Mine***              */ 
HKL WINAPI  Mine_GetKeyboardLayout(
     DWORD idThread)
{
	LoadedApi("GetKeyboardLayout");
      _PrintEnter("GetKeyboardLayout");
      return Real_GetKeyboardLayout(idThread);
}


 /*              ***Real***              */ 
LSTATUS (WINAPI * Real_RegOpenKeyTransactedA)(
     HKEY   hKey,
     LPCSTR lpSubKey,
     DWORD  ulOptions,
     REGSAM samDesired,
     PHKEY  phkResult,
     HANDLE hTransaction,
     PVOID  pExtendedParemeter)
  = RegOpenKeyTransactedA;
 /*              ***Mine***              */ 
LSTATUS WINAPI  Mine_RegOpenKeyTransactedA(
     HKEY   hKey,
     LPCSTR lpSubKey,
     DWORD  ulOptions,
     REGSAM samDesired,
     PHKEY  phkResult,
     HANDLE hTransaction,
     PVOID  pExtendedParemeter)
{
	LoadedApi("RegOpenKeyTransactedA");
      _PrintEnter("RegOpenKeyTransactedA");
      return Real_RegOpenKeyTransactedA(hKey, lpSubKey, ulOptions, samDesired, phkResult, hTransaction, pExtendedParemeter);
}


 /*              ***Real***              */ 
LSTATUS (WINAPI * Real_RegGetValueA)(
     HKEY    hkey,
     LPCSTR  lpSubKey,
     LPCSTR  lpValue,
     DWORD   dwFlags,
     LPDWORD pdwType,
     PVOID   pvData,
     LPDWORD pcbData)
  = RegGetValueA;
 /*              ***Mine***              */ 
LSTATUS WINAPI  Mine_RegGetValueA(
     HKEY    hkey,
     LPCSTR  lpSubKey,
     LPCSTR  lpValue,
     DWORD   dwFlags,
     LPDWORD pdwType,
     PVOID   pvData,
     LPDWORD pcbData)
{
	LoadedApi("RegGetValueA");
      _PrintEnter("RegGetValueA");
      return Real_RegGetValueA(hkey, lpSubKey, lpValue, dwFlags, pdwType, pvData, pcbData);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_EnumPrintProcessorDatatypesA)(
     LPSTR   pName,
     LPSTR   pPrintProcessorName,
     DWORD   Level,
     LPBYTE  pDatatypes,
     DWORD   cbBuf,
     LPDWORD pcbNeeded,
     LPDWORD pcReturned)
  = EnumPrintProcessorDatatypesA;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_EnumPrintProcessorDatatypesA(
     LPSTR   pName,
     LPSTR   pPrintProcessorName,
     DWORD   Level,
     LPBYTE  pDatatypes,
     DWORD   cbBuf,
     LPDWORD pcbNeeded,
     LPDWORD pcReturned)
{
	LoadedApi("EnumPrintProcessorDatatypesA");
      _PrintEnter("EnumPrintProcessorDatatypesA");
      return Real_EnumPrintProcessorDatatypesA(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned);
}


 /*              ***Real***              */ 
DWORD_PTR (WINAPI * Real_SHGetFileInfoA)(
     LPCSTR      pszPath,
     DWORD       dwFileAttributes,
     SHFILEINFOA *psfi,
     UINT        cbFileInfo,
     UINT        uFlags)
  = SHGetFileInfoA;
 /*              ***Mine***              */ 
DWORD_PTR WINAPI  Mine_SHGetFileInfoA(
     LPCSTR      pszPath,
     DWORD       dwFileAttributes,
     SHFILEINFOA *psfi,
     UINT        cbFileInfo,
     UINT        uFlags)
{
	LoadedApi("SHGetFileInfoA");
      _PrintEnter("SHGetFileInfoA");
      return Real_SHGetFileInfoA(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetComputerNameExW)(
     COMPUTER_NAME_FORMAT NameType,
     LPWSTR               lpBuffer,
     LPDWORD              nSize)
  = GetComputerNameExW;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetComputerNameExW(
     COMPUTER_NAME_FORMAT NameType,
     LPWSTR               lpBuffer,
     LPDWORD              nSize)
{
	LoadedApi("GetComputerNameExW");
      _PrintEnter("GetComputerNameExW");
      return Real_GetComputerNameExW(NameType, lpBuffer, nSize);
}


 /*              ***Real***              */ 
void (WINAPI * Real_GetNativeSystemInfo)(
     LPSYSTEM_INFO lpSystemInfo)
  = GetNativeSystemInfo;
 /*              ***Mine***              */ 
void WINAPI  Mine_GetNativeSystemInfo(
     LPSYSTEM_INFO lpSystemInfo)
{
	LoadedApi("GetNativeSystemInfo");
      _PrintEnter("GetNativeSystemInfo");
      return Real_GetNativeSystemInfo(lpSystemInfo);
}


 /*              ***Real***              */ 
LSTATUS (WINAPI * Real_RegOpenKeyTransactedW)(
     HKEY    hKey,
     LPCWSTR lpSubKey,
     DWORD   ulOptions,
     REGSAM  samDesired,
     PHKEY   phkResult,
     HANDLE  hTransaction,
     PVOID   pExtendedParemeter)
  = RegOpenKeyTransactedW;
 /*              ***Mine***              */ 
LSTATUS WINAPI  Mine_RegOpenKeyTransactedW(
     HKEY    hKey,
     LPCWSTR lpSubKey,
     DWORD   ulOptions,
     REGSAM  samDesired,
     PHKEY   phkResult,
     HANDLE  hTransaction,
     PVOID   pExtendedParemeter)
{
	LoadedApi("RegOpenKeyTransactedW");
      _PrintEnter("RegOpenKeyTransactedW");
      return Real_RegOpenKeyTransactedW(hKey, lpSubKey, ulOptions, samDesired, phkResult, hTransaction, pExtendedParemeter);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetSystemTimeAdjustment)(
     PDWORD lpTimeAdjustment,
     PDWORD lpTimeIncrement,
     PBOOL  lpTimeAdjustmentDisabled)
  = GetSystemTimeAdjustment;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetSystemTimeAdjustment(
     PDWORD lpTimeAdjustment,
     PDWORD lpTimeIncrement,
     PBOOL  lpTimeAdjustmentDisabled)
{
	LoadedApi("GetSystemTimeAdjustment");
      _PrintEnter("GetSystemTimeAdjustment");
      return Real_GetSystemTimeAdjustment(lpTimeAdjustment, lpTimeIncrement, lpTimeAdjustmentDisabled);
}


 /*              ***Real***              */ 
ULONGLONG (WINAPI * Real_GetTickCount64)(
   )
  = GetTickCount64;
 /*              ***Mine***              */ 
ULONGLONG WINAPI  Mine_GetTickCount64(
   )
{
	LoadedApi("GetTickCount64");
      _PrintEnter("GetTickCount64");
      return Real_GetTickCount64();
}


 /*              ***Real***              */ 
HANDLE (WINAPI * Real_CreateFileTransactedW)(
     LPCWSTR               lpFileName,
     DWORD                 dwDesiredAccess,
     DWORD                 dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD                 dwCreationDisposition,
     DWORD                 dwFlagsAndAttributes,
     HANDLE                hTemplateFile,
     HANDLE                hTransaction,
     PUSHORT               pusMiniVersion,
     PVOID                 lpExtendedParameter)
  = CreateFileTransactedW;
 /*              ***Mine***              */ 
HANDLE WINAPI  Mine_CreateFileTransactedW(
     LPCWSTR               lpFileName,
     DWORD                 dwDesiredAccess,
     DWORD                 dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD                 dwCreationDisposition,
     DWORD                 dwFlagsAndAttributes,
     HANDLE                hTemplateFile,
     HANDLE                hTransaction,
     PUSHORT               pusMiniVersion,
     PVOID                 lpExtendedParameter)
{
	LoadedApi("CreateFileTransactedW");
      _PrintEnter("CreateFileTransactedW");
      return Real_CreateFileTransactedW(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile, hTransaction, pusMiniVersion, lpExtendedParameter);
}


 /*              ***Real***              */ 
DWORD (WINAPI * Real_EnumPrinterKey)(
     _In_  HANDLE  hPrinter,
     _In_  LPCTSTR pKeyName,
     _Out_ LPTSTR  pSubkey,
     _In_  DWORD   cbSubkey,
     _Out_ LPDWORD pcbSubkey)
  = EnumPrinterKey;
 /*              ***Mine***              */ 
DWORD WINAPI  Mine_EnumPrinterKey(
     _In_  HANDLE  hPrinter,
     _In_  LPCTSTR pKeyName,
     _Out_ LPTSTR  pSubkey,
     _In_  DWORD   cbSubkey,
     _Out_ LPDWORD pcbSubkey)
{
	LoadedApi("EnumPrinterKey");
      _PrintEnter("EnumPrinterKey");
      return Real_EnumPrinterKey(hPrinter, pKeyName, pSubkey, cbSubkey, pcbSubkey);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetThreadPreferredUILanguages)(
     DWORD   dwFlags,
     PULONG  pulNumLanguages,
     PZZWSTR pwszLanguagesBuffer,
     PULONG  pcchLanguagesBuffer)
  = GetThreadPreferredUILanguages;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetThreadPreferredUILanguages(
     DWORD   dwFlags,
     PULONG  pulNumLanguages,
     PZZWSTR pwszLanguagesBuffer,
     PULONG  pcchLanguagesBuffer)
{
	LoadedApi("GetThreadPreferredUILanguages");
      _PrintEnter("GetThreadPreferredUILanguages");
      return Real_GetThreadPreferredUILanguages(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_LocalFileTimeToFileTime)(
     const FILETIME *lpLocalFileTime,
     LPFILETIME     lpFileTime)
  = LocalFileTimeToFileTime;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_LocalFileTimeToFileTime(
     const FILETIME *lpLocalFileTime,
     LPFILETIME     lpFileTime)
{
	LoadedApi("LocalFileTimeToFileTime");
      _PrintEnter("LocalFileTimeToFileTime");
      return Real_LocalFileTimeToFileTime(lpLocalFileTime, lpFileTime);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetFirmwareType)(
     PFIRMWARE_TYPE FirmwareType)
  = GetFirmwareType;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetFirmwareType(
     PFIRMWARE_TYPE FirmwareType)
{
	LoadedApi("GetFirmwareType");
      _PrintEnter("GetFirmwareType");
      return Real_GetFirmwareType(FirmwareType);
}


 /*              ***Real***              */ 
DWORD_PTR (WINAPI * Real_SHGetFileInfoW)(
     LPCWSTR     pszPath,
     DWORD       dwFileAttributes,
     SHFILEINFOW *psfi,
     UINT        cbFileInfo,
     UINT        uFlags)
  = SHGetFileInfoW;
 /*              ***Mine***              */ 
DWORD_PTR WINAPI  Mine_SHGetFileInfoW(
     LPCWSTR     pszPath,
     DWORD       dwFileAttributes,
     SHFILEINFOW *psfi,
     UINT        cbFileInfo,
     UINT        uFlags)
{
	LoadedApi("SHGetFileInfoW");
      _PrintEnter("SHGetFileInfoW");
      return Real_SHGetFileInfoW(pszPath, dwFileAttributes, psfi, cbFileInfo, uFlags);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetUILanguageInfo)(
     DWORD    dwFlags,
     PCZZWSTR pwmszLanguage,
     PZZWSTR  pwszFallbackLanguages,
     PDWORD   pcchFallbackLanguages,
     PDWORD   pAttributes)
  = GetUILanguageInfo;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetUILanguageInfo(
     DWORD    dwFlags,
     PCZZWSTR pwmszLanguage,
     PZZWSTR  pwszFallbackLanguages,
     PDWORD   pcchFallbackLanguages,
     PDWORD   pAttributes)
{
	LoadedApi("GetUILanguageInfo");
      _PrintEnter("GetUILanguageInfo");
      return Real_GetUILanguageInfo(dwFlags, pwmszLanguage, pwszFallbackLanguages, pcchFallbackLanguages, pAttributes);
}


 /*              ***Real***              */ 
DWORD (WINAPI * Real_GetFirmwareEnvironmentVariableA)(
     LPCSTR lpName,
     LPCSTR lpGuid,
     PVOID  pBuffer,
     DWORD  nSize)
  = GetFirmwareEnvironmentVariableA;
 /*              ***Mine***              */ 
DWORD WINAPI  Mine_GetFirmwareEnvironmentVariableA(
     LPCSTR lpName,
     LPCSTR lpGuid,
     PVOID  pBuffer,
     DWORD  nSize)
{
	LoadedApi("GetFirmwareEnvironmentVariableA");
      _PrintEnter("GetFirmwareEnvironmentVariableA");
      return Real_GetFirmwareEnvironmentVariableA(lpName, lpGuid, pBuffer, nSize);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetSystemRegistryQuota)(
     PDWORD pdwQuotaAllowed,
     PDWORD pdwQuotaUsed)
  = GetSystemRegistryQuota;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetSystemRegistryQuota(
     PDWORD pdwQuotaAllowed,
     PDWORD pdwQuotaUsed)
{
	LoadedApi("GetSystemRegistryQuota");
      _PrintEnter("GetSystemRegistryQuota");
      return Real_GetSystemRegistryQuota(pdwQuotaAllowed, pdwQuotaUsed);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_EnumMonitors)(
     _In_  LPTSTR  pName,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pMonitors,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
  = EnumMonitors;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_EnumMonitors(
     _In_  LPTSTR  pName,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pMonitors,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
{
	LoadedApi("EnumMonitors");
      _PrintEnter("EnumMonitors");
      return Real_EnumMonitors(pName, Level, pMonitors, cbBuf, pcbNeeded, pcReturned);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetUserNameA)(
     LPSTR   lpBuffer,
     LPDWORD pcbBuffer)
  = GetUserNameA;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetUserNameA(
     LPSTR   lpBuffer,
     LPDWORD pcbBuffer)
{
	LoadedApi("GetUserNameA");
      _PrintEnter("GetUserNameA");
      return Real_GetUserNameA(lpBuffer, pcbBuffer);
}


 /*              ***Real***              */ 
HMONITOR (WINAPI * Real_MonitorFromRect)(
     LPCRECT lprc,
     DWORD   dwFlags)
  = MonitorFromRect;
 /*              ***Mine***              */ 
HMONITOR WINAPI  Mine_MonitorFromRect(
     LPCRECT lprc,
     DWORD   dwFlags)
{
	LoadedApi("MonitorFromRect");
      _PrintEnter("MonitorFromRect");
      return Real_MonitorFromRect(lprc, dwFlags);
}


 /*              ***Real***              */ 
LSTATUS (WINAPI * Real_RegQueryMultipleValuesW)(
     HKEY     hKey,
     PVALENTW val_list,
     DWORD    num_vals,
     LPWSTR   lpValueBuf,
     LPDWORD  ldwTotsize)
  = RegQueryMultipleValuesW;
 /*              ***Mine***              */ 
LSTATUS WINAPI  Mine_RegQueryMultipleValuesW(
     HKEY     hKey,
     PVALENTW val_list,
     DWORD    num_vals,
     LPWSTR   lpValueBuf,
     LPDWORD  ldwTotsize)
{
	LoadedApi("RegQueryMultipleValuesW");
      _PrintEnter("RegQueryMultipleValuesW");
      return Real_RegQueryMultipleValuesW(hKey, val_list, num_vals, lpValueBuf, ldwTotsize);
}


 /*              ***Real***              */ 
HANDLE (WINAPI * Real_CreateFileA)(
     LPCSTR                lpFileName,
     DWORD                 dwDesiredAccess,
     DWORD                 dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD                 dwCreationDisposition,
     DWORD                 dwFlagsAndAttributes,
     HANDLE                hTemplateFile)
  = CreateFileA;
 /*              ***Mine***              */ 
HANDLE WINAPI  Mine_CreateFileA(
     LPCSTR                lpFileName,
     DWORD                 dwDesiredAccess,
     DWORD                 dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD                 dwCreationDisposition,
     DWORD                 dwFlagsAndAttributes,
     HANDLE                hTemplateFile)
{
	LoadedApi("CreateFileA");
      _PrintEnter("CreateFileA");
      return Real_CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}


 /*              ***Real***              */ 
UINT (WINAPI * Real_GetSystemWindowsDirectoryA)(
     LPSTR lpBuffer,
     UINT  uSize)
  = GetSystemWindowsDirectoryA;
 /*              ***Mine***              */ 
UINT WINAPI  Mine_GetSystemWindowsDirectoryA(
     LPSTR lpBuffer,
     UINT  uSize)
{
	LoadedApi("GetSystemWindowsDirectoryA");
      _PrintEnter("GetSystemWindowsDirectoryA");
      return Real_GetSystemWindowsDirectoryA(lpBuffer, uSize);
}


 /*              ***Real***              */ 
DWORD (WINAPI * Real_EnumPrinterDataEx)(
     _In_  HANDLE  hPrinter,
     _In_  LPCTSTR pKeyName,
     _Out_ LPBYTE  pEnumValues,
     _In_  DWORD   cbEnumValues,
     _Out_ LPDWORD pcbEnumValues,
     _Out_ LPDWORD pnEnumValues)
  = EnumPrinterDataEx;
 /*              ***Mine***              */ 
DWORD WINAPI  Mine_EnumPrinterDataEx(
     _In_  HANDLE  hPrinter,
     _In_  LPCTSTR pKeyName,
     _Out_ LPBYTE  pEnumValues,
     _In_  DWORD   cbEnumValues,
     _Out_ LPDWORD pcbEnumValues,
     _Out_ LPDWORD pnEnumValues)
{
	LoadedApi("EnumPrinterDataEx");
      _PrintEnter("EnumPrinterDataEx");
      return Real_EnumPrinterDataEx(hPrinter, pKeyName, pEnumValues, cbEnumValues, pcbEnumValues, pnEnumValues);
}


 /*              ***Real***              */ 
LANGID (WINAPI * Real_GetThreadUILanguage)(
   )
  = GetThreadUILanguage;
 /*              ***Mine***              */ 
LANGID WINAPI  Mine_GetThreadUILanguage(
   )
{
	LoadedApi("GetThreadUILanguage");
      _PrintEnter("GetThreadUILanguage");
      return Real_GetThreadUILanguage();
}


 /*              ***Real***              */ 
UINT (WINAPI * Real_GetWindowModuleFileNameA)(
     HWND  hwnd,
     LPSTR pszFileName,
     UINT  cchFileNameMax)
  = GetWindowModuleFileNameA;
 /*              ***Mine***              */ 
UINT WINAPI  Mine_GetWindowModuleFileNameA(
     HWND  hwnd,
     LPSTR pszFileName,
     UINT  cchFileNameMax)
{
	LoadedApi("GetWindowModuleFileNameA");
      _PrintEnter("GetWindowModuleFileNameA");
      return Real_GetWindowModuleFileNameA(hwnd, pszFileName, cchFileNameMax);
}


 /*              ***Real***              */ 
LSTATUS (WINAPI * Real_RegQueryMultipleValuesA)(
     HKEY     hKey,
     PVALENTA val_list,
     DWORD    num_vals,
     LPSTR    lpValueBuf,
     LPDWORD  ldwTotsize)
  = RegQueryMultipleValuesA;
 /*              ***Mine***              */ 
LSTATUS WINAPI  Mine_RegQueryMultipleValuesA(
     HKEY     hKey,
     PVALENTA val_list,
     DWORD    num_vals,
     LPSTR    lpValueBuf,
     LPDWORD  ldwTotsize)
{
	LoadedApi("RegQueryMultipleValuesA");
      _PrintEnter("RegQueryMultipleValuesA");
      return Real_RegQueryMultipleValuesA(hKey, val_list, num_vals, lpValueBuf, ldwTotsize);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetSystemTimes)(
     PFILETIME lpIdleTime,
     PFILETIME lpKernelTime,
     PFILETIME lpUserTime)
  = GetSystemTimes;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetSystemTimes(
     PFILETIME lpIdleTime,
     PFILETIME lpKernelTime,
     PFILETIME lpUserTime)
{
	LoadedApi("GetSystemTimes");
      _PrintEnter("GetSystemTimes");
      return Real_GetSystemTimes(lpIdleTime, lpKernelTime, lpUserTime);
}

 /*              ***Real***              */ 
HANDLE (WINAPI * Real_GetProcessHeap)(
   )
  = GetProcessHeap;
 /*              ***Mine***              */ 
HANDLE WINAPI  Mine_GetProcessHeap(
   )
{
	LoadedApi("GetProcessHeap");
      _PrintEnter("GetProcessHeap");
      return Real_GetProcessHeap();
}


 /*              ***Real***              */ 
HRESULT (WINAPI * Real_SHGetFolderPathAndSubDirA)(
     HWND   hwnd,
     int    csidl,
     HANDLE hToken,
     DWORD  dwFlags,
     LPCSTR pszSubDir,
     LPSTR  pszPath)
  = SHGetFolderPathAndSubDirA;
 /*              ***Mine***              */ 
HRESULT WINAPI  Mine_SHGetFolderPathAndSubDirA(
     HWND   hwnd,
     int    csidl,
     HANDLE hToken,
     DWORD  dwFlags,
     LPCSTR pszSubDir,
     LPSTR  pszPath)
{
	LoadedApi("SHGetFolderPathAndSubDirA");
      _PrintEnter("SHGetFolderPathAndSubDirA");
      return Real_SHGetFolderPathAndSubDirA(hwnd, csidl, hToken, dwFlags, pszSubDir, pszPath);
}


 /*              ***Real***              */ 
UINT (WINAPI * Real_GetSystemWindowsDirectoryW)(
     LPWSTR lpBuffer,
     UINT   uSize)
  = GetSystemWindowsDirectoryW;
 /*              ***Mine***              */ 
UINT WINAPI  Mine_GetSystemWindowsDirectoryW(
     LPWSTR lpBuffer,
     UINT   uSize)
{
	LoadedApi("GetSystemWindowsDirectoryW");
      _PrintEnter("GetSystemWindowsDirectoryW");
      return Real_GetSystemWindowsDirectoryW(lpBuffer, uSize);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetFileMUIInfo)(
     DWORD        dwFlags,
     PCWSTR       pcwszFilePath,
     PFILEMUIINFO pFileMUIInfo,
     DWORD        *pcbFileMUIInfo)
  = GetFileMUIInfo;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetFileMUIInfo(
     DWORD        dwFlags,
     PCWSTR       pcwszFilePath,
     PFILEMUIINFO pFileMUIInfo,
     DWORD        *pcbFileMUIInfo)
{
	LoadedApi("GetFileMUIInfo");
      _PrintEnter("GetFileMUIInfo");
      return Real_GetFileMUIInfo(dwFlags, pcwszFilePath, pFileMUIInfo, pcbFileMUIInfo);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_EnumWindows)(
     WNDENUMPROC lpEnumFunc,
     LPARAM      lParam)
  = EnumWindows;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_EnumWindows(
     WNDENUMPROC lpEnumFunc,
     LPARAM      lParam)
{
	LoadedApi("EnumWindows");
      _PrintEnter("EnumWindows");
      return Real_EnumWindows(lpEnumFunc, lParam);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_EnumPrintProcessors)(
     _In_  LPTSTR  pName,
     _In_  LPTSTR  pEnvironment,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pPrintProcessorInfo,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
  = EnumPrintProcessors;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_EnumPrintProcessors(
     _In_  LPTSTR  pName,
     _In_  LPTSTR  pEnvironment,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pPrintProcessorInfo,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
{
	LoadedApi("EnumPrintProcessors");
      _PrintEnter("EnumPrintProcessors");
      return Real_EnumPrintProcessors(pName, pEnvironment, Level, pPrintProcessorInfo, cbBuf, pcbNeeded, pcReturned);
}


 /*              ***Real***              */ 
DWORD (WINAPI * Real_EnumPrinterData)(
     _In_  HANDLE  hPrinter,
     _In_  DWORD   dwIndex,
     _Out_ LPTSTR  pValueName,
     _In_  DWORD   cbValueName,
     _Out_ LPDWORD pcbValueName,
     _Out_ LPDWORD pType,
     _Out_ LPBYTE  pData,
     _In_  DWORD   cbData,
     _Out_ LPDWORD pcbData)
  = EnumPrinterData;
 /*              ***Mine***              */ 
DWORD WINAPI  Mine_EnumPrinterData(
     _In_  HANDLE  hPrinter,
     _In_  DWORD   dwIndex,
     _Out_ LPTSTR  pValueName,
     _In_  DWORD   cbValueName,
     _Out_ LPDWORD pcbValueName,
     _Out_ LPDWORD pType,
     _Out_ LPBYTE  pData,
     _In_  DWORD   cbData,
     _Out_ LPDWORD pcbData)
{
	LoadedApi("EnumPrinterData");
      _PrintEnter("EnumPrinterData");
      return Real_EnumPrinterData(hPrinter, dwIndex, pValueName, cbValueName, pcbValueName, pType, pData, cbData, pcbData);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetDiskFreeSpaceExA)(
     LPCSTR          lpDirectoryName,
     PULARGE_INTEGER lpFreeBytesAvailableToCaller,
     PULARGE_INTEGER lpTotalNumberOfBytes,
     PULARGE_INTEGER lpTotalNumberOfFreeByte)
  = GetDiskFreeSpaceExA;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetDiskFreeSpaceExA(
     LPCSTR          lpDirectoryName,
     PULARGE_INTEGER lpFreeBytesAvailableToCaller,
     PULARGE_INTEGER lpTotalNumberOfBytes,
     PULARGE_INTEGER lpTotalNumberOfFreeByte)
{
	LoadedApi("GetDiskFreeSpaceExA");
      _PrintEnter("GetDiskFreeSpaceExA");
      return Real_GetDiskFreeSpaceExA(lpDirectoryName, lpFreeBytesAvailableToCaller, lpTotalNumberOfBytes, lpTotalNumberOfFreeByte);
}


