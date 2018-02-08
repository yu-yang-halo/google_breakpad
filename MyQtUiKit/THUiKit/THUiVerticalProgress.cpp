#include "THUiVerticalProgress.h"
#include <QDebug>
#include <qmath.h>
#include <climits>
#include <QPushButton>

THUiVerticalProgress::THUiVerticalProgress(QWidget *parent) :
    THUiAbstractProgress(parent)
{

}

void THUiVerticalProgress::paintEvent(QPaintEvent *event)
{
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

     float current=(currentValue-minValue)*1.0f/(maxValue-minValue);


     QPainterPath path;
     path.setFillRule(Qt::WindingFill);
     path.addRect(0,this->height()*(1-current), this->width(),this->height()*current);

     QPainter m_painter(this);
     m_painter.setRenderHint(QPainter::Antialiasing, true);
     m_painter.fillPath(path, QBrush(m_fgColor));


     QString valueStr=QString("%1").arg((int)currentValue);

     QFont f(font());
     f.setBold(true);
     f.setPixelSize(m_fontSize);

     QFontMetrics fm(f);
     QRect rectStr = fm.boundingRect(valueStr);

     m_painter.setFont(f);
     QRectF textRect(0,this->height()-rectStr.height(),this->width(),rectStr.height());
     m_painter.setPen(m_fontColor);
     m_painter.drawText(textRect, Qt::AlignCenter,valueStr);

}


void THUiVerticalProgress::onEvent(int x,int y){
    if(m_tmp_x != INT_MAX && m_tmp_y != INT_MAX){
        if(y > m_tmp_y){

            m_step = maxValue*(y-m_tmp_y)*1.0f/height();
            currentValue-=m_step;
            if(currentValue<=minValue){
                currentValue = minValue;
            }
            update();
        }

        if(y < m_tmp_y){
             m_step = maxValue*(m_tmp_y-y)*1.0f/height();
             currentValue+=m_step;
             if(currentValue > maxValue){
                 currentValue = maxValue;
             }
             update();
        }
    }
    m_tmp_x = x;
    m_tmp_y = y;
}



