
#pragma once

#include <curses.h>
#include <vector>
#include <functional>

#include "ConverterTyptData.h"

using std::vector;
using std::pair;
using std::function;
using std::string;
using std::wstring;

typedef const int  int_c;
typedef const bool bool_c;

typedef       vector<int>                  int_vec;
typedef       vector<string>               str_vec;
typedef const vector<int>                  int_vec_c;
typedef const vector<string>               str_vec_c;
typedef const vector<pair<char_c, char_c>> vec_pair_c;
typedef       pair<int_vec, int_vec>       int_pair_vec;
typedef       vector<int_pair_vec>         int_vec_pair_vec;


enum Color {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
};

#define WALL_Y_PERPENDICULAR "│"
#define WALL_Y_ANGLE_UNDER_90_DOWN "┬"
#define WALL_Y_ANGLE_UNDER_90_TOP "┴"

#define WALL_X_IN_PARALLEL "─"
#define WALL_X_ANGLE_UNDER_90_LEFT "├"
#define WALL_X_ANGLE_UNDER_90_RIGHT "┤"

#define SIMBEL 127
vec_pair_c CODE_KEYS = {
    {'a', 'A'}, {'b', 'B'}, {'c', 'C'}, {'d', 'D'}, {'e', 'E'}, {'f', 'F'},
    {'g', 'G'}, {'h', 'H'}, {'i', 'I'}, {'j', 'J'}, {'k', 'K'}, {'l', 'L'},
    {'m', 'M'}, {'n', 'N'}, {'o', 'O'}, {'p', 'P'}, {'q', 'Q'}, {'r', 'R'},
    {'s', 'S'}, {'t', 'T'}, {'u', 'U'}, {'v', 'V'}, {'w', 'W'}, {'x', 'X'},
    {'y', 'Y'}, {'z', 'Z'}
};


// Движение
#define DOWN KEY_DOWN   // стрелка вниз
#define UP KEY_UP       // стрелка вверх
#define LEFT KEY_LEFT   // стрелка влево
#define RIGHT KEY_RIGHT // стрелка вправо

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

// функции
#define KEY_I 105
#define KEY_R 114
#define KEY_E 101 // открыть инвентарь

#define ESC 27
#define ENTER 10

