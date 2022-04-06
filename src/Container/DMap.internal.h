#pragma once
#include "DMap.h"

struct DMap_Node_Element {
	const char* _key;
	void*  	 	_value;
};

struct DMap_Node {
	bool 	_used;
	DArray* _data;
};

struct DMap {
	DArray*  _data;
	uint32_t _stride;
};
