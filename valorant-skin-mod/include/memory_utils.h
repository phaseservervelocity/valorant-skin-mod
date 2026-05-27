#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include <cstdint>
#include <string>

namespace MemoryUtils {
    uint32_t find_process_id(const std::string& process_name);
    void* open_process(uint32_t pid);
    bool read_memory(void* handle, uintptr_t address, void* buffer, size_t size);
    bool write_memory(void* handle, uintptr_t address, const void* buffer, size_t size);
    void close_process(void* handle);
}

#endif // MEMORY_UTILS_H