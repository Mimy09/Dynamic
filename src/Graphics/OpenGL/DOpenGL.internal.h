#pragma once
#if defined(DYNAMIC_GRAPHICS)
#include "DOpenGL.h"
#include <GLFW/glfw3.h>
#include "../../Container/DArray.h"
#include "../../Container/DStr.h"

struct DOpenGLWindow {
	GLFWwindow* _window;
	uint32_t    _width;
	uint32_t    _height;
	const char* _name;
};

struct DOpenGLCore {

};

struct DOpenGL {
    struct DOpenGLWindow _window;
	struct DOpenGLCore   _core;
	void(*_update)(void*);
	void(*_draw)(void*);
	void(*_create)(void*);
	void(*_free)(void*);
};
#endif