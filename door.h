#ifndef DOOR_H
#define DOOR_H

#include "lightsensor.h"

/**
 * @brief The Door class models doors which open and close.
 */
class Door
{
public:
    Door();
    void open();
    void close();

private:
    bool doorIsOpen;
    const int openingDuration = 10;
    LightSensor lightSensor;
};

#endif // DOOR_H
