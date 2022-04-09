#pragma once
#include "../Container/DArray.h"

union DConArgs_Value {
	char* _cstr;
	u32   _uint;
	i32   _sint;
	bool  _bool;
};
struct DConArgs_Element {
	char*          _name;
	DConArgs_Value _value;
};

struct DConArgs {
	DArray* _args;
};
