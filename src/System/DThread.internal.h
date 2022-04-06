#pragma once
#include "DThread.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdlib.h>

struct DThread {
	pthread_t      _thread;
	volatile bool  _running;
	void* _args;
	void* _retn;
	void(*_func)(DThread*);
};
