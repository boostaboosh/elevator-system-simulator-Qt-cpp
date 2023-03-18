#include "button.h"
#include <QDebug>

//Button::Button()
//{
//}

void Button::pressButton()
{
    if (buttonIsPressed == false)
    {
        buttonIsPressed = true;
        qInfo() << "\nbutton pressed";
        light.switchOn();
    } else // buttonIsPressed is equal to true (so unpress button)
    {
        buttonIsPressed = false;
        light.switchOff();
    }
}
