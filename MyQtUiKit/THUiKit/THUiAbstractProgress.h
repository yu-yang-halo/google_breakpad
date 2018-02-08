#ifndef THUIABSTRACTPROGRESS_H
#define THUIABSTRACTPROGRESS_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QStyleOption>
class THUiAbstractProgress : public QWidget
{
    Q_OBJECT
public:
    explicit THUiAbstractProgress(QWidget *parent = 0);
    virtual void onEvent(int x,int y) = 0;
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    virtual void dragMoveEvent(QDragMoveEvent *event);
    virtual void dragLeaveEvent(QDragLeaveEvent *event);



    void setBackgroundColor(const QColor &color=Qt::white);
    void setFrontgroundColor(const QColor &color=Qt::yellow);
    void setFontColor(const QColor &color=Qt::black);


    int getCurrentValue() const;
    void setCurrentValue(int value);


    void setFontSize(int fontSize);

    void sendChangeStep(int step);

    float getMinValue() const;
    void setMinValue(float value);
    int getMaxValue() const;
    void setMaxValue(int value);

    void setMaxAndMinValue(int max,int min);


signals:
    void onValueChange(int value);

public slots:

protected:
    float currentValue;
    float maxValue;
    float minValue;

    int m_tmp_x;
    int m_tmp_y;
    float m_step;

    QColor m_bgColor;
    QColor m_fgColor;
    QColor m_fontColor;

    int m_fontSize;

};

#endif // THUIABSTRACTPROGRESS_H
