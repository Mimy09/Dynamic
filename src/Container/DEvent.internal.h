#pragma once
#include "DMap.h"
#include "DArray.h"
#include "DEvent.h"

struct DEvent {
	// <char*, DArray<void*()(void*)>>
	struct DMap* _events;
};
