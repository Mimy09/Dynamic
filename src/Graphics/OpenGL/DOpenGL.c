#include "DOpenGL.internal.h"
#if defined(DYNAMIC_GRAPHICS)
#include "../../Core/DMemory.h"
#include "../../Core/DLog.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}  

DOpenGL* DOpenGL_create(const char* in_name, const uint32_t in_width, const uint32_t in_height) {
    DOpenGL* gl = DMalloc(sizeof(DOpenGL));

    // -- Init GLFW -- //
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    gl->_update = NULL;
	gl->_draw   = NULL;
	gl->_create = NULL;
	gl->_free   = NULL;
    gl->_core   = (struct DOpenGLCore) {

    };
    gl->_window = (struct DOpenGLWindow) {
        ._name   = in_name,
		._width  = in_width,
		._height = in_height,
		._window = NULL
    };

    gl->_window._window = glfwCreateWindow(in_width, in_height, in_name, NULL, NULL);
    glfwMakeContextCurrent(gl->_window._window);
    glViewport(0, 0, in_width, in_height);
    glfwSetFramebufferSizeCallback(gl->_window._window, framebuffer_size_callback);  

    return gl;
}

void DOpenGL_free(DOpenGL* in_gl) {
    glfwTerminate();
    DFree(in_gl);
}

void DOpenGL_close(DOpenGL* in_gl) {
    glfwSetWindowShouldClose(in_gl->_window._window, true);
}

void DOpenGL_update(DOpenGL* in_gl) {
	while (!glfwWindowShouldClose(in_gl->_window._window)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(in_gl->_window._window);
		glfwPollEvents();
		if (in_gl->_update != NULL) in_gl->_update(NULL);
	}
}

void DOpenGL_hook_update(DOpenGL* in_gl, void(*in_f)(void*)) {
	in_gl->_update = in_f;
}
void DOpenGL_hook_draw(DOpenGL* in_gl, void(*in_f)(void*)) {
	in_gl->_draw = in_f;
}
#endif