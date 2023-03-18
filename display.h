#ifndef DISPLAY_H
#define DISPLAY_H

#include "floor.h"
#include <string>
using namespace std;

class Floor;
/**
 * @brief The Display class models a display inside an elevator.
 */
class Display
{
public:
    Display();
    void displayFloorNumber(Floor* floor);
    void displayWarningMessage(string);
    void clearDisplay();

private:
    int currentDisplayFloorLevel;
};

#endif // DISPLAY_H
