#pragma once
#include "../System/DTypes.h"

typedef struct DBArray DBArray;

// Creates a new array
DBArray* DBArray_create(uint32_t in_stride);

// Frees the array from memory
void DBArray_free(DBArray* in_arr);

// Sets the buffer size of the array
void DBArray_buffer(DBArray* in_arr, uint32_t in_buffer);

// Size of the elements in the array
uint32_t DBArray_size(DBArray* in_arr);

// Size of the elements in the array
uint32_t DBArray_size_buffer(DBArray* in_arr);

// Removes the element at the back of the array
void DBArray_popback(DBArray* in_arr);

// Removes the element at the start of the array
void DBArray_popfront(DBArray* in_arr);

// Get mangled pointer to begining of array
void* DBArray_begin(DBArray* in_arr);

// Get pointer to begining of array
void* DBArray_begin_alloc(DBArray* in_arr);

// Get mangled pointer to end of array
void* DBArray_end(DBArray* in_arr);

// Get pointer to end of array
void* DBArray_end_alloc(DBArray* in_arr);

// Get the stride of the array
uint32_t DBArray_stride(DBArray* in_arr);

// -- Pushback -- //

void DBArray_pushback(DBArray* in_arr, void* in_value);

//{SCAR}static void DBArray_pushback__Tn_(DBArray* in_arr, _Tp_ in_value) { DBArray_pushback(in_arr, &in_value); }
//{DESC}:13:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*; bool;
//{DESC}:13:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;  bool;
//{SCAR}
//---{{{
static void DBArray_pushback_u8(DBArray* in_arr, uint8_t in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_u16(DBArray* in_arr, uint16_t in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_u32(DBArray* in_arr, uint32_t in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_u64(DBArray* in_arr, uint64_t in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_i8(DBArray* in_arr, int8_t in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_i16(DBArray* in_arr, int16_t in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_i32(DBArray* in_arr, int32_t in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_i64(DBArray* in_arr, int64_t in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_f32(DBArray* in_arr, float in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_f64(DBArray* in_arr, double in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_char(DBArray* in_arr, char in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_cstr(DBArray* in_arr, char* in_value) { DBArray_pushback(in_arr, &in_value); }
static void DBArray_pushback_bool(DBArray* in_arr, bool in_value) { DBArray_pushback(in_arr, &in_value); }
//---}}}

// -- Pushfront -- //

void DBArray_pushfront(DBArray* in_arr, void* in_value);

//{SCAR}static void DBArray_pushfront__Tn_(DBArray* in_arr, _Tp_ in_value) { DBArray_pushfront(in_arr, &in_value); }
//{DESC}:13:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*; bool;
//{DESC}:13:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;  bool;
//{SCAR}
//---{{{
static void DBArray_pushfront_u8(DBArray* in_arr, uint8_t in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_u16(DBArray* in_arr, uint16_t in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_u32(DBArray* in_arr, uint32_t in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_u64(DBArray* in_arr, uint64_t in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_i8(DBArray* in_arr, int8_t in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_i16(DBArray* in_arr, int16_t in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_i32(DBArray* in_arr, int32_t in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_i64(DBArray* in_arr, int64_t in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_f32(DBArray* in_arr, float in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_f64(DBArray* in_arr, double in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_char(DBArray* in_arr, char in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_cstr(DBArray* in_arr, char* in_value) { DBArray_pushfront(in_arr, &in_value); }
static void DBArray_pushfront_bool(DBArray* in_arr, bool in_value) { DBArray_pushfront(in_arr, &in_value); }
//---}}}

// -- Get -- //

void* DBArray_get(DBArray* in_arr, uint32_t in_index);

//{SCAR}static _Tp_* DBArray_get__Tn_(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
//{DESC}:13:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*; bool;
//{DESC}:13:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;  bool;
//{SCAR}
//---{{{
static uint8_t* DBArray_get_u8(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static uint16_t* DBArray_get_u16(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static uint32_t* DBArray_get_u32(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static uint64_t* DBArray_get_u64(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static int8_t* DBArray_get_i8(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static int16_t* DBArray_get_i16(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static int32_t* DBArray_get_i32(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static int64_t* DBArray_get_i64(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static float* DBArray_get_f32(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static double* DBArray_get_f64(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static char* DBArray_get_char(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static char** DBArray_get_cstr(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
static bool* DBArray_get_bool(DBArray* in_arr, uint32_t in_index) { return DBArray_get(in_arr, in_index); }
//---}}}

// -- Get -- //

void* DBArray_get_real(DBArray* in_arr, uint32_t in_index);

//{SCAR}static _Tp_* DBArray_get_real__Tn_(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
//{DESC}:13:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*; bool;
//{DESC}:13:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;  bool;
//{SCAR}
//---{{{
static uint8_t* DBArray_get_real_u8(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static uint16_t* DBArray_get_real_u16(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static uint32_t* DBArray_get_real_u32(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static uint64_t* DBArray_get_real_u64(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static int8_t* DBArray_get_real_i8(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static int16_t* DBArray_get_real_i16(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static int32_t* DBArray_get_real_i32(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static int64_t* DBArray_get_real_i64(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static float* DBArray_get_real_f32(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static double* DBArray_get_real_f64(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static char* DBArray_get_real_char(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static char** DBArray_get_real_cstr(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
static bool* DBArray_get_real_bool(DBArray* in_arr, uint32_t in_index) { return DBArray_get_real(in_arr, in_index); }
//---}}}

