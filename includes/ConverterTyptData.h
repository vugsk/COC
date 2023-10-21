
#pragma once

#include <string>

using std::string;
using std::wstring;


typedef const char    char_c;
typedef const size_t  size_t_c;
typedef const wchar_t wchar_t_c;
typedef const wstring wstr_c;
typedef const string  str_c;


wchar_t_c* converterCharInWchar(char_c* ch);
wstr_c converterStringInWstring(str_c text);

template<typename T> size_t_c sizeWchar(T wch);
