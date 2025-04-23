#pragma once
#include "winStructs.h"

namespace windows_functions
{
	static PEB* GetPEBInternal()
	{
#ifdef _WIN64
		PEB* peb = (PEB*)__readgsqword(0x60);

#else
		PEB* peb = (PEB*)__readfsdword(0x30);
#endif

		return peb;
	}

	static LDR_DATA_TABLE_ENTRY* GetLDREntryInternal(const wchar_t* modName)
	{
		LDR_DATA_TABLE_ENTRY* modEntry = nullptr;

		PEB* peb = GetPEBInternal();

		LIST_ENTRY head = peb->Ldr->InMemoryOrderModuleList;

		LIST_ENTRY curr = head;

		for (auto curr = head; curr.Flink != &peb->Ldr->InMemoryOrderModuleList; curr = *curr.Flink)
		{
			LDR_DATA_TABLE_ENTRY* mod = (LDR_DATA_TABLE_ENTRY*)CONTAINING_RECORD(curr.Flink, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);

			if (mod->BaseDllName.Buffer)
			{
				if (_wcsicmp(modName, mod->BaseDllName.Buffer) == 0)
				{
					modEntry = mod;
					break;
				}
			}
		}
		return modEntry;
	}
}