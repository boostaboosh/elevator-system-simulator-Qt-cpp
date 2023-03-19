#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <iostream>
using namespace std;
#include <QApplication>
#include <QEventLoop>
#include <QTimer>
#include <QDebug>
#include <QCoreApplication>

Floor* floors;
ElevatorCar* elevators;

int numberOfFloors;
int numberOfElevators;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupEventHandlers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillComboBoxInRange(QComboBox* box, int upperBound)
{
    // clear values before I assign new values in case user presses start simulation twice
    box->clear();
    // the floor can be any number from 1 to the number of floors which is numberOfFloors
    for (int counter = 0; counter < upperBound; counter++)
    {
        box->addItem(QString::number(counter + 1));
    }
}

/**
 * @brief MainWindow::populateComboBoxes fills the comboboxes in the UI with values according to simulation selection.
 * @param numFloors
 * @param numElevators
 */
void MainWindow::populateComboBoxes(int numFloors, int numElevators)
{
    // populate floor selection combo box
    fillComboBoxInRange(ui->floorSelectionComboBox, numFloors);

    // populate elevator selection elevator number combobox
    fillComboBoxInRange(ui->elevatorSelectionComboBox, numElevators);

    // populate destination floor combobox
    fillComboBoxInRange(ui->elevatorDestinationFloorComboBox, numFloors);
}

/**
 * @brief MainWindow::startSimulation Start an elevator system simulation using the number or floors and elevators inputted.
 */
void MainWindow::startSimulation()
{    
    // The start simulation button creates a new simulation which stores elevators and floors in arrays.
    qInfo("starting simulation \nelevators will start on floor zero\n");

    // populate floors array
    numberOfFloors = ui->numberOfFloorsSpinBox->value();
    floors = new Floor[numberOfFloors];
    for (int floorCounter = 0; floorCounter < numberOfFloors; floorCounter++)
    {
        Floor* floor = new Floor(floorCounter + 1);
        floors[floorCounter] = *floor;
    }

    // populate elevators array
    numberOfElevators = ui->numberOfElevatorsSpinBox->value();
    elevators = new ElevatorCar[numberOfElevators];
    int carWeightLimit = ui->elevatorCarWeightLimitSpinBox->value();
    for (int elevatorCounter = 0; elevatorCounter < numberOfElevators; elevatorCounter++)
    {
        ElevatorCar elevator{carWeightLimit, elevatorCounter + 1, floors};
        elevators[elevatorCounter] = elevator;
    }

    // populates comboboxes for the floor and elevator selections and the destination floor options.
    populateComboBoxes(numberOfFloors, numberOfElevators);
}

int nextElevator = 0;
ElevatorCar* MainWindow::getNextElevator(){
    nextElevator = nextElevator % (numberOfElevators);
    ElevatorCar* next = elevators+nextElevator;
    nextElevator++;
    return next;
}

void MainWindow::requestElevator()
{
    // recieve elevator request
    // identify selected floor
    int selectedFloorLevel = ui->floorSelectionComboBox->currentIndex(); // index in floors of the selected floor level
    Floor* thisFloor = floors+selectedFloorLevel;
    // turn on button light by pressing the button
    thisFloor->button.pressButton();
    // request elevator at floor
    thisFloor->requestElevator();

    // send next elevator to the request floor
    ElevatorCar* nextElevator = getNextElevator();
    nextElevator->goToFloor(thisFloor);

    // execute arrival procedure
    nextElevator->executeArrivalProcedure(ui->doorObstacleCheckBox->isChecked());
}

ElevatorCar* MainWindow::getSelectedElevator()
{
    // identify selected elevator
    int selectedElevatorIndex = ui->elevatorSelectionComboBox->currentIndex();
    ElevatorCar* selectedElevator = elevators + selectedElevatorIndex;
    return selectedElevator;
}

void MainWindow::sendElevatorToFloor()
{
    // identify selected elevator
    ElevatorCar* selectedElevator = getSelectedElevator();

    // identify selected destination floor
    int selectedDestinationFloorIndex = ui->elevatorDestinationFloorComboBox->currentIndex();
    Floor* destinationFloor = floors + selectedDestinationFloorIndex;

    // send selected elevator to selected destination floor
    selectedElevator->goToFloor(destinationFloor);
    // execute arrival procedure after selected elevator arrives at arrival floor
    selectedElevator->executeArrivalProcedure(ui->doorObstacleCheckBox->isChecked());
}

void MainWindow::openDoors()
{
    // identify selected elevator
    ElevatorCar* selectedElevator = getSelectedElevator();

    // open selected elevator and its floor's doors for 10 seconds
    qInfo() << "\nElevator number " << selectedElevator->elevatorNumber;
    selectedElevator->openElevatorAndFloorDoorsForTenSeconds();

    // close the doors again
    selectedElevator->closeElevatorAndFloorDoors(ui->doorObstacleCheckBox->isChecked());
}

void MainWindow::closeDoors()
{
    // identify selected elevator
    ElevatorCar* selectedElevator = getSelectedElevator();

    // stop the selected elevator from keeping its doors open for 10 seconds
    selectedElevator->stopFlag = true;

    // close the doors of the selected elevator
    qInfo() << "Elevator number " << selectedElevator->elevatorNumber;
    selectedElevator->closeElevatorAndFloorDoors(ui->doorObstacleCheckBox->isChecked());
}

void MainWindow::helpSignal()
{
    // identify selected elevator
    ElevatorCar* selectedElevator = getSelectedElevator();

    // connect passenger to building safety service through
    qInfo() << "Connecting elevator " << selectedElevator->elevatorNumber << " to building safety service";

    // if building safety services does not respond then call 911
    qInfo() << "No response -> 911 placed";
}

void MainWindow::setupEventHandlers()
{
    // start simultation button event handler
    connect(ui->startSimulationButton, SIGNAL(released()), this, SLOT (startSimulation()));

    // floor up button event handler
    connect(ui->floorUpButton, SIGNAL(released()), this, SLOT(requestElevator()));
    // floor down button event handler
    connect(ui->floorDownButton, SIGNAL(released()), this, SLOT(requestElevator()));

    // go to destination elevator button handler
    connect(ui->goToDestinationFloorButton, SIGNAL(released()), this, SLOT(sendElevatorToFloor()));

    // open doors button inside elevator event handler
    connect(ui->openDoorButton, SIGNAL(released()), this, SLOT(openDoors()));

    // close doors button inside elevator event handler
    connect(ui->closeDoorButton, SIGNAL(released()), this, SLOT(closeDoors()));

    // elevator help button functionality
    connect(ui->elevatorHelpButton, SIGNAL(released()), this, SLOT(helpSignal()));
}
