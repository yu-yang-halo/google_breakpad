#include "AnimationStackedWidget.h"
#include <QPainter>
#include <QDebug>

AnimationStackedWidget::AnimationStackedWidget(QWidget *parent) :
    QStackedWidget(parent)
{
    m_isAnimation = false;
    m_bIsSwitchNext = true;
    //Ĭ�ϵĶ������ʱ��
    m_duration = 500;
    //��ʼ��animation��ܡ��������źźͲ�
    m_animation = new QPropertyAnimation(this, QByteArray());
    connect(m_animation, SIGNAL(valueChanged(QVariant)), this, SLOT(valueChanged_slot(QVariant)));
    connect(m_animation, SIGNAL(finished()), this, SLOT(animationFinished()));

    m_bIsPress = false;
}

AnimationStackedWidget::~AnimationStackedWidget()
{

}

void AnimationStackedWidget::addEventControl(QObject * pObj)
{
    pObj->installEventFilter(this);
}

void AnimationStackedWidget::paintEvent(QPaintEvent *e)
{
    if( m_isAnimation )
    {
        QPainter paint(this);
        if(m_bIsSwitchNext)
        {
            //���Ƶ�ǰWidget
            paintPrevious(paint, currentIndex());
            //������һ��widget
            paintNext(paint, m_anotherIndex);
        }
        else
        {
            //������һ��Widget
            paintPrevious(paint, m_anotherIndex);
            //���Ƶ�ǰwidget
            paintNext(paint, currentIndex());
        }
    }
}

void AnimationStackedWidget::setDuration(int dura)
{
    m_duration = dura;
}

void AnimationStackedWidget::setCurrentIndex(int index)
{
    if(index >= count() || index < 0)
        return;

    int curIndex = currentIndex();
    if(-1 == curIndex || index == curIndex)
    {
        QStackedWidget::setCurrentIndex(index);
        emit finished();
        return;
    }

    //�л�ҳ����ʾ����Ч��
    if(index > curIndex)
        next(index - curIndex);
    else
        forward(curIndex - index);
}

void AnimationStackedWidget::valueChanged_slot(QVariant value)
{
    m_currentValue = value;
    update();
}

void AnimationStackedWidget::animationFinished()
{
    m_isAnimation = false;
    widget(currentIndex())->show();
    QStackedWidget::setCurrentIndex(m_anotherIndex);

    emit finished();
}

bool AnimationStackedWidget::eventFilter(QObject *obj, QEvent *ev)
{
    if(ev->type() == QEvent::MouseButtonPress
        || ev->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent* e = (QMouseEvent*)ev;
        if(e && e->button() == Qt::LeftButton)
        {
            if(ev->type() == QEvent::MouseButtonPress)
            {
                m_bIsPress = true;
                m_pressPoint = e->pos();
                m_time.restart();
            }
            else
            {
                if(m_bIsPress)
                {
                    m_bIsPress = false;
                    int px = e->pos().x() - m_pressPoint.x();
                    int py = e->pos().y() - m_pressPoint.y();

                    //����ʱ�䲻����5�룬��ˮƽ����һ�����롢�ȴ�ֱ�����ľ��볤ʱ����ʾ�ôλ�����Ч
                    if(m_time.elapsed() < 5000 && qAbs(px) >= width()/5 && qAbs(px) > qAbs(py))
                    {
                        if(px < 0)
                            next();
                        else
                            forward();
                    }
                }
            }
        }
    }

    return QStackedWidget::eventFilter(obj, ev);
}

/*
void AnimationStackedWidget::mousePressEvent(QMouseEvent *e)
{
    m_bIsPress = true;
    m_pressPoint = e->pos();
    m_time.restart();
}

void AnimationStackedWidget::mouseReleaseEvent(QMouseEvent *e)
{
    if(m_bIsPress)
    {
        m_bIsPress = false;
        int px = e->pos().x() - m_pressPoint.x();
        int py = e->pos().y() - m_pressPoint.y();

        //����ʱ�䲻����5�룬��ˮƽ����һ�����롢�ȴ�ֱ�����ľ��볤ʱ����ʾ�ôλ�����Ч
        if(m_time.elapsed() < 5000 && qAbs(px) >= width()/4 && qAbs(px) > qAbs(py))
        {
            if(px < 0)
                next();
            else
                forward();
        }
    }
}
*/

void AnimationStackedWidget::next(int intervalPages)
{
    if(intervalPages <= 0)
        return;

    int c = currentIndex();
    if(c + intervalPages >= count())
        return;     //�Ѿ���βҳ��������ʾ�¸�page

    //������ڶ�����ֱ�ӷ���
    if( m_isAnimation )
        return;

    m_isAnimation = true;
    m_bIsSwitchNext = true;
    m_anotherIndex = c + intervalPages;
    widget(c)->hide();

    //��ʼ���������ü���Ϳ�ʼ������ֵ
    QRect g = geometry();
    int width = g.width();
    m_animation->setStartValue(width);
    m_animation->setEndValue(0);
    m_animation->setDuration(m_duration);
    m_animation->start();
}

void AnimationStackedWidget::forward(int intervalPages)
{
    if(intervalPages <= 0)
        return;

    int c = currentIndex();
    if(c - intervalPages < 0)
        return;     //�Ѿ�����ҳ��������ʾ�ϸ�page

    //������ڶ�����ֱ�ӷ���
    if( m_isAnimation )
        return;

    m_isAnimation = true;
    m_bIsSwitchNext = false;
    m_anotherIndex = c - intervalPages;
    widget(c)->hide();

    //��ʼ���������ü���Ϳ�ʼ������ֵ
    QRect g = geometry();
    int width = g.width();
    m_animation->setStartValue(0);
    m_animation->setEndValue(width);
    m_animation->setDuration(m_duration);
    m_animation->start();
}

void AnimationStackedWidget::paintPrevious(QPainter & paint, int preIndex)
{
    //��õ�ǰҳ���Widget
    QWidget *w = widget(preIndex);
    QPixmap pixmap(w->size());
    //��Widget��������Ⱦ��QPixmap�����У�����Widget���һ��ͼƬ
    w->render(&pixmap);
    QRect r = w->geometry();
    //���Ƶ�ǰ��Widget
    double value = m_currentValue.toDouble();
    QRectF r1(0.0, 0.0, value, r.height());
    QRectF r2(r.width() - value, 0, value, r.height());
    paint.drawPixmap(r1, pixmap, r2);
}

void AnimationStackedWidget::paintNext(QPainter & paint, int nextIndex)
{
    QWidget *nextWidget = widget(nextIndex);
    QRect r = geometry();
    //���д��벻�ӻ���bug����һ���л���ʱ��QStackedWidget��û��Ϊchild�����С
    nextWidget->resize(r.width(), r.height());
    QPixmap nextPixmap(nextWidget->size());
    nextWidget->render(&nextPixmap);
    double value = m_currentValue.toDouble();
    QRectF r1(value, 0.0, r.width() - value, r.height());
    QRectF r2(0.0, 0.0, r.width() - value, r.height());
    paint.drawPixmap(r1, nextPixmap, r2);
}
