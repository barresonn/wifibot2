
#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>


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
    //changevalue(NULL);
    connect(&robot, SIGNAL(updateUI(const QByteArray)),this, SLOT(changevalue(const QByteArray)));
}



void MainWindow::on_avant_clicked()
{
    qDebug("avant");
    robot.changeDatatosend(255,0x07,120,0,120,0,0b01010000);
}



void MainWindow::on_droite_clicked()
{
    robot.changeDatatosend(255,0x07,120,0,120,0,0b00010000);
    qDebug("droite");
}


void MainWindow::on_arriere_clicked()
{

    robot.changeDatatosend(255,0x07,120,0,120,0,0b00000000);
    qDebug("ariere");
}


void MainWindow::on_gauche_clicked()
{
    robot.changeDatatosend(255,0x07,120,0,120,0,0b01000000);

    qDebug("avant");
}


void MainWindow::changevalue(const QByteArray Data)
{

    ui->progressBar->setValue(Data[2]);//batterie
    qDebug("test");
    int Lspeed = ((Data[1] << 8) + Data[0]);
    if (Lspeed > 32767){ Lspeed=Lspeed-65536;};
    ui->speedleft2->setValue(Lspeed);//speed left

    int Rspeed = ((Data[10] << 8) + Data[9]);
    if (Rspeed > 32767){ Lspeed=Lspeed-65536;};
    ui->speedr->setValue(Rspeed);//speed right
    ui->speedright2->setValue(Rspeed);
}
bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type()==QEvent::KeyPress) {
        QKeyEvent* key = static_cast<QKeyEvent*>(event);
        if ( (key->key()==Qt::Key_Forward)) {
            robot.changeDatatosend(255,0x07,120,0,120,0,0b01000000);}
        if ( (key->key()==Qt::Key_Back)) {
            robot.changeDatatosend(255,0x07,120,0,120,0,0b01000000);}
        if ( (key->key()==Qt::Key_Left)) {
            robot.changeDatatosend(255,0x07,120,0,120,0,0b01000000);}
        if ( (key->key()==Qt::Key_Right)) {
            robot.changeDatatosend(255,0x07,120,0,120,0,0b01000000);}
    } else {
        return QObject::eventFilter(obj, event);
    }
    return false;

}
