#pragma once
#include "../mem.h"

inline uintptr_t resolve_virtual_method(Il2CppObject* object, std::string method_name, int arg_count) {
	MethodInfo* method_info = il2cpp_api::il2cpp_class_get_method_from_name(il2cpp_api::il2cpp_object_get_class(object), method_name.c_str(), arg_count);
	if (!method_info) return 0;
	uintptr_t method_address = reinterpret_cast<uintptr_t>(il2cpp_api::il2cpp_object_get_virtual_method(object, method_info)->methodPointer);
	return method_address;
}

template <typename t_key, typename t_value>
struct entry {
	int hash_code;
	int next;
	t_key key;
	t_value value;
};

struct il2cpp_obj {
	Il2CppClass* klass;

	il2cpp_obj() {
		klass = il2cpp_api::il2cpp_object_get_class(reinterpret_cast<Il2CppObject*>(this));
	}

	template <typename t>
	t get_field_value(const char* name) {
		t to_return;
		FieldInfo* info = il2cpp_api::il2cpp_class_get_field_from_name(klass, name);
		if (!info) return 0;
		il2cpp_api::il2cpp_field_get_value(reinterpret_cast<Il2CppObject*>(this), info, &to_return);
		return to_return;
	}
};

template <typename t> 
struct il2cpp_array : il2cpp_obj {
	int get_size() {
		return this->get_field_value<int>("_count");
	}

	uintptr_t get_values_start() {
		return (uintptr_t)(reinterpret_cast<uintptr_t>(this) + sizeof(Il2CppArray));
	}

	t* get_value(int i) {
		return reinterpret_cast<t*>(this->get_values_start() + i * sizeof(t));
	}
};

template <typename t_key, typename t_value> 
struct il2cpp_dictionary : il2cpp_obj {
	int get_size() {
		return this->get_field_value<int>("_count");
	}

	entry<t_key, t_value>* get_entry(int i) {
		auto entries = this->get_field_value<il2cpp_array<entry<t_key, t_value>>*>("_entries");
		if (!entries) return nullptr;
		return entries->get_value(i);
	}
};

struct il2cpp_string {

	static il2cpp_string* new_str(const char* str) {
		return reinterpret_cast<il2cpp_string*>(il2cpp_api::il2cpp_string_new_len(str, strlen(str)));
	}

	const size_t get_lenght() {
		return il2cpp_api::il2cpp_string_length(reinterpret_cast<Il2CppString*>(this));
	}

	const wchar_t* get_wchar() {
		return reinterpret_cast<wchar_t*>(il2cpp_api::il2cpp_string_chars(reinterpret_cast<Il2CppString*>(this)));
	}

	std::string to_string() {
		if (!this) return "";

		std::string sRet(static_cast<size_t>(get_lenght()) * 3 + 1, '\0');
		WideCharToMultiByte(CP_UTF8, 0, get_wchar(), get_lenght(), &sRet[0], static_cast<int>(sRet.size()), 0, 0);
		return sRet;
	}
};