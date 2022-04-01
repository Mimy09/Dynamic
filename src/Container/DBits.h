#pragma once
#include <stdint.h>
#include <stdbool.h>

//{SCAR}typedef struct DBits__Tn_ DBits__Tn_;
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
typedef struct DBits_8 DBits_8;
typedef struct DBits_16 DBits_16;
typedef struct DBits_32 DBits_32;
typedef struct DBits_64 DBits_64;
//---}}}

//{SCAR}DBits__Tn_* DBits_create__Tn_();
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
DBits_8* DBits_create_8();
DBits_16* DBits_create_16();
DBits_32* DBits_create_32();
DBits_64* DBits_create_64();
//---}}}

//{SCAR}void DBits_free__Tn_(DBits__Tn_* in_bits);
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
void DBits_free_8(DBits_8* in_bits);
void DBits_free_16(DBits_16* in_bits);
void DBits_free_32(DBits_32* in_bits);
void DBits_free_64(DBits_64* in_bits);
//---}}}

//{SCAR}void DBits_set__Tn_(DBits__Tn_* in_bits, uint32_t in_index, bool in_set);
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
void DBits_set_8(DBits_8* in_bits, uint32_t in_index, bool in_set);
void DBits_set_16(DBits_16* in_bits, uint32_t in_index, bool in_set);
void DBits_set_32(DBits_32* in_bits, uint32_t in_index, bool in_set);
void DBits_set_64(DBits_64* in_bits, uint32_t in_index, bool in_set);
//---}}}

//{SCAR}void DBits_flip__Tn_(DBits__Tn_* in_bits, uint32_t in_index);
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
void DBits_flip_8(DBits_8* in_bits, uint32_t in_index);
void DBits_flip_16(DBits_16* in_bits, uint32_t in_index);
void DBits_flip_32(DBits_32* in_bits, uint32_t in_index);
void DBits_flip_64(DBits_64* in_bits, uint32_t in_index);
//---}}}

//{SCAR}bool DBits_get__Tn_(DBits__Tn_* in_bits, uint32_t in_index);
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
bool DBits_get_8(DBits_8* in_bits, uint32_t in_index);
bool DBits_get_16(DBits_16* in_bits, uint32_t in_index);
bool DBits_get_32(DBits_32* in_bits, uint32_t in_index);
bool DBits_get_64(DBits_64* in_bits, uint32_t in_index);
//---}}}
