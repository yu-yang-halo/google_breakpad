#ifndef THUIPROGRESS_H
#define THUIPROGRESS_H

#include <QWidget>
#include "THUiAbstractProgress.h"


class THUiVerticalProgress : public THUiAbstractProgress
{
    Q_OBJECT
public:
    explicit THUiVerticalProgress(QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *event);
    virtual void onEvent(int x,int y);



signals:

public slots:

};

#endif // THUIPROGRESS_H
