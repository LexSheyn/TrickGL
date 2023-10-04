#pragma once

#include "TrickDefinitions.h"
#include "TrickPrimitiveTypes.h"

typedef enum TkResult
{
      TK_SUCCESS       = 0
    , TK_ERROR_UNKNOWN = -10
    , TK_ERROR_OUT_OF_HOST_MEMORY
    , TK_ERROR_OUT_OF_DEVICE_MEMORY
} TkResult;