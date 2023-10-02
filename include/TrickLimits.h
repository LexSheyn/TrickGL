#pragma once

#define TK_INT8_MAX  0x7F
#define TK_INT16_MAX 0x7FFF
#define TK_INT32_MAX 0x7FFFFFFF
#define TK_INT64_MAX 0x7FFFFFFFFFFFFFFF

#define TK_INT8_MIN  (-TK_INT8_MAX  - 1)
#define TK_INT16_MIN (-TK_INT16_MAX - 1)
#define TK_INT32_MIN (-TK_INT32_MAX - 1)
#define TK_INT64_MIN (-TK_INT64_MAX - 1)

#define TK_UINT8_MAX  0xFF
#define TK_UINT16_MAX 0xFFFF
#define TK_UINT32_MAX 0xFFFFFFFF
#define TK_UINT64_MAX 0xFFFFFFFFFFFFFFFF

#define TK_FLOAT32_MAX 3.402823466e+38F
#define TK_FLOAT64_MAX 1.7976931348623158E+308

#define TK_FLOAT32_EPSILON 1.192092896e-7F
#define TK_FLOAT64_EPSILON 2.2204460492503131E-16

// Little endian
// Sign 1 bit    Value 31 bits
// 0             0000000000000000000000000000000
// 31            30                            0
#define TK_INT32_BINARY

// Little endian
// Sign 1 bit    Exponent 8 bits    Fraction 23 bits
// 0             00000000           00000000000000000000000
// 31            30     23          22                    0
#define TK_FLOAT32_BINARY_IEEE_754

// Little endian
// Sign 1 bit    Exponent 11 bits    Fraction 52 bits
// 0             00000000000         0000000000000000000000000000000000000000000000000000
// 63            62        52        51                                                 0
#define TK_FLOAT64_BINARY_IEEE_754

typedef enum TkMaskFloat32
{
      TK_MASK_FLOAT32_EXPONENT = 0b1111111100000000000000000000000
    , TK_MASK_FLOAT32_FRACTION = 0b0000000011111111111111111111111
} TkMaskFloat32;
