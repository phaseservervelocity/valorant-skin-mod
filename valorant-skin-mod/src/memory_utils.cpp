#include "memory_utils.h"

#ifdef _WIN32
#include <windows.h>
#include <tlhelp32.h>
#else
#error "This project is Windows-only."
#endif

#include <cstring>

namespace MemoryUtils {

uint32_t find_process_id(const std::string& process_name) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return 0;

    PROCESSENTRY32 entry;
    entry.dwSize = sizeof(PROCESSENTRY32);

    uint32_t pid = 0;
    if (Process32First(snapshot, &entry)) {
        do {
            if (process_name == entry.szExeFile) {
                pid = entry.th32ProcessID;
                break;
            }
        } while (Process32Next(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return pid;
}

void* open_process(uint32_t pid) {
    return OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, pid);
}

bool read_memory(void* handle, uintptr_t address, void* buffer, size_t size) {
    SIZE_T bytes_read;
    return ReadProcessMemory(handle, reinterpret_cast<LPCVOID>(address), buffer, size, &bytes_read) != 0;
}

bool write_memory(void* handle, uintptr_t address, const void* buffer, size_t size) {
    SIZE_T bytes_written;
    return WriteProcessMemory(handle, reinterpret_cast<LPVOID>(address), buffer, size, &bytes_written) != 0;
}

void close_process(void* handle) {
    if (handle) {
        CloseHandle(handle);
    }
}

} // namespace MemoryUtils