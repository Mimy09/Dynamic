#pragma once
#include "DThread.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>

struct DThread {
	pthread_t      _thread;
	volatile bool  _running;
	volatile void* _args;
	volatile void* _retn;
	void(*_func)(DThread*);
};
