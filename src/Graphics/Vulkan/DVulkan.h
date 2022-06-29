#pragma once
#if defined(DYNAMIC_GRAPHICS)
#include <stdint.h>

typedef struct DVulkan DVulkan;

DVulkan* DVulkan_create(const char* in_name, const uint32_t in_width, const uint32_t in_height);
void DVulkan_free(DVulkan* in_vk);

void DVulkan_update(DVulkan* in_vk);

void DVulkan_hook_update(DVulkan* in_vk, void(*in_f)(void*));
void DVulkan_hook_draw(DVulkan* in_vk, void(*in_f)(void*));
#endif