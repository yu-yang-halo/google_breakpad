#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "test1.h"
#include "test2.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Test1 *test1;
    Test2 *test2;

private slots:
    void OnSig();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
