#ifndef THUIGROUPWIDGET_H
#define THUIGROUPWIDGET_H

#include <QWidget>
#include <QList>
#include <QString>
#include <QPushButton>
#include <QHBoxLayout>
class THUiGroupWidget : public QWidget
{
    Q_OBJECT
public:
    explicit THUiGroupWidget(QWidget *parent = 0);


    void setGroupContents(QList<QString> contents);
    void setButtonSize(int w,int h);
    void setButtonStyle(const QString &style);

    int GetSelected_pos() const;
    void setSelected_pos(int selected_pos);
    void setAppointedPosIcon(int posIndex, const QIcon&, bool bCleanLast = true);   //对指定位置的按钮设置图标

signals:
    void clickedButton(int pos);
public slots:
    void buttonClick();
protected:
    void caculateWidgetSize();
    void initButtonStyle();
private:
    QList<QString> m_contents;
    QList<QPushButton *> m_buttons;
    int m_btn_width;
    int m_btn_height;
    int m_selected_pos;
    QString m_style;
    QString m_style_selected;
    QHBoxLayout *layout;
    int m_icoIndex;
};

#endif // THUIGROUPWIDGET_H
