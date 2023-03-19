#ifndef ELEVATORCONTROLSYSTEM_H
#define ELEVATORCONTROLSYSTEM_H

#include "elevatorcar.h"
#include "floor.h"

/**
 * @brief The ElevatorControlSystem class controls elevator safety systems within an elevator system and mediates between floor and elevator requests.
 */
class ElevatorControlSystem
{
public:
    ElevatorControlSystem();
    void runObstructedDoorProcedure();
    void runElevatorHelpProcedure();
    void runBuildingFireProcedure();
    void runElevatorFireProcedure();
    void runPowerOutProcedure();
    void runElevatorOverloadProcedure();
};

#endif // ELEVATORCONTROLSYSTEM_H
