#include "elevatorcar.h"
#include <iostream>
#include <QDebug>
#include <chrono>
using namespace std::chrono;

ElevatorCar::ElevatorCar()
{
    cargoLoad = 0;
    weightLimit = 0;
    elevatorNumber = 0;
    currentFloor;
    display = new Display{};
    sensor = new ArrivalSensor{};
    bell = new Bell{};
    door = new Door{};
    stopFlag = false;
    audioSystem = new AudioSystem{};
    overloaded = false;
}

ElevatorCar::ElevatorCar(int carWeightLimit, int elevatorNumber, Floor* floor)
{
    cargoLoad = 0;
    weightLimit = carWeightLimit;
    this->elevatorNumber = elevatorNumber;
    currentFloor = floor;
    display = new Display{};
    sensor = new ArrivalSensor{};
    bell = new Bell{};
    door = new Door{};
    stopFlag = false;
    audioSystem = new AudioSystem{};
    overloaded = false;
}

void ElevatorCar::openElevatorAndFloorDoorsForTenSeconds()
{
    // elevator and floor open their doors
    qInfo() << "Elevator and floor doors:";
    this->door->open();
    this->currentFloor->door.open();

    // elevator and floor remain open for 10 seconds to allow people to board
    qInfo() << "wait 10 seconds";
    auto startTime = steady_clock::now();
    while (duration_cast<seconds>(steady_clock::now() - startTime).count() < 10){
        if (stopFlag == true){
            return;
        }
    }
}

void ElevatorCar::closeElevatorAndFloorDoors(bool obstructed)
{
    // if obstructed doors checkbox is checked I need to interrupt the elevator door's light sensor
    if (obstructed){
        this->door->lightSensor.lightInterrupted = true;
        this->currentFloor->door.lightSensor.lightInterrupted = true;
    } else if (!obstructed) {
        this->door->lightSensor.lightInterrupted = false;
        this->currentFloor->door.lightSensor.lightInterrupted = false;
    }

    // elevator and floor close their doors
    this->door->close();
    this->currentFloor->door.close();
}

void ElevatorCar::executeArrivalProcedure(bool obstructed)
{
    // elevator rings its bell
    this->bell->ring();

    // elevator and floor open their doors for 10 seconds
    openElevatorAndFloorDoorsForTenSeconds();

    // elevator rings bell again
    this->bell->ring();

    // elevator and floor close their doors
    closeElevatorAndFloorDoors(obstructed);
}

void ElevatorCar::moveUp()
{
    // move elevator up 1 floor
    this->currentFloor++;
    qInfo() << "Elevator " << this->elevatorNumber << " moved up a floor";

    // update elevator display text
    this->display->displayFloorNumber(currentFloor);
}

void ElevatorCar::moveDown()
{
    // move elevator down 1 floor
    this->currentFloor--;
    qInfo() << "Elevator " << this->elevatorNumber << " moved down a floor";

    //update elevator display text
    this->display->displayFloorNumber(currentFloor);
}

void ElevatorCar::goToFloor(Floor* destinationFloor)
{
    // if elevator is overlaoded do not move and trigger overloaded messages to passengers
    if (this->overloaded == true){
        // display audio and text messages asking for the laod to be reduced before attempting to move again
        this->display->displayWarningMessage("Elevator is overloaded. Reduce cargo load before attempting to move again.");
        this->audioSystem->playMessage("Elevator is overloaded. Reduce cargo load before attempting to move again.");
        return;
    }

    // console output to display elevator going to floor
    qInfo() << "Elevator " << this->elevatorNumber << " going to floor " << destinationFloor->floorLevel;

    // set arrival sensor to false
    sensor->elevatorHasArrived = false;

    // move elevator until arrival sensor says elevator has arrived at arrival floor
    while (currentFloor->floorLevel < destinationFloor->floorLevel)
    {
        moveUp();
    }
    while (currentFloor->floorLevel > destinationFloor->floorLevel)
    {
        moveDown();
    }

    // arrive at destination floor
    qInfo() << "Elevator " << this->elevatorNumber << " arrived at floor " << destinationFloor->floorLevel;
    // arrival sensor alerts elevator that it has arrived at floor
    sensor->elevatorHasArrived = true;
    sensor->notifyElevatorCar();
    // if elevator moved because of floor request the floor button switches off its light by unpressing itself
    if (currentFloor->button.buttonIsPressed == true)
    {
        currentFloor->button.pressButton();
    }
}
