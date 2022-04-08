#pragma once
#include "../System/DTypes.h"
#include <stdlib.h>

typedef struct DLinkList DLinkList;
typedef struct DLinkList_Node DLinkList_Node;

// Creates a new linked list
DLinkList* DLinkList_create(uint32_t in_stride);

// Frees the linked list
void DLinkList_free(DLinkList* in_ll);

void DLinkList_remove_at(DLinkList* in_ll, uint32_t in_index);
void DLinkList_remove_back(DLinkList* in_ll);
void DLinkList_remove_front(DLinkList* in_ll);

void DLinkList_insert_at(DLinkList* in_ll, void* in_value, uint32_t in_index);
void DLinkList_insert_back(DLinkList* in_ll, void* in_value);
void DLinkList_insert_front(DLinkList* in_ll, void* in_value);

void* DLinkList_get(DLinkList* in_ll, uint32_t in_index);

DLinkList_Node* DLinkList_node(DLinkList* in_ll, uint32_t in_index);
DLinkList_Node* DLinkList_head(DLinkList* in_ll);
DLinkList_Node* DLinkList_tail(DLinkList* in_ll);

DLinkList_Node* DLinkList_Node_next(DLinkList_Node* in_node);
DLinkList_Node* DLinkList_Node_prev(DLinkList_Node* in_node);
void* DLinkList_Node_value(DLinkList_Node* in_node);

