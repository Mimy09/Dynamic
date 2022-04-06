#include "DLinkList.internal.h"
#include "../Core/DMemory.h"
#include <string.h>

DLinkList* DLinkList_create(uint32_t in_stride) {
	DLinkList* ll = DMalloc(sizeof(DLinkList));
	ll->_size   = 0;
	ll->_head   = NULL;
	ll->_tail   = NULL;
	ll->_stride = in_stride;
	return ll;
}

void DLinkList_free(DLinkList* in_ll) {
	for (uint32_t i = 0; i < in_ll->_size; i++) {
		DFree(DLinkList_get(in_ll, i));
		DFree(DLinkList_node(in_ll, i));
	}
	DFree(in_ll);
}

void DLinkList_remove_at(DLinkList* in_ll, uint32_t in_index) {
	if (in_index == 0) { DLinkList_remove_front(in_ll); return; }
	if (in_index == in_ll->_size) { DLinkList_remove_back(in_ll); return; }

	DLinkList_Node* n = DLinkList_node(in_ll, in_index);

	n->_prev->_next = n->_next;
	n->_next->_prev = n->_prev;
	in_ll->_size--;

	DFree(n->_data);
	DFree(n);
}
void DLinkList_remove_back(DLinkList* in_ll) {
	DLinkList_Node* n = in_ll->_tail;

	n->_prev->_next = NULL;
	in_ll->_tail = n->_prev;
	in_ll->_size--;

	DFree(n->_data);
	DFree(n);
}
void DLinkList_remove_front(DLinkList* in_ll) {
	DLinkList_Node* n = in_ll->_head;

	n->_next->_prev = NULL;
	in_ll->_head = n->_next;
	in_ll->_size--;

	DFree(n->_data);
	DFree(n);
}

void DLinkList_insert_at(DLinkList* in_ll, void* in_value, uint32_t in_index) {
	if (in_index == 0) { DLinkList_insert_front(in_ll, in_value); return; }
	if (in_index == in_ll->_size) { DLinkList_insert_back(in_ll, in_value); return; }

	DLinkList_Node* n = DMalloc(sizeof(DLinkList_Node));
	n->_data = DMalloc(sizeof(in_ll->_stride));
	memcpy(n->_data, in_value, sizeof(in_ll->_stride));

	DLinkList_Node* p = DLinkList_node(in_ll, in_index);
	n->_next = p;
	n->_prev = p->_prev;
	p->_prev->_next = n;
	p->_prev = n;
	in_ll->_size++;
}
void DLinkList_insert_back(DLinkList* in_ll, void* in_value) {
	DLinkList_Node* n = DMalloc(sizeof(DLinkList_Node));
	n->_data = DMalloc(sizeof(in_ll->_stride));
	memcpy(n->_data, in_value, sizeof(in_ll->_stride));
	n->_next = NULL;

	if (in_ll->_head == NULL) {
		n->_prev = NULL;
		in_ll->_head = n;
		in_ll->_tail = n;
	} else {
		n->_prev = in_ll->_tail;
		in_ll->_tail->_next = n;
		in_ll->_tail = n;
	}
	in_ll->_size++;
}
void DLinkList_insert_front(DLinkList* in_ll, void* in_value) {
	DLinkList_Node* n = DMalloc(sizeof(DLinkList_Node));
	n->_data = DMalloc(sizeof(in_ll->_stride));
	memcpy(n->_data, in_value, sizeof(in_ll->_stride));
	n->_prev = NULL;

	if (in_ll->_head == NULL) {
		in_ll->_head = n;
		in_ll->_tail = n;
	} else {
		n->_next = in_ll->_head;
		in_ll->_head->_prev = n;
		
		in_ll->_head = n;
	}
	in_ll->_size++;
}

void* DLinkList_get(DLinkList* in_ll, uint32_t in_index) { return DLinkList_node(in_ll, in_index)->_data; }
DLinkList_Node* DLinkList_head(DLinkList* in_ll) { return in_ll->_head; }
DLinkList_Node* DLinkList_tail(DLinkList* in_ll) { return in_ll->_tail; }
DLinkList_Node* DLinkList_node(DLinkList* in_ll, uint32_t in_index) {
	DLinkList_Node* p = in_ll->_head;
	for (uint32_t i = 0; i < in_index; i++)
		if (p->_next != NULL) p = p->_next; else return NULL;
	return p;
}

DLinkList_Node* DLinkList_Node_next(DLinkList_Node* in_node) { return in_node->_next; }
DLinkList_Node* DLinkList_Node_prev(DLinkList_Node* in_node) { return in_node->_prev; }
void* DLinkList_Node_value(DLinkList_Node* in_node) { return in_node->_data; }
