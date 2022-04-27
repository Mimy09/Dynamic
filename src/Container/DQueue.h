#pragma once
#include "../System/DTypes.h"

typedef struct DQueue DQueue;

// Creates a new array
DQueue* DQueue_create(uint32_t in_stride);

// Frees the array from memory
void DQueue_free(DQueue* in_arr);

// Sets the buffer size of the array
void DQueue_buffer(DQueue* in_arr, uint32_t in_buffer);

// Size of the elements in the array
uint32_t DQueue_size(DQueue* in_arr);

// Size of the elements in the array
uint32_t DQueue_size_buffer(DQueue* in_arr);

// Removes the element at the back of the array
void DQueue_popback(DQueue* in_arr);

// Removes the element at the start of the array
void DQueue_popfront(DQueue* in_arr);

// Get mangled pointer to begining of array
void* DQueue_begin(DQueue* in_arr);

// Get pointer to begining of array
void* DQueue_begin_alloc(DQueue* in_arr);

// Get mangled pointer to end of array
void* DQueue_end(DQueue* in_arr);

// Get pointer to end of array
void* DQueue_end_alloc(DQueue* in_arr);

// Get the stride of the array
uint32_t DQueue_stride(DQueue* in_arr);

// -- Pushback -- //

void DQueue_pushback(DQueue* in_arr, void* in_value);

//{SCAR}static void DQueue_pushback__Tn_(DQueue* in_arr, _Tp_ in_value) { DQueue_pushback(in_arr, &in_value); }
//{DESC}:13:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*; bool;
//{DESC}:13:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;  bool;
//{SCAR}
//---{{{
static void DQueue_pushback_u8(DQueue* in_arr, uint8_t in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_u16(DQueue* in_arr, uint16_t in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_u32(DQueue* in_arr, uint32_t in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_u64(DQueue* in_arr, uint64_t in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_i8(DQueue* in_arr, int8_t in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_i16(DQueue* in_arr, int16_t in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_i32(DQueue* in_arr, int32_t in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_i64(DQueue* in_arr, int64_t in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_f32(DQueue* in_arr, float in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_f64(DQueue* in_arr, double in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_char(DQueue* in_arr, char in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_cstr(DQueue* in_arr, char* in_value) { DQueue_pushback(in_arr, &in_value); }
static void DQueue_pushback_bool(DQueue* in_arr, bool in_value) { DQueue_pushback(in_arr, &in_value); }
//---}}}

// -- Pushfront -- //

void DQueue_pushfront(DQueue* in_arr, void* in_value);

//{SCAR}static void DQueue_pushfront__Tn_(DQueue* in_arr, _Tp_ in_value) { DQueue_pushfront(in_arr, &in_value); }
//{DESC}:13:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*; bool;
//{DESC}:13:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;  bool;
//{SCAR}
//---{{{
static void DQueue_pushfront_u8(DQueue* in_arr, uint8_t in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_u16(DQueue* in_arr, uint16_t in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_u32(DQueue* in_arr, uint32_t in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_u64(DQueue* in_arr, uint64_t in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_i8(DQueue* in_arr, int8_t in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_i16(DQueue* in_arr, int16_t in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_i32(DQueue* in_arr, int32_t in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_i64(DQueue* in_arr, int64_t in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_f32(DQueue* in_arr, float in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_f64(DQueue* in_arr, double in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_char(DQueue* in_arr, char in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_cstr(DQueue* in_arr, char* in_value) { DQueue_pushfront(in_arr, &in_value); }
static void DQueue_pushfront_bool(DQueue* in_arr, bool in_value) { DQueue_pushfront(in_arr, &in_value); }
//---}}}

// -- Get -- //

void* DQueue_get(DQueue* in_arr, uint32_t in_index);

//{SCAR}static _Tp_* DQueue_get__Tn_(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
//{DESC}:13:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*; bool;
//{DESC}:13:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;  bool;
//{SCAR}
//---{{{
static uint8_t* DQueue_get_u8(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static uint16_t* DQueue_get_u16(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static uint32_t* DQueue_get_u32(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static uint64_t* DQueue_get_u64(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static int8_t* DQueue_get_i8(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static int16_t* DQueue_get_i16(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static int32_t* DQueue_get_i32(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static int64_t* DQueue_get_i64(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static float* DQueue_get_f32(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static double* DQueue_get_f64(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static char* DQueue_get_char(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static char** DQueue_get_cstr(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
static bool* DQueue_get_bool(DQueue* in_arr, uint32_t in_index) { return DQueue_get(in_arr, in_index); }
//---}}}

// -- Get -- //

void* DQueue_get_real(DQueue* in_arr, uint32_t in_index);

//{SCAR}static _Tp_* DQueue_get_real__Tn_(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
//{DESC}:13:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*; bool;
//{DESC}:13:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;  bool;
//{SCAR}
//---{{{
static uint8_t* DQueue_get_real_u8(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static uint16_t* DQueue_get_real_u16(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static uint32_t* DQueue_get_real_u32(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static uint64_t* DQueue_get_real_u64(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static int8_t* DQueue_get_real_i8(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static int16_t* DQueue_get_real_i16(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static int32_t* DQueue_get_real_i32(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static int64_t* DQueue_get_real_i64(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static float* DQueue_get_real_f32(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static double* DQueue_get_real_f64(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static char* DQueue_get_real_char(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static char** DQueue_get_real_cstr(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
static bool* DQueue_get_real_bool(DQueue* in_arr, uint32_t in_index) { return DQueue_get_real(in_arr, in_index); }
//---}}}

