#pragma once

#if TK_EXPORT
#define TK_API // TO DO
#else
#define TK_API // TO DO
#endif // TK_EXPORT

#define TK_ALIGNAS(Value)  alignas(Value)
#define TK_ALIGNOF(Object) alignof(Object)
#define TK_INLINE          __always_inline
#define TK_NOINLINE        noinline
#define TK_CALL            __fastcall
#define TK_VARCALL         __cdecl
#define TK_FUNCTION        __func__

//
#define TK_DEBUG_BREAK()   __builtin_trap()
