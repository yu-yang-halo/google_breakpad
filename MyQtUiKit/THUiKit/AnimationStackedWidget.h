#ifndef ANIMATIONSTACKEDWIDGET_H
#define ANIMATIONSTACKEDWIDGET_H

#include <QPaintEvent>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QTime>

class AnimationStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit AnimationStackedWidget(QWidget *parent = 0);
    ~AnimationStackedWidget();

     //���ö��������ļ��
    void addEventControl(QObject *);
    void setDuration(int dura);

public slots:
    void setCurrentIndex(int index);   //��д����ķ���

signals:
    void finished();

private slots:
    //���Զ���ֵ�ı�Ĳ�
    void valueChanged_slot(QVariant );
    //�����л����
    void animationFinished();

protected:
    bool eventFilter(QObject *obj, QEvent *ev);
    //void mousePressEvent(QMouseEvent *e);
    //void mouseReleaseEvent(QMouseEvent *e);

private:
    void next(int intervalPages = 1);      //��ʾ�¼�ҳ
    void forward(int intervalPages = 1);   //��ʾ�ϼ�ҳ

    void paintEvent(QPaintEvent *);
    void paintPrevious(QPainter &, int);
    void paintNext(QPainter &, int);

private:
    QPropertyAnimation* m_animation; //�������
    int         m_duration;         //�����ĳ���ʱ��
    bool        m_isAnimation;      //�Ƿ����ڶ���
    QVariant    m_currentValue;     //��Animation�����ı��ֵ
    int         m_anotherIndex;    //�뵱ǰҳ���л�����һ��ҳ�������
    bool        m_bIsSwitchNext;    //�Ƿ������л�ҳ��ı��

    bool        m_bIsPress;
    QPoint      m_pressPoint;
    QTime       m_time;
};

#endif // ANIMATIONSTACKEDWIDGET_H
