#pragma once
#include "DArray.h"

struct DArray {
	uint32_t _stride;
	uint32_t _buffer;
	void* _start;
	void* _back;
	void* _end;
};
