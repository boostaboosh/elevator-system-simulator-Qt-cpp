#include "light.h"
#include <QDebug>

Light::Light()
{
    lightTurnedOn = false;
}

void Light::switchOn()
{
    lightTurnedOn = true;
    qInfo() << "light turned on";
}

void Light::switchOff()
{
    lightTurnedOn = false;
    qInfo() << "light turned off";
}
