#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <math.h>

typedef struct {
    size_t   _size;
    uint8_t* _mask;
} DMetaMask;

DMetaMask DMetaMask_create(size_t size);
DMetaMask DMetaMask_recreate(void* ptr, size_t size);
void  DMetaMask_free(DMetaMask mask);
bool  DMetaMask_get_single(DMetaMask mask, size_t position);
bool* DMetaMask_get_mutiple(DMetaMask mask, uint8_t* ptr);
bool  DMetaMask_set_single(DMetaMask mask, size_t position, bool value);
bool  DMetaMask_set_multiple(DMetaMask mask, bool* arr, size_t size);
void* DMetaMask_get_pointer(DMetaMask mask);
void  DMetaMask_print(DMetaMask mask);
