#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <io.h>
#if defined(__WIN32) || defined(__WIN64)
#  define X_WIN
#  include <windows.h>
#  define ENABLE_VIRTUAL_TERMINAL_INPUT (0x0200)
#  define ENABLE_VIRTUAL_TERMINAL_PROCESSING (0x0004)
#endif // X_WIN

#include "builtin.h"
#include "cmdps.h"

#endif // COMMON_H_INCLUDED
