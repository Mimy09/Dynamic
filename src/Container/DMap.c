#include "DMap.internal.h"

DMap* DMap_create(uint32_t in_k_size, u_int32_t in_v_size) {
	DMap* map = (DMap*)malloc(sizeof(DMap));
	map->_k = DArray_create(in_k_size);
	map->_v = DArray_create(in_v_size);
	return map;
}

void DMap_free(DMap* in_map) {
	if (in_map != NULL) {
		DArray_free(in_map->_k);
		DArray_free(in_map->_v);
		free(in_map);
	}
}

void DMap_pushback(DMap* in_map, void* in_key, void* in_value) {
	DArray_pushback(in_map->_k, in_key);
	DArray_pushback(in_map->_v, in_value);
}
