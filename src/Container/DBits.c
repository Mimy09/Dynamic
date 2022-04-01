#include "DBits.internal.h"
#include "../Core/DMemory.h"
#include <stdlib.h>

//{SCAR}DBits__Tn_* DBits_create__Tn_() { DBits__Tn_* b = DMalloc(sizeof(DBits__Tn_)); b->_bits = 0; return b; }
//{DESC}:4:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t;
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
DBits_8* DBits_create_8() { DBits_8* b = DMalloc(sizeof(DBits_8)); b->_bits = 0; return b; }
DBits_16* DBits_create_16() { DBits_16* b = DMalloc(sizeof(DBits_16)); b->_bits = 0; return b; }
DBits_32* DBits_create_32() { DBits_32* b = DMalloc(sizeof(DBits_32)); b->_bits = 0; return b; }
DBits_64* DBits_create_64() { DBits_64* b = DMalloc(sizeof(DBits_64)); b->_bits = 0; return b; }
//---}}}

//{SCAR}void DBits_free__Tn_(DBits__Tn_* in_bits) { if (in_bits != NULL) DFree(in_bits); }
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
void DBits_free_8(DBits_8* in_bits) { if (in_bits != NULL) DFree(in_bits); }
void DBits_free_16(DBits_16* in_bits) { if (in_bits != NULL) DFree(in_bits); }
void DBits_free_32(DBits_32* in_bits) { if (in_bits != NULL) DFree(in_bits); }
void DBits_free_64(DBits_64* in_bits) { if (in_bits != NULL) DFree(in_bits); }
//---}}}

//{SCAR}void DBits_set__Tn_(DBits__Tn_* in_bits, uint32_t in_index, bool in_set) { if (in_set)in_bits->_bits|=(1<<in_index); else in_bits->_bits&=~(1<<in_index); }
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
void DBits_set_8(DBits_8* in_bits, uint32_t in_index, bool in_set) { if (in_set)in_bits->_bits|=(1<<in_index); else in_bits->_bits&=~(1<<in_index); }
void DBits_set_16(DBits_16* in_bits, uint32_t in_index, bool in_set) { if (in_set)in_bits->_bits|=(1<<in_index); else in_bits->_bits&=~(1<<in_index); }
void DBits_set_32(DBits_32* in_bits, uint32_t in_index, bool in_set) { if (in_set)in_bits->_bits|=(1<<in_index); else in_bits->_bits&=~(1<<in_index); }
void DBits_set_64(DBits_64* in_bits, uint32_t in_index, bool in_set) { if (in_set)in_bits->_bits|=(1<<in_index); else in_bits->_bits&=~(1<<in_index); }
//---}}}

//{SCAR}void DBits_flip__Tn_(DBits__Tn_* in_bits, uint32_t in_index) { in_bits->_bits ^= (1 << in_index); }
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
void DBits_flip_8(DBits_8* in_bits, uint32_t in_index) { in_bits->_bits ^= (1 << in_index); }
void DBits_flip_16(DBits_16* in_bits, uint32_t in_index) { in_bits->_bits ^= (1 << in_index); }
void DBits_flip_32(DBits_32* in_bits, uint32_t in_index) { in_bits->_bits ^= (1 << in_index); }
void DBits_flip_64(DBits_64* in_bits, uint32_t in_index) { in_bits->_bits ^= (1 << in_index); }
//---}}}

//{SCAR}bool DBits_get__Tn_(DBits__Tn_* in_bits, uint32_t in_index) { return in_bits->_bits & (1 << in_index); }
//{DESC}:4:_Tn_: 8; 16; 32; 64;
//{SCAR}
//---{{{
bool DBits_get_8(DBits_8* in_bits, uint32_t in_index) { return in_bits->_bits & (1 << in_index); }
bool DBits_get_16(DBits_16* in_bits, uint32_t in_index) { return in_bits->_bits & (1 << in_index); }
bool DBits_get_32(DBits_32* in_bits, uint32_t in_index) { return in_bits->_bits & (1 << in_index); }
bool DBits_get_64(DBits_64* in_bits, uint32_t in_index) { return in_bits->_bits & (1 << in_index); }
//---}}}
