#ifndef THUIABSTRACTPROGRESSEXT_H
#define THUIABSTRACTPROGRESSEXT_H

#include <QWidget>
#include <QPushButton>
#include "THUiAbstractProgress.h"

#define DEFULT_BUTTON_STYLE "\
QPushButton{\
    color:#FFFFFF;\
    font:38px;\
    background-color:rgb(17,205,124,255);\
    padding:3px;\
    border-radius:2;\
}\
QPushButton::pressed{\
    background-color:rgb(17,205,124,125);\
    color:#eeeeee;\
} \
"
extern const int DEFALUE_PROGRESS_WIDTH;//defalut progress width
extern const int DEFAULT_BUTTON_WIDTH ;//default button width
extern const int VIEW_DIVIDE;

class THUiAbstractProgressExt : public QWidget
{
    Q_OBJECT
public:
    explicit THUiAbstractProgressExt(QWidget *parent = 0);

    virtual void onLayout() = 0;
    virtual void moveEvent(QMoveEvent *event);
    virtual void resizeEvent(QResizeEvent *event);

    void setMaxAndMinValue(int maxValue,int minValue);
    void setCurrentValue(int currentValue);

    void setBackgroundColor(const QColor &color);
    void setFrontgroundColor(const QColor &color);
    void setFontColor(const QColor &color);

signals:
   void onValueChangeExt(int value);
public slots:
   void clickAdd();
   void clickSub();
   void valueChange(int changeValue);
   void setButtonStyle(const QString &style);

protected:
    void buttonStyleInit(QPushButton *btn,const QString &style);
    THUiAbstractProgress *progress;
    QPushButton  *button_add;
    QPushButton  *button_sub;

};

#endif // THUIABSTRACTPROGRESSEXT_H
