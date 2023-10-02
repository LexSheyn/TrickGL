#pragma once

#if TK_EXPORT
#define TK_API __declspec(dllexport)
#else
#define TK_API __declspec(dllimport)
#endif // TK_EXPORT

#define TK_ALIGNAS(Value)  __declspec(align(Value))
#define TK_ALIGNOF(Object) __alignof(Object)
#define TK_INLINE          __forceinline
#define TK_NOINLINE        __declspec(noinline)
#define TK_CALL            __stdcall
#define TK_VARCALL         __cdecl
#define TK_FUNCTION        __FUNCTION__

#include <intrin.h>
#define TK_DEBUG_BREAK()   __debugbreak()
