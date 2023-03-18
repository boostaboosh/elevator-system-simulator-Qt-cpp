#ifndef ARRIVALSENSOR_H
#define ARRIVALSENSOR_H

/**
 * @brief The ArrivalSensor class models a sensor which can signal arrival at a certain floor.
 */
class ArrivalSensor
{
public:
    ArrivalSensor();
    void notifyElevatorCar();

public:
    bool elevatorHasArrived;
};

#endif // ARRIVALSENSOR_H
