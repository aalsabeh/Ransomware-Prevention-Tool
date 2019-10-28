 /*              ***Real***              */ 
BOOL (WINAPI * Real_EnumPorts)(
     _In_  LPTSTR  pName,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pPorts,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
  = EnumPorts;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_EnumPorts(
     _In_  LPTSTR  pName,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pPorts,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
{
	LoadedApi("EnumPorts");
      _PrintEnter("EnumPorts");
      return Real_EnumPorts(pName, Level, pPorts, cbBuf, pcbNeeded, pcReturned);
}


 /*              ***Real***              */ 
SHORT (WINAPI * Real_GetKeyState)(
     int nVirtKey)
  = GetKeyState;
 /*              ***Mine***              */ 
SHORT WINAPI  Mine_GetKeyState(
     int nVirtKey)
{
	LoadedApi("GetKeyState");
      _PrintEnter("GetKeyState");
      return Real_GetKeyState(nVirtKey);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_SHGetDiskFreeSpaceExW)(
     LPCWSTR        pszDirectoryName,
     ULARGE_INTEGER *pulFreeBytesAvailableToCaller,
     ULARGE_INTEGER *pulTotalNumberOfBytes,
     ULARGE_INTEGER *pulTotalNumberOfFreeBytes)
  = SHGetDiskFreeSpaceExW;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_SHGetDiskFreeSpaceExW(
     LPCWSTR        pszDirectoryName,
     ULARGE_INTEGER *pulFreeBytesAvailableToCaller,
     ULARGE_INTEGER *pulTotalNumberOfBytes,
     ULARGE_INTEGER *pulTotalNumberOfFreeBytes)
{
	LoadedApi("SHGetDiskFreeSpaceExW");
      _PrintEnter("SHGetDiskFreeSpaceExW");
      return Real_SHGetDiskFreeSpaceExW(pszDirectoryName, pulFreeBytesAvailableToCaller, pulTotalNumberOfBytes, pulTotalNumberOfFreeBytes);
}


 /*              ***Real***              */ 
UINT (WINAPI * Real_GetSystemWow64DirectoryW)(
     LPWSTR lpBuffer,
     UINT   uSize)
  = GetSystemWow64DirectoryW;
 /*              ***Mine***              */ 
UINT WINAPI  Mine_GetSystemWow64DirectoryW(
     LPWSTR lpBuffer,
     UINT   uSize)
{
	LoadedApi("GetSystemWow64DirectoryW");
      _PrintEnter("GetSystemWow64DirectoryW");
      return Real_GetSystemWow64DirectoryW(lpBuffer, uSize);
}


 /*              ***Real***              */ 
HANDLE (WINAPI * Real_CreateFile2)(
     LPCWSTR                           lpFileName,
     DWORD                             dwDesiredAccess,
     DWORD                             dwShareMode,
     DWORD                             dwCreationDisposition,
     LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams)
  = CreateFile2;
 /*              ***Mine***              */ 
HANDLE WINAPI  Mine_CreateFile2(
     LPCWSTR                           lpFileName,
     DWORD                             dwDesiredAccess,
     DWORD                             dwShareMode,
     DWORD                             dwCreationDisposition,
     LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams)
{
	LoadedApi("CreateFile2");
      _PrintEnter("CreateFile2");
      return Real_CreateFile2(lpFileName, dwDesiredAccess, dwShareMode, dwCreationDisposition, pCreateExParams);
}


 /*              ***Real***              */ 
UINT (WINAPI * Real_GetSystemWow64DirectoryA)(
     LPSTR lpBuffer,
     UINT  uSize)
  = GetSystemWow64DirectoryA;
 /*              ***Mine***              */ 
UINT WINAPI  Mine_GetSystemWow64DirectoryA(
     LPSTR lpBuffer,
     UINT  uSize)
{
	LoadedApi("GetSystemWow64DirectoryA");
      _PrintEnter("GetSystemWow64DirectoryA");
      return Real_GetSystemWow64DirectoryA(lpBuffer, uSize);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetUserPreferredUILanguages)(
     DWORD   dwFlags,
     PULONG  pulNumLanguages,
     PZZWSTR pwszLanguagesBuffer,
     PULONG  pcchLanguagesBuffer)
  = GetUserPreferredUILanguages;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetUserPreferredUILanguages(
     DWORD   dwFlags,
     PULONG  pulNumLanguages,
     PZZWSTR pwszLanguagesBuffer,
     PULONG  pcchLanguagesBuffer)
{
	LoadedApi("GetUserPreferredUILanguages");
      _PrintEnter("GetUserPreferredUILanguages");
      return Real_GetUserPreferredUILanguages(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer);
}


 /*              ***Real***              */ 
LONG (WINAPI * Real_CompareFileTime)(
     const FILETIME *lpFileTime1,
     const FILETIME *lpFileTime2)
  = CompareFileTime;
 /*              ***Mine***              */ 
LONG WINAPI  Mine_CompareFileTime(
     const FILETIME *lpFileTime1,
     const FILETIME *lpFileTime2)
{
	LoadedApi("CompareFileTime");
      _PrintEnter("CompareFileTime");
      return Real_CompareFileTime(lpFileTime1, lpFileTime2);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_SetProcessPreferredUILanguages)(
     DWORD    dwFlags,
     PCZZWSTR pwszLanguagesBuffer,
     PULONG   pulNumLanguages)
  = SetProcessPreferredUILanguages;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_SetProcessPreferredUILanguages(
     DWORD    dwFlags,
     PCZZWSTR pwszLanguagesBuffer,
     PULONG   pulNumLanguages)
{
	LoadedApi("SetProcessPreferredUILanguages");
      _PrintEnter("SetProcessPreferredUILanguages");
      return Real_SetProcessPreferredUILanguages(dwFlags, pwszLanguagesBuffer, pulNumLanguages);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_EnumPrintProcessorDatatypes)(
     _In_  LPTSTR  pName,
     _In_  LPTSTR  pPrintProcessorName,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pDatatypes,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
  = EnumPrintProcessorDatatypes;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_EnumPrintProcessorDatatypes(
     _In_  LPTSTR  pName,
     _In_  LPTSTR  pPrintProcessorName,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pDatatypes,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
{
	LoadedApi("EnumPrintProcessorDatatypes");
      _PrintEnter("EnumPrintProcessorDatatypes");
      return Real_EnumPrintProcessorDatatypes(pName, pPrintProcessorName, Level, pDatatypes, cbBuf, pcbNeeded, pcReturned);
}


 /*              ***Real***              */ 
void (WINAPI * Real_GetSystemTime)(
     LPSYSTEMTIME lpSystemTime)
  = GetSystemTime;
 /*              ***Mine***              */ 
void WINAPI  Mine_GetSystemTime(
     LPSYSTEMTIME lpSystemTime)
{
	LoadedApi("GetSystemTime");
      _PrintEnter("GetSystemTime");
      return Real_GetSystemTime(lpSystemTime);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetFileTime)(
     HANDLE     hFile,
     LPFILETIME lpCreationTime,
     LPFILETIME lpLastAccessTime,
     LPFILETIME lpLastWriteTime)
  = GetFileTime;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetFileTime(
     HANDLE     hFile,
     LPFILETIME lpCreationTime,
     LPFILETIME lpLastAccessTime,
     LPFILETIME lpLastWriteTime)
{
	LoadedApi("GetFileTime");
      _PrintEnter("GetFileTime");
      return Real_GetFileTime(hFile, lpCreationTime, lpLastAccessTime, lpLastWriteTime);
}


 /*              ***Real***              */ 
HWND (WINAPI * Real_GetForegroundWindow)(
   )
  = GetForegroundWindow;
 /*              ***Mine***              */ 
HWND WINAPI  Mine_GetForegroundWindow(
   )
{
	LoadedApi("GetForegroundWindow");
      _PrintEnter("GetForegroundWindow");
      return Real_GetForegroundWindow();
}


 /*              ***Real***              */ 
LSTATUS (WINAPI * Real_RegGetValueW)(
     HKEY    hkey,
     LPCWSTR lpSubKey,
     LPCWSTR lpValue,
     DWORD   dwFlags,
     LPDWORD pdwType,
     PVOID   pvData,
     LPDWORD pcbData)
  = RegGetValueW;
 /*              ***Mine***              */ 
LSTATUS WINAPI  Mine_RegGetValueW(
     HKEY    hkey,
     LPCWSTR lpSubKey,
     LPCWSTR lpValue,
     DWORD   dwFlags,
     LPDWORD pdwType,
     PVOID   pvData,
     LPDWORD pcbData)
{
	LoadedApi("RegGetValueW");
      _PrintEnter("RegGetValueW");
      return Real_RegGetValueW(hkey, lpSubKey, lpValue, dwFlags, pdwType, pvData, pcbData);
}


 /*              ***Real***              */ 
void (WINAPI * Real_GetSystemTimePreciseAsFileTime)(
     LPFILETIME lpSystemTimeAsFileTime)
  = GetSystemTimePreciseAsFileTime;
 /*              ***Mine***              */ 
void WINAPI  Mine_GetSystemTimePreciseAsFileTime(
     LPFILETIME lpSystemTimeAsFileTime)
{
	LoadedApi("GetSystemTimePreciseAsFileTime");
      _PrintEnter("GetSystemTimePreciseAsFileTime");
      return Real_GetSystemTimePreciseAsFileTime(lpSystemTimeAsFileTime);
}


 /*              ***Real***              */ 
HMONITOR (WINAPI * Real_MonitorFromWindow)(
     HWND  hwnd,
     DWORD dwFlags)
  = MonitorFromWindow;
 /*              ***Mine***              */ 
HMONITOR WINAPI  Mine_MonitorFromWindow(
     HWND  hwnd,
     DWORD dwFlags)
{
	LoadedApi("MonitorFromWindow");
      _PrintEnter("MonitorFromWindow");
      return Real_MonitorFromWindow(hwnd, dwFlags);
}


 /*              ***Real***              */ 
DWORD (WINAPI * Real_GetTickCount)(
   )
  = GetTickCount;
 /*              ***Mine***              */ 
DWORD WINAPI  Mine_GetTickCount(
   )
{
	LoadedApi("GetTickCount");
      _PrintEnter("GetTickCount");
      return Real_GetTickCount();
}


 /*              ***Real***              */ 
HANDLE (WINAPI * Real_CreateFileTransactedA)(
     LPCSTR                lpFileName,
     DWORD                 dwDesiredAccess,
     DWORD                 dwShareMode,
     LPSECURITY_ATTRIBUTES lpSecurityAttributes,
     DWORD                 dwCreationDisposition,
     DWORD                 dwFlagsAndAttributes,
     HANDLE                hTemplateFile,
     HANDLE                hTransaction,
     PUSHORT               pusMiniVersion,
     PVOID                 lpExtendedParameter)
  = CreateFileTransactedA;
 /*              ***Mine***              */ 
HANDLE WINAPI  Mine_CreateFileTransactedA(
     LPCSTR                lpFileName,
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
	LoadedApi("CreateFileTransactedA");
      _PrintEnter("CreateFileTransactedA");
      return Real_CreateFileTransactedA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile, hTransaction, pusMiniVersion, lpExtendedParameter);
}


 /*              ***Real***              */ 
DWORD (WINAPI * Real_GetDynamicTimeZoneInformation)(
     PDYNAMIC_TIME_ZONE_INFORMATION pTimeZoneInformation)
  = GetDynamicTimeZoneInformation;
 /*              ***Mine***              */ 
DWORD WINAPI  Mine_GetDynamicTimeZoneInformation(
     PDYNAMIC_TIME_ZONE_INFORMATION pTimeZoneInformation)
{
	LoadedApi("GetDynamicTimeZoneInformation");
      _PrintEnter("GetDynamicTimeZoneInformation");
      return Real_GetDynamicTimeZoneInformation(pTimeZoneInformation);
}


 /*              ***Real***              */ 
LSTATUS (WINAPI * Real_RegLoadKeyA)(
     HKEY   hKey,
     LPCSTR lpSubKey,
     LPCSTR lpFile)
  = RegLoadKeyA;
 /*              ***Mine***              */ 
LSTATUS WINAPI  Mine_RegLoadKeyA(
     HKEY   hKey,
     LPCSTR lpSubKey,
     LPCSTR lpFile)
{
	LoadedApi("RegLoadKeyA");
      _PrintEnter("RegLoadKeyA");
      return Real_RegLoadKeyA(hKey, lpSubKey, lpFile);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetProcessPreferredUILanguages)(
     DWORD   dwFlags,
     PULONG  pulNumLanguages,
     PZZWSTR pwszLanguagesBuffer,
     PULONG  pcchLanguagesBuffer)
  = GetProcessPreferredUILanguages;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetProcessPreferredUILanguages(
     DWORD   dwFlags,
     PULONG  pulNumLanguages,
     PZZWSTR pwszLanguagesBuffer,
     PULONG  pcchLanguagesBuffer)
{
	LoadedApi("GetProcessPreferredUILanguages");
      _PrintEnter("GetProcessPreferredUILanguages");
      return Real_GetProcessPreferredUILanguages(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetSystemPreferredUILanguages)(
     DWORD   dwFlags,
     PULONG  pulNumLanguages,
     PZZWSTR pwszLanguagesBuffer,
     PULONG  pcchLanguagesBuffer)
  = GetSystemPreferredUILanguages;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetSystemPreferredUILanguages(
     DWORD   dwFlags,
     PULONG  pulNumLanguages,
     PZZWSTR pwszLanguagesBuffer,
     PULONG  pcchLanguagesBuffer)
{
	LoadedApi("GetSystemPreferredUILanguages");
      _PrintEnter("GetSystemPreferredUILanguages");
      return Real_GetSystemPreferredUILanguages(dwFlags, pulNumLanguages, pwszLanguagesBuffer, pcchLanguagesBuffer);
}


 /*              ***Real***              */ 
UINT (WINAPI * Real_GetWindowModuleFileNameW)(
     HWND   hwnd,
     LPWSTR pszFileName,
     UINT   cchFileNameMax)
  = GetWindowModuleFileNameW;
 /*              ***Mine***              */ 
UINT WINAPI  Mine_GetWindowModuleFileNameW(
     HWND   hwnd,
     LPWSTR pszFileName,
     UINT   cchFileNameMax)
{
	LoadedApi("GetWindowModuleFileNameW");
      _PrintEnter("GetWindowModuleFileNameW");
      return Real_GetWindowModuleFileNameW(hwnd, pszFileName, cchFileNameMax);
}


 /*              ***Real***              */ 
DWORD (WINAPI * Real_GetFirmwareEnvironmentVariableW)(
     LPCWSTR lpName,
     LPCWSTR lpGuid,
     PVOID   pBuffer,
     DWORD   nSize)
  = GetFirmwareEnvironmentVariableW;
 /*              ***Mine***              */ 
DWORD WINAPI  Mine_GetFirmwareEnvironmentVariableW(
     LPCWSTR lpName,
     LPCWSTR lpGuid,
     PVOID   pBuffer,
     DWORD   nSize)
{
	LoadedApi("GetFirmwareEnvironmentVariableW");
      _PrintEnter("GetFirmwareEnvironmentVariableW");
      return Real_GetFirmwareEnvironmentVariableW(lpName, lpGuid, pBuffer, nSize);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_SHGetDiskFreeSpaceExA)(
     LPCSTR         pszDirectoryName,
     ULARGE_INTEGER *pulFreeBytesAvailableToCaller,
     ULARGE_INTEGER *pulTotalNumberOfBytes,
     ULARGE_INTEGER *pulTotalNumberOfFreeBytes)
  = SHGetDiskFreeSpaceExA;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_SHGetDiskFreeSpaceExA(
     LPCSTR         pszDirectoryName,
     ULARGE_INTEGER *pulFreeBytesAvailableToCaller,
     ULARGE_INTEGER *pulTotalNumberOfBytes,
     ULARGE_INTEGER *pulTotalNumberOfFreeBytes)
{
	LoadedApi("SHGetDiskFreeSpaceExA");
      _PrintEnter("SHGetDiskFreeSpaceExA");
      return Real_SHGetDiskFreeSpaceExA(pszDirectoryName, pulFreeBytesAvailableToCaller, pulTotalNumberOfBytes, pulTotalNumberOfFreeBytes);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_EnumPrinterDrivers)(
     _In_  LPTSTR  pName,
     _In_  LPTSTR  pEnvironment,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pDriverInfo,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
  = EnumPrinterDrivers;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_EnumPrinterDrivers(
     _In_  LPTSTR  pName,
     _In_  LPTSTR  pEnvironment,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pDriverInfo,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
{
	LoadedApi("EnumPrinterDrivers");
      _PrintEnter("EnumPrinterDrivers");
      return Real_EnumPrinterDrivers(pName, pEnvironment, Level, pDriverInfo, cbBuf, pcbNeeded, pcReturned);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetDiskFreeSpaceA)(
     LPCSTR  lpRootPathName,
     LPDWORD lpSectorsPerCluster,
     LPDWORD lpBytesPerSector,
     LPDWORD lpNumberOfFreeClusters,
     LPDWORD lpTotalNumberOfClusters)
  = GetDiskFreeSpaceA;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetDiskFreeSpaceA(
     LPCSTR  lpRootPathName,
     LPDWORD lpSectorsPerCluster,
     LPDWORD lpBytesPerSector,
     LPDWORD lpNumberOfFreeClusters,
     LPDWORD lpTotalNumberOfClusters)
{
	LoadedApi("GetDiskFreeSpaceA");
      _PrintEnter("GetDiskFreeSpaceA");
      return Real_GetDiskFreeSpaceA(lpRootPathName, lpSectorsPerCluster, lpBytesPerSector, lpNumberOfFreeClusters, lpTotalNumberOfClusters);
}


 /*              ***Real***              */ 
void (WINAPI * Real_GetSystemInfo)(
     LPSYSTEM_INFO lpSystemInfo)
  = GetSystemInfo;
 /*              ***Mine***              */ 
void WINAPI  Mine_GetSystemInfo(
     LPSYSTEM_INFO lpSystemInfo)
{
	LoadedApi("GetSystemInfo");
      _PrintEnter("GetSystemInfo");
      return Real_GetSystemInfo(lpSystemInfo);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_EnumPrinters)(
     _In_  DWORD   Flags,
     _In_  LPTSTR  Name,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pPrinterEnum,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
  = EnumPrinters;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_EnumPrinters(
     _In_  DWORD   Flags,
     _In_  LPTSTR  Name,
     _In_  DWORD   Level,
     _Out_ LPBYTE  pPrinterEnum,
     _In_  DWORD   cbBuf,
     _Out_ LPDWORD pcbNeeded,
     _Out_ LPDWORD pcReturned)
{
	LoadedApi("EnumPrinters");
      _PrintEnter("EnumPrinters");
      return Real_EnumPrinters(Flags, Name, Level, pPrinterEnum, cbBuf, pcbNeeded, pcReturned);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetTimeZoneInformationForYear)(
     USHORT                         wYear,
     PDYNAMIC_TIME_ZONE_INFORMATION pdtzi,
     LPTIME_ZONE_INFORMATION        ptzi)
  = GetTimeZoneInformationForYear;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetTimeZoneInformationForYear(
     USHORT                         wYear,
     PDYNAMIC_TIME_ZONE_INFORMATION pdtzi,
     LPTIME_ZONE_INFORMATION        ptzi)
{
	LoadedApi("GetTimeZoneInformationForYear");
      _PrintEnter("GetTimeZoneInformationForYear");
      return Real_GetTimeZoneInformationForYear(wYear, pdtzi, ptzi);
}


 /*              ***Real***              */ 
LANGID (WINAPI * Real_GetSystemDefaultUILanguage)(
   )
  = GetSystemDefaultUILanguage;
 /*              ***Mine***              */ 
LANGID WINAPI  Mine_GetSystemDefaultUILanguage(
   )
{
	LoadedApi("GetSystemDefaultUILanguage");
      _PrintEnter("GetSystemDefaultUILanguage");
      return Real_GetSystemDefaultUILanguage();
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_EnumDisplayMonitors)(
     HDC             hdc,
     LPCRECT         lprcClip,
     MONITORENUMPROC lpfnEnum,
     LPARAM          dwData)
  = EnumDisplayMonitors;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_EnumDisplayMonitors(
     HDC             hdc,
     LPCRECT         lprcClip,
     MONITORENUMPROC lpfnEnum,
     LPARAM          dwData)
{
	LoadedApi("EnumDisplayMonitors");
      _PrintEnter("EnumDisplayMonitors");
      return Real_EnumDisplayMonitors(hdc, lprcClip, lpfnEnum, dwData);
}


 /*              ***Real***              */ 
int (WINAPI * Real_GetKeyboardLayoutList)(
     int nBuff,
     HKL *lpList)
  = GetKeyboardLayoutList;
 /*              ***Mine***              */ 
int WINAPI  Mine_GetKeyboardLayoutList(
     int nBuff,
     HKL *lpList)
{
	LoadedApi("GetKeyboardLayoutList");
      _PrintEnter("GetKeyboardLayoutList");
      return Real_GetKeyboardLayoutList(nBuff, lpList);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetWindowInfo)(
     HWND        hwnd,
     PWINDOWINFO pwi)
  = GetWindowInfo;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetWindowInfo(
     HWND        hwnd,
     PWINDOWINFO pwi)
{
	LoadedApi("GetWindowInfo");
      _PrintEnter("GetWindowInfo");
      return Real_GetWindowInfo(hwnd, pwi);
}


 /*              ***Real***              */ 
BOOL (WINAPI * Real_GetDiskFreeSpaceExW)(
     LPCWSTR         lpDirectoryName,
     PULARGE_INTEGER lpFreeBytesAvailableToCaller,
     PULARGE_INTEGER lpTotalNumberOfBytes,
     PULARGE_INTEGER lpTotalNumberOfFreeByte)
  = GetDiskFreeSpaceExW;
 /*              ***Mine***              */ 
BOOL WINAPI  Mine_GetDiskFreeSpaceExW(
     LPCWSTR         lpDirectoryName,
     PULARGE_INTEGER lpFreeBytesAvailableToCaller,
     PULARGE_INTEGER lpTotalNumberOfBytes,
     PULARGE_INTEGER lpTotalNumberOfFreeByte)
{
	LoadedApi("GetDiskFreeSpaceExW");
      _PrintEnter("GetDiskFreeSpaceExW");
      return Real_GetDiskFreeSpaceExW(lpDirectoryName, lpFreeBytesAvailableToCaller, lpTotalNumberOfBytes, lpTotalNumberOfFreeByte);
}


