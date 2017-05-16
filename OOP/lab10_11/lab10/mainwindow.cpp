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

    QPushButton btn1("test", this);
    QWidget p;
    QPushButton btn2("other", &btn1);

    p.setWindowTitle("fuck this shit really");
    p.show();
    btn1.show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
