#pragma once
#include "DArray.h"
#include "../System/DTypes.h"

typedef struct DStr DStr;

// Creates a new string
DStr* DStr_create(char* in_cstr);

// Frees the string from memory
void DStr_free(DStr* in_str);

// Clears the string
void DStr_clear(DStr* in_str);

// Gets the string a a c string
char* DStr_cstr(DStr* in_str);

// Returns the size of the string
uint32_t DStr_size(DStr* in_str);

// Returns the size of the string
uint32_t DStr_size_buffer(DStr* in_str);

// Returns the underlying array from the string
DArray* DStr_arr(DStr* in_str);

// Appends a c string to the end
void DStr_append(DStr* in_str, char* in_cstr);

// Removes first matching to the c string
void DStr_remove(DStr* in_str, const char* in_cstr);

// Replaced part of the string with a c string
char* DStr_replace(DStr* in_str, char* in_cstr, char* in_replacement);

// Inserts a new c string at the index
void DStr_insert(DStr* in_str, char* in_cstr, uint32_t in_index);

// Remove all chars of type
void DStr_remove_all(DStr* in_str, char in_c);

// Splits the string into a new allocated array
DArray* DStr_split(DStr* in_str, char* in_delim);

// Frees the elements in the array from the split
void DStr_split_free(DArray* in_arr);

// Returns true or false depending on if the string contains the c string
bool DStr_contains(DStr* in_str, char* in_cstr);
