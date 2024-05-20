/*
   This file has been generated by IDA.
   It contains local type definitions from
   the type library 'Cached'
*/

struct _SCOPETABLE_ENTRY;
struct _SYSTEMTIME;
struct HWND__;
struct tagWNDCLASSEXW;
struct HINSTANCE__;
struct HICON__;
struct HBRUSH__;
struct _RTL_CRITICAL_SECTION_DEBUG;
struct _PROCESS_MEMORY_COUNTERS;
union _LARGE_INTEGER;
struct _iobuf;
struct HDC__;

/* 1 */
struct _GUID
{
    unsigned __int32 Data1;
    unsigned __int16 Data2;
    unsigned __int16 Data3;
    unsigned __int8 Data4[8];
};

/* 2 */
typedef struct _GUID GUID;

/* 3 */
typedef struct _SCOPETABLE_ENTRY* PSCOPETABLE_ENTRY;

/* 41 */
typedef void* PVOID;

/* 13 */
typedef unsigned __int32 DWORD;

/* 4 */
struct _EH3_EXCEPTION_REGISTRATION
{
    struct _EH3_EXCEPTION_REGISTRATION* Next;
    PVOID ExceptionHandler;
    PSCOPETABLE_ENTRY ScopeTable;
    DWORD TryLevel;
};

/* 5 */
typedef struct _EH3_EXCEPTION_REGISTRATION EH3_EXCEPTION_REGISTRATION;

/* 6 */
typedef struct _EH3_EXCEPTION_REGISTRATION* PEH3_EXCEPTION_REGISTRATION;

/* 7 */
struct CPPEH_RECORD
{
    DWORD old_esp;
    EXCEPTION_POINTERS* exc_ptr;
    struct _EH3_EXCEPTION_REGISTRATION registration;
};

/* 8 */
struct _SCOPETABLE_ENTRY
{
    int EnclosingLevel;
    void* FilterFunc;
    void* HandlerFunc;
};

/* 9 */
typedef _SYSTEMTIME SYSTEMTIME;

/* 11 */
typedef unsigned __int16 WORD;

/* 10 */
struct _SYSTEMTIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
};

/* 12 */
struct _FILETIME
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
};

/* 15 */
typedef HWND__* HWND;

/* 17 */
typedef unsigned int UINT;

/* 18 */
typedef UINT WPARAM;

/* 20 */
typedef __int32 LONG;

/* 19 */
typedef LONG LPARAM;

/* 22 */
struct tagPOINT
{
    LONG x;
    LONG y;
};

/* 21 */
typedef tagPOINT POINT;

/* 14 */
struct tagMSG
{
    HWND hwnd;
    UINT message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
};

/* 16 */
struct HWND__
{
    int unused;
};

/* 23 */
typedef tagWNDCLASSEXW WNDCLASSEXW;

/* 26 */
typedef LONG LRESULT;

/* 25 */
typedef LRESULT(__stdcall* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

/* 27 */
typedef HINSTANCE__* HINSTANCE;

/* 29 */
typedef HICON__* HICON;

/* 31 */
typedef HICON HCURSOR;

/* 32 */
typedef HBRUSH__* HBRUSH;

/* 36 */
typedef unsigned __int16 wchar_t;

/* 35 */
typedef wchar_t WCHAR;

/* 34 */
typedef const WCHAR* LPCWSTR;

/* 24 */
struct tagWNDCLASSEXW
{
    UINT cbSize;
    UINT style;
    WNDPROC lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
    HICON hIconSm;
};

/* 28 */
struct HINSTANCE__
{
    int unused;
};

/* 30 */
struct HICON__
{
    int unused;
};

/* 33 */
struct HBRUSH__
{
    int unused;
};

/* 37 */
#pragma pack(push, 4)
struct WSAData
{
    WORD wVersion;
    WORD wHighVersion;
    char szDescription[257];
    char szSystemStatus[129];
    unsigned __int16 iMaxSockets;
    unsigned __int16 iMaxUdpDg;
    char* lpVendorInfo;
};
#pragma pack(pop)

/* 39 */
typedef unsigned __int16 u_short;

/* 38 */
#pragma pack(push, 4)
struct sockaddr
{
    u_short sa_family;
    char sa_data[14];
};
#pragma pack(pop)

/* 43 */
typedef unsigned __int32 UINT_PTR;

/* 42 */
typedef UINT_PTR SIZE_T;

/* 40 */
struct _MEMORY_BASIC_INFORMATION
{
    PVOID BaseAddress;
    PVOID AllocationBase;
    DWORD AllocationProtect;
    SIZE_T RegionSize;
    DWORD State;
    DWORD Protect;
    DWORD Type;
};

/* 45 */
typedef _RTL_CRITICAL_SECTION_DEBUG* PRTL_CRITICAL_SECTION_DEBUG;

/* 49 */
typedef void* HANDLE;

/* 44 */
struct _RTL_CRITICAL_SECTION
{
    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
    LONG LockCount;
    LONG RecursionCount;
    HANDLE OwningThread;
    HANDLE LockSemaphore;
    DWORD SpinCount;
};

/* 48 */
struct _LIST_ENTRY
{
    _LIST_ENTRY* Flink;
    _LIST_ENTRY* Blink;
};

/* 47 */
typedef _LIST_ENTRY LIST_ENTRY;

/* 46 */
struct _RTL_CRITICAL_SECTION_DEBUG
{
    WORD Type;
    WORD CreatorBackTraceIndex;
    struct _RTL_CRITICAL_SECTION_DEBUG::_RTL_CRITICAL_SECTION* CriticalSection;
    LIST_ENTRY ProcessLocksList;
    DWORD EntryCount;
    DWORD ContentionCount;
    DWORD Spare[2];
};

/* 52 */
struct _SYSTEM_INFO::$A707B71C060B6D10F73A71917EA8473F::$AA04DEB0C6383F89F13D312A174572A9
{
    WORD wProcessorArchitecture;
    WORD wReserved;
};

/* 51 */
union _SYSTEM_INFO::$A707B71C060B6D10F73A71917EA8473F
{
    DWORD dwOemId;
    struct
    {
        WORD wProcessorArchitecture;
        WORD wReserved;
    };
};

/* 53 */
typedef void* LPVOID;

/* 50 */
struct _SYSTEM_INFO
{
    union
    {
        DWORD dwOemId;
        struct
        {
            WORD wProcessorArchitecture;
            WORD wReserved;
        };
    };
    DWORD dwPageSize;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD dwActiveProcessorMask;
    DWORD dwNumberOfProcessors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
};

/* 55 */
typedef unsigned __int32 u_long;

/* 54 */
#pragma pack(push, 4)
struct _WSABUF
{
    u_long len;
    char* buf;
};
#pragma pack(pop)

/* 57 */
typedef WCHAR* LPWSTR;

/* 56 */
#pragma pack(push, 1)
struct _PDH_COUNTER_PATH_ELEMENTS_W
{
    LPWSTR szMachineName;
    LPWSTR szObjectName;
    LPWSTR szInstanceName;
    LPWSTR szParentInstance;
    DWORD dwInstanceIndex;
    LPWSTR szCounterName;
};
#pragma pack(pop)

/* 60 */
typedef unsigned __int64 ULONGLONG;

/* 59 */
typedef ULONGLONG DWORDLONG;

/* 58 */
struct _MEMORYSTATUSEX
{
    DWORD dwLength;
    DWORD dwMemoryLoad;
    DWORDLONG ullTotalPhys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ullTotalPageFile;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ullTotalVirtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
};

/* 61 */
typedef _PROCESS_MEMORY_COUNTERS PROCESS_MEMORY_COUNTERS;

/* 62 */
#pragma pack(push, 1)
struct _PROCESS_MEMORY_COUNTERS
{
    DWORD cb;
    DWORD PageFaultCount;
    SIZE_T PeakWorkingSetSize;
    SIZE_T WorkingSetSize;
    SIZE_T QuotaPeakPagedPoolUsage;
    SIZE_T QuotaPagedPoolUsage;
    SIZE_T QuotaPeakNonPagedPoolUsage;
    SIZE_T QuotaNonPagedPoolUsage;
    SIZE_T PagefileUsage;
    SIZE_T PeakPagefileUsage;
};
#pragma pack(pop)

/* 64 */
typedef int BOOL;

/* 63 */
struct _SECURITY_ATTRIBUTES
{
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

/* 67 */
typedef char CHAR;

/* 66 */
typedef CHAR* LPSTR;

/* 69 */
typedef unsigned __int8 BYTE;

/* 68 */
typedef BYTE* LPBYTE;

/* 65 */
struct _STARTUPINFOA
{
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
};

/* 70 */
struct _TIME_ZONE_INFORMATION
{
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
};

/* 71 */
struct _cpinfo
{
    UINT MaxCharSize;
    BYTE DefaultChar[2];
    BYTE LeadByte[12];
};

/* 72 */
typedef _LARGE_INTEGER LARGE_INTEGER;

/* 74 */
struct _LARGE_INTEGER::$837407842DC9087486FDFA5FEB63B74E
{
    DWORD LowPart;
    LONG HighPart;
};

/* 75 */
typedef __int64 LONGLONG;

/* 73 */
union _LARGE_INTEGER
{
    struct
    {
        DWORD LowPart;
        LONG HighPart;
    };
    _LARGE_INTEGER::$837407842DC9087486FDFA5FEB63B74E u;
    LONGLONG QuadPart;
};

/* 76 */
typedef _iobuf FILE;

/* 77 */
#pragma pack(push, 8)
struct _iobuf
{
    char* _ptr;
    int _cnt;
    char* _base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char* _tmpfname;
};
#pragma pack(pop)

/* 81 */
typedef unsigned __int8 u_char;

/* 80 */
#pragma pack(push, 4)
struct in_addr::$C13EC994467D6E67044F092615EC7EA9::$01C175C1F0716DCA00314EDD79DBC0A0
{
    u_char s_b1;
    u_char s_b2;
    u_char s_b3;
    u_char s_b4;
};
#pragma pack(pop)

/* 82 */
#pragma pack(push, 4)
struct in_addr::$C13EC994467D6E67044F092615EC7EA9::$4DE764E669F663DACA3CBFDE73714CB5
{
    u_short s_w1;
    u_short s_w2;
};
#pragma pack(pop)

/* 79 */
#pragma pack(push, 4)
union in_addr::$C13EC994467D6E67044F092615EC7EA9
{
    in_addr::$C13EC994467D6E67044F092615EC7EA9::$01C175C1F0716DCA00314EDD79DBC0A0 S_un_b;
    in_addr::$C13EC994467D6E67044F092615EC7EA9::$4DE764E669F663DACA3CBFDE73714CB5 S_un_w;
    u_long S_addr;
};
#pragma pack(pop)

/* 78 */
#pragma pack(push, 4)
struct in_addr
{
    in_addr::$C13EC994467D6E67044F092615EC7EA9 S_un;
};
#pragma pack(pop)

/* 84 */
typedef HDC__* HDC;

/* 87 */
struct tagRECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
};

/* 86 */
typedef tagRECT RECT;

/* 83 */
struct tagPAINTSTRUCT
{
    HDC hdc;
    BOOL fErase;
    RECT rcPaint;
    BOOL fRestore;
    BOOL fIncUpdate;
    BYTE rgbReserved[32];
};

/* 85 */
struct HDC__
{
    int unused;
};

/* 88 */
struct exception;

/* 89 */
struct _msExcept7
{
    int Magic;
    int Count;
    void* InfoPtr;
    int CountDtr;
    void* DtrPtr;
    int _unk[2];
};

/* 90 */
struct _msExcInfo
{
    int Id;
    void* Proc;
};

/* 91 */
struct _msExcExt
{
    int _unk[3];
    int Count;
    void* RttiBlkPtr;
};

/* 92 */
struct _msRttiDscr
{
    int _unk;
    void* RttiPtr;
    int spoff;
    void* Dtr;
};