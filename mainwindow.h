
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "myrobot.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initialise();
    void Dataanalysis();

private slots:
    void on_avant_clicked();
    void on_droite_clicked();
    void on_arriere_clicked();
    void on_gauche_clicked();
    void changevalue(const QByteArray );
    bool eventFilter(QObject* obj, QEvent* event);


    //void on_progressBar_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    void handleButton();
    MyRobot robot;
    QPushButton *m_button;

};

#endif // MAINWINDOW_H
