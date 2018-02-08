#include "THUiAbstractProgress.h"
#include <QDebug>
THUiAbstractProgress::THUiAbstractProgress(QWidget *parent) :
    QWidget(parent)
{

    m_bgColor = QColor::fromRgb(0,0,0,10);
    m_fgColor = Qt::yellow;

    m_tmp_x = INT_MAX;
    m_tmp_y = INT_MAX;

    minValue = 1;
    maxValue = 100;
    currentValue = 0;
    m_fontSize = 16;

    m_step = 1;

    setBackgroundColor(m_bgColor);
}
void THUiAbstractProgress::mouseMoveEvent(QMouseEvent *e){
    onEvent(e->x(),e->y());
}

void THUiAbstractProgress::mouseReleaseEvent(QMouseEvent *event){
    emit onValueChange(currentValue);
    m_tmp_x = INT_MAX;
    m_tmp_y = INT_MAX;
}

void THUiAbstractProgress::dragMoveEvent(QDragMoveEvent *event){
    onEvent(event->pos().x(),event->pos().y());
}

void THUiAbstractProgress::dragLeaveEvent(QDragLeaveEvent *event){
    emit onValueChange(currentValue);
    m_tmp_x = INT_MAX;
    m_tmp_y = INT_MAX;
}


void THUiAbstractProgress::setBackgroundColor(const QColor &color){

    QPalette pal=this->palette();
    pal.setColor(QPalette::Background,color);
    setAutoFillBackground(true);
    this->setPalette(pal);

    m_bgColor = color;
}
void THUiAbstractProgress::setFrontgroundColor(const QColor &color){
    m_fgColor = color;
    update();
}
void THUiAbstractProgress::setFontColor(const QColor &color){
    m_fontColor = color;
    update();
}
void THUiAbstractProgress::sendChangeStep(int step){
     currentValue+=step;
     if(currentValue<=minValue){
         currentValue = minValue;
     }else if(currentValue > maxValue){
         currentValue = maxValue;
     }
     emit onValueChange(currentValue);
     update();
}

int THUiAbstractProgress::getCurrentValue() const
{
    return currentValue;
}

void THUiAbstractProgress::setCurrentValue(int value)
{
    if(value >= minValue && value <= maxValue){
        currentValue = value;
        update();
    }
}
int THUiAbstractProgress::getMaxValue() const
{
    return maxValue;
}

void THUiAbstractProgress::setMaxValue(int value)
{
    maxValue = value;
}
float THUiAbstractProgress::getMinValue() const
{
    return minValue;
}

void THUiAbstractProgress::setMinValue(float value)
{
    minValue = value;
}

void THUiAbstractProgress::setMaxAndMinValue(int max,int min){
    maxValue = max;
    minValue = min;
    if(max == min){
        qDebug()<<"Max can not equal Min";
    }
}

void THUiAbstractProgress::setFontSize(int fontSize)
{
    m_fontSize = fontSize;
}
