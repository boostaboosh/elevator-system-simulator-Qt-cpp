#ifndef ELEVATORCAR_H
#define ELEVATORCAR_H

#include "button.h"
#include "elevatorcontrolsystem.h"
#include "floor.h"
#include "door.h"
#include "bell.h"
#include "display.h"
#include "audiosystem.h"
#include "arrivalsensor.h"

/**
 * @brief The ElevatorCar class models an elevator cab which services floors.
 */
class ElevatorCar
{
public:
    ElevatorCar();
    void goToFloor(Floor destinationFloor);
    void arriveAtFloor();
};

#endif // ELEVATORCAR_H
