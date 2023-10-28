
#pragma once

#include <cstddef>

typedef const char           char_c;
typedef const wchar_t        wchar_t_c;

#define sizeWch(wch) wcslen(wch)

wchar_t_c* converterCharInWchar(char_c* ch);

