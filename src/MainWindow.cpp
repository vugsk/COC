
#include "MainWindow.h"

#include "Config.h"
#include "ConverterTyptData.h"
#include "ErrorTest.h"



inline void IOSys::print(char_c *text, va_list args, WINDOW *window,  int_c y, int_c x) {
    move(y, x);
    vw_printw(window, text, args);
    wrefresh(window);
}

inline void IOSys::scan(char_c *str, va_list args, WINDOW *window,  int_c y, int_c x) {
    move(y, x);
    vw_scanw(window, str, args);
}

using std::exit;

inline bool_c conditionMoreOrLess(int_c cheackNum, int_c maxNumOrMinNum, bool_c sign) {
    return sign ? cheackNum > maxNumOrMinNum : cheackNum < maxNumOrMinNum; 
}

inline bool_c ConditionWithAnOrOrAndSign(int_c cheackNum, int_c minNum, int_c maxNum, bool_c sign) {
    return sign ? conditionMoreOrLess(cheackNum, minNum, false) && conditionMoreOrLess(cheackNum, maxNum, true) : 
                  conditionMoreOrLess(cheackNum, minNum, false) || conditionMoreOrLess(cheackNum, maxNum, true);
}

template <typename T1, typename T2, typename T3, typename T4>
void Screen::cheackError(function<void(T1, T2, T3, T4)> func, T1 t1, T2 t2, T3 t3, T4 t4) {
    try {
        func(t1, t2, t3, t4);
    } catch (exception &ex) {
        print("%s \n", ex.what());
        exit(EXIT_FAILURE);
    }
}

void Screen::ErrorSize(int_c size, bool_c ifSizeXY, int_c sizeAdditionally) {
    cheackError<int_c, bool_c, int_c, int_c>([this](int_c size, bool_c ifSizeXY, int_c sizeAdditionally, int_c io) {
        if (ifSizeXY) {
            if (sizeAdditionally < -1 || !sizeAdditionally) throw ErrorSizeLessThanZero();
        }
        if (size < -1 || !size) throw ErrorSizeLessThanZero(); 
    }, size, ifSizeXY, sizeAdditionally, 0);
}

void Screen::ErrorXY(int_c x, int_c y, int_c finishX, int_c finishY) {
    cheackError<int_c, int_c, int_c, int_c>([this](int_c x, int_c y, int_c finishX, int_c finishY) {
        if (finishX && finishY) {
            if (conditionMoreOrLess(finishX, this->x, true) || 
                conditionMoreOrLess(finishY, this->y, true)) throw ::ErrorXY();
        }
        if (ConditionWithAnOrOrAndSign(x, -1, this->x, true) ||
            ConditionWithAnOrOrAndSign(y, -1, this->y, true)) throw ::ErrorXY();
    }, x, y, finishX, finishY);
}

template<typename T> void Screen::ErrorVector(const vector<T> vec, bool_c ifT_vector) {
    cheackError<const vector<T>, bool_c, int_c, int_c>([this](const vector<T> vec, bool_c ifT_vector, int_c finishX, int_c finishY) {
        if (ifT_vector) {
            for (size_t i = 0; i < vec.size(); i++) {
                if (vec[i].empty()) throw ErrorVectorEmpty(); 
            }
        }
        if (vec.empty()) throw ErrorVectorEmpty();
    }, vec, ifT_vector, 0, 0);
}



int_c Screen::getX() { return x; }
int_c Screen::getY() { return y; }
int_c Screen::getChoice() { return _choice; }
int_c Screen::getHighlight() { return _highlight; }
int_c Screen::getHighlightX() { return _highlightX; }
int_c Screen::getHighlightY() { return _highlightY; }

void Screen::setHighlight(int_c highlight) { _highlight = highlight; }


void Screen::clear() { wclear(win); }
void Screen::refresh() { wrefresh(win); }
void Screen::setCurs(int_c numCurs) { curs_set(numCurs);}
void Screen::echoOn() { echo(); }
void Screen::echoOff() { noecho(); }
void Screen::box(int_c a, int_c b) { ::box(win, a, b); }
void Screen::close() { delwin(win); }
int_c Screen::getChar() { return _choice = wgetch(win); }
void Screen::attrOn(int_c attr) { wattron(win, attr); }
void Screen::attrOff(int_c attr) { wattroff(win, attr); }
void Screen::keypad(bool_c key) { ::keypad(win, key); }

void Screen::cheackColorSupport() {
    try {
        if (!has_colors()) throw ErrorColorSupport();
    } catch (exception &ex) {
        print("%s \n", ex.what());
        exit(EXIT_FAILURE);
    }
}

void Screen::print(int_c x, int_c y, char_c* text, ...) {
    va_list args;
    va_start(args, text);
    IOSys::print(text, args, win, y, x);
    va_end(args);
}

void Screen::print(char_c* text, ...) {
    va_list args;   
    va_start(args, text);
    IOSys::print(text, args, win);
    va_end(args);
}

void Screen::addChar(char_c ch, int_c x, int_c y) {
    ErrorXY(x, y);
    mvwaddch(win, y, x, ch);
}

void Screen::addStr(char_c *str, int_c x, int_c y) {
    ErrorXY(x, y);
    mvwaddstr(win, y, x, str);
}

void Screen::scan(char_c *str, ...) {
    va_list args;
    va_start(args, str);
    IOSys::scan(str, args, win);
    va_end(args);
}

void Screen::scan(int_c x, int_c y, char_c *str, ...) {
    va_list args;
    va_start(args, str);
    IOSys::scan(str, args, win, y, x);
    va_end(args);
}

int_c Screen::ifTheWsOrAdButtonIsPressed(int_vec_c button, int highlight, int size) {
    if ((_choice == button[0]) || (_choice == button[1])) {
        if (!size) {
            if (highlight == -1) return 0;
            return --highlight;
        } else {
            if (highlight == size) return size--;
            return ++highlight; 
        }
    }

    if (highlight == size) {
        if (!size) return 0;
        else return size--;
    }

    return highlight;
}

void Screen::wsOrAdButton(int_c size, bool_c WS_or_AD) {
    ErrorSize(size);
    getChar();

    int_pair_vec button_WS_or_AD;
    if (WS_or_AD) button_WS_or_AD = {{KEY_W, UP}, {KEY_S, DOWN}};
    else          button_WS_or_AD = {{KEY_A, LEFT}, {KEY_D, RIGHT}};

    _highlight = ifTheWsOrAdButtonIsPressed(button_WS_or_AD.second, _highlight, size);
    _highlight = ifTheWsOrAdButtonIsPressed(button_WS_or_AD.first, _highlight);
}

void Screen::wasdButton(int_c size_x, int_c size_y) {
    ErrorSize(size_x, true, size_y);
    getChar();

    int_vec_pair_vec button_WASD{
        {{KEY_W, UP}, {KEY_S, DOWN}}, 
        {{KEY_A, LEFT}, {KEY_D, RIGHT}}
    };

    _highlightY = ifTheWsOrAdButtonIsPressed(button_WASD[0].second, _highlightY, size_y);
    _highlightY = ifTheWsOrAdButtonIsPressed(button_WASD[0].first, _highlightY);

    _highlightX = ifTheWsOrAdButtonIsPressed(button_WASD[1].second, _highlightX, size_x);
    _highlightX = ifTheWsOrAdButtonIsPressed(button_WASD[1].first, _highlightX);
}

void Screen::clear(int_c start_x, int_c start_y, int_c finish_x, int_c finish_y) {
    ErrorXY(start_x, start_y, finish_x, finish_y);
    for (int i = start_y; i <= finish_y; i++) {
        for (int j = start_x; j <= finish_x; j++) {
            addChar(' ', j, i);
        }
    }
}

void Screen::drawWall(int wall_x, int wall_y, bool_c drawWallXOrY) {
    ErrorXY(wall_x, wall_y);

    char_c* WALL;
    char_c* WALL_90;
    char_c* WALL_180;

    int numXOrY;

    if (drawWallXOrY) {
        WALL = WALL_Y_PERPENDICULAR;
        WALL_90 = WALL_Y_ANGLE_UNDER_90_DOWN;
        WALL_180 = WALL_Y_ANGLE_UNDER_90_TOP;
        
        numXOrY = y;
    } else {
        WALL = WALL_X_IN_PARALLEL;
        WALL_90 = WALL_X_ANGLE_UNDER_90_LEFT;
        WALL_180 = WALL_X_ANGLE_UNDER_90_RIGHT;

        numXOrY = x;

        int temp;
        temp = wall_x;
        wall_x = wall_y;
        wall_y = temp;
    }

    for (int i = numXOrY - wall_x; i < numXOrY; i++) {
        if (i != numXOrY - 1) {
            if (drawWallXOrY) print(wall_x, i, WALL);
            else              print(i, wall_y, WALL);
        }
    }

    if (drawWallXOrY) {
        print(wall_x, y - wall_y, WALL_90);
        print(wall_x, y - 1, WALL_180);
    } else {
        print(x - wall_x, wall_y, WALL_90);
        print(x - 1, wall_y, WALL_180);
    }
}



void Screen::textSelection(str_vec_c vec, int_c x, int_c y) {
    ErrorVector(vec, false);
    ErrorXY(x, y);

    for (size_t i = 0; i < vec.size(); i++) {
        if (i == _highlight) attrOn(A_REVERSE);
        print(x, y+i, vec[i].c_str());
        attrOff(A_REVERSE);
    }
}

void Screen::textSelection(str_vec_c vec, function<void(int, str_vec_c)> func) {
    ErrorVector(vec, false);

    for (size_t i = 0; i < vec.size(); i++) {
        if (i == _highlight) attrOn(A_REVERSE);
        func(i, vec);
        attrOff(A_REVERSE);
    }
}

template<typename T> void Screen::textSelectionTable(const vector<vector<T>> tableVec, function<void(int, int)> func) {
    ErrorVector(tableVec, true);

    for (size_t i = 0; i < tableVec.size(); i++) {
        for (size_t j = 0; j < tableVec[i].size(); j++) {
            if (j == _highlightX && i == _highlightY) {
                attrOn(A_REVERSE);
            }

            if (i == 0 || j == 0) { func(i, j); }
            else                  { func(i, j); }

            attrOff(A_REVERSE);
        }
    }
}

Screen* Screen::createWindow(int_c x, int_c y, int_c width, int_c height) {
    WINDOW* WIN = newwin(y, x, height, width);
    return new Screen(win, x, y);
}

Screen::Screen(WINDOW* win, int_c x, int_c y)
        : win(win), x(x), y(y) {
    _highlight = 0;
    _highlightX = 0;
    _highlightY = 0;
}

Screen::~Screen() { delwin(win); }

