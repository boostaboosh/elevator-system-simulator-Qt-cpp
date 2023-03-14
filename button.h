#ifndef BUTTON_H
#define BUTTON_H

#include "light.h"

/**
 * @brief The Button class models a button which can be pressed.
 */
class Button
{
public:
    Button();
    void pressButton();

private:
    bool buttonIsPressed;
    Light light;
};

#endif // BUTTON_H
