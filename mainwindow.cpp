
#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}
void MainWindow::initialise(){
    robot.doConnect();
    //robot.readyRead();
    changevalue();
}



void MainWindow::on_avant_clicked()
{
    qDebug("avant");
    robot.changeDatatosend(255,0x07,120,0,120,0,0b01010000);
}



void MainWindow::on_droite_clicked()
{
    robot.changeDatatosend(255,0x07,0,0,120,0,0b01010000);
    qDebug("droite");
}


void MainWindow::on_arriere_clicked()
{

    robot.changeDatatosend(255,0x07,120,0,120,0,0b00000000);
    qDebug("ariere");
}


void MainWindow::on_gauche_clicked()
{
    robot.changeDatatosend(255,0x07,120,0,0,0,0b01010000);


    qDebug("avant");
}



void MainWindow::changevalue()
{
    ui->progressBar->setValue(robot.DataReceived[2]);//batterie
    qDebug("test");
    int Lspeed = -((robot.DataReceived[1] << 8) + robot.DataReceived[0]);
    if (Lspeed > 32767){ Lspeed=Lspeed-65536;};
    ui->speedl->setValue(Lspeed/100);//speed left


    ui->speedr->setValue(68);//batterie
}
