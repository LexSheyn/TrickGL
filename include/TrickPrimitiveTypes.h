#pragma once

typedef signed   char      tk_int8;
typedef signed   short     tk_int16;
typedef signed   int       tk_int32;
typedef signed   long long tk_int64;

typedef unsigned char      tk_uint8;
typedef unsigned short     tk_uint16;
typedef unsigned int       tk_uint32;
typedef unsigned long long tk_uint64;

typedef char               tk_char8;
typedef tk_uint16          tk_char16;
typedef tk_uint32          tk_char32;

typedef signed   long      tk_long32;
typedef unsigned long      tk_ulong32;

typedef float              tk_float32;
typedef double             tk_float64;

static_assert(sizeof(tk_int8)    == 1, "Expected to be 1 byte.");
static_assert(sizeof(tk_int16)   == 2, "Expected to be 2 bytes.");
static_assert(sizeof(tk_int32)   == 4, "Expected to be 4 bytes.");
static_assert(sizeof(tk_int64)   == 8, "Expected to be 8 bytes.");

static_assert(sizeof(tk_uint8)   == 1, "Expected to be 1 byte.");
static_assert(sizeof(tk_uint16)  == 2, "Expected to be 2 bytes.");
static_assert(sizeof(tk_uint32)  == 4, "Expected to be 4 bytes.");
static_assert(sizeof(tk_uint64)  == 8, "Expected to be 8 bytes.");

static_assert(sizeof(tk_char8)   == 1, "Expected to be 1 byte.");
static_assert(sizeof(tk_char16)  == 2, "Expected to be 2 bytes.");
static_assert(sizeof(tk_char32)  == 4, "Expected to be 4 bytes.");

static_assert(sizeof(tk_long32)  == 4, "Expected to be 4 bytes.");
static_assert(sizeof(tk_ulong32) == 4, "Expected to be 4 bytes.");

static_assert(sizeof(tk_float32) == 4, "Expected to be 4 bytes.");
static_assert(sizeof(tk_float64) == 8, "Expected to be 8 bytes.");

typedef tk_uint8  tk_bool8;
typedef tk_uint32 tk_bool32;
typedef tk_uint64 tk_bool64;

#define TK_FALSE 0u
#define TK_TRUE  1u

typedef tk_uint8  tk_byte8;

typedef tk_uint64 tk_size;
typedef tk_uint32 TkFlags;
