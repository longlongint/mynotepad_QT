#include "finddialog.h"

FindDialog::FindDialog(QWidget *parent)//parent是传递给本类的直接基类
    : QDialog(parent)
{
    initUi();
    direction_flag=0;
    connect(btn_more,SIGNAL(clicked(bool)),this,SLOT(onBtnMoreClicked(bool)));
    connect(btn_find,SIGNAL(clicked(bool)),this,SLOT(onBtnFindClicked()));
    connect(edit_text,SIGNAL(textChanged(QString)),this,SLOT(onTextChanged(QString)));
    connect(m_pButtonGroup,SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(onButtonClicked(QAbstractButton*)));
    connect(cb_case,SIGNAL(toggled(bool)),this,SLOT(onCaseSensitive(bool)));
    connect(cb_whole,SIGNAL(toggled(bool)),this,SLOT(onWholeWords(bool)));

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

    m_pButtonGroup = new QButtonGroup(this);
    // 设置互斥
    m_pButtonGroup->setExclusive(true);
    cb_up = new QRadioButton("向上搜索");
    cb_down = new QRadioButton("向下搜索");
    cb_down->setChecked(true);
    m_pButtonGroup->addButton(cb_up);
    m_pButtonGroup->addButton(cb_down);
    cb_whole = new QCheckBox("全词匹配");
    cb_case = new QCheckBox("区分大小写");

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
    emit sigSendString(text,direction_flag);
}

void FindDialog::onTextChanged(QString text)
{
    btn_find->setEnabled(!text.isEmpty());
}
//QRadioButton
void FindDialog::onButtonClicked(QAbstractButton *button)
{
    // 当前点击的按钮
    qDebug() << QString("Clicked Button : %1").arg(button->text());

    /* 遍历按钮，获取选中状态
    QList<QAbstractButton*> list = m_pButtonGroup->buttons();
    foreach (QAbstractButton *pButton, list)
    {
        QString strStatus = pButton->isChecked() ? "Checked" : "Unchecked";
        qDebug() << button->text()<<"::"<<button->statusTip();
    }*/
    if(cb_up->isChecked()){
        direction_flag |=0x01;/*
    QTextDocument::FindBackward 0x00001 Search backwards instead of forwards.
        */
    }
    else if(cb_down->isChecked()){
        direction_flag &=(~0x01);//默认向下
    }
    else{
        direction_flag &=(~0x01);//默认向下
    }
    qDebug()<<direction_flag;
}

void FindDialog::onCaseSensitive(bool)
{
    if(cb_case->isChecked()){
        direction_flag|=0x02;/*
QTextDocument::FindCaseSensitively 0x00002
By default find works case insensitive. Specifying this
option changes the behaviour to a case sensitive find operation.
*/
    }
    else{
        direction_flag&=(~0x02);
    }
    qDebug()<<direction_flag;
}

void FindDialog::onWholeWords(bool)
{
    if(cb_whole->isChecked()){
        direction_flag|=0x04;/*
QTextDocument::FindWholeWords 0x00004
Makes find match only complete words.
*/
    }
    else{
        direction_flag&=(~0x04);
    }
    qDebug()<<direction_flag;
}



