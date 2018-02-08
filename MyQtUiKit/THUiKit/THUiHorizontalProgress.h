#ifndef THUIHORIZONTALPROGRESS_H
#define THUIHORIZONTALPROGRESS_H
#include "THUiAbstractProgress.h"
class THUiHorizontalProgress : public THUiAbstractProgress
{
    Q_OBJECT
public:
    explicit THUiHorizontalProgress(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *event);
    virtual void onEvent(int x,int y);
signals:

public slots:

};

#endif // THUIHORIZONTALPROGRESS_H
