#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QComboBox>
#include "floor.h"
#include "elevatorcar.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Floor* floors;
    ElevatorCar* elevators;

    int numberOfFloors;
    int numberOfElevators;

private:
    Ui::MainWindow *ui;
    void setupEventHandlers();
    void populateComboBoxes(int, int);
    void fillComboBoxInRange(QComboBox*, int);
    ElevatorCar* getNextElevator();
    ElevatorCar* getSelectedElevator();

private slots:
    void startSimulation();
    void requestElevator();
    void sendElevatorToFloor();
    void openDoors();
    void closeDoors();
    void helpSignal();
    void buildingFireSignal();
    void elevatorFireSignal();
    void addCargoLoad();
    void buildingPowerOutSignal();
};
#endif // MAINWINDOW_H
