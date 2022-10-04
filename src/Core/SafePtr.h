#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <math.h>

#include "DLog.h"

typedef struct {
    uint8_t  _refr;
    uint8_t  _pfsz;
    void**   _pfre;
    void*    _chek;
} _sptr_meta_t;
typedef struct {
    _sptr_meta_t _meta;
    void*        _data;
} _sptr_t;

#define safe(Type) __attribute__((cleanup(_sptr_free))) Type*
#define safe_child(Type) Type*
#define safe_return(Val) return (__typeof__(Val))_sptr_return(Val)
#define safe_add(Type, Ptr, ...) ({ \
    struct _sptr_tmp_t { Type _data; } _tmp = { __VA_ARGS__ }; \
    void* _ptr = _sptr_add(&_tmp._data, Ptr, sizeof(Type)); (Type*)_ptr; })
#define safe_ptr(Type, ...) ({ \
    struct _sptr_tmp_t { __typeof__(Type) _data; } _tmp = { __VA_ARGS__ }; \
    void* _ptr = _sptr_make(&_tmp._data, sizeof(Type)); (Type*)_ptr; })
#define safe_arr(Type, Len, ...) ({ \
    struct _sptr_tmp_t {  __typeof__(__typeof__(Type)[Len]) _data; } _tmp = { __VA_ARGS__ }; \
    void* _ptr = _sptr_make(&_tmp._data, sizeof(Type) * Len); (Type*)_ptr; })

_sptr_t* _sptr_get_meta(void* ptr);
void*    _sptr_make(void* data, size_t size);
void     _sptr_free(void* ptr);
void*    _sptr_return(void* ptr);
void*    _sptr_add(void* child, void* ptr, size_t size);
