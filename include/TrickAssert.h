#pragma once

#include "TrickDefinitions.h"
#include "TrickPrimitiveTypes.h"

TK_API void TK_CALL tkReportFailure (const tk_char8* ExpressionString, const tk_char8* Message, const tk_char8* FunctionName, const tk_char8* File, tk_int32 Line);

#if TK_DEBUG
#define TK_ASSERT(Expression)\
    {                        \
        if (Expression)      \
        {}                   \
        else                 \
        {                    \
            TK_DEBUG_BREAK();\
        }                    \
    }

#define TK_ASSERT_MESSAGE(Expression, Message)                                   \
    {                                                                            \
        if (Expression)                                                          \
        {}                                                                       \
        else                                                                     \
        {                                                                        \
            tkReportFailure(#Expression, Message, TK_FUNCTION, TK_FILE, TK_LINE);\
                                                                                 \
            TK_DEBUG_BREAK();                                                    \
        }                                                                        \
    }
#else
#define TK_ASSERT(Expression)
#define TK_ASSERT_MESSAGE(Expression, Message)
#endif // TK_DEBUG
