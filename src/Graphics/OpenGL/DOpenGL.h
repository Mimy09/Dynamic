#pragma once
#if defined(DYNAMIC_GRAPHICS)
#include <stdint.h>

typedef struct DOpenGL DOpenGL;

DOpenGL* DOpenGL_create(const char* in_name, const uint32_t in_width, const uint32_t in_height);
void DOpenGL_free(DOpenGL* in_gl);
void DOpenGL_close(DOpenGL* in_gl);
void DOpenGL_update(DOpenGL* in_gl);
void DOpenGL_hook_update(DOpenGL* in_gl, void(*in_f)(void*));
void DOpenGL_hook_draw(DOpenGL* in_gl, void(*in_f)(void*));
#endif