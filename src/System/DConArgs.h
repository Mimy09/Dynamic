#pragma once
#include "DTypes.h"

typedef struct DConArgs DConArgs;

// Creates a console argument passer
DConArgs* DConArgs_create();

// Frees the console argument passer
void DConArgs_free(DConArgs* in_con);
