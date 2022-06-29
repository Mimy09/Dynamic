#include "DIO.internal.h"
#include "../Core/DMemory.h"
#include <stdio.h>
#include <string.h>

DIO* DIO_create() {
    DIO* io = DMalloc(sizeof(DIO));
    io->_fp = NULL;
    return io;
}
void DIO_free(DIO* in_io) {
    if (in_io->_fp != NULL) fclose(in_io->_fp);
    DFree(in_io);
}

void DIO_close(DIO* in_io) {
    if (in_io->_fp != NULL) fclose(in_io->_fp);
}
bool DIO_open(DIO* in_io, const char* in_file, const char* in_modes) {
    if (in_io->_fp == NULL) { in_io->_fp = fopen(in_file, in_modes); }
    else { fclose(in_io->_fp); in_io->_fp = fopen(in_file, in_modes); }
    return in_io->_fp != NULL;
}

void DIO_seek(DIO* in_io, uint32_t in_pos) {
    fseek(in_io->_fp, in_pos, SEEK_SET);
}
void DIO_seek_begin(DIO* in_io, uint32_t in_pos) {
    fseek(in_io->_fp, 0, SEEK_SET);
}
void DIO_seek_end(DIO* in_io, uint32_t in_pos) {
    fseek(in_io->_fp, 0, SEEK_END);
}
uint32_t DIO_file_size(DIO* in_io) {
    fseek(in_io->_fp, 0, SEEK_END);
    long pos = ftell(in_io->_fp);
    fseek(in_io->_fp, 0, SEEK_SET);
    return pos;
}
uint32_t DIO_pos(DIO* in_io) {
    return ftell(in_io->_fp);
}

// -- READ -- //
void* DIO_read(DIO* in_io, uint32_t in_size) {
    void* _ptr = DMalloc(in_size);
    fread(_ptr, in_size, 1, in_io->_fp);
    return _ptr;
}
char* DIO_read_cstr(DIO* in_io) {
    uint32_t i = 0; char p, *_p = DMalloc(sizeof(char) * 255);
    while ((p = getc(in_io->_fp)) != EOF) {
        _p[i] = p; i++; if (p == '\0') break;
    }
    return _p;
}
char* DIO_read_file(DIO* in_io) {
    uint32_t file_size = DIO_file_size(in_io);
    char* _p = (char*)DMalloc(file_size + 1);
    memset(_p, 0, file_size);
    fread(_p, sizeof(char), file_size, in_io->_fp);
    return _p;
}
DArray* DIO_read_DArray(DIO* in_io) {
    uint32_t size = DIO_read_u32(in_io);
    uint32_t stride = DIO_read_u32(in_io);
    DArray* arr = DArray_create(stride);
    void* _ptr = DMalloc(size * stride);
    fread(_ptr, size, stride, in_io->_fp);
    DArray_allocate(arr, _ptr, size);
    return arr;
}
DStr* DIO_read_DStr(DIO* in_io) {
    uint32_t size = DIO_read_u32(in_io);
    
    DArray* arr = DArray_create(sizeof(char));
    void* _ptr = DMalloc(size * sizeof(char));
    fread(_ptr, size, sizeof(char), in_io->_fp);
    DArray_allocate(arr, _ptr, size);

    DStr* str = DStr_create(DArray_begin(arr));
    DArray_free(arr);
    return str;
}

// -- WRITE -- //
void DIO_write(DIO* in_io, void* in_data, uint32_t in_size) {
    fwrite(in_data, in_size, 1, in_io->_fp);
}
void DIO_write_cstr(DIO* in_io, char* in_data) {
    fwrite(in_data, sizeof(char), strlen(in_data) + 1, in_io->_fp);
}
void DIO_write_DArray(DIO* in_io, DArray* in_data) {
    DIO_write_u32(in_io, DArray_size(in_data));
    DIO_write_u32(in_io, DArray_stride(in_data));
    fwrite(DArray_begin(in_data), DArray_size(in_data), DArray_stride(in_data), in_io->_fp);
}
void DIO_write_DStr(DIO* in_io, DStr* in_data) {
    DIO_write_u32(in_io, DStr_size(in_data));
    fwrite(DStr_cstr(in_data), DStr_size(in_data), sizeof(char), in_io->_fp);
}

//{SCAR}_Tp_ DIO_read__Tn_(DIO* in_io) { _Tp_ p; fread(&p, sizeof(_Tp_), 1, in_io->_fp); return p; }
//{DESC}:12:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t; int8_t; int16_t; int32_t; int64_t;	float; double; char; bool;
//{DESC}:12:_Tn_: u8; 	   u16; 	 u32; 	   u64; 	 i8; 	 i16; 	  i32; 	   i64; 	f32;   f64;    char; bool;
//{SCAR}
//---{{{
uint8_t DIO_read_u8(DIO* in_io) { uint8_t p; fread(&p, sizeof(uint8_t), 1, in_io->_fp); return p; }
uint16_t DIO_read_u16(DIO* in_io) { uint16_t p; fread(&p, sizeof(uint16_t), 1, in_io->_fp); return p; }
uint32_t DIO_read_u32(DIO* in_io) { uint32_t p; fread(&p, sizeof(uint32_t), 1, in_io->_fp); return p; }
uint64_t DIO_read_u64(DIO* in_io) { uint64_t p; fread(&p, sizeof(uint64_t), 1, in_io->_fp); return p; }
int8_t DIO_read_i8(DIO* in_io) { int8_t p; fread(&p, sizeof(int8_t), 1, in_io->_fp); return p; }
int16_t DIO_read_i16(DIO* in_io) { int16_t p; fread(&p, sizeof(int16_t), 1, in_io->_fp); return p; }
int32_t DIO_read_i32(DIO* in_io) { int32_t p; fread(&p, sizeof(int32_t), 1, in_io->_fp); return p; }
int64_t DIO_read_i64(DIO* in_io) { int64_t p; fread(&p, sizeof(int64_t), 1, in_io->_fp); return p; }
float DIO_read_f32(DIO* in_io) { float p; fread(&p, sizeof(float), 1, in_io->_fp); return p; }
double DIO_read_f64(DIO* in_io) { double p; fread(&p, sizeof(double), 1, in_io->_fp); return p; }
char DIO_read_char(DIO* in_io) { char p; fread(&p, sizeof(char), 1, in_io->_fp); return p; }
bool DIO_read_bool(DIO* in_io) { bool p; fread(&p, sizeof(bool), 1, in_io->_fp); return p; }
//---}}}

