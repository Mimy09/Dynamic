#pragma once
#include "DLinkList.h"

struct DLinkList_Node {
	void* _data;
	struct DLinkList_Node* _next;
	struct DLinkList_Node* _prev;
};

struct DLinkList {
	uint32_t        _size;
	uint32_t        _stride;
	DLinkList_Node* _head;
	DLinkList_Node* _tail;
};
