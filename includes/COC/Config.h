
#pragma once

#include <curses.h>
#include <functional>


#include "ConverterTyptData.h"


//* TYPE DATA

typedef const int  int_c;
typedef const bool bool_c;
typedef const std::vector<char_c*> str_vec_c;

class ButtonMove {
public:
    ButtonMove(int_c* KeyUp=nullptr, int_c* KeyDown=nullptr);
    ButtonMove(const ButtonMove &other);
    ButtonMove(ButtonMove &&other) noexcept;
    ButtonMove &operator=(const ButtonMove &other);
    ButtonMove &operator=(ButtonMove &&other) noexcept;
    ~ButtonMove();
        
    int_c* getKeyUp();
    int_c* getKeyDown();

private:
    int_c* KeyUp;
    int_c* KeyDown;
};


//* STYLE
#define WALL_Y_PERPENDICULAR "│"
#define WALL_Y_ANGLE_UNDER_90_DOWN "┬"
#define WALL_Y_ANGLE_UNDER_90_TOP "┴"

#define WALL_X_IN_PARALLEL "─"
#define WALL_X_ANGLE_UNDER_90_LEFT "├"
#define WALL_X_ANGLE_UNDER_90_RIGHT "┤"


enum Color
{
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
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


int_c _UP[]    {KEY_W, UP};
int_c _DOWN[]  {KEY_S, DOWN};
int_c _LEFT[]  {KEY_A, LEFT}; 
int_c _RIGHT[] {KEY_D, RIGHT};

