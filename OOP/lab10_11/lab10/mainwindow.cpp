#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
