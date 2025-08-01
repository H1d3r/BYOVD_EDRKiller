/*
     Stores all macro's and function prototypes used across the project
*/

#pragma once

#include "windows.h"
#include "stdio.h"

#include "structs.h"
#include "config.h"
#include "typedef.h"

// ***** HELPER FUNCTIONS FOR PRINTING ***** //
#define okay(msg, ...) printf("[+] "msg "\n", ##__VA_ARGS__);
#define info(msg, ...) printf("[i] "msg "\n", ##__VA_ARGS__);
#define error(msg, ...) printf("[-] "msg "\n", ##__VA_ARGS__);

#define okayW(msg, ...) wprintf(L"[+] " msg L"\n", ##__VA_ARGS__)
#define infoW(msg, ...) wprintf(L"[i] " msg L"\n", ##__VA_ARGS__)
#define errorW(msg, ...) wprintf(L"[-] " msg L"\n", ##__VA_ARGS__)

// NT Macro for succes of syscalls
#define NT_SUCCESS(status)	        (((NTSTATUS)(status)) >= 0) // https://learn.microsoft.com/en-us/windows-hardware/drivers/kernel/using-ntstatus-values

// Tabbed versions for info without the [i]
#define infoW_t(msg, ...) wprintf(L"\t" msg L"\n", ##__VA_ARGS__)
#define info_t(msg, ...) printf("\t"msg "\n", ##__VA_ARGS__);

// ***** HELPER FUNCTION TO GET HANDLE TO CURRENT PROCESS OR THREAD ***** //
#define NtCurrentProcess() ((HANDLE)-1) // Return the pseudo handle for the current process
#define NtCurrentThread()  ((HANDLE)-2) // Return the pseudo handle for the current thread

// ***** FUNCTION PROTOTYPES ***** //
// Function prototypes are needed so each source file is aware of the function's signature 
// (name, return type, and parameters) before the compiler encounters the function call.

// For functions in 'helpers.c'
int errorWin32(IN const char* msg);
int errorNT(IN const char* msg, IN NTSTATUS ntstatus);
void print_bytes(IN void* ptr, IN int size);

// For functions in 'driver_un_loading.c'
BOOL LoadDriver(IN LPCWSTR lpwcDriverName, IN LPCWSTR lpwcDriverPath);
BOOL UnloadDriver(IN LPCWSTR lpwcDriverName);
HANDLE GetDeviceHandle(IN LPCWSTR lpwcDriverSymlink);
BOOL WriteDriverToFile(IN LPWSTR pszDriverName, IN PBYTE pbDriver, IN DWORD dwDriverSize, OUT LPWSTR* pszFullDriverPath);

// For functions in 'IO.c'
BOOL WriteFileW(IN LPCWSTR wszFileName, IN PBYTE pbFileContent, IN DWORD dwFileSize);
BOOL RemoveFileW(IN LPCWSTR wszFileName);

// For functions in 'killEDR.c'
BOOL KillEdrProcesses();
