#include "elevatorcar.h"
#include <QDebug>

ElevatorCar::ElevatorCar()
{
    cargoLoad = 0;
    weightLimit = 0;
    elevatorNumber = 0;
    currentFloor;
    display = new Display{};
    sensor = new ArrivalSensor{};
    bell = new Bell{};
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
}

void ElevatorCar::executeArrivalProcedure()
{
    // elevator rings its bell
    this->bell->ring();

    // elevator and floor open their doors for 10 seconds

    // elevator rings bell again

    // elevator and floor close their doors

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
