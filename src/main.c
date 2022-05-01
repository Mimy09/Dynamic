#include <stdio.h>
#include <stdlib.h>
#include "Dynamic.h"

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
