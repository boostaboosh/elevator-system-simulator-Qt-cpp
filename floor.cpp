#include "floor.h"
#include "QDebug"

#include <iostream>
using namespace std;

Floor::Floor()
{
    floorLevel = 0;
    button = Button{};
}

Floor::Floor(int floorLevelNumber)
{
    floorLevel = floorLevelNumber;
    button = Button{};
}

void Floor::requestElevator()
{
    // console output to display button press
    qInfo() << "Request elevator at floor " << this->floorLevel;

}
