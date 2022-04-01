#include "DStr.internal.h"
#include "../Core/DMemory.h"
#include "../Core/DLog.h"

DStr* DStr_create(char* in_cstr) {
	DStr* str = (DStr*)DMalloc(sizeof(DStr));
	str->_data = DArray_create(sizeof(char));
	if (in_cstr != NULL) DArray_append_char(str->_data, in_cstr, strlen(in_cstr) + 1);
	return str;
}

void DStr_free(DStr* in_str) {
	if (in_str != NULL) {
		DArray_free(in_str->_data);
		DFree(in_str);
	}
}

void DStr_clear(DStr* in_str) {
	DArray_clear(in_str->_data);
}

char* DStr_cstr(DStr* in_str) {
	return DArray_get_char(in_str->_data, 0);
}

uint32_t DStr_size(DStr* in_str) {
	return DArray_size(in_str->_data);
}

uint32_t DStr_size_buffer(DStr* in_str) {
	return  DArray_size_buffer(in_str->_data);
}

DArray* DStr_arr(DStr* in_str) {
	return in_str->_data;
}

void DStr_append(DStr* in_str, char* in_cstr) {
	if (DArray_size(in_str->_data) > 0)
		if (*DArray_end_char(in_str->_data) == '\0')
			DArray_popback(in_str->_data);
	DArray_append_char(in_str->_data, in_cstr, strlen(in_cstr) + 1);

}

void DStr_remove(DStr* in_str, const char* in_cstr) {
	char* val = strstr(DStr_cstr(in_str), in_cstr);
	if (val) {
		uint32_t pos = val - DStr_cstr(in_str);
		DArray_remove(in_str->_data, pos, pos + strlen(in_cstr));
	}
}

char* DStr_replace(DStr* in_str, char* in_cstr, char* in_replacement) {
	char* val = strstr(DStr_cstr(in_str), in_cstr);
	if (val) {
		uint32_t pos = val - DStr_cstr(in_str);
		DArray_remove(in_str->_data, pos, pos + strlen(in_cstr));
		DArray_insert_char(in_str->_data, in_replacement, strlen(in_replacement), pos);
	}
	return val;
}

void DStr_insert(DStr* in_str, char* in_cstr, uint32_t in_index) {
	DArray_insert_char(in_str->_data, in_cstr, strlen(in_cstr), in_index);
}

void DStr_remove_all(DStr* in_str, char in_c) {
	DArray* arr = DArray_create(sizeof(char));
	DArray_buffer(arr, 10);
	for (int i = 0; i < DArray_size(in_str->_data); i++) {
		char c = *DArray_get_char(in_str->_data, i);
		if (c != in_c) {
			DArray_pushback_char(arr, c);
		}
	}
	DArray_free(in_str->_data);
	in_str->_data = arr;
}

DArray* DStr_split(DStr* in_str, char* in_delim) {
	DArray* arr = DArray_create(sizeof(char*));
	DArray_buffer(arr, 5);

	char* tok = strdup(DStr_cstr(in_str));
	char* tok_ptr = strtok(tok, in_delim);
	DArray_pushback_cstr(arr, strdup(tok_ptr));
	while ((tok_ptr = strtok(NULL, in_delim)) != NULL) {
		DArray_pushback_cstr(arr, strdup(tok_ptr));
	}

	free(tok);
	return arr;
}

void DStr_split_free(DArray* in_arr) {
	for (int i = 0; i < DArray_size(in_arr); i++) {
		free(*DArray_get_cstr(in_arr, i));
	}
	DArray_free(in_arr);
}

bool DStr_contains(DStr* in_str, char* in_cstr) {
	return strstr(DStr_cstr(in_str), in_cstr) != 0;
}
