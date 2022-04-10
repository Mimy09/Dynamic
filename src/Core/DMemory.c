#include "DMemory.h"
#ifdef DEBUG
#include "DLog.h"
#include <string.h>
#include <stdio.h>
#include <errno.h>

DArray* g_DMemory           = NULL;
DArray* g_DMemory_trace     = NULL;
bool    g_DMemory_enabled   = true;
bool    g_DMemory_logging   = false;

// Disable managed memory for DArray
#define DYNAMIC_UNSAFE if (!g_DMemory_enabled || g_DMemory == NULL)
#define DYNAMIC_UNSAFE_START g_DMemory_enabled = false;
#define DYNAMIC_UNSAFE_END   g_DMemory_enabled = true;

#define DYNAMIC_MEMORY_LOG(type, ptr, size, color)\
    if (g_DMemory_logging) {\
		DStr* trace = DStr_create(NULL); DPrint_get_trace(trace, true);\
		printf (color type COL_BOLDWHITE " = %p" COL_RESET "[%u]   \t%s\n" COL_RESET, ptr, size, DStr_cstr(trace));\
		DStr_free(trace);\
	} 

void DMemory_begin(bool in_logging) {
    DPrint_dbg("DMemory begin...");
    DYNAMIC_UNSAFE_START
    g_DMemory  		= DArray_create(sizeof(uint64_t));
    g_DMemory_trace = DArray_create(sizeof(DStr*));
	DArray_buffer(g_DMemory, 10);
	DArray_buffer(g_DMemory_trace, 10);
    g_DMemory_logging = in_logging;
	DYNAMIC_UNSAFE_END
}
void DMemory_end() {
    DYNAMIC_UNSAFE_START
    uint32_t allocated = DArray_size(g_DMemory);
    
    if (allocated > 0) {
        DPrint_wrn("DMemory_end...");
        for (int i = 0; i < allocated; i++) {
            printf("\t0x%lx -> %s\n", *DArray_get_u64(g_DMemory, i), DStr_cstr(*(DStr**)DArray_get(g_DMemory_trace, i)));
        }
    } else {
        DPrint_dbg("DMemory end...");
    }
    DArray_free(g_DMemory);
	for (int i = 0; i < DArray_size(g_DMemory_trace); i++)
		DStr_free(*(DStr**)DArray_get(g_DMemory_trace, i));
    DArray_free(g_DMemory_trace);
	DYNAMIC_UNSAFE_END
}

void DMemory_logging(bool in_logging) {
	g_DMemory_logging = in_logging;
}

void DMemory_add(void* in_ptr) {
    if (g_DMemory == NULL) return;
	uint64_t ptr = (uint64_t)in_ptr;
    DArray_pushback_u64(g_DMemory, ptr);
	DStr* buff = DStr_create(NULL);
	DPrint_get_trace(buff, true);
    DArray_pushback(g_DMemory_trace, &buff);
}
void DMemory_free(void* in_ptr) {
    if (g_DMemory == NULL) return;
    uint64_t ptr = (uint64_t)in_ptr;
    for (int i = 0; i < DArray_size(g_DMemory); i++) {
        if (*DArray_get_u64(g_DMemory, i) == ptr) {
            DArray_remove_at(g_DMemory, i);
			DStr_free(*(DStr**)DArray_get(g_DMemory_trace, i));
			DArray_remove_at(g_DMemory_trace, i);
			break;
        }
    }
}

void* DMalloc (uint32_t in_size) {
    DYNAMIC_UNSAFE { return malloc(in_size); }
    DYNAMIC_UNSAFE_START

    void* ptr = malloc(in_size);
    DYNAMIC_MEMORY_LOG("malloc    ", ptr, in_size, COL_GREEN);
    DMemory_add(ptr);

    DYNAMIC_UNSAFE_END
    return ptr;
}
void* DCalloc (uint32_t in_nmemb, uint32_t in_size) {
    DYNAMIC_UNSAFE { return calloc(in_nmemb, in_size); }
    DYNAMIC_UNSAFE_START

    void* ptr = calloc(in_nmemb, in_size);
	if (errno == ENOMEM) {
		DPrint_err("DCalloc: Alloc size overflowed");
		return NULL;
	}
    DYNAMIC_MEMORY_LOG("calloc    ", ptr, in_size, COL_GREEN);
    DMemory_add(ptr);

    DYNAMIC_UNSAFE_END
    return ptr;
}
void* DRealloc (void* in_ptr, uint32_t in_size) {
    DYNAMIC_UNSAFE { return realloc(in_ptr, in_size); }
    DYNAMIC_UNSAFE_START

    DMemory_free(in_ptr);
    void* ptr = realloc(in_ptr, in_size);
    DYNAMIC_MEMORY_LOG("realloc   ", ptr, in_size, COL_MAGENTA);
    DMemory_add(ptr);

    DYNAMIC_UNSAFE_END
    return ptr;
}
void* DReallocArr (void* in_ptr, uint32_t in_nmemb, uint32_t in_size) {
    DYNAMIC_UNSAFE { return reallocarray(in_ptr, in_nmemb, in_size); }
    DYNAMIC_UNSAFE_START

    DMemory_free(in_ptr);
	if (errno == ENOMEM) {
		DPrint_err("DCalloc: reallocarr size overflowed");
		return NULL;
	}
    void* ptr = reallocarray(in_ptr, in_nmemb, in_size);
    DYNAMIC_MEMORY_LOG("reallocarr", ptr, in_size, COL_MAGENTA);
    DMemory_add(ptr);

    DYNAMIC_UNSAFE_END
    return ptr;
}
void DFree (void* in_ptr) {
    DYNAMIC_UNSAFE { free(in_ptr); return; }
    DYNAMIC_UNSAFE_START

    DMemory_free(in_ptr);
    DYNAMIC_MEMORY_LOG("free      ", in_ptr, 0, COL_RED);
    free(in_ptr);

    DYNAMIC_UNSAFE_END
}

void DMemory_print() {
	for (int i = 0; i < DArray_size(g_DMemory); i++) {
		printf("\t0x%lx -> %s\n", *DArray_get_u64(g_DMemory, i), DStr_cstr(*(DStr**)DArray_get(g_DMemory_trace, i)));
	}
}
#endif
