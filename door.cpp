#include "door.h"
#include <QDebug>

Door::Door()
{
    doorIsOpen = false;
    LightSensor lightSensor{};
}

void Door::close()
{
    if (lightSensor.lightInterrupted == true)
    {
        qInfo() << "Cannot close doors because obstructed!\n";
    } else if (lightSensor.lightInterrupted == false){
        doorIsOpen = false;
        qInfo() << "close door";
    }
}

void Door::open()
{
    doorIsOpen = true;
    qInfo() << "open door";
}
