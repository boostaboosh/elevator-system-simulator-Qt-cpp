#ifndef ELEVATORCONTROLSYSTEM_H
#define ELEVATORCONTROLSYSTEM_H

/**
 * @brief The ElevatorControlSystem class controls elevator safety systems within an elevator system.
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
