#include "DArray.internal.h"
#include "../Core/DMemory.h"
#include "../Core/DLog.h"

DArray* DArray_create(uint32_t in_stride) {
	DArray* arr = (DArray*)DMalloc(sizeof(DArray));
	arr->_stride = in_stride;
	arr->_buffer = 0;
	arr->_start  = NULL;
	arr->_back   = NULL;
	arr->_end    = NULL;
	return arr;
}
void DArray_free(DArray* in_arr) {
	if (in_arr != NULL) {
		if (in_arr->_start != NULL)
			DFree(in_arr->_start);
		in_arr->_start = NULL;
		DFree(in_arr);
		in_arr = NULL;
	}
}
void DArray_free_elements(DArray* in_arr) {
	for (int i = 0; i < DArray_size(in_arr); i++)
		free(in_arr->_start + (i * in_arr->_stride));
	in_arr->_start = NULL;
}

void DArray_remove(DArray* in_arr, uint32_t in_begin, u_int32_t in_end) {
	uint32_t right = in_arr->_back - (in_arr->_start + ((in_end) * in_arr->_stride));
	memmove(in_arr->_start + (in_begin * in_arr->_stride), in_arr->_start + ((in_end) * in_arr->_stride), right);
	in_arr->_back -= in_arr->_stride * (in_end - in_begin);
}

void DArray_remove_at(DArray* in_arr, uint32_t in_index) {
	uint32_t right = in_arr->_back - (in_arr->_start + ((in_index + 1) * in_arr->_stride));
	memmove(in_arr->_start + (in_index * in_arr->_stride), in_arr->_start + ((in_index + 1) * in_arr->_stride), right);
	in_arr->_back -= in_arr->_stride;
}

void DArray_buffer(DArray* in_arr, uint32_t in_buffer) {
	in_arr->_buffer = in_buffer * in_arr->_stride;
}

void DArray_allocate(DArray* in_arr, void* in_data, uint32_t in_size) {
	in_arr->_start  = in_data;
	in_arr->_back   = in_data + (in_size * in_arr->_stride);
	in_arr->_end    = in_arr->_back;
}

void DArray_popback(DArray* in_arr) {
	if (in_arr->_back - in_arr->_start > 0) {
		in_arr->_back -= in_arr->_stride;
	}
}

void DArray_clear(DArray* in_arr) {
	if (in_arr->_start != NULL) {
		DFree(in_arr->_start);
		in_arr->_start = NULL;
		in_arr->_back  = NULL;
		in_arr->_end   = NULL;
	}
}

void DArray_pushback(DArray* in_arr, void* in_value) {
	if (in_value == NULL) return;

	if (in_arr->_start == NULL) {
		in_arr->_start = DMalloc(in_arr->_stride + in_arr->_buffer);
		in_arr->_back  = in_arr->_start;
		in_arr->_end   = in_arr->_start + in_arr->_stride + in_arr->_buffer;

	} else if (in_arr->_back >= in_arr->_end) {
		uint32_t _size = in_arr->_back - in_arr->_start;
		in_arr->_start = DRealloc(in_arr->_start, _size + in_arr->_stride + in_arr->_buffer);
		in_arr->_back  = in_arr->_start + _size;
		in_arr->_end   = in_arr->_start + _size + in_arr->_stride + in_arr->_buffer;
	}

	memmove(in_arr->_back, in_value, in_arr->_stride);
	in_arr->_back += in_arr->_stride;
}

void DArray_append(DArray* in_arr, void* in_value, uint32_t in_size) {
	if (in_value == NULL) return;

	if (in_arr->_start == NULL) {
		in_arr->_start = DMalloc((in_size * in_arr->_stride) + in_arr->_buffer);
		in_arr->_back  = in_arr->_start;
		in_arr->_end   = in_arr->_start + (in_size * in_arr->_stride) + in_arr->_buffer;
	} else if (in_arr->_back + (in_size * in_arr->_stride) >= in_arr->_end) {
		uint32_t _size = in_arr->_back - in_arr->_start;
		in_arr->_start = DRealloc(in_arr->_start, _size + (in_size * in_arr->_stride) + in_arr->_buffer);
		in_arr->_back  = in_arr->_start + _size;
		in_arr->_end   = in_arr->_start + _size + (in_size * in_arr->_stride) + in_arr->_buffer;
	}
	memmove(in_arr->_back, in_value, in_size * in_arr->_stride);
	in_arr->_back += in_size * in_arr->_stride;
}

void DArray_insert(DArray* in_arr, void* in_value, u_int32_t in_size, uint32_t in_index) {
	uint32_t _new_size = (DArray_size(in_arr) + in_size) * in_arr->_stride;

	void* _new = DMalloc(_new_size);
	uint32_t _size_left  = in_index * in_arr->_stride;
	uint32_t _size_right = in_arr->_back - (in_arr->_start + (in_index * in_arr->_stride));
	
	memcpy(_new, in_arr->_start, _size_left);
	memcpy(_new + _size_left, in_value, in_size * in_arr->_stride);
	memcpy(_new + _size_left + (in_size * in_arr->_stride), in_arr->_start + _size_left, _size_right);

	DFree(in_arr->_start);

	in_arr->_start = _new;
	in_arr->_back  = in_arr->_start + _new_size;
	in_arr->_end   = in_arr->_back;
}

void DArray_put(DArray* in_arr, void* in_value, uint32_t in_index) {
	DArray_insert(in_arr, in_value, 1, in_index);
}

void* DArray_get(DArray* in_arr, uint32_t in_index) {
	return (in_arr->_start + (in_index * in_arr->_stride));
}

void DArray_set(DArray* in_arr, uint32_t in_index, void* in_value) {
	void* _dest = in_arr->_start + (in_index * in_arr->_stride);
	memcpy(_dest, in_value, in_arr->_stride);
}

uint32_t DArray_size(DArray* in_arr) {
	return (in_arr->_back - in_arr->_start) / in_arr->_stride;
}
uint32_t DArray_stride(DArray* in_arr) {
	return in_arr->_stride;
}
uint32_t DArray_size_buffer(DArray* in_arr) {
	return (in_arr->_end - in_arr->_back) / in_arr->_stride;
}

void* DArray_begin(DArray* in_arr) {
	return in_arr->_start;
}

void* DArray_end(DArray* in_arr) {
	return in_arr->_back - in_arr->_stride;
}
