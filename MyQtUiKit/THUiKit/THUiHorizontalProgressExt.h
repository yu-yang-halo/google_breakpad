#ifndef THUIHORIZONTALPROGRESSEXT_H
#define THUIHORIZONTALPROGRESSEXT_H
#include "THUiAbstractProgressExt.h"
#include "THUiHorizontalProgress.h"
#include <QHBoxLayout>
class THUiHorizontalProgressExt : public THUiAbstractProgressExt
{
    Q_OBJECT
public:
    explicit THUiHorizontalProgressExt(QWidget *parent = 0);
    virtual void onLayout();
signals:

public slots:

private:
    QHBoxLayout *layout;
};

#endif // THUIHORIZONTALPROGRESSEXT_H
