#pragma once

#define INFO		0x0
#define WARNING		0x1
#define ERROR		0x2
#define HEADER		0x3

#include "ANSI.h"

void Log(int lvl, const char *msg, const char *err);
