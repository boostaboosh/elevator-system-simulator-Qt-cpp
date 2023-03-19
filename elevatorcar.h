#ifndef ELEVATORCAR_H
#define ELEVATORCAR_H

#include "button.h"
#include "floor.h"
#include "door.h"
#include "bell.h"
#include "display.h"
#include "audiosystem.h"
#include "arrivalsensor.h"

class Floor;
class Display;
class ArrivalSensor;
class Bell;
class Door;
/**
 * @brief The ElevatorCar class models an elevator cab which services floors.
 */
class ElevatorCar
{
public:
    ElevatorCar();
    ElevatorCar(int carWeightLimit, int elevatorNumber, Floor* floor);
    void goToFloor(Floor* destinationFloor);
    void moveUp();
    void moveDown();
    void executeArrivalProcedure(bool obstructed);
    void closeElevatorAndFloorDoors(bool obstructed);
    void openElevatorAndFloorDoorsForTenSeconds();

public:
    Floor* currentFloor;
    int cargoLoad;
    int weightLimit;
    int elevatorNumber;
    Display* display;
    ArrivalSensor* sensor;
    Bell* bell;
    Door* door;
    bool stopFlag;
    AudioSystem* audioSystem;
    bool overloaded;
};

#endif // ELEVATORCAR_H
