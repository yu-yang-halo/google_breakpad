#ifndef THUIHEARTBEATVIEW_H
#define THUIHEARTBEATVIEW_H

#include <QWidget>
/**
 * @brief The THUiHeartBeatView class
 *
 * ÐÄÌø¶¯»­view
 *
 */

class THUiHeartBeatView : public QWidget
{
    Q_OBJECT
public:
    explicit THUiHeartBeatView(QWidget *parent = 0);
     virtual void paintEvent(QPaintEvent *event);

signals:

public slots:

};

#endif // THUIHEARTBEATVIEW_H
