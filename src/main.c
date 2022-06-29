#include <stdio.h>
#include <stdlib.h>
#include "Dynamic.h"

typedef struct {
	bool _ownr : 1;
	bool _shar : 1;
	bool _dtor : 1;
	bool _free : 1;
} _sptr_info;
typedef struct {
	void* _ptr;
	_sptr_info _info;
} _sptr;
typedef struct {
	_sptr _head;
	uint32_t _refr;
} _sptr_shar;
typedef struct {
	_sptr _head;
	void (*_dtor)(void*);
} _sptr_dtor;
typedef struct {
	_sptr _head;
	size_t _refr;
	void (*_dtor)(void*);
} _sptr_shar_dtor;

#define smalloc(val) (__typeof__(val))malloc(sizeof(*val))
#define safe __attribute__ ((cleanup(safe_cleanup)))


int main(int argc, char** argv) {
	// DPrint_set_level(
	// 		DPRINT_INF_FLAG
	// 		| DPRINT_DBG_FLAG
	// 		| DPRINT_WRN_FLAG
	// 		| DPRINT_ERR_FLAG
	// 		);
	// DMemory_begin(false);

	safe int* p = DPtr_unique(p);

	// DMemory_end();
	return 0;
}