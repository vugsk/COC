
#include "ConverterTyptData.h"

#include <codecvt>
#include <cstring>
#include <locale>


wchar_t_c* converterCharInWchar(char_c* ch) {
    size_t_c cSize = strlen(ch)+1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, ch, cSize);
    return wc;
}

wstr_c converterStringInWstring(str_c text) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> con;
    return con.from_bytes(text);
}