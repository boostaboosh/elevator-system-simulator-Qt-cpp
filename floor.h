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
    Floor();
    Floor(int floorLevelNumber);
    void requestElevator();

public:
    int floorLevel;
    Button button;
    Door door;
};

#endif // FLOOR_H
