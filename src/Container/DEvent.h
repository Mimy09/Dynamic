#pragma once
#include "../System/DTypes.h"

typedef struct DEvent DEvent;

// Create a new event system
DEvent* DEvent_create(uint32_t in_size);

// Free the event system
void DEvent_free(DEvent* in_e);

// Add a new callabck to the event system
void DEvent_add(DEvent* in_e, const char* in_event, void*(*in_func)(void*));

// Call an event
void DEvent_call(DEvent* in_e, const char* in_event);
