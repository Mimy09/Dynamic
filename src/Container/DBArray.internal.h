#pragma once
#include "DBArray.h"

struct DBArray {
    uint32_t _stride;
    uint32_t _buffer;
    void* _start;
    void* _end;
    void* _start_alloc;
    void* _end_alloc;
};