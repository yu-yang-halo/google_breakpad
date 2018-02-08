#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "THUiKit/THUiToast.h"
#include <QDebug>
#include <QTime>
#include "QBreakpadHandler.h"
void appCrashFunc(bool isDump ,const QString &path,void* ctx){
     qDebug()<<"APP Crash";
     
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QBreakpadInstance.setAppCrashCallback(appCrashFunc,this);

    test1 = new Test1(this);
    test2 = new Test2(this);
    connect(test1, SIGNAL(sig()), this, SLOT(OnSig()));


    ui->stackedWidget->addWidget(test1);
    ui->stackedWidget->addWidget(test2);

    ui->stackedWidget->setCurrentIndex(1);
    test1->StartShow();





}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnSig()
{
    QTime tt;
    tt.start();
    while(tt.elapsed() <= 1000)
        QCoreApplication::processEvents();

    qDebug()<<"onSig ... ";

    int i=3;
    int j=0;
    int k=i/j;

    int* arr=new int[10];

    delete [] arr;


    arr = NULL;





    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget->setCurrentIndex(1);


    arr[2] = 100;


}
