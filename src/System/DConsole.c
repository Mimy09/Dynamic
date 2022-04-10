#include "DConsole.internal.h"
#include "../Core/DMemory.h"

DConsole* DConsole_create(int argc, char** argv) {
	DConsole* con = DMalloc(sizeof(DConsole));
	con->_argc = argc;
	con->_argv = argv;
	return con;
}

void DConsole_free(DConsole* in_con) {
	DFree(in_con);
}

DConsole_Value DConsole_add_cstr(DConsole* in_con, const char* in_name) {
	for (uint32_t i = 0; i < in_con->_argc - 1; i++) {
		if (strstr(in_name, in_con->_argv[i]) != 0) {
			return (DConsole_Value){ ._used = true, ._cstr = in_con->_argv[i + 1] };
		}
	}
	return (DConsole_Value){ ._used = false, 0 };
}
DConsole_Value DConsole_add_numb(DConsole* in_con, const char* in_name) {
	for (uint32_t i = 0; i < in_con->_argc - 1; i++) {
		if (strstr(in_name, in_con->_argv[i]) != 0) {
			return (DConsole_Value){ ._used = true, ._numb = strtol(in_con->_argv[i + 1], NULL, 10) };
		}
	}
	return (DConsole_Value){ false, 0 };
	return (DConsole_Value){ ._used = false, 0 };
}

DConsole_Value DConsole_add_bool(DConsole* in_con, const char* in_name) {
	for (uint32_t i = 0; i < in_con->_argc; i++) {
		if (strstr(in_name, in_con->_argv[i]) != 0) {
			return (DConsole_Value){ ._used = true, ._bool = true };
		}
	}
	return (DConsole_Value){ ._used = false, ._bool = false };
}
