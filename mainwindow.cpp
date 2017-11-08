#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keyboard.h"
#include <qthread.h>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->progressBarInit->setValue(0);
    this->frameTimer = new QTimer(this);
    this->frameTimer->setSingleShot(false);
    this->frameTimer->setInterval(50);
    connect(this->frameTimer,SIGNAL(timeout()),this,SLOT(onNewFrame()));

}

MainWindow::~MainWindow()
{
    if(this->screen){
        delete this->screen;
    }
    delete ui;
}


void MainWindow::on_buttonStart_clicked()
{
    if(!this->started){
        if(this->screen){
            delete this->screen;
        }
        this->screen = new Screen("Grand Theft Auto V");
        this->frameTimer->start();

        this->ui->buttonStart->setText("Stop");

    }
    else{
       this->ui->buttonStart->setText("Start");
       this->frameTimer->stop();
    }
    this->started=!this->started;

}

void MainWindow::onNewFrame(){
    qDebug()<<"New Frame !";
    this->ui->label->setPixmap(QPixmap::fromImage(this->screen->screenshot()));

}
