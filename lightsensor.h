#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

/**
 * @brief The LightSensor class models a light sensor which can be be interrupted.
 */
class LightSensor
{
public:
    LightSensor();
    void recieveSignal();

private:
    bool lightInterrupted;
};

#endif // LIGHTSENSOR_H
