#ifndef TEST1_H
#define TEST1_H

#include <QWidget>

namespace Ui {
class Test1;
}

class Test1 : public QWidget
{
    Q_OBJECT

public:
    explicit Test1(QWidget *parent = 0);
    ~Test1();
    void StartShow();

signals:
    void sig();

private slots:
    void update();


private:
    Ui::Test1 *ui;
    QTimer *timer;
};

#endif // TEST1_H
