#include "THUiHorizontalProgress.h"

THUiHorizontalProgress::THUiHorizontalProgress(QWidget *parent) :
    THUiAbstractProgress(parent)
{
}

void THUiHorizontalProgress::paintEvent(QPaintEvent *event)
{
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

     float current=(currentValue-minValue)*1.0f/(maxValue-minValue);

     QPainterPath path;
     path.setFillRule(Qt::WindingFill);
     path.addRect(0,0,this->width()*current,this->height());

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
     QRectF textRect((this->width()-rectStr.width())/2,0,rectStr.width(),this->height());
     m_painter.setPen(m_fontColor);
     m_painter.drawText(textRect, Qt::AlignCenter,valueStr);

}


void THUiHorizontalProgress::onEvent(int x,int y){
    if(m_tmp_x != INT_MAX && m_tmp_y != INT_MAX){
        if(x > m_tmp_x){

            m_step = maxValue*(x-m_tmp_x)*1.0f/width();
            currentValue+=m_step;
            if(currentValue > maxValue){
                currentValue = maxValue;
            }
            update();
        }

        if(x < m_tmp_x){
             m_step = maxValue*(m_tmp_x-x)*1.0f/width();
             currentValue-=m_step;
             if(currentValue<=minValue){
                 currentValue = minValue;
             }
             update();
        }
    }
    m_tmp_x = x;
    m_tmp_y = y;
}

