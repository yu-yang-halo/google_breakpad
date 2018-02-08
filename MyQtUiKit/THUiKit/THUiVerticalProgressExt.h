#ifndef THUIPROGRESSEXT_H
#define THUIPROGRESSEXT_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "THUiAbstractProgressExt.h"
#include "THUiVerticalProgress.h"

class THUiVerticalProgressExt : public THUiAbstractProgressExt
{
    Q_OBJECT
public:
     explicit THUiVerticalProgressExt(QWidget *parent = 0);
     virtual void onLayout();
private:
    QVBoxLayout *layout;
};

#endif // THUIPROGRESSEXT_H
