#pragma once
#include "DArray.h"
#include <stdbool.h>

typedef struct DMap DMap;


uint64_t DMap_hashing(const char* in_cstr, uint32_t in_size);

// Creates a new map
DMap* DMap_create(uint32_t in_size);

// Free the map from memory
void DMap_free(DMap* in_map);

// Push back a new value to the map
void DMap_set(DMap* in_map, const char* in_key, void* in_value);

// Get the element at the keys posistion
void* DMap_get(DMap* in_map, const char* in_key);

// Removes the element using the key
bool DMap_remove(DMap* in_map, const char* in_key);

// Get by the index in the map
void* DMap_index(DMap* in_map, uint32_t in_index, uint32_t in_element);
