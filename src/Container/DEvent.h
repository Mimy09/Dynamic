#pragma once
#include "../System/DTypes.h"

typedef struct DEvent DEvent;

// Create a new event system
DEvent* DEvent_create(uint32_t in_size);

// Free the event system
void DEvent_free(DEvent* in_e);

// Add a new callabck to the event system
void DEvent_add(DEvent* in_e, const char* in_event, void(*in_func)(void*));

// Call an event
void DEvent_call(DEvent* in_e, const char* in_event, void* in_arg);

//{SCAR}static void DEvent_call__Tn_(DEvent* in_e, const char* in_event, _Tp_ in_arg) { DEvent_call(in_e, in_event, &in_arg); }
//{DESC}:13:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; char*; bool;
//{DESC}:13:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; cstr;  bool;
//{SCAR}
//---{{{
static void DEvent_call_u8(DEvent* in_e, const char* in_event, uint8_t in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_u16(DEvent* in_e, const char* in_event, uint16_t in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_u32(DEvent* in_e, const char* in_event, uint32_t in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_u64(DEvent* in_e, const char* in_event, uint64_t in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_i8(DEvent* in_e, const char* in_event, int8_t in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_i16(DEvent* in_e, const char* in_event, int16_t in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_i32(DEvent* in_e, const char* in_event, int32_t in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_i64(DEvent* in_e, const char* in_event, int64_t in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_f32(DEvent* in_e, const char* in_event, float in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_f64(DEvent* in_e, const char* in_event, double in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_char(DEvent* in_e, const char* in_event, char in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_cstr(DEvent* in_e, const char* in_event, char* in_arg) { DEvent_call(in_e, in_event, &in_arg); }
static void DEvent_call_bool(DEvent* in_e, const char* in_event, bool in_arg) { DEvent_call(in_e, in_event, &in_arg); }
//---}}}
