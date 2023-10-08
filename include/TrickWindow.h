#pragma once

#include "TrickBase.h"

TK_HANDLE(TkWindow);
TK_HANDLE(TkWindowClass);

typedef enum TkWindowMessage
{
    TK_WINDOW_MESSAGE_CREATE
} TkWindowMessage;

typedef union TkWindowMessageData
{
    tk_uint64     uint64 [2];
    tk_int64      int64  [2];
    tk_float64    float64[2];
    tk_uint32     uint32 [4];
    tk_int32      int32  [4];
    tk_float32    float32[4];
    tk_uint16     uint16 [8];
    tk_int16      int16  [8];
    tk_uint8      uint8  [16];
    tk_int8       int8   [16];
    tk_char8      char8  [16];
} TkWindowMessageData;

typedef tk_bool8 (TK_CALL* PFN_tkWindowProcedure) (TkWindow Window, TkWindowMessage Message, const TkWindowMessageData* p_MessageData);

typedef struct TkWindowClassCreateInfo
{
    TkStructureType          StructureType;
    const void*              p_Next;
    PFN_tkWindowProcedure    pfn_WindowProcedure;
    void*                    Icon;
    void*                    SmallIcon;
    void*                    Cursor;
    const tk_char8*          Name;
} TkWindowClassCreateInfo;

TK_API TkResult TK_CALL tkCreateWindowClass  (const TkWindowClassCreateInfo* p_CreateInfo, void* p_Allocator, TkWindowClass* p_WindowClass);
TK_API void     TK_CALL tkDestroyWindowClass (TkWindowClass WindowClass, void* p_Allocator);

typedef struct TkWindowCreateInfo
{
    TkStructureType    StructureType;
    const void*        p_Next;
    TkWindowClass      Class;
    TkWindow           Parent;
    const tk_char8*    Title;
    tk_int32           PositionX;
    tk_int32           PositionY;
    tk_int32           Width;
    tk_int32           Height;
} TkWindowCreateInfo;

TK_API TkResult TK_CALL tkCreateWindow  (const TkWindowCreateInfo* p_CreateInfo, void* p_Allocator, TkWindow* p_Window);
TK_API void     TK_CALL tkDestroyWindow (TkWindow Window, void* p_Allocator);
TK_API tk_bool8 TK_CALL tkWindowUpdate  (TkWindow Window);