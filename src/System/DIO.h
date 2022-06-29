#pragma once
#include "DTypes.h"
#include "../Container/DArray.h"
#include "../Container/DMap.h"
#include "../Container/DStr.h"
#include <stdio.h>

typedef struct DIO DIO;

DIO* DIO_create();
void DIO_free(DIO* in_io);

void DIO_close(DIO* in_io);
bool DIO_open(DIO* in_io, const char* in_file, const char* in_opts);
void DIO_seek(DIO* in_io, uint32_t in_pos);
void DIO_seek_begin(DIO* in_io, uint32_t in_pos);
void DIO_seek_end(DIO* in_io, uint32_t in_pos);
uint32_t DIO_file_size(DIO* in_io);
uint32_t DIO_pos(DIO* in_io);


// -- Read -- //

void* DIO_read(DIO* in_io, uint32_t in_size);
char* DIO_read_cstr(DIO* in_io);
char* DIO_read_file(DIO* in_io);
DArray* DIO_read_DArray(DIO* in_io);
DStr* DIO_read_DStr(DIO* in_io);

//{SCAR}_Tp_ DIO_read__Tn_(DIO* in_io);
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; bool;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; bool;
//{SCAR}
//---{{{
uint8_t DIO_read_u8(DIO* in_io);
uint16_t DIO_read_u16(DIO* in_io);
uint32_t DIO_read_u32(DIO* in_io);
uint64_t DIO_read_u64(DIO* in_io);
int8_t DIO_read_i8(DIO* in_io);
int16_t DIO_read_i16(DIO* in_io);
int32_t DIO_read_i32(DIO* in_io);
int64_t DIO_read_i64(DIO* in_io);
float DIO_read_f32(DIO* in_io);
double DIO_read_f64(DIO* in_io);
char DIO_read_char(DIO* in_io);
bool DIO_read_bool(DIO* in_io);
//---}}}


// -- Write -- //

void DIO_write(DIO* in_io, void* in_data, uint32_t in_size);
void DIO_write_cstr(DIO* in_io, char* in_data);
void DIO_write_DArray(DIO* in_io, DArray* in_data);
void DIO_write_DStr(DIO* in_io, DStr* in_data);

//{SCAR}static void DIO_write__Tn_(DIO* in_io, _Tp_ in_data) { DIO_write(in_io, &in_data, sizeof(_Tp_)); }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; bool;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; bool;
//{SCAR}
//---{{{
static void DIO_write_u8(DIO* in_io, uint8_t in_data) { DIO_write(in_io, &in_data, sizeof(uint8_t)); }
static void DIO_write_u16(DIO* in_io, uint16_t in_data) { DIO_write(in_io, &in_data, sizeof(uint16_t)); }
static void DIO_write_u32(DIO* in_io, uint32_t in_data) { DIO_write(in_io, &in_data, sizeof(uint32_t)); }
static void DIO_write_u64(DIO* in_io, uint64_t in_data) { DIO_write(in_io, &in_data, sizeof(uint64_t)); }
static void DIO_write_i8(DIO* in_io, int8_t in_data) { DIO_write(in_io, &in_data, sizeof(int8_t)); }
static void DIO_write_i16(DIO* in_io, int16_t in_data) { DIO_write(in_io, &in_data, sizeof(int16_t)); }
static void DIO_write_i32(DIO* in_io, int32_t in_data) { DIO_write(in_io, &in_data, sizeof(int32_t)); }
static void DIO_write_i64(DIO* in_io, int64_t in_data) { DIO_write(in_io, &in_data, sizeof(int64_t)); }
static void DIO_write_f32(DIO* in_io, float in_data) { DIO_write(in_io, &in_data, sizeof(float)); }
static void DIO_write_f64(DIO* in_io, double in_data) { DIO_write(in_io, &in_data, sizeof(double)); }
static void DIO_write_char(DIO* in_io, char in_data) { DIO_write(in_io, &in_data, sizeof(char)); }
static void DIO_write_bool(DIO* in_io, bool in_data) { DIO_write(in_io, &in_data, sizeof(bool)); }
//---}}}
