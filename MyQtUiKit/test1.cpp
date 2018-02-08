#include "test1.h"
#include "ui_test1.h"
#include <QTimer>
#include <QDebug>
Test1::Test1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Test1)
{
    ui->setupUi(this);


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

}

Test1::~Test1()
{
    delete ui;
}

void Test1::StartShow()
{
    timer->start(1000);
}

void Test1::update()
{
    qDebug()<<"update ... ";

    this->hide();
    static int i=0;
    ui->pushButton->setText(QString::number((i++)));

    this->show();
    emit sig();
}
