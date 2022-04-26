#include <stdio.h>
#include <stdlib.h>
#include "Dynamic.h"

#include <pthread.h>

#pragma region Unit Tests

#pragma region Array
void UT_DArray() {
	#pragma region Pushback
	#if 0
	DArray* arr = DArray_create(sizeof(char*));
	DArray_buffer(arr, 5);
	printf("S[%d] ",  DArray_size(arr));
	printf("B[%d]\n", DArray_size_buffer(arr));

	DArray_pushback_cstr(arr, "Hello");
	printf("S[%d] ",  DArray_size(arr));
	printf("B[%d]\n", DArray_size_buffer(arr));

	DArray_pushback_cstr(arr, "World");
	printf("S[%d] ",  DArray_size(arr));
	printf("B[%d]\n", DArray_size_buffer(arr));

	DArray_pushback_cstr(arr, "!");
	printf("S[%d] ",  DArray_size(arr));
	printf("B[%d]\n", DArray_size_buffer(arr));

	printf("%s", *DArray_get_cstr(arr, 0));
	printf(" %s", *DArray_get_cstr(arr, 1));
	printf("%s\n", *DArray_get_cstr(arr, 2));
	DArray_free(arr);
	#endif
	#pragma endregion
	#pragma region Removing
	#if 0
	DArray* arr = DArray_create(sizeof(uint32_t));
	DArray_buffer(arr, 5);
	DArray_pushback_u32(arr, 1);
	DArray_pushback_u32(arr, 2);
	DArray_pushback_u32(arr, 3);
	DArray_pushback_u32(arr, 4);
	DArray_pushback_u32(arr, 5);
	printf("S[%d] ",  DArray_size(arr));
	printf("B[%d]\n", DArray_size_buffer(arr));

	for (int i = 0; i < DArray_size(arr); i++)
		printf("%d ", *DArray_get_u32(arr, i));
	puts("");

	DArray_remove_at(arr, 1);
	printf("S[%d] ",  DArray_size(arr));
	printf("B[%d]\n", DArray_size_buffer(arr));

	for (int i = 0; i < DArray_size(arr); i++)
		printf("%d ", *DArray_get_u32(arr, i));
	puts("");

	DArray_remove(arr, 1, 3);
	printf("S[%d] ",  DArray_size(arr));
	printf("B[%d]\n", DArray_size_buffer(arr));

	for (int i = 0; i < DArray_size(arr); i++)
		printf("%d ", *DArray_get_u32(arr, i));
	puts("");
	DArray_free(arr);
	#endif
	#pragma endregion
	#pragma region Append
	#if 0
	DArray* arr = DArray_create(sizeof(uint32_t));
	uint32_t carr_1[4] = { 5, 4, 3, 2 };
	uint32_t carr_2[4] = { 9, 8, 7, 6 };
	DArray_append_u32(arr, carr_1, 4);
	printf("S[%d] ",  DArray_size(arr));
	printf("B[%d]\n", DArray_size_buffer(arr));

	for (int i = 0; i < DArray_size(arr); i++)
		printf("%d ", *DArray_get_u32(arr, i));
	puts("");

	DArray_insert(arr, carr_2, 1, 2);
	printf("S[%d] ",  DArray_size(arr));
	printf("B[%d]\n", DArray_size_buffer(arr));

	for (int i = 0; i < DArray_size(arr); i++)
		printf("%d ", *DArray_get_u32(arr, i));
	puts("");
	DArray_free(arr);
	#endif
	#pragma endregion
}
#pragma endregion
#pragma region Network
void UT_Network() {
	DNet* server = DNet_server_create(55377, DNET_TCP);
	DNet* client = DNet_client_create(55377, DNET_TCP);
	if (server != NULL && client != NULL) {
		DNetSocket server_client = DNet_server_accept(server);
		
		{
			char _buffer[256] = "SERVER: Hello World";
			DNet_write(server_client, _buffer, 256);
		}

		{
			char _buffer[256];
			DNet_read(DNet_socket(client), _buffer, 256);
			printf("C: %s\n", _buffer);
		}

		{
			char _buffer[256] = "CLIENT: Hello World";
			DNet_write(DNet_socket(client), _buffer, 256);
		}

		{
			char _buffer[256];
			DNet_read(server_client, _buffer, 256);
			printf("S: %s\n", _buffer);
		}
	}
	DNet_free(client);
	DNet_free(server);
}
#pragma endregion
#pragma region Thread
void thread_function(DThread* in_thread) {
	while (DThread_get_running(in_thread)) {
		printf("Thread: %s\n", *(char**)DThread_get_args(in_thread));
		DThread_set_running(in_thread, false);
	}
	DThread_set_return(in_thread, NULL);
}
void UT_Thread() {
	char* _thread_args = "Hello World";
	DThread* thread = DThread_create(thread_function, &_thread_args);
	{
		DThread_join(thread);
	}
	DThread_free(thread);
}
#pragma endregion
#pragma region String
void UT_DStr() {
	DStr* str = DStr_create("Hello World! It's a new world!");
	DStr_replace(str, "World", "Test");

	DPrint_inf("%s", DStr_cstr(str) );

	DArray* arr = DStr_split(str, " ");

	for (int i = 0; i < DArray_size(arr); i++)
		DPrint_inf("%s", *DArray_get_cstr(arr, i));

	DStr_split_free(arr);

	if (DStr_contains(str, "world")) {
		DPrint_inf("Contains \"world\"");
	}
	if (DStr_contains(str, "wworld")) {
		DPrint_inf("Contains \"wworld\"");
	}

	DStr_remove_all(str, ' ');

	DPrint_inf("%s", DStr_cstr(str) );


	DStr_free(str);
}
#pragma endregion
#pragma region Bits
void UT_DBits() {
	DBits_8* bit = DBits_create_8();

	for (int i = 0; i < 8; i ++) printf("%d", DBits_get_8(bit, i)); printf("\n");

	DBits_set_8(bit, 0, true);
	DBits_set_8(bit, 7, true);
	DBits_flip_8(bit, 3);
	DBits_flip_8(bit, 3);

	for (int i = 0; i < 8; i ++) printf("%d", DBits_get_8(bit, i)); printf("\n");

	DBits_free_8(bit);
}
#pragma endregion
#pragma region DEvent
void e_func1(void* in_arg) { DPrint_inf("Called 1: %s", *(char**)in_arg); }
void e_func2(void* in_arg) { DPrint_inf("Called 2: %s", *(char**)in_arg); }
void e_func3(void* in_arg) { DPrint_inf("Called 3: %s", *(char**)in_arg); }
void e_func4(void* in_arg) { DPrint_inf("Called 4: %s", *(char**)in_arg); }
void e_func5(void* in_arg) { DPrint_inf("Called 5: %s", *(char**)in_arg); }
void UT_DEvent() {
	DPrint_dbg("DEvent_create");
	DEvent* e = DEvent_create(9);

	{
		DPrint_dbg("DEvent_add");
		DEvent_add(e, "test2", e_func1);
		DPrint_dbg("DEvent_add");
		DEvent_add(e, "test2", e_func2);
		DPrint_dbg("DEvent_add");
		DEvent_add(e, "test2", e_func3);
		DPrint_dbg("DEvent_add");
		DEvent_add(e, "test3", e_func4);
		DPrint_dbg("DEvent_add");
		DEvent_add(e, "test3", e_func5);
	}
	{
		DPrint_dbg("DEvent_call");
		DEvent_call_cstr(e, "test2", "test");
	}

	DPrint_dbg("DEvent_free");
	DEvent_free(e);
}
#pragma endregion

#pragma endregion


int main(int argc, char** argv) {
	DPrint_set_level(DPRINT_ALL_FLAG);
	DMemory_begin(false);


	DMemory_end();
	return 0;
}
