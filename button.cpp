#include "button.h"

Button::Button()
{
    buttonIsPressed = false;
    Light light{};
}

void Button::pressButton()
{
    if (buttonIsPressed == false)
    {
        buttonIsPressed = true;
        light.switchOn();
    } else // buttonIsPressed is equal to true
    {
        buttonIsPressed = false;
        light.switchOff();
    }
}
