#ifndef THUIPAGECONTROL_H
#define THUIPAGECONTROL_H

#include <QWidget>
#include <QList>
#include <QPushButton>
#include <QHBoxLayout>
class THUiPageControl : public QWidget
{
    Q_OBJECT
public:
    explicit THUiPageControl(QWidget *parent = 0);
    void setPageNums(int pageNums);
    void setCurrentPageIndex(int pageIndex);

signals:
    void clickedPageControl(int clickPageIndex);
public slots:
    void pageControlClick();
protected:
    void initPageControlStyle();
private:
    int n_pageNums;
    int n_pageIndex;
    QList<QPushButton *> list_buttons;
    QString m_style;
    QString m_style_selected;
    QHBoxLayout *layout;

};

#endif // THUIPAGECONTROL_H
