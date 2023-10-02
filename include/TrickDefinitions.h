#pragma once

#if _WIN32
#define TK_WINDOWS 1
#include "TrickDefinitions_win.h"
#else
#define TK_WINDOWS 0
#endif // _WIN32

#if __linux__
#define TK_LINUX 1
#include "TrickDefinitions_linux.h"
#else
#define TK_LINUX 0
#endif // __linux__

#define TK_HANDLE(Object) typedef struct Object##_T* Object
#define TK_NULL           ((void*)0)
#define TK_TEXT(Value)    #Value
#define TK_FILE           __FILE__
#define TK_LINE           __LINE__

#if _DEBUG
#define TK_DEBUG 1
#else
#define TK_DEBUG 0
#endif // _DEBUG
