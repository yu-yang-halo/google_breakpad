#include "THUiGroupWidget.h"
#include <QDebug>
#include <QPalette>
const int DEFALUT_WIDTH = 90;
const int DEFALUT_HEIGHT = 40;
const int DEFALUT_SPACE = 1;

#define DEFULT_BUTTON_STYLE "\
QPushButton{\
    color:#aaaaaa;\
    font:20px;\
    background-color:rgb(255,255,255,255);\
    padding:3px;\
    border-radius:2;\
    border:1px solid #cccccc;\
}\
QPushButton::pressed{\
    background-color:rgb(255,255,255,125);\
    color:#eeeeee;\
    border:1px solid #cccccc;\
} \
"
#define DEFULT_BUTTON_STYLE_SELECTED "\
QPushButton{\
    color:#ffffff;\
    font:20px;\
    background-color:rgb(17,205,124,255);\
    padding:3px;\
    border-radius:2;\
    border:1px solid #cccccc;\
}\
QPushButton::pressed{\
    background-color:rgb(17,205,124,125);\
    color:#eeeeee;\
    border:1px solid #cccccc;\
} \
"

THUiGroupWidget::THUiGroupWidget(QWidget *parent) :
    QWidget(parent)
{

    m_btn_width = DEFALUT_WIDTH;
    m_btn_height = DEFALUT_HEIGHT;

    m_style = DEFULT_BUTTON_STYLE;
    m_style_selected = DEFULT_BUTTON_STYLE_SELECTED;

    m_selected_pos = 0;

    layout = new QHBoxLayout(this);
    layout->setMargin(0);

//    QPalette pa=this->palette();
//    pa.setColor(QPalette::Background,Qt::red);
//    this->setAutoFillBackground(true);
//    this->setPalette(pa);

}
void THUiGroupWidget::caculateWidgetSize(){
    int size = m_buttons.size();
    this->setFixedSize(size*m_btn_width+(size+1)*DEFALUT_SPACE,m_btn_height+10);


    for(int i=0;i<m_buttons.size();i++){
       m_buttons[i]->setFixedSize(m_btn_width,m_btn_height);
       //m_buttons[i]->move(m_btn_width*i+(i+1)*DEFALUT_SPACE,0);
    }

}
void THUiGroupWidget::initButtonStyle(){

    if(m_selected_pos<0||m_selected_pos>=m_buttons.size()){
        m_selected_pos = 0;
    }

    for(int i=0;i<m_buttons.size();i++){
       if(i==m_selected_pos){
          m_buttons[i]->setStyleSheet(m_style_selected);
       }else{
          m_buttons[i]->setStyleSheet(m_style);
       }
    }




}

void THUiGroupWidget::setButtonSize(int w,int h){
    m_btn_width = w;
    m_btn_height = h;

    caculateWidgetSize();
}
void THUiGroupWidget::setButtonStyle(const QString &style){
    m_style = style;
    initButtonStyle();
}

void THUiGroupWidget::buttonClick(){
    QPushButton* btn= qobject_cast<QPushButton*>(sender());

    int n_whatsThis = btn->whatsThis().toInt();

    if(n_whatsThis < m_buttons.size() && n_whatsThis >= 0)
    {

        for(int i=0;i<m_buttons.size();i++){
            m_buttons[i]->setStyleSheet(m_style);
        }

        m_buttons[n_whatsThis]->setStyleSheet(m_style_selected);

        m_selected_pos = n_whatsThis;

        emit clickedButton(m_selected_pos);
    }

}


void THUiGroupWidget::setGroupContents(QList<QString> contents){
     m_contents = contents;

     if(m_buttons.size()>0){
         for(int i=0;i<m_buttons.size();i++){
            delete  m_buttons[i];
         }
         m_buttons.clear();

     }

     for(int i=0;i<m_contents.size();i++){
         QPushButton *btn=new QPushButton();
         btn->setText(m_contents[i]);
         btn->setWhatsThis(QString("%1").arg(i));
         connect(btn,SIGNAL(clicked()),this,SLOT(buttonClick()));
         m_buttons.append(btn);


        layout->addWidget(btn,0,Qt::AlignVCenter);
     }

     layout->setSpacing(DEFALUT_SPACE);

     caculateWidgetSize();
     initButtonStyle();
     m_icoIndex = -1;
}

int THUiGroupWidget::GetSelected_pos() const
{
    return m_selected_pos;
}

void THUiGroupWidget::setSelected_pos(int selected_pos)
{
    m_selected_pos = selected_pos;
    initButtonStyle();
}

void THUiGroupWidget::setAppointedPosIcon(int posIndex, const QIcon & ico, bool bCleanLast)
{
    if(posIndex<0 || posIndex>=m_buttons.size())
        return;

    if(m_buttons.size() > 0)
    {
        if(posIndex == m_icoIndex)
            return;

        if(bCleanLast && m_icoIndex >= 0)
            m_buttons[m_icoIndex]->setIcon(QIcon());    //清除上次已设置图标按钮上的图标
        m_buttons[posIndex]->setIcon(ico);
        m_icoIndex = posIndex;
    }
}
