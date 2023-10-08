#pragma once

#include "TrickDefinitions.h"
#include "TrickPrimitiveTypes.h"
#include "TrickLimits.h"

typedef enum TkResult
{
      TK_SUCCESS       = 0
    , TK_ERROR_UNKNOWN = -10
    , TK_ERROR_OUT_OF_HOST_MEMORY
    , TK_ERROR_OUT_OF_DEVICE_MEMORY
    , TK_ERROR_INITIALIZATION_FAILED
} TkResult;

typedef enum TkStructureType
{
      TK_STRUCTURE_TYPE_WINDOW_CLASS_CREATE_INFO
    , TK_STRUCTURE_TYPE_WINDOW_CREATE_INFO
    , TK_STRUCTURE_TYPE_MAX_ENUM = TK_INT32_MAX
} TkStructureType;