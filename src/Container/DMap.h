#pragma once
#include "DArray.h"

typedef struct DMap DMap;

// Creates a new map
DMap* DMap_create(uint32_t in_k_size, u_int32_t in_v_size);

// Free the map from memory
void DMap_free(DMap* in_map);

// Pushback
// {{{

void DMap_pushback(DMap* in_map, void* in_key, void* in_value);

//{SCAR}static void DMap_pushback__Tn_(DMap* in_map, _Tp_ in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8(DMap* in_map, uint8_t in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_u16(DMap* in_map, uint16_t in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_u32(DMap* in_map, uint32_t in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_u64(DMap* in_map, uint64_t in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_i8(DMap* in_map, int8_t in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_i16(DMap* in_map, int16_t in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_i32(DMap* in_map, int32_t in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_i64(DMap* in_map, int64_t in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_f32(DMap* in_map, float in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_f64(DMap* in_map, double in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_char(DMap* in_map, char in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
static void DMap_pushback_cstr(DMap* in_map, char* in_key, void* in_value) { DMap_pushback(in_map, &in_key, in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__u8(DMap* in_map, _Tp_ in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_u8(DMap* in_map, uint8_t in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_u8(DMap* in_map, uint16_t in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_u8(DMap* in_map, uint32_t in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_u8(DMap* in_map, uint64_t in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_u8(DMap* in_map, int8_t in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_u8(DMap* in_map, int16_t in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_u8(DMap* in_map, int32_t in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_u8(DMap* in_map, int64_t in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_u8(DMap* in_map, float in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_u8(DMap* in_map, double in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_u8(DMap* in_map, char in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_u8(DMap* in_map, char* in_key, uint8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__u16(DMap* in_map, _Tp_ in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_u16(DMap* in_map, uint8_t in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_u16(DMap* in_map, uint16_t in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_u16(DMap* in_map, uint32_t in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_u16(DMap* in_map, uint64_t in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_u16(DMap* in_map, int8_t in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_u16(DMap* in_map, int16_t in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_u16(DMap* in_map, int32_t in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_u16(DMap* in_map, int64_t in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_u16(DMap* in_map, float in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_u16(DMap* in_map, double in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_u16(DMap* in_map, char in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_u16(DMap* in_map, char* in_key, uint16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__u32(DMap* in_map, _Tp_ in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_u32(DMap* in_map, uint8_t in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_u32(DMap* in_map, uint16_t in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_u32(DMap* in_map, uint32_t in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_u32(DMap* in_map, uint64_t in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_u32(DMap* in_map, int8_t in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_u32(DMap* in_map, int16_t in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_u32(DMap* in_map, int32_t in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_u32(DMap* in_map, int64_t in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_u32(DMap* in_map, float in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_u32(DMap* in_map, double in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_u32(DMap* in_map, char in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_u32(DMap* in_map, char* in_key, uint32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__u64(DMap* in_map, _Tp_ in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_u64(DMap* in_map, uint8_t in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_u64(DMap* in_map, uint16_t in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_u64(DMap* in_map, uint32_t in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_u64(DMap* in_map, uint64_t in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_u64(DMap* in_map, int8_t in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_u64(DMap* in_map, int16_t in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_u64(DMap* in_map, int32_t in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_u64(DMap* in_map, int64_t in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_u64(DMap* in_map, float in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_u64(DMap* in_map, double in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_u64(DMap* in_map, char in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_u64(DMap* in_map, char* in_key, uint64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__i8(DMap* in_map, _Tp_ in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_i8(DMap* in_map, uint8_t in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_i8(DMap* in_map, uint16_t in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_i8(DMap* in_map, uint32_t in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_i8(DMap* in_map, uint64_t in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_i8(DMap* in_map, int8_t in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_i8(DMap* in_map, int16_t in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_i8(DMap* in_map, int32_t in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_i8(DMap* in_map, int64_t in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_i8(DMap* in_map, float in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_i8(DMap* in_map, double in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_i8(DMap* in_map, char in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_i8(DMap* in_map, char* in_key, int8_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__i16(DMap* in_map, _Tp_ in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_i16(DMap* in_map, uint8_t in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_i16(DMap* in_map, uint16_t in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_i16(DMap* in_map, uint32_t in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_i16(DMap* in_map, uint64_t in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_i16(DMap* in_map, int8_t in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_i16(DMap* in_map, int16_t in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_i16(DMap* in_map, int32_t in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_i16(DMap* in_map, int64_t in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_i16(DMap* in_map, float in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_i16(DMap* in_map, double in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_i16(DMap* in_map, char in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_i16(DMap* in_map, char* in_key, int16_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__i32(DMap* in_map, _Tp_ in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_i32(DMap* in_map, uint8_t in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_i32(DMap* in_map, uint16_t in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_i32(DMap* in_map, uint32_t in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_i32(DMap* in_map, uint64_t in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_i32(DMap* in_map, int8_t in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_i32(DMap* in_map, int16_t in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_i32(DMap* in_map, int32_t in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_i32(DMap* in_map, int64_t in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_i32(DMap* in_map, float in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_i32(DMap* in_map, double in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_i32(DMap* in_map, char in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_i32(DMap* in_map, char* in_key, int32_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__i64(DMap* in_map, _Tp_ in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_i64(DMap* in_map, uint8_t in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_i64(DMap* in_map, uint16_t in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_i64(DMap* in_map, uint32_t in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_i64(DMap* in_map, uint64_t in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_i64(DMap* in_map, int8_t in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_i64(DMap* in_map, int16_t in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_i64(DMap* in_map, int32_t in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_i64(DMap* in_map, int64_t in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_i64(DMap* in_map, float in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_i64(DMap* in_map, double in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_i64(DMap* in_map, char in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_i64(DMap* in_map, char* in_key, int64_t in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__f32(DMap* in_map, _Tp_ in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_f32(DMap* in_map, uint8_t in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_f32(DMap* in_map, uint16_t in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_f32(DMap* in_map, uint32_t in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_f32(DMap* in_map, uint64_t in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_f32(DMap* in_map, int8_t in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_f32(DMap* in_map, int16_t in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_f32(DMap* in_map, int32_t in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_f32(DMap* in_map, int64_t in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_f32(DMap* in_map, float in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_f32(DMap* in_map, double in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_f32(DMap* in_map, char in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_f32(DMap* in_map, char* in_key, float in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__f64(DMap* in_map, _Tp_ in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_f64(DMap* in_map, uint8_t in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_f64(DMap* in_map, uint16_t in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_f64(DMap* in_map, uint32_t in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_f64(DMap* in_map, uint64_t in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_f64(DMap* in_map, int8_t in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_f64(DMap* in_map, int16_t in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_f64(DMap* in_map, int32_t in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_f64(DMap* in_map, int64_t in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_f64(DMap* in_map, float in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_f64(DMap* in_map, double in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_f64(DMap* in_map, char in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_f64(DMap* in_map, char* in_key, double in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__char(DMap* in_map, _Tp_ in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_char(DMap* in_map, uint8_t in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_char(DMap* in_map, uint16_t in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_char(DMap* in_map, uint32_t in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_char(DMap* in_map, uint64_t in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_char(DMap* in_map, int8_t in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_char(DMap* in_map, int16_t in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_char(DMap* in_map, int32_t in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_char(DMap* in_map, int64_t in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_char(DMap* in_map, float in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_char(DMap* in_map, double in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_char(DMap* in_map, char in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_char(DMap* in_map, char* in_key, char in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

//{SCAR}static void DMap_pushback__Tn__cstr(DMap* in_map, _Tp_ in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_pushback_u8_cstr(DMap* in_map, uint8_t in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u16_cstr(DMap* in_map, uint16_t in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u32_cstr(DMap* in_map, uint32_t in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_u64_cstr(DMap* in_map, uint64_t in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i8_cstr(DMap* in_map, int8_t in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i16_cstr(DMap* in_map, int16_t in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i32_cstr(DMap* in_map, int32_t in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_i64_cstr(DMap* in_map, int64_t in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f32_cstr(DMap* in_map, float in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_f64_cstr(DMap* in_map, double in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_char_cstr(DMap* in_map, char in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
static void DMap_pushback_cstr_cstr(DMap* in_map, char* in_key, char* in_value) { DMap_pushback(in_map, &in_key, &in_value); }
//---}}}

// }}}




