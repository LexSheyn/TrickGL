#include "TrickWindow.h"

#if TK_WINDOWS

#include "Trick_win.h"

#include <stdlib.h>

typedef struct TkWindowClass_T
{
    ATOM                     Handle;
    PFN_tkWindowProcedure    pfn_WindowProcedure;
} TkWindowClass_T;

LRESULT _tkWindowMessageReturnCode(UINT Message);

TkWindowMessage _tkTranslateWindowMessage(UINT Message);

TkWindowMessageData _tkExtractWindowMessageData(TkWindowMessage Message, WPARAM WParam, LPARAM LParam);

LRESULT _tkWindowProcedure(HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam);

TkResult tkCreateWindowClass(const TkWindowClassCreateInfo* p_CreateInfo, void* p_Allocator, TkWindowClass* p_WindowClass)
{
    *p_WindowClass = malloc(sizeof(TkWindowClass_T));

    TkWindowClass WindowClass = *p_WindowClass;

    if (!WindowClass)
    {
        return TK_ERROR_OUT_OF_HOST_MEMORY;
    }

    WNDCLASSEXA WindowClassInfo = { 0 };

    WindowClassInfo.cbSize = sizeof(WNDCLASSEXA);
    WindowClassInfo.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
    WindowClassInfo.lpfnWndProc = 0;

    // TO DO

    return TK_SUCCESS;
}

void tkDestroyWindowClass(TkWindowClass WindowClass, void* p_Allocator)
{
    // TO DO
}

LRESULT _tkWindowMessageReturnCode(UINT Message)
{
    // TO DO

    return 0;
}

TkWindowMessage _tkTranslateWindowMessage(UINT Message)
{
    switch (Message)
    {
        case WM_CREATE: return TK_WINDOW_MESSAGE_CREATE;

        default: return -1;
    }
}

TkWindowMessageData _tkExtractWindowMessageData(TkWindowMessage Message, WPARAM WParam, LPARAM LParam)
{
    TkWindowMessageData MessageData = { 0 };

    switch (Message)
    {
        // TO DO

        default: break;
    }

    return MessageData;
}

LRESULT _tkWindowProcedure(HWND Handle, UINT Message, WPARAM WParam, LPARAM LParam)
{
    const LRESULT             WindowMessageReturnCode = _tkWindowMessageReturnCode(Message);
    const TkWindowMessage     WindowMessage           = _tkTranslateWindowMessage(Message);
    const TkWindowMessageData WindowMessageData       = _tkExtractWindowMessageData(WindowMessage, WParam, LParam);

    TkWindowClass WindowClass = 0;

    // TO DO: Get window class from HWND, then get TkWindowClass from window class user data here.

    TkWindow Window = (TkWindow)GetWindowLongPtrA(Handle, GWLP_USERDATA);

    // TO DO: Get TkWindow from HWND user data here.

    if (WindowClass->pfn_WindowProcedure(Window, WindowMessage, &WindowMessageData))
    {
        return WindowMessageReturnCode;
    }

    return DefWindowProcA(Handle, Message, WParam, LParam);
}

TkResult tkCreateWindow(const TkWindowCreateInfo* p_CreateInfo, void* p_Allocator, TkWindow* p_Window)
{
    return TK_SUCCESS;
}

void tkDestroyWindow(TkWindow Window, void* p_Allocator)
{
    // TO DO
}

#endif // TK_WINDOWS