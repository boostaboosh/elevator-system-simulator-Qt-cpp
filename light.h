#ifndef LIGHT_H
#define LIGHT_H

/**
 * @brief The Light class models a light that can be switched on and off.
 */
class Light
{
public:
    Light();
    void switchOn();
    void switchOff();

private:
    bool lightTurnedOn;
};

#endif // LIGHT_H
