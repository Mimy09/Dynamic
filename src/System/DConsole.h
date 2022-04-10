#pragma once
#include "DTypes.h"

typedef struct DConsole DConsole;
typedef struct {
	bool _used;
	union {
		char* _cstr;
		i32   _numb;
		bool  _bool;
	};
} DConsole_Value;

// Creates a console argument passer
DConsole* DConsole_create(int argc, char** argv);

// Frees the console argument passer
void DConsole_free(DConsole* in_con);

// Populates the console args with the argv
void DConsole_run(DConsole* in_con, int argc, char** argv);

//{SCAR}DConsole_Value DConsole_add__Tn_(DConsole* in_con, const char* in_name);
//{DESC}:3:_Tn_: cstr;  numb;    bool;
//{SCAR}
//---{{{
DConsole_Value DConsole_add_cstr(DConsole* in_con, const char* in_name);
DConsole_Value DConsole_add_numb(DConsole* in_con, const char* in_name);
DConsole_Value DConsole_add_bool(DConsole* in_con, const char* in_name);
//---}}}
