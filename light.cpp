#include "light.h"

Light::Light()
{
    lightTurnedOn = false;
}

void Light::switchOn()
{
    lightTurnedOn = true;
}

void Light::switchOff()
{
    lightTurnedOn = false;
}
