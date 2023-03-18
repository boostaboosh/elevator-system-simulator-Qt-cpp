#include "arrivalsensor.h"
#include <QDebug>

ArrivalSensor::ArrivalSensor()
{
    elevatorHasArrived = false;
}

void ArrivalSensor::notifyElevatorCar()
{
    if (elevatorHasArrived == true)
    {
        qInfo() << "arrival sensor is triggered";
    } else {
        qInfo() << "arrival sensor is not triggered";
    }
}
