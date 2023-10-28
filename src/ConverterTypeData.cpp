
#include "ConverterTyptData.h"


#include <codecvt>
#include <cstring>


wchar_t_c* converterCharInWchar(char_c* ch)
{
    size_t cSize = strlen(ch)+1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs (wc, ch, cSize);
    return wc;
}
