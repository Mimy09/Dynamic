#pragma once
#include "DQueue.h"

struct DQueue {
    uint32_t _stride;
    uint32_t _buffer;
    void* _start;
    void* _end;
    void* _start_alloc;
    void* _end_alloc;
};