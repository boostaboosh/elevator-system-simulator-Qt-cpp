#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QComboBox>
#include "floor.h"
#include "elevatorcar.h"
#include "elevatorcontrolsystem.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void setupEventHandlers();
    void populateComboBoxes(int, int);
    void fillComboBoxInRange(QComboBox*, int);
//    ElevatorCar getClosestElevator(Floor);
    ElevatorCar* getNextElevator();

private slots:
    void startSimulation();
    void requestElevator();
};
#endif // MAINWINDOW_H
