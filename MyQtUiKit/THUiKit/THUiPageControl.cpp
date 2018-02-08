#include "THUiPageControl.h"

#define DEFULT_PAGECONTROL_STYLE "\
QPushButton{\
    background-color:rgb(255,255,255,255);\
    border-radius:15;\
    border:1px solid #cccccc;\
}\
QPushButton::pressed{\
    background-color:rgb(255,255,255,125);\
} \
"
#define DEFULT_PAGECONTROL_STYLE_SELECTED "\
QPushButton{\
    background-color:rgb(17,205,124,255);\
    border-radius:15;\
    border:1px solid #cccccc;\
}\
QPushButton::pressed{\
    background-color:rgb(17,205,124,125);\
} \
"
const int PAGE_CONTROL_BUTTON_RADIUS = 30;
const int PAGE_CONTROL_SPACE = 30;

THUiPageControl::THUiPageControl(QWidget *parent) :
    QWidget(parent)
{
    n_pageIndex = 0;
    n_pageNums = 0;

    m_style = DEFULT_PAGECONTROL_STYLE;
    m_style_selected = DEFULT_PAGECONTROL_STYLE_SELECTED;

    layout = new QHBoxLayout(this);
    layout->setMargin(0);

//        QPalette pa=this->palette();
//        pa.setColor(QPalette::Background,Qt::red);
//        this->setAutoFillBackground(true);
//        this->setPalette(pa);
}
void THUiPageControl::pageControlClick(){
    QPushButton* btn= qobject_cast<QPushButton*>(sender());

    int n_whatsThis = btn->whatsThis().toInt();

    if(n_whatsThis < list_buttons.size() && n_whatsThis >= 0)
    {

        for(int i=0;i<list_buttons.size();i++){
            list_buttons[i]->setStyleSheet(m_style);
        }

        list_buttons[n_whatsThis]->setStyleSheet(m_style_selected);

        n_pageIndex = n_whatsThis;

        emit clickedPageControl(n_pageIndex);
    }

}

void THUiPageControl::initPageControlStyle(){

    if(list_buttons.size() <= 0){
        return;
    }
    if(n_pageIndex < 0 || n_pageIndex >= list_buttons.size()){

        n_pageIndex = 0;
    }

    for(int i=0;i<list_buttons.size();i++){

        if(n_pageIndex == i){
             list_buttons[i]->setStyleSheet(m_style_selected);
        }else{
             list_buttons[i]->setStyleSheet(m_style);
        }
    }

}


void THUiPageControl::setPageNums(int pageNums){
    n_pageNums = pageNums;

    if(list_buttons.size()>0){
        for(int i=0;i<list_buttons.size();i++){
           delete  list_buttons[i];
        }
        list_buttons.clear();
    }
    for(int i=0;i<n_pageNums;i++){
        QPushButton *btn=new QPushButton();
        btn->setWhatsThis(QString("%1").arg(i));
        btn->setFixedSize(PAGE_CONTROL_BUTTON_RADIUS,PAGE_CONTROL_BUTTON_RADIUS);
        connect(btn,SIGNAL(clicked()),this,SLOT(pageControlClick()));
        btn->setFocusPolicy(Qt::NoFocus);
        list_buttons.append(btn);

        layout->addWidget(btn);
    }
    layout->setSpacing(PAGE_CONTROL_SPACE);

    int width = (PAGE_CONTROL_BUTTON_RADIUS+PAGE_CONTROL_SPACE)*n_pageNums + PAGE_CONTROL_SPACE;
    this->setFixedSize(width,
                       PAGE_CONTROL_BUTTON_RADIUS);

    initPageControlStyle();

}

void THUiPageControl::setCurrentPageIndex(int pageIndex){
   n_pageIndex = pageIndex;

   initPageControlStyle();
}
