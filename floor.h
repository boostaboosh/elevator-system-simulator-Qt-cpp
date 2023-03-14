#ifndef FLOOR_H
#define FLOOR_H

#include "elevatorcar.h"
#include "door.h"
#include "button.h"

/**
 * @brief The Floor class describes a floor serviced by an elevator.
 */
class Floor
{
public:
    Floor(int floorLevelNumber);
    void requestElevator();

private:
    int floorLevel;
};

#endif // FLOOR_H
