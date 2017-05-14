#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget *wnd = new QWidget;
    QHBoxLayout *hLay = new QHBoxLayout();
    //QVBoxLayout *hLay = new QVBoxLayout();
    QPushButton *btn1 = new QPushButton("Btkjashdakjdakjskjsasd &1");
    QPushButton *btn2 = new QPushButton("Bt &2");
    QPushButton *btn3 = new QPushButton("Bt &3");
    hLay->addWidget(btn1);
    //hLay->addStretch();
    hLay->addWidget(btn2);
    //hLay->addStretch();
    hLay->addWidget(btn3);
    wnd->setLayout(hLay);
    wnd->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
