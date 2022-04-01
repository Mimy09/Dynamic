#include "DThread.internal.h"

void* thread_func(void* in_args) {
	DThread* thread = (DThread*)in_args;
	thread->_func(thread);
	pthread_exit(NULL);
}

DThread* DThread_create(void(*in_func)(DThread*), void* in_args) {
	DThread* thread = (DThread*)malloc(sizeof(DThread));
	thread->_running = true;
	thread->_func = in_func;
	thread->_args = in_args;
	pthread_create(&thread->_thread, NULL, thread_func, (void*)thread);

	return thread;
}

void DThread_free(DThread* in_thread) {
	if (in_thread != NULL) {
		free(in_thread);
	}
}

void* DThread_get_args(DThread* in_thread) {
	return in_thread->_args;
}

void DThread_set_args(DThread* in_thread, void* in_args) {
	in_thread->_args = in_args;
}

bool DThread_get_running(DThread* in_thread) {
	return in_thread->_running;
}

void DThread_set_running(DThread* in_thread, bool in_running) {
	in_thread->_running = in_running;
}

void DThread_join(DThread* in_thread) {
	pthread_join(in_thread->_thread, NULL);
}

void* DThread_get_return(DThread* in_thread) {
	return in_thread->_retn;
}

void DThread_set_return(DThread* in_thread, void* in_args) {
	in_thread->_retn = in_args;
}
