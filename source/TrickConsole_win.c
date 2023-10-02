#include "TrickConsole.h"

#if TK_WINDOWS

#include "Trick_win.h"

void TK_CALL _tkWriteConsole (HANDLE OutputHandle, tk_uint8 ForegroundColor, tk_uint8 BackgroundColor, const tk_char8* Message);

void tkConsoleStandardOutput(tk_uint8 ForegroundColor, tk_uint8 BackgroundColor, const tk_char8* Message)
{
    const HANDLE OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    _tkWriteConsole(OutputHandle, ForegroundColor, BackgroundColor, Message);
}

void tkConsoleErrorOutput(tk_uint8 ForegroundColor, tk_uint8 BackgroundColor, const tk_char8* Message)
{
    const HANDLE OutputHandle = GetStdHandle(STD_ERROR_HANDLE);

    _tkWriteConsole(OutputHandle, ForegroundColor, BackgroundColor, Message);
}

typedef enum TkConsoleForegroundColor
{
	  TK_CONSOLE_FOREGROUND_COLOR_BLACK        = 0x0
	, TK_CONSOLE_FOREGROUND_COLOR_BLUE         = FOREGROUND_BLUE
	, TK_CONSOLE_FOREGROUND_COLOR_GREEN        = FOREGROUND_GREEN
	, TK_CONSOLE_FOREGROUND_COLOR_CYAN         = FOREGROUND_BLUE  | FOREGROUND_GREEN
	, TK_CONSOLE_FOREGROUND_COLOR_RED          = FOREGROUND_RED
	, TK_CONSOLE_FOREGROUND_COLOR_PURPLE       = FOREGROUND_BLUE  | FOREGROUND_RED
	, TK_CONSOLE_FOREGROUND_COLOR_YELLOW       = FOREGROUND_GREEN | FOREGROUND_RED
	, TK_CONSOLE_FOREGROUND_COLOR_WHITE        = FOREGROUND_BLUE  | FOREGROUND_GREEN | FOREGROUND_RED
	, TK_CONSOLE_FOREGROUND_COLOR_LIGHT_BLACK  = FOREGROUND_INTENSITY
	, TK_CONSOLE_FOREGROUND_COLOR_LIGHT_BLUE   = FOREGROUND_INTENSITY | FOREGROUND_BLUE
	, TK_CONSOLE_FOREGROUND_COLOR_LIGHT_GREEN  = FOREGROUND_INTENSITY | FOREGROUND_GREEN
	, TK_CONSOLE_FOREGROUND_COLOR_LIGHT_CYAN   = FOREGROUND_INTENSITY | FOREGROUND_BLUE  | FOREGROUND_GREEN
	, TK_CONSOLE_FOREGROUND_COLOR_LIGHT_RED    = FOREGROUND_INTENSITY | FOREGROUND_RED
	, TK_CONSOLE_FOREGROUND_COLOR_LIGHT_PURPLE = FOREGROUND_INTENSITY | FOREGROUND_BLUE  | FOREGROUND_RED
	, TK_CONSOLE_FOREGROUND_COLOR_LIGHT_YELLOW = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED
	, TK_CONSOLE_FOREGROUND_COLOR_LIGHT_WHITE  = FOREGROUND_INTENSITY | FOREGROUND_BLUE  | FOREGROUND_GREEN | FOREGROUND_RED
} TkConsoleForegroundColor;

typedef enum TkConsoleBackgroundColor
{
	  TK_CONSOLE_BACKGROUND_COLOR_BLACK        = 0x0
	, TK_CONSOLE_BACKGROUND_COLOR_BLUE         = BACKGROUND_BLUE
	, TK_CONSOLE_BACKGROUND_COLOR_GREEN        = BACKGROUND_GREEN
	, TK_CONSOLE_BACKGROUND_COLOR_CYAN         = BACKGROUND_BLUE  | BACKGROUND_GREEN
	, TK_CONSOLE_BACKGROUND_COLOR_RED          = BACKGROUND_RED
	, TK_CONSOLE_BACKGROUND_COLOR_PURPLE       = BACKGROUND_BLUE  | BACKGROUND_RED
	, TK_CONSOLE_BACKGROUND_COLOR_YELLOW       = BACKGROUND_GREEN | BACKGROUND_RED
	, TK_CONSOLE_BACKGROUND_COLOR_WHITE        = BACKGROUND_BLUE  | BACKGROUND_GREEN | BACKGROUND_RED
	, TK_CONSOLE_BACKGROUND_COLOR_LIGHT_BLACK  = BACKGROUND_INTENSITY
	, TK_CONSOLE_BACKGROUND_COLOR_LIGHT_BLUE   = BACKGROUND_INTENSITY | BACKGROUND_BLUE
	, TK_CONSOLE_BACKGROUND_COLOR_LIGHT_GREEN  = BACKGROUND_INTENSITY | BACKGROUND_GREEN
	, TK_CONSOLE_BACKGROUND_COLOR_LIGHT_CYAN   = BACKGROUND_INTENSITY | BACKGROUND_BLUE  | BACKGROUND_GREEN
	, TK_CONSOLE_BACKGROUND_COLOR_LIGHT_RED    = BACKGROUND_INTENSITY | BACKGROUND_RED
	, TK_CONSOLE_BACKGROUND_COLOR_LIGHT_PURPLE = BACKGROUND_INTENSITY | BACKGROUND_BLUE  | BACKGROUND_RED
	, TK_CONSOLE_BACKGROUND_COLOR_LIGHT_YELLOW = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_RED
	, TK_CONSOLE_BACKGROUND_COLOR_LIGHT_WHITE  = BACKGROUND_INTENSITY | BACKGROUND_BLUE  | BACKGROUND_GREEN | BACKGROUND_RED
} TkConsoleBackgroundColor;

void _tkWriteConsole(HANDLE OutputHandle, tk_uint8 ForegroundColor, tk_uint8 BackgroundColor, const tk_char8* Message)
{
    // Colors.

    TkConsoleForegroundColor ForegroundColors[TK_CONSOLE_MESSAGE_COLOR_ENUM_SIZE] =
    {
          TK_CONSOLE_FOREGROUND_COLOR_BLACK
        , TK_CONSOLE_FOREGROUND_COLOR_BLUE
        , TK_CONSOLE_FOREGROUND_COLOR_GREEN
        , TK_CONSOLE_FOREGROUND_COLOR_CYAN
        , TK_CONSOLE_FOREGROUND_COLOR_RED
        , TK_CONSOLE_FOREGROUND_COLOR_PURPLE
        , TK_CONSOLE_FOREGROUND_COLOR_YELLOW
        , TK_CONSOLE_FOREGROUND_COLOR_WHITE
        , TK_CONSOLE_FOREGROUND_COLOR_LIGHT_BLACK
        , TK_CONSOLE_FOREGROUND_COLOR_LIGHT_BLUE
        , TK_CONSOLE_FOREGROUND_COLOR_LIGHT_GREEN
        , TK_CONSOLE_FOREGROUND_COLOR_LIGHT_CYAN
        , TK_CONSOLE_FOREGROUND_COLOR_LIGHT_RED
        , TK_CONSOLE_FOREGROUND_COLOR_LIGHT_PURPLE
        , TK_CONSOLE_FOREGROUND_COLOR_LIGHT_YELLOW
        , TK_CONSOLE_FOREGROUND_COLOR_LIGHT_WHITE
    };

    TkConsoleBackgroundColor BackgroundColors[TK_CONSOLE_MESSAGE_COLOR_ENUM_SIZE] =
    {
          TK_CONSOLE_BACKGROUND_COLOR_BLACK
        , TK_CONSOLE_BACKGROUND_COLOR_BLUE
        , TK_CONSOLE_BACKGROUND_COLOR_GREEN
        , TK_CONSOLE_BACKGROUND_COLOR_CYAN
        , TK_CONSOLE_BACKGROUND_COLOR_RED
        , TK_CONSOLE_BACKGROUND_COLOR_PURPLE
        , TK_CONSOLE_BACKGROUND_COLOR_YELLOW
        , TK_CONSOLE_BACKGROUND_COLOR_WHITE
        , TK_CONSOLE_BACKGROUND_COLOR_LIGHT_BLACK
        , TK_CONSOLE_BACKGROUND_COLOR_LIGHT_BLUE
        , TK_CONSOLE_BACKGROUND_COLOR_LIGHT_GREEN
        , TK_CONSOLE_BACKGROUND_COLOR_LIGHT_CYAN
        , TK_CONSOLE_BACKGROUND_COLOR_LIGHT_RED
        , TK_CONSOLE_BACKGROUND_COLOR_LIGHT_PURPLE
        , TK_CONSOLE_BACKGROUND_COLOR_LIGHT_YELLOW
        , TK_CONSOLE_BACKGROUND_COLOR_LIGHT_WHITE
    };

    // Aqcuire current text attributes.

    CONSOLE_SCREEN_BUFFER_INFO BufferInfo;

    const BOOL b_GetConsoleScreenBufferInfoResult = GetConsoleScreenBufferInfo(OutputHandle, &BufferInfo);

    WORD PreviousTextAttributes = BufferInfo.wAttributes;

    // Set new text attributes.

    const tk_uint8 MessageColor = ForegroundColors[ForegroundColor] | BackgroundColors[BackgroundColor];

    const BOOL b_SetConsoleTextAttributeResult = SetConsoleTextAttribute(OutputHandle, MessageColor);

    // Write into debug console.

    OutputDebugStringA(Message);

    // Write into OutputHandle:

    DWORD MessageLength = (DWORD)strlen(Message);

    DWORD CharsWritten;

    const BOOL b_WriteConsoleResult = WriteConsoleA(OutputHandle, Message, MessageLength, &CharsWritten, NULL);

    // Set previous text attributes back:

    const BOOL b_SetPreviousConsoleTextAttributeResult = SetConsoleTextAttribute(OutputHandle, PreviousTextAttributes);
}

#endif // TK_WINDOWS