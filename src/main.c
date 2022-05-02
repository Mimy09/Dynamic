#include <stdio.h>
#include <stdlib.h>
#include "Dynamic.h"

void Update(void* args) {

}

void Draw(void* args) {

}

int main(int argc, char** argv) {
	DPrint_set_level(
			DPRINT_INF_FLAG
			| DPRINT_DBG_FLAG
			| DPRINT_WRN_FLAG
			| DPRINT_ERR_FLAG
			);
	DMemory_begin(false);

	DVulkan* vk = NULL;
	if ((vk = DVulkan_create("Test", 800, 600)) == NULL) {
		DVulkan_free(vk); return EXIT_FAILURE;
	} else {
		DVulkan_hook_update(vk, Update);
		DVulkan_hook_draw(vk, Update);
		DVulkan_update(vk);

		DVulkan_free(vk);
	}

	DMemory_end();
	return 0;
}
