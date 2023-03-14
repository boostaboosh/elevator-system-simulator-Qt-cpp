#ifndef DISPLAY_H
#define DISPLAY_H

#include "floor.h"
#include <string>
using namespace std;

/**
 * @brief The Display class models a display inside an elevator.
 */
class Display
{
public:
    Display();
    void displayFloorNumber(Floor);
    void displayWarningMessage(string);
    void clearDisplay();

private:
    string currentDisplayText;
};

#endif // DISPLAY_H
