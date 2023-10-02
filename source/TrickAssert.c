#include "TrickAssert.h"

#include <stdio.h>

void tkReportFailure(const tk_char8* ExpressionString, const tk_char8* Message, const tk_char8* FunctionName, const tk_char8* File, tk_int32 Line)
{
    printf("Assertion failed: %s\nMessage: %s\nFunction: %s\nFile: %s\nLine: %d", ExpressionString, Message, FunctionName, File, Line);
}
