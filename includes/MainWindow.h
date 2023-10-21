
#pragma once

#include <Config.h>

namespace IOSys {
    inline void print(char_c *text, va_list args, WINDOW *window,  int_c y = 0, int_c x = 0);
    inline void scan(char_c *str, va_list args, WINDOW *window,  int_c y = 0, int_c x = 0);
}

class Screen {
public:
    Screen(const Screen &)            = delete;
    Screen(Screen &&)                 = delete;
    Screen &operator=(const Screen &) = delete;
    Screen &operator=(Screen &&)      = delete;
    Screen(WINDOW* win=stdscr, int_c x=getmaxx(stdscr), int_c y=getmaxy(stdscr));
    ~Screen();
    
    int_c getX();
    int_c getY();
    int_c getChoice();
    int_c getHighlight();
    int_c getHighlightX();
    int_c getHighlightY();

    void cheackColorSupport();
    
    void setHighlight(int_c highlight);

    void print(int_c x, int_c y, char_c* text, ...);
    void print(char_c* text, ...);

    void addChar(char_c ch=' ', int_c x=0, int_c y=0);
    void addStr(char_c *str, int_c x=0, int_c y=0);

    void scan(int_c x, int_c y, char_c *str, ...);
    void scan(char_c *str, ...);

    void clear();
    void clear(int_c x, int_c y, int_c width, int_c height);
    void refresh();
    void setCurs(int_c numCurs);
    void echoOn();
    void echoOff();
    void box(int_c a, int_c b);
    void close();
    int_c getChar();
    void attrOn(int_c attrs);
    void attrOff(int_c attrs);
    void keypad(bool_c key);
 
    void wsOrAdButton(int_c size, bool_c WS_or_AD = true);
    void wasdButton(int_c size_x, int_c size_y);
    void clearWin(int_c start_x, int_c start_y, int_c finish_x, int_c finish_y);
    void drawWall(int wall_x, int wall_y, bool_c drawWallXOrY = true); 
    void textSelection(str_vec_c vec, int_c x, int_c y);
    void textSelection(str_vec_c vec, function<void(int, str_vec_c)> func);
    template<typename T> void textSelectionTable(const vector<vector<T>> tableVec, function<void(int, int)> func);
    Screen* createWindow(int_c x, int_c y, int_c width, int_c height);

private:
    WINDOW* win;
    int x, y;
    int _choice;
    int _highlight;
    int _highlightX;
    int _highlightY;

    int_c ifTheWsOrAdButtonIsPressed(int_vec_c button, int highlight, int size=0);
    void ErrorXY(int_c x, int_c y, int_c finishX=0, int_c finishY=0);
    template<typename T> void ErrorVector(const vector<T> vec, bool_c ifT_vector);
    void ErrorSize(int_c size, bool_c ifSizeXY=false, int_c sizeAdditionally=0);
    
    template<typename T1, typename T2, typename T3, typename T4>
    void cheackError(function<void(T1, T2, T3, T4)> func, T1 t1, T2 t2, T3 t3, T4 t4);
};

