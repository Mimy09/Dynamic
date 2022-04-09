#pragma once
#include "DArray.h"
#include "../System/DTypes.h"

typedef struct DMap DMap;


uint64_t DMap_hashing(const char* in_cstr, uint32_t in_size);

// Creates a new map
DMap* DMap_create(uint32_t in_size, uint32_t in_stride);

// Free the map from memory
void DMap_free(DMap* in_map);

// Removes the element using the key
bool DMap_remove(DMap* in_map, const char* in_key);

// Get by the index in the map
void* DMap_index(DMap* in_map, uint32_t in_index, uint32_t in_element);

// Get by the key at index in the map
const char* DMap_index_key(DMap* in_map, uint32_t in_index, uint32_t in_element);

// Return the size of the map
uint32_t DMap_size(DMap* in_map);

// Push back a new value to the map
void DMap_set(DMap* in_map, const char* in_key, void* in_value);

//{SCAR}static void DMap_set__Tn_(DMap* in_map, const char* in_key, _Tp_ in_value) { DMap_set(in_map, in_key, &in_value); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static void DMap_set_u8(DMap* in_map, const char* in_key, uint8_t in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_u16(DMap* in_map, const char* in_key, uint16_t in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_u32(DMap* in_map, const char* in_key, uint32_t in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_u64(DMap* in_map, const char* in_key, uint64_t in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_i8(DMap* in_map, const char* in_key, int8_t in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_i16(DMap* in_map, const char* in_key, int16_t in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_i32(DMap* in_map, const char* in_key, int32_t in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_i64(DMap* in_map, const char* in_key, int64_t in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_f32(DMap* in_map, const char* in_key, float in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_f64(DMap* in_map, const char* in_key, double in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_char(DMap* in_map, const char* in_key, char in_value) { DMap_set(in_map, in_key, &in_value); }
static void DMap_set_cstr(DMap* in_map, const char* in_key, char* in_value) { DMap_set(in_map, in_key, &in_value); }
//---}}}

// Get the element at the keys posistion
void* DMap_get(DMap* in_map, const char* in_key);

//{SCAR}static _Tp_* DMap_get__Tn_(DMap* in_map, const char* in_key) { return (_Tp_*)DMap_get(in_map, in_key); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;
//{SCAR}
//---{{{
static uint8_t* DMap_get_u8(DMap* in_map, const char* in_key) { return (uint8_t*)DMap_get(in_map, in_key); }
static uint16_t* DMap_get_u16(DMap* in_map, const char* in_key) { return (uint16_t*)DMap_get(in_map, in_key); }
static uint32_t* DMap_get_u32(DMap* in_map, const char* in_key) { return (uint32_t*)DMap_get(in_map, in_key); }
static uint64_t* DMap_get_u64(DMap* in_map, const char* in_key) { return (uint64_t*)DMap_get(in_map, in_key); }
static int8_t* DMap_get_i8(DMap* in_map, const char* in_key) { return (int8_t*)DMap_get(in_map, in_key); }
static int16_t* DMap_get_i16(DMap* in_map, const char* in_key) { return (int16_t*)DMap_get(in_map, in_key); }
static int32_t* DMap_get_i32(DMap* in_map, const char* in_key) { return (int32_t*)DMap_get(in_map, in_key); }
static int64_t* DMap_get_i64(DMap* in_map, const char* in_key) { return (int64_t*)DMap_get(in_map, in_key); }
static float* DMap_get_f32(DMap* in_map, const char* in_key) { return (float*)DMap_get(in_map, in_key); }
static double* DMap_get_f64(DMap* in_map, const char* in_key) { return (double*)DMap_get(in_map, in_key); }
static char* DMap_get_char(DMap* in_map, const char* in_key) { return (char*)DMap_get(in_map, in_key); }
static char** DMap_get_cstr(DMap* in_map, const char* in_key) { return (char**)DMap_get(in_map, in_key); }
//---}}}
