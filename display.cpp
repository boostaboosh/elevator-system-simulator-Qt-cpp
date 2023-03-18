#include "display.h"
#include <string>

#include <QDebug>

Display::Display()
{
    currentDisplayFloorLevel = 0;
}

void Display::displayFloorNumber(Floor* floor)
{
    currentDisplayFloorLevel = floor->floorLevel;
    qInfo() << "Elevator display: " << currentDisplayFloorLevel;
}

void Display::displayWarningMessage(string message)
{
    // TODO: fill in implementation
}

void Display::clearDisplay()
{
    // TODO: fill in implementation
}
