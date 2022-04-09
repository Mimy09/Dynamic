#ifndef _DYNAMIC_MEMORY_H_
#define _DYNAMIC_MEMORY_H_
#include "../System/DTypes.h"

void DMemory_begin(bool in_logging);
void DMemory_end();

// Turns logging on or off
void  DMemory_logging(bool in_logging);
// Allocate SIZE bytes in memory
void* DMalloc     (uint32_t in_size);
// Allocate NMEMB elements of SIZE bytes each, all initialized to 0
void* DCalloc     (uint32_t in_nmemb, uint32_t in_size);
// Re-allocates the previously allocated block in PTR, making the new block SIZE bytes long
void* DRealloc    (void* in_ptr, uint32_t in_size);
// Re-allocates the previously allocated block in PTR, making the new block SIZE bytes long
void* DReallocArr (void* in_ptr, uint32_t in_nmemb, uint32_t in_size);
// Free a block allocated by 'malloc', 'realloc' or 'calloc'
void  DFree       (void* in_ptr);
// Prints the currently allocated memory
void DMemory_print();
#endif
