#include <stdio.h>
#include <stdlib.h>

#include "Dynamic.h"
#include "Core/DLog.h"
#include "Core/DMemory.h"

// DArray
// {{{
void UT_DArray() {
	// DArray Pushback
	// {{{
	if (0) {
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
	}
	// }}}
	// DArray Removing
	// {{{
	if (0) {
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
	}
	// }}}
	// DArray Append
	// {{{
	if (0) {
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
	}
	// }}}
}
// }}}
// DNetwork
// {{{
void UT_Network() {
	// DNetwork
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
// }}}
// DThread
// {{{
void thread_function(DThread* in_thread) {
	while (DThread_get_running(in_thread)) {
		printf("Thread: %s\n", *(char**)DThread_get_args(in_thread));
		DThread_set_running(in_thread, false);
	}
	DThread_set_return(in_thread, NULL);
}
void UT_Thread() {
	// DThread
	char* _thread_args = "Hello World";
	DThread* thread = DThread_create(thread_function, &_thread_args);
	{
		DThread_join(thread);
	}
	DThread_free(thread);
}
// }}}
// DStr
// {{{
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
// }}}
// DBits
// {{{
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
// }}}
// DEvent
// {{{
void* e_func1(void* in_arg) { DPrint_inf("Called 1"); return NULL; }
void* e_func2(void* in_arg) { DPrint_inf("Called 2"); return NULL; }
void* e_func3(void* in_arg) { DPrint_inf("Called 3"); return NULL; }
void* e_func4(void* in_arg) { DPrint_inf("Called 4"); return NULL; }
void* e_func5(void* in_arg) { DPrint_inf("Called 5"); return NULL; }
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
		DEvent_call(e, "test2");
	}

	DPrint_dbg("DEvent_free");
	DEvent_free(e);
}
// }}}

int main(int argc, char** argv) {
	DPrint_set_level(DPRINT_ALL_FLAG);
	DMemory_begin(true);

	//UT_DArray();
	//UT_Network();
	//UT_Thread();
	//UT_DStr();
	//UT_DBits();
	
	DConsole* con = DConsole_create(argc, argv);
	DConsole_Value con_ser = DConsole_add_bool(con, "--server");
	DConsole_Value con_cli = DConsole_add_bool(con, "--client");
	DConsole_free(con);
	
	if (con_ser._used) {
		DNet* s = DNet_server_create(554433, DNET_TCP);

		while(1) {
			DNetSocket s_c = DNet_server_accept(s);

			char buff[256];
			DNet_read(s_c, buff, 256);
			DPrint_inf(buff);

			if (strstr(buff, "quit")) {
				break;
			}
		}
		
		DNet_free(s);
	}
	if (con_cli._used) {
		DNet* c = DNet_client_create(554433, DNET_TCP);	

		char buff[256];
		fscanf(stdin, "%s", buff);

		DNet_write(DNet_socket(c), buff, 256);

		DNet_free(c);
	}

	

	DMemory_end();
	return 0;
}
