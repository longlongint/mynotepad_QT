#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)//parent是传递给本类的直接基类
    : QDialog(parent)
{
    initUi();
    connect(btn_more,SIGNAL(clicked(bool)),this,SLOT(onBtnMoreClicked(bool)));
    connect(btn_find,SIGNAL(clicked(bool)),this,SLOT(onBtnFindClicked()));
    connect(edit_text,SIGNAL(textChanged(QString)),this,SLOT(onTextChanged(QString)));
}

FindDialog::~FindDialog()
{

}

void FindDialog::initUi()
{
    glayout = new QGridLayout;
    vbox_down = new QVBoxLayout;
    mainbox = new QVBoxLayout;

    widget_down = new QWidget;
    widget_up = new QWidget;

    lbl_text = new QLabel("内容:");
    edit_text = new QLineEdit;

    btn_close = new QPushButton("关闭");
    btn_find = new QPushButton("查找");
    btn_find->setEnabled(false);
    btn_more = new QPushButton("更多");
    btn_more->setCheckable(true);//设置按钮可选

    cb_case = new QCheckBox("option");
    cb_up = new QRadioButton("向上搜索");
    cb_down = new QRadioButton("向下搜索");
    cb_whole = new QCheckBox("option");


    glayout->addWidget(lbl_text,0,0);
    glayout->addWidget(edit_text,0,1);
    glayout->addWidget(btn_find,0,2);
    glayout->addWidget(cb_up,1,0,1,2);
    glayout->addWidget(cb_down,2,0,1,2);
    glayout->addWidget(btn_close,1,2);
    glayout->addWidget(btn_more,2,2);

    widget_up->setLayout(glayout);
    //---------------------------
    vbox_down->addWidget(cb_case);
    vbox_down->addWidget(cb_whole);
    widget_down->setLayout(vbox_down);
    //----------------------------

    mainbox->addWidget(widget_up);
    mainbox->addWidget(widget_down);
    //初始化时把下半部分隐藏起来
    widget_down->hide();

    //设置布局的大小约束：顶层布局固定，自动适应布局大小，且不变
    mainbox->setSizeConstraint(QLayout::SetFixedSize);
    this->setLayout(mainbox);
}

void FindDialog::onBtnMoreClicked(bool ok)
{
    if(ok)
    {
        btn_more->setText("隐藏");
    }
    else
    {
        btn_more->setText("更多");
    }
    widget_down->setVisible(ok);
}

void FindDialog::onBtnFindClicked()
{
    //1.接收用户输入
    QString text = edit_text->text();
    //2.把要查找的字符串发出去
    emit sigSendString(text);
}

void FindDialog::onTextChanged(QString text)
{
    btn_find->setEnabled(!text.isEmpty());
}



