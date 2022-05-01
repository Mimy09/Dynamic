#include <stdio.h>
#include <stdlib.h>
#include "Dynamic.h"

#include <pthread.h>

#pragma region Unit Tests

#pragma region Array
// {{{
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
// }}}
#pragma endregion
#pragma region Network
// {{{
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
// }}}
#pragma endregion
#pragma region Thread
// {{{
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
// }}}
#pragma endregion
#pragma region String
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
#pragma endregion
#pragma region Bits
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
#pragma endregion
#pragma region DEvent
// {{{
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
// }}}
#pragma endregion
#pragma region DQueue
// {{{
void UT_DQueue_print(DQueue* in_arr) {
	u32 qsz = DQueue_size(in_arr);
	u32 qbz = DQueue_size_buffer(in_arr);
	DPrint_inf("SZ: %d", qsz);
	DPrint_inf("BZ: %d", qbz);
	DPrint("Fake: ");
	for (int i = 0; i < qsz + qbz;  i++) {
		u32* f = DQueue_get_u32(in_arr, i); if (f != NULL) DPrint("%d ", *f); else DPrint("# ");
	}
	DPrint("\nReal: ");
	for (int i = 0; i < qsz + qbz;  i++) {
		u32* r = DQueue_get_real_u32(in_arr, i); if (r != NULL) DPrint("%d ", *r); else DPrint("# ");
	}
	DPrint("\n      ");
	for (int i = 0; i < (qsz + qbz + 1) * DQueue_stride(in_arr);  i += DQueue_stride(in_arr)) {
		if (DQueue_begin_alloc(in_arr)+  i == DQueue_begin(in_arr)) DPrint("^ ");
		else if (DQueue_begin_alloc(in_arr)+  i == DQueue_end(in_arr)) DPrint("^ "); else DPrint("  ");
	}
	DPrint("\n      ");
	for (int i = 0; i < (qsz + qbz + 1) * DQueue_stride(in_arr);  i += DQueue_stride(in_arr)) {
		if (DQueue_begin_alloc(in_arr) + i == DQueue_begin(in_arr) && DQueue_begin(in_arr) == DQueue_end(in_arr)) DPrint("^ ");
		else if (DQueue_begin_alloc(in_arr) + i == DQueue_begin(in_arr)) DPrint("S ");
		else if (DQueue_begin_alloc(in_arr) + i == DQueue_end(in_arr)) DPrint("E "); else DPrint("  ");
	}
	DPrint_nl();
}
bool UT_DQueue_check(DQueue* in_arr, i32* in_fake, i32* in_real, u32 in_size) {
	u32 _sz = DQueue_size(in_arr) + DQueue_size_buffer(in_arr);
	if (in_size != _sz) { DPrint_wrn("Size missmatch: expected %d, got %d", _sz, in_size); return false; }
	for (int i = 0; i < _sz;  i++) {
		u32* f = DQueue_get_u32(in_arr, i); u32* r = DQueue_get_real_u32(in_arr, i);
		if (in_fake[i] == -1 && f != NULL) return false;
		if (in_real[i] == -1 && r != NULL) return false;
		if (in_fake[i] != -1 && *f != in_fake[i]) return false;
		if (in_real[i] != -1 && *r != in_real[i]) return false;
	}
	return true;
}
void UT_DQueue() {
	DPrint("UT_DQueue\n==============================================================================\n");
	DQueue* q = DQueue_create(sizeof(uint32_t));
	DQueue_buffer(q, 4);
	{ // -- 0 -- // {{{
		i32 _comp_f[4] = { 1, 2, 3, -1 };
		i32 _comp_r[4] = { 1, 2, 3, -1 };
		DQueue_pushback_u32(q, 1);
		DQueue_pushback_u32(q, 2);
		DQueue_pushback_u32(q, 3);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 4)) { DPrint_err("[0]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[0]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 1 -- // {{{
		i32 _comp_f[4] = { 3, 2, 1, -1 };
		i32 _comp_r[4] = { -1, 3, 2, 1 };
		DQueue_pushfront_u32(q, 1);
		DQueue_pushfront_u32(q, 2);
		DQueue_pushfront_u32(q, 3);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 4)) { DPrint_err("[1]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[1]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 2 -- // {{{
		i32 _comp_f[8] = { 1, 2, 3, 4, -1, -1, -1, -1 };
		i32 _comp_r[8] = { 1, 2, 3, 4, -1, -1, -1, -1 };
		DQueue_pushback_u32(q, 1);
		DQueue_pushback_u32(q, 2);
		DQueue_pushback_u32(q, 3);
		DQueue_pushback_u32(q, 4);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 8)) { DPrint_err("[2]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[2]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 3 -- // {{{
		i32 _comp_f[4] = { 2, 3, 4, -1 };
		i32 _comp_r[4] = { -1, 2, 3, 4 };
		DQueue_pushback_u32(q, 1);
		DQueue_popfront(q);
		DQueue_pushback_u32(q, 2);
		DQueue_pushback_u32(q, 3);
		DQueue_pushback_u32(q, 4);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 4)) { DPrint_err("[3]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[3]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 4 -- // {{{
		i32 _comp_f[8] = { 2, 3, 4, 5, -1, -1, -1, -1 };
		i32 _comp_r[8] = { 2, 3, 4, 5, -1, -1, -1, -1 };
		DQueue_pushback_u32(q, 1);
		DQueue_popfront(q);
		DQueue_pushback_u32(q, 2);
		DQueue_pushback_u32(q, 3);
		DQueue_pushback_u32(q, 4);
		DQueue_pushback_u32(q, 5);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 8)) { DPrint_err("[4]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[4]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 5 -- // {{{
		i32 _comp_f[8] = { 2, 3, 4, 5, -1, -1, -1, -1 };
		i32 _comp_r[8] = { 2, 3, 4, 5, -1, -1, -1, -1 };
		DQueue_pushback_u32(q, 1);
		DQueue_pushback_u32(q, 1);
		DQueue_popfront(q);
		DQueue_popfront(q);
		DQueue_pushback_u32(q, 2);
		DQueue_pushback_u32(q, 3);
		DQueue_pushback_u32(q, 4);
		DQueue_pushback_u32(q, 5);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 8)) { DPrint_err("[5]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[5]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 7 -- // {{{
		i32 _comp_f[8] = { 4, 3, 2, 1, -1, -1, -1, -1 };
		i32 _comp_r[8] = { 4, 3, 2, 1, -1, -1, -1, -1 };
		DQueue_pushfront_u32(q, 1);
		DQueue_pushfront_u32(q, 2);
		DQueue_pushfront_u32(q, 3);
		DQueue_pushfront_u32(q, 4);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 8)) { DPrint_err("[7]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[7]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 8 -- // {{{
		i32 _comp_f[8] = { 1, 2, 3, 4, -1, -1, -1, -1 };
		i32 _comp_r[8] = { 2, 3, 4, -1, -1, -1, -1, 1 };
		DQueue_pushback_u32(q, 1);
		DQueue_pushback_u32(q, 1);
		DQueue_popfront(q);
		DQueue_popfront(q);
		DQueue_pushback_u32(q, 2);
		DQueue_pushback_u32(q, 3);
		DQueue_pushback_u32(q, 4);
		DQueue_pushfront_u32(q, 1);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 8)) { DPrint_err("[8]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[8]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 9 -- // {{{
		i32 _comp_f[8] = { 3, 1, 2, 3, -1, -1, -1, -1 };
		i32 _comp_r[8] = { 1, 2, 3, -1, -1, -1, -1, 3 };
		DQueue_pushback_u32(q, 1);
		DQueue_pushback_u32(q, 2);
		DQueue_pushback_u32(q, 3);
		DQueue_pushfront_u32(q, 3);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 8)) { DPrint_err("[9]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[9]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 10 -- // {{{
		i32 _comp_f[9] = { 1, 2, 3, 4, 5, -1, -1, -1 };
		i32 _comp_r[9] = { 1, 2, 3, 4, 5, -1, -1, -1 };
		DArray* a = DArray_create(sizeof(u32));
		DArray_buffer(a, 3);
		DArray_pushback_u32(a, 1);
		DArray_pushback_u32(a, 2);
		DArray_pushback_u32(a, 3);
		DArray_pushback_u32(a, 4);
		DQueue_free(q);
		q = DArray_convert_to_DQueue(a);
		DQueue_buffer(q, 4);
		DQueue_pushback_u32(q, 5);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 8)) { DPrint_err("[10]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[10]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	{ // -- 11 -- // {{{
		i32 _comp_f[9] = { 5, 1, 2, 3, 4, -1, -1, -1 };
		i32 _comp_r[9] = { 1, 2, 3, 4, -1, -1, -1, 5 };
		DArray* a = DArray_create(sizeof(u32));
		DArray_buffer(a, 3);
		DArray_pushback_u32(a, 1);
		DArray_pushback_u32(a, 2);
		DArray_pushback_u32(a, 3);
		DArray_pushback_u32(a, 4);
		DQueue_free(q);
		q = DArray_convert_to_DQueue(a);
		DQueue_buffer(q, 4);
		DQueue_pushfront_u32(q, 5);

		if (!UT_DQueue_check(q, _comp_f, _comp_r, 8)) { DPrint_err("[11]" COL_BOLDRED " Error:" COL_RESET); UT_DQueue_print(q); }
		else { DPrint_inf("[11]" COL_BOLDGREEN " Passed" COL_RESET); }

		DQueue_free(q); q = DQueue_create(sizeof(uint32_t)); DQueue_buffer(q, 4);
	} // }}}
	DPrint("==============================================================================\n");

	DQueue_free(q);
}
// }}}
#pragma endregion


int main(int argc, char** argv) {
	DPrint_set_level(
			DPRINT_INF_FLAG
			| DPRINT_DBG_FLAG
			| DPRINT_WRN_FLAG
			| DPRINT_ERR_FLAG
			);
	DMemory_begin(false);

	DVulkan* vk = DVulkan_create("Test", 800, 600);
	if (vk == NULL) {
		DVulkan_free(vk);
		return EXIT_FAILURE;
	}

	DVulkan_update(vk);

	DVulkan_free(vk);

	DMemory_end();
	return 0;
}
