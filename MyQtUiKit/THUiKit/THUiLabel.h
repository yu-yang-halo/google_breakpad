#ifndef THUILABEL_H
#define THUILABEL_H

#include <QLabel>

class THUiLabel : public QLabel
{
    Q_OBJECT
public:
    explicit THUiLabel(QWidget *parent = 0);
    virtual void mousePressEvent(QMouseEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *);

public:
    bool getBSupporttips() const;
    void setBSupporttips(bool value);

    QString getContentTips() const;
    void setContentTips(const QString &value);
    void setOffset(int offsetX,int offsetY);

signals:

public slots:
private:
    bool bSupporttips;
    QString contentTips;
    QWidget *m_parent;
    int m_offsetX,m_offsetY;


};

#endif // THUILABEL_H
