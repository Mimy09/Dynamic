#include <stdlib.h>
#include <string.h>
#include "DQueue.internal.h"
#include "DArray.internal.h"
#include "../Core/DMemory.h"
#include "../Core/DLog.h"

DQueue* DQueue_create(uint32_t in_stride) {
    DQueue* arr      = DMalloc(sizeof(DQueue));
    arr->_start       = NULL;
    arr->_end         = NULL;
    arr->_start_alloc = NULL;
    arr->_end_alloc   = NULL;
    arr->_buffer      = in_stride * 10;
    arr->_stride      = in_stride;
    return arr;
}

void DQueue_free(DQueue* in_arr) {
    if (in_arr != NULL) {
        if (in_arr->_start_alloc != NULL)
            DFree(in_arr->_start_alloc);
        DFree(in_arr);
    }
}

void DQueue_buffer(DQueue* in_arr, uint32_t in_buffer) {
    in_arr->_buffer = (in_buffer - 1) * in_arr->_stride;
}

uint32_t DQueue_size(DQueue* in_arr) {
    if (in_arr->_end == in_arr->_start) return 0;
    if (in_arr->_end > in_arr->_start) {
        return (in_arr->_end - in_arr->_start) / in_arr->_stride;
    } else {
        return ((in_arr->_end_alloc - in_arr->_start) + (in_arr->_end - in_arr->_start_alloc)) / in_arr->_stride;
    }
}
uint32_t DQueue_size_buffer(DQueue* in_arr) {
    if (in_arr->_end == in_arr->_start)
        return (in_arr->_end_alloc - in_arr->_start_alloc) / in_arr->_stride;
    if (in_arr->_end > in_arr->_start) {
        return ((in_arr->_end_alloc - in_arr->_end) + (in_arr->_start - in_arr->_start_alloc)) / in_arr->_stride;
    } else {
        return (in_arr->_start - in_arr->_end) / in_arr->_stride;
    }
}

void DQueue_pushback(DQueue* in_arr, void* in_value) {
	if (in_value == NULL) return;

	if (in_arr->_start_alloc == NULL) {
        DPrint_dbg("DQueue_pushback: in_arr->_start_alloc == NULL");
		in_arr->_start_alloc = DMalloc(in_arr->_stride + in_arr->_buffer);
        in_arr->_start       = in_arr->_start_alloc;
		in_arr->_end         = in_arr->_start_alloc;
		in_arr->_end_alloc   = in_arr->_start_alloc + in_arr->_stride + in_arr->_buffer;
    } else {
        if (in_arr->_end == in_arr->_end_alloc) {
            if (in_arr->_start_alloc == in_arr->_start) {
                DPrint_dbg("DQueue_pushback: in_arr->_end == in_arr->_end_alloc");
                uint32_t _size       = in_arr->_end_alloc - in_arr->_start_alloc;
                in_arr->_start_alloc = DRealloc(in_arr->_start_alloc, _size + in_arr->_stride + in_arr->_buffer);
                in_arr->_start       = in_arr->_start_alloc;
                in_arr->_end         = in_arr->_start_alloc + _size;
                in_arr->_end_alloc   = in_arr->_start_alloc + _size + in_arr->_stride + in_arr->_buffer;
            } else {
                in_arr->_end         = in_arr->_start_alloc;
            }
        } else if (in_arr->_end + in_arr->_stride == in_arr->_end_alloc) {
            if (in_arr->_start_alloc == in_arr->_start) {
                DPrint_dbg("DQueue_pushback: in_arr->_start_alloc == in_arr->_start");
                uint32_t _size       = in_arr->_end_alloc - in_arr->_start_alloc;
                in_arr->_start_alloc = DRealloc(in_arr->_start_alloc, _size + in_arr->_stride + in_arr->_buffer);
                in_arr->_start       = in_arr->_start_alloc;
                in_arr->_end         = in_arr->_start_alloc + _size - in_arr->_stride;
                in_arr->_end_alloc   = in_arr->_start_alloc + _size + in_arr->_stride + in_arr->_buffer;
            }
        } else if (in_arr->_end + in_arr->_stride == in_arr->_start) {
            DPrint_dbg("DQueue_pushback: in_arr->_end + in_arr->_stride == in_arr->_start");
            uint32_t _size = in_arr->_end_alloc - in_arr->_start_alloc;
            uint32_t _size_r = (in_arr->_end_alloc - in_arr->_start);
            uint32_t _size_l = (in_arr->_end - in_arr->_start_alloc);
            void* _tmp = DMalloc(_size + in_arr->_stride + in_arr->_buffer);
            memcpy(_tmp, in_arr->_start, _size_r);
            memcpy(_tmp + _size_r, in_arr->_start_alloc, _size_l);
            DFree(in_arr->_start_alloc);
            in_arr->_start_alloc = _tmp;
            in_arr->_start       = in_arr->_start_alloc;
            in_arr->_end         = in_arr->_start_alloc + _size - in_arr->_stride;
            in_arr->_end_alloc   = in_arr->_start_alloc + _size + in_arr->_stride + in_arr->_buffer;
        }
    }

	memmove(in_arr->_end, in_value, in_arr->_stride);
	in_arr->_end += in_arr->_stride;

    if (in_arr->_end == in_arr->_end_alloc) {
        in_arr->_end = in_arr->_start_alloc;
    }
}
void DQueue_popback(DQueue* in_arr) {
    if (in_arr->_end != in_arr->_start) {
        if (in_arr->_end == in_arr->_start_alloc) {
            in_arr->_end = in_arr->_end_alloc;
        } else {
            in_arr->_end -= in_arr->_stride;
        }
    }
}
void DQueue_pushfront(DQueue* in_arr, void* in_value) {
    if (in_arr->_start_alloc == NULL) {
        DPrint_dbg("DQueue_pushfront: in_arr->_start_alloc == NULL");
		in_arr->_start_alloc = DMalloc(in_arr->_stride + in_arr->_buffer);
		in_arr->_end         = in_arr->_start_alloc;
		in_arr->_end_alloc   = in_arr->_start_alloc + in_arr->_stride + in_arr->_buffer;
        in_arr->_start       = in_arr->_end_alloc;
    } else {
        if (in_arr->_start - in_arr->_stride == in_arr->_end) {
            if (in_arr->_end == in_arr->_start_alloc) {
                DPrint_dbg("DQueue_pushfront: in_arr->_end == in_arr->_start_alloc");
                memmove(in_arr->_start_alloc, in_value, in_arr->_stride);
                uint32_t _size = in_arr->_end_alloc - in_arr->_start_alloc + in_arr->_stride;
                in_arr->_start_alloc = DRealloc(in_arr->_start_alloc, _size + in_arr->_buffer);
                in_arr->_end         = in_arr->_start_alloc + _size - in_arr->_stride;
                in_arr->_end_alloc   = in_arr->_start_alloc + _size + in_arr->_buffer;
                in_arr->_start       = in_arr->_end_alloc;
                return;
            } else {
                DPrint_dbg("DQueue_pushfront: in_arr->_end != in_arr->_start_alloc");
                uint32_t _size = in_arr->_end_alloc - in_arr->_start_alloc;
                uint32_t _size_r = (in_arr->_end_alloc - in_arr->_start);
                uint32_t _size_l = (in_arr->_end - in_arr->_start_alloc);
                void* _tmp = DMalloc(_size + in_arr->_stride + in_arr->_buffer);
                memcpy(_tmp, in_arr->_start, _size_r);
                memcpy(_tmp + _size_r, in_arr->_start_alloc, _size_l);
                DFree(in_arr->_start_alloc);
                in_arr->_start_alloc = _tmp;
                in_arr->_end         = in_arr->_start_alloc + _size - in_arr->_stride;
                in_arr->_end_alloc   = in_arr->_start_alloc + _size + in_arr->_stride + in_arr->_buffer;
                in_arr->_start       = in_arr->_end_alloc;
            }
        } else if (in_arr->_start == in_arr->_start_alloc) {
            in_arr->_start = in_arr->_end_alloc;

            if (in_arr->_end == in_arr->_end_alloc) {
                DPrint_dbg("DQueue_pushfront: in_arr->_end == in_arr->_end_alloc");
                uint32_t _size       = in_arr->_end_alloc - in_arr->_start_alloc;
                in_arr->_start_alloc = DRealloc(in_arr->_start_alloc, _size + in_arr->_stride + in_arr->_buffer);
                in_arr->_end         = in_arr->_start_alloc + _size;
                in_arr->_end_alloc   = in_arr->_start_alloc + _size + in_arr->_stride + in_arr->_buffer;
                in_arr->_start       = in_arr->_end_alloc;
            }

            if (in_arr->_end + in_arr->_stride == in_arr->_end_alloc) {
                DPrint_dbg("DQueue_pushfront: in_arr->_end + in_arr->_stride == in_arr->_end_alloc");
                uint32_t _size       = in_arr->_end_alloc - in_arr->_start_alloc;
                in_arr->_start_alloc = DRealloc(in_arr->_start_alloc, _size + in_arr->_stride + in_arr->_buffer);
                in_arr->_end         = in_arr->_start_alloc + _size - in_arr->_stride;
                in_arr->_end_alloc   = in_arr->_start_alloc + _size + in_arr->_stride + in_arr->_buffer;
                in_arr->_start       = in_arr->_end_alloc;
            }
        }
    }
    
    in_arr->_start -= in_arr->_stride;
    memmove(in_arr->_start, in_value, in_arr->_stride);
}
void DQueue_popfront(DQueue* in_arr) {
    if (in_arr->_start != in_arr->_end) {
        if (in_arr->_start + in_arr->_stride == in_arr->_end_alloc) {
            in_arr->_start = in_arr->_start_alloc;
        } else {
            in_arr->_start += in_arr->_stride;
        }
    }
}

void* DQueue_get(DQueue* in_arr, uint32_t in_index) {
    if (in_arr->_start == in_arr->_end) return NULL;
    if (in_index > DQueue_size(in_arr) - 1) return NULL;

    in_index *= in_arr->_stride;
    if (in_index > in_arr->_end_alloc - in_arr->_start_alloc) return NULL;
    
    if (in_arr->_start + in_index >= in_arr->_end_alloc) {
        in_index -= in_arr->_end_alloc - in_arr->_start;
        return in_arr->_start_alloc + in_index;
    } else {
        return in_arr->_start + in_index;
    }
}
void* DQueue_get_real(DQueue* in_arr, uint32_t in_index) {
    in_index *= in_arr->_stride;
    
    if (in_index > in_arr->_end_alloc - in_arr->_start_alloc) return NULL;
    if (in_arr->_end >= in_arr->_start) {
        if (in_index < in_arr->_start - in_arr->_start_alloc) return NULL;
        if (in_index > in_arr->_end - in_arr->_start_alloc - in_arr->_stride) return NULL;
    } else {
        if (
            in_index > in_arr->_end - in_arr->_start_alloc - in_arr->_stride &&
            in_index < in_arr->_start - in_arr->_start_alloc
        ) return NULL;
    }
    return in_arr->_start_alloc + in_index;
}

void* DQueue_begin(DQueue* in_arr) {
    return in_arr->_start;
}
void* DQueue_begin_alloc(DQueue* in_arr) {
    return in_arr->_start_alloc;
}
void* DQueue_end(DQueue* in_arr) {
    return in_arr->_end;
}
void* DQueue_end_alloc(DQueue* in_arr) {
    return in_arr->_end_alloc;
}
uint32_t DQueue_stride(DQueue* in_arr) {
    return in_arr->_stride;
}

DArray* DQueue_to_DArray(DQueue* in_arr) {
    uint32_t _size_r = (in_arr->_end_alloc - in_arr->_start);
    uint32_t _size_l = (in_arr->_end - in_arr->_start_alloc);
    void* _tmp = DMalloc(_size_r + _size_l);
    memcpy(_tmp, in_arr->_start, _size_r);
    memcpy(_tmp + _size_r, in_arr->_start_alloc, _size_l);
    DArray* arr = DArray_create(in_arr->_stride);
    DArray_allocate(arr, _tmp, (_size_r + _size_l) / in_arr->_stride);

    return arr;
}
DQueue* DArray_to_DQueue(DArray* in_arr) {
    DQueue* arr = DQueue_create(in_arr->_stride);
    arr->_start_alloc = DMalloc(in_arr->_back - in_arr->_start + arr->_buffer);
    memcpy(arr->_start_alloc, in_arr->_start, in_arr->_back - in_arr->_start);
    arr->_start       = arr->_start_alloc;
	arr->_end         = arr->_start_alloc + (in_arr->_back - in_arr->_start);
	arr->_end_alloc   = arr->_end + arr->_buffer;

    return arr;
}
DArray* DQueue_convert_to_DArray(DQueue* in_arr) {
    if (in_arr->_start != in_arr->_start_alloc) {
        uint32_t _size_r = (in_arr->_end_alloc - in_arr->_start);
        uint32_t _size_l = (in_arr->_end - in_arr->_start_alloc);
        void* _tmp = DMalloc(_size_r + _size_l);
        memcpy(_tmp, in_arr->_start, _size_r);
        memcpy(_tmp + _size_r, in_arr->_start_alloc, _size_l);
        DArray* arr = DArray_create(in_arr->_stride);
        DArray_allocate(arr, _tmp, (_size_r + _size_l) / in_arr->_stride);
        DFree(in_arr->_start_alloc);
        DFree(in_arr);
        return arr;
    } else {
        DArray* arr = DArray_create(in_arr->_stride);
        arr->_start = in_arr->_start_alloc;
        arr->_back  = in_arr->_end;
        arr->_end   = in_arr->_end_alloc;
        DFree(in_arr);
    }
}
DQueue* DArray_convert_to_DQueue(DArray* in_arr) {
    DQueue* arr = DQueue_create(in_arr->_stride);
    arr->_start_alloc = in_arr->_start;
    arr->_start       = in_arr->_start;
	arr->_end         = in_arr->_back;
	arr->_end_alloc   = in_arr->_end;
    DFree(in_arr);
    return arr;
}

void DQueue_clear(DQueue* in_arr) {
    in_arr->_end = in_arr->_start_alloc;
    in_arr->_start = in_arr->_start_alloc;
}
