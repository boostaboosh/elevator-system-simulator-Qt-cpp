#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <iostream>
using namespace std;

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
    box->clear();
    // the floor can be any number from 1 to the number of floors which is numberOfFloors
    for (int counter = 0; counter < upperBound; counter++)
    {
        box->addItem("level " + QString::number(counter + 1));
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
    // clear values before I assign new values in case user presses start simulation twice
    fillComboBoxInRange(ui->floorSelectionComboBox, numFloors);

    // populate elevator selection elevator floor and elevator number comboboxes
    // populate elevator selection floor combobox
    fillComboBoxInRange(ui->elevatorFloorSelectionComboBox, numFloors);
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
    qInfo("starting simulation\n");

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
    ElevatorCar* next = &elevators[nextElevator];
    nextElevator++;
    return next;
}

void MainWindow::requestElevator()
{
    // recieve elevator request
    // identify selected floor
    int selectedFloorLevel = ui->floorSelectionComboBox->currentIndex(); // index in floors of the selected floor level
    Floor* thisFloor = &floors[selectedFloorLevel];
    // turn on button light by pressing the button
    thisFloor->button.pressButton();
    // request elevator at floor
    thisFloor->requestElevator();

    // send next elevator to the request floor
    ElevatorCar* nextElevator = getNextElevator();
    nextElevator->goToFloor(thisFloor);

    // execute arrival procedure
    nextElevator->executeArrivalProcedure();
}

void MainWindow::setupEventHandlers()
{
    // start simultation button event handler
    connect(ui->startSimulationButton, SIGNAL(released()), this, SLOT (startSimulation()));

    // floor up button event handler
    connect(ui->floorUpButton, SIGNAL(released()), this, SLOT(requestElevator()));
    // floor down button event handler
    connect(ui->floorDownButton, SIGNAL(released()), this, SLOT(requestElevator()));
}
