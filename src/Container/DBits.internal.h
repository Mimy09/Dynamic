#pragma once
#include "DBits.h"


//{SCAR}struct DBits__Tn_ { _Tp_ _bits; };
//{DESC}:4:_Tp_: uint8_t; uint16_t; uint32_t; uint64_t;
//{DESC}:4:_Tn_: 8;       16;       32;       64;
//{SCAR}
//---{{{
struct DBits_8 { uint8_t _bits; };
struct DBits_16 { uint16_t _bits; };
struct DBits_32 { uint32_t _bits; };
struct DBits_64 { uint64_t _bits; };
//---}}}
