#pragma once
#include"../il2cpp/il2cpp_types.h"
#include "../il2cpp/il2cpp_api.h"
#include <vector>
namespace il2cpp_sdk_gen {static Il2CppDomain* domain;extern std::vector<Il2CppAssembly*> assembly_list;static void init() {	if (!il2cpp_api::il2cpp_domain_get)		il2cpp_api::initialize();	domain = il2cpp_api::il2cpp_domain_get();	if (!domain) return;	size_t size;	Il2CppAssembly** assemblies = il2cpp_api::il2cpp_domain_get_assemblies(domain, &size);	if (!assemblies) return;	for (int i = 0; i < size; i++) {	Il2CppAssembly* assembly = (Il2CppAssembly*)assemblies[i];		if (!assembly) continue;		assembly_list.push_back(assembly);	}	}}