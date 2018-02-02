#include "mynote.h"
#include "ui_mynote.h"

MyNote::MyNote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyNote)
{
    ui->setupUi(this);
    connect(ui->actionnew,SIGNAL(triggered(bool)),this,SLOT(onNew()));
    connect(ui->actionopen,SIGNAL(triggered(bool)),this,SLOT(onOpen()));
    connect(ui->actionsaveAs,SIGNAL(triggered(bool)),this,SLOT(onSaveAs()));
}

MyNote::~MyNote()
{
    delete ui;
}
//新建菜单项
void MyNote::onNew()
{
    if(ui->textEdit->document()->isModified())
    {
        //显示消息对话框以提示用户
      QMessageBox::information(this,"提示","这里就是提示文本内容！");
      QMessageBox::warning(this,"提示","这里就是提示文本内容！");
      QMessageBox::critical(this,"提示","这里就是提示文本内容！");
    }
}
//打开 文件
void MyNote::onOpen()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"提示","打开失败:"+file.errorString());
        return ;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();

    ui->textEdit->setText(text);
}
//另存为
void MyNote::onSaveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if(fileName.isEmpty())
        return;

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"提示","打开失败:"+file.errorString());
        return ;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;

    file.close();
}



