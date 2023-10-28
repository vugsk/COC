
#include "Config.h"



int_c* ButtonMove::getKeyUp() { return KeyUp; }
int_c* ButtonMove::getKeyDown() { return KeyDown; }




ButtonMove::ButtonMove(int_c* KeyUp, int_c* KeyDown)
    : KeyUp(KeyUp), KeyDown(KeyDown) {}

ButtonMove::ButtonMove(const ButtonMove &other) 
    : KeyUp(!other.KeyUp? new int(*other.KeyUp) : nullptr)
    , KeyDown(!other.KeyDown? new int(*other.KeyDown) : nullptr){}

ButtonMove::ButtonMove(ButtonMove &&other) noexcept 
    : KeyUp(nullptr), KeyDown(nullptr)
{
    KeyUp = other.KeyUp;
    KeyDown = other.KeyDown;

    other.KeyUp = nullptr;
    other.KeyDown = nullptr;
}

ButtonMove& ButtonMove::operator=(const ButtonMove &other)
{
    if (this != &other) {
        if (!KeyUp) {
            KeyUp = new int(*other.KeyUp);
        } else {
            KeyUp = nullptr;
        }

        if (!KeyDown) {
            KeyDown = new int(*other.KeyDown);
        } else {
            KeyDown = nullptr;
        }
    }

    return *this;
}

ButtonMove& ButtonMove::operator=(ButtonMove &&other) noexcept
{
    if (this != &other)
    {
        KeyUp = nullptr;
        KeyDown = nullptr;

        KeyUp = other.KeyUp;
        KeyDown = other.KeyDown;

        other.KeyUp = nullptr;
        other.KeyDown = nullptr;
    }

    return *this;
}

ButtonMove::~ButtonMove()
{
    if (!KeyUp)
    {
        delete [] KeyUp;
    }

    if (!KeyDown)
    {
        delete [] KeyDown;
    }
}
    
