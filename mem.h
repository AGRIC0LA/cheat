#pragma once
#include <cstdint>
#include <vector>
#include "windows/myWindows.hpp"

namespace memory {
	template <typename t, typename ...args>
	t call_method(uintptr_t address, args... arguments) {
		using method_t = t(*)(args...);
		method_t method = reinterpret_cast<method_t>(address);
		return method(arguments...);
	}

    static DWORD64 PatternScan(const char* signature, LDR_DATA_TABLE_ENTRY* dll) {
        static auto pattern_to_byte = [](const char* pattern) {
            auto bytes = std::vector<char> {};
            auto start = const_cast<char*>(pattern);
            auto end = const_cast<char*>(pattern) + strlen(pattern);

            for (auto current = start; current < end; ++current) {
                if (*current == '?') {
                    ++current;
                    if (*current == '?')
                        ++current;
                    bytes.push_back('\?');
                }
                else {
                    bytes.push_back(strtoul(current, &current, 16));
                }
            }
            return bytes;
            };

        DWORD64 base = (uintptr_t)dll->DllBase;
        DWORD64 sizeOfImage = dll->SizeOfImage;
        auto patternBytes = pattern_to_byte(signature);

        DWORD64 patternLength = patternBytes.size();
        auto data = patternBytes.data();

        for (DWORD64 i = 0; i < sizeOfImage - patternLength; i++) {
            bool found = true;
            for (DWORD64 j = 0; j < patternLength; j++) {
                char a = '\?';
                char b = *(char*)(base + i + j);
                found &= data[j] == a || data[j] == b;
            }
            if (found) {
                return base + i;
            }
        }
        return NULL;
    }
}