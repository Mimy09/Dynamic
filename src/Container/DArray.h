#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../System/DTypes.h"

typedef struct DArray DArray;

// Creates a new array
DArray* DArray_create(uint32_t in_stride);

// Frees the array from memory
void DArray_free(DArray* in_arr);

// runs a free on all the elements in the array
void DArray_free_elements(DArray* in_arr);

// Removes the elements from index of in_begin to in_end
void DArray_remove(DArray* in_arr, uint32_t in_begin, u_int32_t in_end);

// Removes the element at in_index
void DArray_remove_at(DArray* in_arr, uint32_t in_index);

// Sets the buffer size of the array
void DArray_buffer(DArray* in_arr, uint32_t in_buffer);

// Sets the array to a c array (arr must be empty)
void DArray_allocate(DArray* in_arr, void* in_data, uint32_t in_size);

// Removes last element from the array
void DArray_popback(DArray* in_arr);

// Clears all elements in the array
void DArray_clear(DArray* in_arr);

// Size of the elements in the array
uint32_t DArray_size(DArray* in_arr);

// Size of the type of elements in the array
uint32_t DArray_stride(DArray* in_arr);

// Size of the buffer
uint32_t DArray_size_buffer(DArray* in_arr);

// -- Pushback -- //

// Adds a new value to the end of the array
void DArray_pushback(DArray* in_arr, void* in_value);

//{SCAR}static void DArray_pushback__Tn_(DArray* in_arr, _Tp_ in_value) { DArray_pushback(in_arr, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DArray_pushback_u8(DArray* in_arr, uint8_t in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_u16(DArray* in_arr, uint16_t in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_u32(DArray* in_arr, uint32_t in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_u64(DArray* in_arr, uint64_t in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_i8(DArray* in_arr, int8_t in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_i16(DArray* in_arr, int16_t in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_i32(DArray* in_arr, int32_t in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_i64(DArray* in_arr, int64_t in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_f32(DArray* in_arr, float in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_f64(DArray* in_arr, double in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_char(DArray* in_arr, char in_value) { DArray_pushback(in_arr, &in_value); }
static void DArray_pushback_cstr(DArray* in_arr, char* in_value) { DArray_pushback(in_arr, &in_value); }
//---}}}

// -- Append -- //

// Appends a c array to the end
void DArray_append(DArray* in_arr, void* in_value, uint32_t in_size);

//{SCAR}static void DArray_append__Tn_(DArray* in_arr, _Tp_* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DArray_append_u8(DArray* in_arr, uint8_t* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_u16(DArray* in_arr, uint16_t* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_u32(DArray* in_arr, uint32_t* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_u64(DArray* in_arr, uint64_t* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_i8(DArray* in_arr, int8_t* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_i16(DArray* in_arr, int16_t* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_i32(DArray* in_arr, int32_t* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_i64(DArray* in_arr, int64_t* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_f32(DArray* in_arr, float* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_f64(DArray* in_arr, double* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_char(DArray* in_arr, char* in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
static void DArray_append_cstr(DArray* in_arr, char** in_value, uint32_t in_size) { DArray_append(in_arr, in_value, in_size); }
//---}}}


// -- Insert -- //

void DArray_insert(DArray* in_arr, void* in_value, u_int32_t in_size, uint32_t in_index);

//{SCAR}static void DArray_insert__Tn_(DArray* in_arr, _Tp_* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DArray_insert_u8(DArray* in_arr, uint8_t* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_u16(DArray* in_arr, uint16_t* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_u32(DArray* in_arr, uint32_t* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_u64(DArray* in_arr, uint64_t* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_i8(DArray* in_arr, int8_t* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_i16(DArray* in_arr, int16_t* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_i32(DArray* in_arr, int32_t* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_i64(DArray* in_arr, int64_t* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_f32(DArray* in_arr, float* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_f64(DArray* in_arr, double* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_char(DArray* in_arr, char* in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
static void DArray_insert_cstr(DArray* in_arr, char** in_value, uint32_t in_size, uint32_t in_index) { DArray_insert(in_arr, in_value, in_size, in_index); }
//---}}}

// -- Put -- //

// Inserts a single value to the array
void DArray_put(DArray* in_arr, void* in_value, uint32_t in_index);

//{SCAR}static void DArray_put__Tn_(DArray* in_arr, _Tp_ in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DArray_put_u8(DArray* in_arr, uint8_t in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_u16(DArray* in_arr, uint16_t in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_u32(DArray* in_arr, uint32_t in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_u64(DArray* in_arr, uint64_t in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_i8(DArray* in_arr, int8_t in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_i16(DArray* in_arr, int16_t in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_i32(DArray* in_arr, int32_t in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_i64(DArray* in_arr, int64_t in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_f32(DArray* in_arr, float in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_f64(DArray* in_arr, double in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_char(DArray* in_arr, char in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
static void DArray_put_cstr(DArray* in_arr, char* in_value, uint32_t in_index) { DArray_put(in_arr, &in_value, in_index); }
//---}}}


// -- Get -- //

void* DArray_get(DArray* in_arr, uint32_t in_index);

//{SCAR}static _Tp_* DArray_get__Tn_(DArray* in_arr, uint32_t in_index) { return (_Tp_*)DArray_get(in_arr, in_index); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static uint8_t* DArray_get_u8(DArray* in_arr, uint32_t in_index) { return (uint8_t*)DArray_get(in_arr, in_index); }
static uint16_t* DArray_get_u16(DArray* in_arr, uint32_t in_index) { return (uint16_t*)DArray_get(in_arr, in_index); }
static uint32_t* DArray_get_u32(DArray* in_arr, uint32_t in_index) { return (uint32_t*)DArray_get(in_arr, in_index); }
static uint64_t* DArray_get_u64(DArray* in_arr, uint32_t in_index) { return (uint64_t*)DArray_get(in_arr, in_index); }
static int8_t* DArray_get_i8(DArray* in_arr, uint32_t in_index) { return (int8_t*)DArray_get(in_arr, in_index); }
static int16_t* DArray_get_i16(DArray* in_arr, uint32_t in_index) { return (int16_t*)DArray_get(in_arr, in_index); }
static int32_t* DArray_get_i32(DArray* in_arr, uint32_t in_index) { return (int32_t*)DArray_get(in_arr, in_index); }
static int64_t* DArray_get_i64(DArray* in_arr, uint32_t in_index) { return (int64_t*)DArray_get(in_arr, in_index); }
static float* DArray_get_f32(DArray* in_arr, uint32_t in_index) { return (float*)DArray_get(in_arr, in_index); }
static double* DArray_get_f64(DArray* in_arr, uint32_t in_index) { return (double*)DArray_get(in_arr, in_index); }
static char* DArray_get_char(DArray* in_arr, uint32_t in_index) { return (char*)DArray_get(in_arr, in_index); }
static char** DArray_get_cstr(DArray* in_arr, uint32_t in_index) { return (char**)DArray_get(in_arr, in_index); }
//---}}}


// -- Set -- //

void DArray_set(DArray* in_arr, uint32_t in_index, void* in_value);

//{SCAR}static void DArray_set__Tn_(DArray* in_arr, uint32_t in_index, _Tp_ in_value) { DArray_set(in_arr, in_index, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DArray_set_u8(DArray* in_arr, uint32_t in_index, uint8_t in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_u16(DArray* in_arr, uint32_t in_index, uint16_t in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_u32(DArray* in_arr, uint32_t in_index, uint32_t in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_u64(DArray* in_arr, uint32_t in_index, uint64_t in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_i8(DArray* in_arr, uint32_t in_index, int8_t in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_i16(DArray* in_arr, uint32_t in_index, int16_t in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_i32(DArray* in_arr, uint32_t in_index, int32_t in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_i64(DArray* in_arr, uint32_t in_index, int64_t in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_f32(DArray* in_arr, uint32_t in_index, float in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_f64(DArray* in_arr, uint32_t in_index, double in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_char(DArray* in_arr, uint32_t in_index, char in_value) { DArray_set(in_arr, in_index, &in_value); }
static void DArray_set_cstr(DArray* in_arr, uint32_t in_index, char* in_value) { DArray_set(in_arr, in_index, &in_value); }
//---}}}


// -- Begin -- //

void* DArray_begin(DArray* in_arr);

//{SCAR}static _Tp_* DArray_begin__Tn_(DArray* in_arr) { return (_Tp_*)DArray_begin(in_arr); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static uint8_t* DArray_begin_u8(DArray* in_arr) { return (uint8_t*)DArray_begin(in_arr); }
static uint16_t* DArray_begin_u16(DArray* in_arr) { return (uint16_t*)DArray_begin(in_arr); }
static uint32_t* DArray_begin_u32(DArray* in_arr) { return (uint32_t*)DArray_begin(in_arr); }
static uint64_t* DArray_begin_u64(DArray* in_arr) { return (uint64_t*)DArray_begin(in_arr); }
static int8_t* DArray_begin_i8(DArray* in_arr) { return (int8_t*)DArray_begin(in_arr); }
static int16_t* DArray_begin_i16(DArray* in_arr) { return (int16_t*)DArray_begin(in_arr); }
static int32_t* DArray_begin_i32(DArray* in_arr) { return (int32_t*)DArray_begin(in_arr); }
static int64_t* DArray_begin_i64(DArray* in_arr) { return (int64_t*)DArray_begin(in_arr); }
static float* DArray_begin_f32(DArray* in_arr) { return (float*)DArray_begin(in_arr); }
static double* DArray_begin_f64(DArray* in_arr) { return (double*)DArray_begin(in_arr); }
static char* DArray_begin_char(DArray* in_arr) { return (char*)DArray_begin(in_arr); }
static char** DArray_begin_cstr(DArray* in_arr) { return (char**)DArray_begin(in_arr); }
//---}}}


// -- End -- //

void* DArray_end(DArray* in_arr);

//{SCAR}static _Tp_* DArray_end__Tn_(DArray* in_arr) { return (_Tp_*)DArray_end(in_arr); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static uint8_t* DArray_end_u8(DArray* in_arr) { return (uint8_t*)DArray_end(in_arr); }
static uint16_t* DArray_end_u16(DArray* in_arr) { return (uint16_t*)DArray_end(in_arr); }
static uint32_t* DArray_end_u32(DArray* in_arr) { return (uint32_t*)DArray_end(in_arr); }
static uint64_t* DArray_end_u64(DArray* in_arr) { return (uint64_t*)DArray_end(in_arr); }
static int8_t* DArray_end_i8(DArray* in_arr) { return (int8_t*)DArray_end(in_arr); }
static int16_t* DArray_end_i16(DArray* in_arr) { return (int16_t*)DArray_end(in_arr); }
static int32_t* DArray_end_i32(DArray* in_arr) { return (int32_t*)DArray_end(in_arr); }
static int64_t* DArray_end_i64(DArray* in_arr) { return (int64_t*)DArray_end(in_arr); }
static float* DArray_end_f32(DArray* in_arr) { return (float*)DArray_end(in_arr); }
static double* DArray_end_f64(DArray* in_arr) { return (double*)DArray_end(in_arr); }
static char* DArray_end_char(DArray* in_arr) { return (char*)DArray_end(in_arr); }
static char** DArray_end_cstr(DArray* in_arr) { return (char**)DArray_end(in_arr); }
//---}}}

