#include "TrickWindow.h"

#if TK_WINDOWS

#include "Trick_win.h"

#include <stdlib.h>

#define TK_WINDOW_CLASS_NAME_LENGTH_NT 256
#define TK_WINDOW_CLASS_NAME_LENGTH    255

typedef struct TkWindowClass_T
{
    ATOM                     Handle;
    CHAR                     Name[TK_WINDOW_CLASS_NAME_LENGTH_NT];
    PFN_tkWindowProcedure    pfn_WindowProcedure;
} TkWindowClass_T;

LRESULT             TK_CALL _tkWindowMessageReturnCode  (UINT Message);
TkWindowMessage     TK_CALL _tkTranslateWindowMessage   (UINT Message);
TkWindowMessageData TK_CALL _tkExtractWindowMessageData (UINT Message, WPARAM WParam, LPARAM LParam);
LRESULT             TK_CALL _tkWindowProcedure          (HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam);

TkResult tkCreateWindowClass(const TkWindowClassCreateInfo* p_CreateInfo, void* p_Allocator, TkWindowClass* p_WindowClass)
{
    *p_WindowClass = malloc(sizeof(TkWindowClass_T));

    TkWindowClass WindowClass = *p_WindowClass;

    if (!WindowClass)
    {
        return TK_ERROR_OUT_OF_HOST_MEMORY;
    }

    const HINSTANCE ModuleHandle = GetModuleHandleA(NULL);

    WNDCLASSEXA WindowClassInfo = { 0 };

    WindowClassInfo.cbSize        = sizeof(WNDCLASSEXA);
    WindowClassInfo.style         = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    WindowClassInfo.lpfnWndProc   = _tkWindowProcedure;
    WindowClassInfo.cbClsExtra    = 0;
    WindowClassInfo.cbWndExtra    = 0;
    WindowClassInfo.hInstance     = ModuleHandle;
    WindowClassInfo.hIcon         = NULL;
    WindowClassInfo.hCursor       = NULL;
    WindowClassInfo.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    WindowClassInfo.lpszMenuName  = NULL;
    WindowClassInfo.lpszClassName = p_CreateInfo->Name;
    WindowClassInfo.hIconSm       = NULL;

    WindowClass->Handle = RegisterClassExA(&WindowClassInfo);

    if (!WindowClass->Handle)
    {
        return TK_ERROR_INITIALIZATION_FAILED;
    }

    const tk_size NameLength = strlen(p_CreateInfo->Name);

    memcpy(WindowClass->Name, p_CreateInfo->Name, NameLength);

    WindowClass->pfn_WindowProcedure = p_CreateInfo->pfn_WindowProcedure;

    return TK_SUCCESS;
}

void tkDestroyWindowClass(TkWindowClass WindowClass, void* p_Allocator)
{
    const HINSTANCE ModuleHandle = GetModuleHandleA(NULL);

    const BOOL b_Unregistered = UnregisterClassA(WindowClass->Name, ModuleHandle);

    free(WindowClass);
}

LRESULT _tkWindowMessageReturnCode(UINT Message)
{
    switch (Message)
    {
        case WM_CREATE:    return 0;
        case WM_DESTROY:   return 0;
        case WM_MOVE:      return 0;
        case WM_SIZE:      return 0;
        case WM_ACTIVATE:  return 0;
        case WM_SETFOCUS:  return 0;
        case WM_KILLFOCUS: return 0;
        case WM_ENABLE:    return 0;
        case WM_SETREDRAW: return 0;

        default: return -1;
    }
}

TkWindowMessage _tkTranslateWindowMessage(UINT Message)
{
    switch (Message)
    {
        case WM_CREATE:    return TK_WINDOW_MESSAGE_CREATE;
        case WM_DESTROY:   return TK_WINDOW_MESSAGE_DESTROY;
        case WM_MOVE:      return TK_WINDOW_MESSAGE_MOVE;
        case WM_SIZE:      return TK_WINDOW_MESSAGE_SIZE;
        case WM_ACTIVATE:  return TK_WINDOW_MESSAGE_ACTIVATE;
        case WM_SETFOCUS:  return TK_WINDOW_MESSAGE_GAIN_FOCUS;
        case WM_KILLFOCUS: return TK_WINDOW_MESSAGE_LOSE_FOCUS;
        case WM_ENABLE:    return TK_WINDOW_MESSAGE_ENABLE;
        case WM_SETREDRAW: return TK_WINDOW_MESSAGE_SET_REDRAW;

        default: return -1;
    }
}

TkWindowMessageData _tkExtractWindowMessageData(UINT Message, WPARAM WParam, LPARAM LParam)
{
    TkWindowMessageData MessageData = { 0 };

    switch (Message)
    {
        case WM_CREATE:
        {
            CREATESTRUCTA* CreateStruct = (CREATESTRUCTA*)LParam;

            // Embed TkWindowCreateInfo structure into TkWindow?
            // Pass pointer to it as TkWindowMessageData along with TK_WINDOW_MESSAGE_CREATE?
        }

        default: break;
    }

    return MessageData;
}

LRESULT _tkWindowProcedure(HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam)
{
    switch (Message)
    {
        case WM_NCCREATE:
        {
            CREATESTRUCTA* CreateStruct = (CREATESTRUCTA*)LParam;

            SetWindowLongPtrA(Handle, GWLP_USERDATA, (LONG_PTR)CreateStruct->lpCreateParams);

            return DefWindowProcA(Handle, Message, WParam, LParam);
        }

        default: break;
    }

    const LRESULT             WindowMessageReturnCode = _tkWindowMessageReturnCode(Message);
    const TkWindowMessage     WindowMessage           = _tkTranslateWindowMessage(Message);
    const TkWindowMessageData WindowMessageData       = _tkExtractWindowMessageData(Message, WParam, LParam);

    ATOM WindowClassHandle = (ATOM)GetClassLongPtrA(Handle, GCW_ATOM);

    // Specify extra memory for the window class when creating it.
    // Try to access it by using SetClassLongPtrA/GetClassLongPtrA with right after the las available index,
    // allocated extra memory might be there.

    // TO DO: Get window class from HWND, then get TkWindowClass from window class user data here.

    TkWindow Window = (TkWindow)GetWindowLongPtrA(Handle, GWLP_USERDATA);

    TkWindowClass WindowClass = Window->Class;

    // TO DO: Get TkWindow from HWND user data here.

    if (WindowClass->pfn_WindowProcedure(Window, WindowMessage, &WindowMessageData))
    {
        return WindowMessageReturnCode;
    }

    return DefWindowProcA(Handle, Message, WParam, LParam);
}

typedef struct TkWindow_T
{
    HWND             Handle;
    TkWindowClass    Class;
} TkWindow_T;

TkResult tkCreateWindow(const TkWindowCreateInfo* p_CreateInfo, void* p_Allocator, TkWindow* p_Window)
{
    *p_Window = malloc(sizeof(TkWindow_T));

    TkWindow Window = *p_Window;

    if (!Window)
    {
        return TK_ERROR_OUT_OF_HOST_MEMORY;
    }

    const HINSTANCE ModuleHandle = GetModuleHandleA(NULL);

    Window->Handle = CreateWindowExA((DWORD)p_CreateInfo->ExtensionFlags
                                     , p_CreateInfo->Class->Name
                                     , p_CreateInfo->Title
                                     , (DWORD)p_CreateInfo->StyleFlags
                                     , p_CreateInfo->X
                                     , p_CreateInfo->Y
                                     , p_CreateInfo->Width
                                     , p_CreateInfo->Height
                                     , p_CreateInfo->Parent->Handle
                                     , NULL
                                     , ModuleHandle
                                     , Window);

    if (!Window->Handle)
    {
        return TK_ERROR_INITIALIZATION_FAILED;
    }

    Window->Class = p_CreateInfo->Class;

    return TK_SUCCESS;
}

void tkDestroyWindow(TkWindow Window, void* p_Allocator)
{
    const BOOL b_Destroyed = DestroyWindow(Window->Handle);

    free(Window);
}

tk_bool8 tkWindowUpdate(TkWindow Window)
{
    const BOOL b_Updated = UpdateWindow(Window->Handle);

    return (tk_bool8)b_Updated;
}

tk_bool8 tkWindowShow(TkWindow Window, TkWindowShowCommand ShowCommand)
{
    const BOOL b_Visible = ShowWindow(Window->Handle, (INT)ShowCommand);

    return (tk_bool8)b_Visible;
}

tk_bool8 tkWindowProcessMessages(TkWindow Window)
{
    MSG Msg;

    while (PeekMessageA(&Msg, Window->Handle, 0, 0, PM_REMOVE))
    {
        if (Msg.message == WM_QUIT)
        {
            return TK_FALSE;
        }

        TranslateMessage(&Msg);

        DispatchMessageA(&Msg);
    }

    return TK_TRUE;
}

#endif // TK_WINDOWS