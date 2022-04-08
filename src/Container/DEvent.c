#include "DEvent.internal.h"
#include "../Core/DMemory.h"
#include "../Core/DLog.h"


DEvent* DEvent_create(uint32_t in_size) {
	DEvent* event = DMalloc(sizeof(DEvent));
	event->_events = DMap_create(in_size, sizeof(DArray*));

	return event;
}

void DEvent_free(DEvent* in_e) {
	for (uint32_t i = 0; i < DMap_size(in_e->_events); i++) {
		DArray** arr = NULL; uint32_t j = 0;
		while ((arr = (DArray**)DMap_index(in_e->_events, i, j)) != NULL) {
			if (arr != NULL) DArray_free(*arr);
			else break;
			j++;
		}
	}
	DMap_free(in_e->_events);
	DFree(in_e);
}

void DEvent_add(DEvent* in_e, const char* in_event, void*(*in_func)(void*)) {
	if (DMap_get(in_e->_events, in_event) == NULL) {
		DArray* arr = DArray_create(sizeof(void*(*)(void*)));
		DArray_buffer(arr, 4);
		DArray_pushback(arr, &in_func);
		DMap_set(in_e->_events, in_event, &arr);
	} else {
		DArray_pushback(*(DArray**)DMap_get(in_e->_events, in_event), &in_func);
	}
}

void DEvent_call(DEvent* in_e, const char* in_event) {
	DArray** arr = DMap_get(in_e->_events, in_event);
	if (arr != NULL) {
		for (uint32_t i = 0; i < DArray_size(*arr); i++) {
			(*((void*(**)(void*))DArray_get(*arr, i)))(NULL);
		}
	}
}
