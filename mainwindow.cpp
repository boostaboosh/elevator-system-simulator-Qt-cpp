#include "mainwindow.h"
#include "ui_mainwindow.h"

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

/**
 * @brief MainWindow::startSimulation Start an elevator system simulation using the number or floors and elevators inputted.
 */
void MainWindow::startSimulation()
{
    qInfo("Hello world!");
}

void MainWindow::setupEventHandlers()
{
    connect(ui->startSimulationButton, SIGNAL(released()), this, SLOT (startSimulation()));
}
