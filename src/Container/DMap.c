#include "DMap.internal.h"
#include "../Core/DMemory.h"
#include "../Core/DLog.h"

uint64_t DMap_hashing(const char* in_cstr, uint32_t in_size) {
    uint32_t hash = 0;

    for(; *in_cstr; ++in_cstr)
    {
        hash += *in_cstr;
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash % in_size;
}

DMap* DMap_create(uint32_t in_size, uint32_t in_stride) {
	DMap* map = (DMap*)DMalloc(sizeof(DMap));
	map->_data   = DArray_create(sizeof(struct DMap_Node));
	map->_stride = in_stride;

	void* data = DMalloc(in_size * sizeof(struct DMap_Node));
	memset(data, 0, in_size * sizeof(struct DMap_Node));
	DArray_allocate(map->_data, data, in_size);

	for (struct DMap_Node* p = data; p < ((struct DMap_Node*)data) + (in_size ); p++) {
		p->_used = false;
		p->_data = DArray_create(sizeof(struct DMap_Node_Element));
		DArray_buffer(p->_data, 4);
	}

	return map;
}

void DMap_free(DMap* in_map) {
	if (in_map != NULL) {
		for (uint32_t i = 0; i < DArray_size(in_map->_data); i++) {
			struct DMap_Node* n = DArray_get(in_map->_data, i);
			for (uint32_t j = 0; j < DArray_size(n->_data); j++) {
				struct DMap_Node_Element* e = DArray_get(n->_data, j);
				DFree(e->_value);
			}
			DArray_free(n->_data);
		}
		
		DArray_free(in_map->_data);
		DFree(in_map);
	}
}

void DMap_set(DMap* in_map, const char* in_key, void* in_value) {
	uint32_t h = DMap_hashing(in_key, DArray_size(in_map->_data));

	void* p = DMalloc(in_map->_stride);
	memcpy(p, in_value, in_map->_stride);
	struct DMap_Node_Element e = { in_key, p };
	struct DMap_Node* n = DArray_get(in_map->_data, h);
	DArray_pushback(n->_data, &e);
	n->_used = true;
}

void* DMap_get(DMap* in_map, const char* in_key) {
	uint32_t h = DMap_hashing(in_key, DArray_size(in_map->_data));
	struct DMap_Node* n = DArray_get(in_map->_data, h);
	if (!n->_used) return NULL;

	for (uint32_t i = 0; i < DArray_size(n->_data); i++) {
		struct DMap_Node_Element* e = DArray_get(n->_data, i);
		if (strstr(in_key, e->_key) != 0) {
			return e->_value;
		}
	}

	return NULL;
}

bool DMap_remove(DMap* in_map, const char* in_key) {
	uint32_t h = DMap_hashing(in_key, DArray_size(in_map->_data));
	struct DMap_Node* n = DArray_get(in_map->_data, h);
	if (!n->_used) return false;
	for (uint32_t i = 0; i < DArray_size(n->_data); i++) {
		struct DMap_Node_Element* e = DArray_get(n->_data, i);
		if (strstr(in_key, e->_key) != 0) {
			DFree(e->_value);
			DArray_remove_at(n->_data, i);
			if (DArray_size(n->_data) == 0) {
				DArray_clear(n->_data);
				n->_used = false;
			}
			return true;
		}
	}
	return false;
}

void* DMap_index(DMap* in_map, uint32_t in_index, uint32_t in_element) {
	struct DMap_Node* n = DArray_get(in_map->_data, in_index);
	if (!n->_used || in_element >= DArray_size(n->_data)) return NULL;
	return ((struct DMap_Node_Element*)DArray_get(n->_data, in_element))->_value;
}

const char* DMap_index_key(DMap* in_map, uint32_t in_index, uint32_t in_element) {
	struct DMap_Node* n = DArray_get(in_map->_data, in_index);
	if (!n->_used || in_element >= DArray_size(n->_data)) return "";
	return ((struct DMap_Node_Element*)DArray_get(n->_data, in_element))->_key;
}
