#include "THUiAbstractProgressExt.h"

const int DEFALUE_PROGRESS_WIDTH = 40;//defalut progress width
const int DEFAULT_BUTTON_WIDTH = 54;//default button width
const int VIEW_DIVIDE = 5;

THUiAbstractProgressExt::THUiAbstractProgressExt(QWidget *parent) :
    QWidget(parent)
{

    progress = NULL;

    button_add = new QPushButton();
    button_add->setText("+");

    button_sub = new QPushButton();
    button_sub->setText("-");

    setButtonStyle(DEFULT_BUTTON_STYLE);


    connect(this->button_add,SIGNAL(clicked()),this,SLOT(clickAdd()));
    connect(this->button_sub,SIGNAL(clicked()),this,SLOT(clickSub()));
}
void THUiAbstractProgressExt::setBackgroundColor(const QColor &color)
{
    if(progress != NULL){
        progress->setBackgroundColor(color);
    }

}

void THUiAbstractProgressExt::setFrontgroundColor(const QColor &color)
{
    if(progress != NULL){
        progress->setFrontgroundColor(color);
    }

}

void THUiAbstractProgressExt::setFontColor(const QColor &color)
{
    if(progress != NULL){
        progress->setFontColor(color);
    }
}

void THUiAbstractProgressExt::moveEvent(QMoveEvent *event){
    onLayout();
}

void THUiAbstractProgressExt::resizeEvent(QResizeEvent *event)
{
    //onLayout();
}

void THUiAbstractProgressExt::setMaxAndMinValue(int maxValue,int minValue){
    if(progress == NULL)
        return ;
     progress->setMaxAndMinValue(maxValue,minValue);
}

void THUiAbstractProgressExt::setCurrentValue(int currentValue){
    if(progress == NULL)
        return ;
     progress->setCurrentValue(currentValue);
}

void THUiAbstractProgressExt::setButtonStyle(const QString &style){

    buttonStyleInit(button_add,style);
    buttonStyleInit(button_sub,style);
}

void THUiAbstractProgressExt::buttonStyleInit(QPushButton *btn,const QString &style){
    if(btn == NULL){
        return ;
    }
    btn->setStyleSheet(style);
    btn->setAutoRepeat(true);
    btn->setAutoRepeatDelay(500);
    btn->setAutoRepeatInterval(100);
}

void THUiAbstractProgressExt::clickAdd(){
    if(progress == NULL)
        return ;
    progress->sendChangeStep(1);
}
void THUiAbstractProgressExt::clickSub(){
    if(progress == NULL)
        return ;
    progress->sendChangeStep(-1);
}
void THUiAbstractProgressExt::valueChange(int changeValue){
    emit onValueChangeExt(changeValue);
}
