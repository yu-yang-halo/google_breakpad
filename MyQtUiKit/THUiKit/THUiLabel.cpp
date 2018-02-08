#include "THUiLabel.h"
#include "THUiToast.h"
THUiLabel::THUiLabel(QWidget *parent) :
QLabel(parent), m_parent(parent),
    m_offsetX(0),
    m_offsetY(0)
{
    contentTips = "";
}
void THUiLabel::mousePressEvent(QMouseEvent *event){

    if(bSupporttips){

        if(contentTips.isEmpty()){
            contentTips = "No tips";
        }
        THUiToast *toast = new THUiToast(m_parent, contentTips);
        toast->showToast(this,m_offsetX,m_offsetY);
    }
}

void THUiLabel::mouseReleaseEvent(QMouseEvent *event){

}

bool THUiLabel::getBSupporttips() const
{
    return bSupporttips;
}

void THUiLabel::setBSupporttips(bool value)
{
    bSupporttips = value;
}
QString THUiLabel::getContentTips() const
{
    return contentTips;
}

void THUiLabel::setContentTips(const QString &value)
{
    contentTips = value;
}

void THUiLabel::setOffset(int offsetX, int offsetY)
{
    m_offsetX = offsetX;
    m_offsetY = offsetY;
}


