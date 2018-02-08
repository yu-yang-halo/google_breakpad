#include "THUiHorizontalProgressExt.h"

THUiHorizontalProgressExt::THUiHorizontalProgressExt(QWidget *parent) :
    THUiAbstractProgressExt(parent)
{


    layout = new QHBoxLayout(this);
    layout->setMargin(0);

    progress = new THUiHorizontalProgress();

    connect(this->progress,SIGNAL(onValueChange(int)),this,SLOT(valueChange(int)));


//    QPalette pa=this->palette();
//    pa.setColor(QPalette::Background,Qt::red);
//    this->setAutoFillBackground(true);
//    this->setPalette(pa);


}
void THUiHorizontalProgressExt::onLayout(){
    int btn_width = DEFAULT_BUTTON_WIDTH;

    if(btn_width>height()){
        btn_width = height();
    }
    button_add->setFixedSize(btn_width,btn_width);
    button_sub->setFixedSize(btn_width,btn_width);

    int progress_width = DEFALUE_PROGRESS_WIDTH;

    if(progress_width>btn_width){
         progress_width= btn_width*0.6;
    }
    progress->setFixedHeight(progress_width);


    layout->addWidget(button_sub,0, Qt::AlignVCenter);
    layout->addSpacing(VIEW_DIVIDE);
    layout->addWidget(progress,0, Qt::AlignVCenter);
    layout->addSpacing(VIEW_DIVIDE);
    layout->addWidget(button_add,0, Qt::AlignVCenter);
}

