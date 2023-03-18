#include "door.h"
#include <QTimer>
#include <QDebug>

Door::Door()
{
    doorIsOpen = false;
    LightSensor lightSensor{};
}

void Door::close()
{
    doorIsOpen = false;
    qInfo() << "close door";
}

void Door::open()
{
    doorIsOpen = true;
    qInfo() << "open door";
}
