#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mytime.h"
#include "screen.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_buttonStart_clicked();
    void onNewFrame();
private:
    Ui::MainWindow *ui;
    bool started=false;
    Screen *screen;
    QTimer *frameTimer;
};

#endif // MAINWINDOW_H
