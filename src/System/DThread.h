#pragma once
#include "DTypes.h"

typedef struct DThread DThread;

// Creates a new thread
DThread* DThread_create(void(*in_func)(DThread*), void* in_args);

// Free the thread from memory
void DThread_free(DThread* in_thread);

// Returns the args passed into the thread
void* DThread_get_args(DThread* in_thread);

// Returns the args passed into the thread
void DThread_set_args(DThread* in_thread, void* in_args);

// Is the thread still running
bool DThread_get_running(DThread* in_thread);

// Stops the thread
void DThread_set_running(DThread* in_thread, bool in_running);

// Joints the thread to the main thread
void DThread_join(DThread* in_thread);

// Gets the return value from the thread
void* DThread_get_return(DThread* in_thread);

// Set the thread return value
void DThread_set_return(DThread* in_thread, void* in_args);
