#include "mynote.h"
#include "ui_mynote.h"

MyNote::MyNote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyNote)
{
    ui->setupUi(this);
    //实例化查找对话框
    findDialog = new FindDialog(this);
    connect(findDialog,SIGNAL(sigSendString(QString)),this,SLOT(onFindString(QString)));
    connect(ui->actionnew,SIGNAL(triggered(bool)),this,SLOT(onNew()));
    connect(ui->actionopen,SIGNAL(triggered(bool)),this,SLOT(onOpen()));
    connect(ui->actionsaveAs,SIGNAL(triggered(bool)),this,SLOT(onSaveAs()));
    connect(ui->actionsave,SIGNAL(triggered(bool)),this,SLOT(onSave()));
    connect(ui->action_close,SIGNAL(triggered(bool)),this,SLOT(close()));
}

MyNote::~MyNote()
{
    delete ui;
}

void MyNote::saveagain()
{
    if(currentEditTextNamePath==nullptr){
        return ;
    }
    else{
        QFile file(currentEditTextNamePath);
        if(!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this,"提示","打开失败:"+file.errorString());
            return ;
        }
        QTextStream out(&file);
        QString text = ui->edit_text->toPlainText();
        out << text;
        file.close();
    }
}
//新建菜单项
void MyNote::onNew()
{
    if(currentEditTextNamePath==nullptr)
    {//如果当前文档没有被保存过
        if(!ui->edit_text->document()->isEmpty())
        {//如果有文字
            QMessageBox msgBox;
            msgBox.setText("文档已经被修改过了");
            msgBox.setInformativeText("那你要保存吗?");
            msgBox.setDetailedText(tr("再仔细想想吧"));
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();
            switch (ret) {
                case QMessageBox::Save:
                    onSaveAs();
                    break;
                case QMessageBox::Discard:
                    ui->edit_text->clear();
                    this->setWindowTitle(tr("无标题"));
                    break;
                case QMessageBox::Cancel:
                    // Cancel was clicked
                    break;
                default:
                    // should never be reached
                    break;
              }
        }
        else{//编辑窗口是空的
            ui->edit_text->clear();
            this->setWindowTitle(tr("无标题"));
        }
    }
    else{//文档被保存过
        QMessageBox msgBox;
        msgBox.setText("是否保存当前修改");
        msgBox.setDetailedText(tr("再仔细想想吧"));
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret)
        {
            case QMessageBox::Save:
                onSave();
                break;
            case QMessageBox::Discard:
                ui->edit_text->clear();
                currentEditTextNamePath=nullptr;
                this->setWindowTitle(tr("无标题"));
                break;
            case QMessageBox::Cancel:
                // Cancel was clicked
                break;
            default:
                // should never be reached
                break;
          }
    }
}
//打开 文件
void MyNote::onOpen()
{
    currentEditTextNamePath = QFileDialog::getOpenFileName(this);
    if(currentEditTextNamePath.isEmpty())
    {
        return ;
    }
    QFileInfo info(currentEditTextNamePath);
    this->setWindowTitle(info.fileName());
//    qDebug()<<"*********************";
//    qDebug()<<info.absoluteDir();
//    qDebug()<<info.absoluteFilePath();
//    qDebug()<<info.absolutePath();
//    qDebug()<<info.baseName();
//    qDebug()<<info.bundleName();
//    qDebug()<<info.caching();
//    qDebug()<<info.fileName();
//    qDebug()<<info.filePath();
    QFile file(currentEditTextNamePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"提示","打开失败"+file.errorString());
        return ;
    }
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString text= in.readAll();
    file.close();
    ui->edit_text->setText(text);
}

void MyNote::onSave()
{
    if(currentEditTextNamePath==nullptr)
    {//如果当前文档没有被保存过
        if(!ui->edit_text->document()->isEmpty())
        {//如果有文字
            QMessageBox msgBox;
            msgBox.setText("文档已经被修改过了");
            msgBox.setInformativeText("那你要保存吗?");
            msgBox.setDetailedText(tr("再仔细想想吧"));
            msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
            msgBox.setDefaultButton(QMessageBox::Save);
            int ret = msgBox.exec();
            switch (ret) {
                case QMessageBox::Save:
                    onSaveAs();
                    break;
                case QMessageBox::Discard:
                    ui->edit_text->clear();
                    this->setWindowTitle(tr("无标题"));
                    break;
                case QMessageBox::Cancel:
                    // Cancel was clicked
                    break;
                default:
                    // should never be reached
                    break;
              }
        }
        else{//编辑窗口是空的
            ui->edit_text->clear();
            this->setWindowTitle(tr("无标题"));
        }
    }
    else{//文档被保存过
        QMessageBox msgBox;
        msgBox.setText("是否保存当前修改");
        msgBox.setDetailedText(tr("再仔细想想吧"));
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret)
        {
            case QMessageBox::Save:
                saveagain();
                break;
            case QMessageBox::Discard:
                ui->edit_text->clear();
                currentEditTextNamePath=nullptr;
                this->setWindowTitle(tr("无标题"));
                break;
            case QMessageBox::Cancel:
                // Cancel was clicked
                break;
            default:
                // should never be reached
                break;
          }
    }

}
//另存为
void MyNote::onSaveAs()
{
    currentEditTextNamePath = QFileDialog::getSaveFileName(this);
    if(currentEditTextNamePath.isEmpty())
        return;
    QFileInfo info(currentEditTextNamePath);
    this->setWindowTitle(info.fileName());
    //    qDebug()<<info.absoluteDir();
    //    qDebug()<<info.absoluteFilePath();
    //    qDebug()<<info.absolutePath();
    //    qDebug()<<info.baseName();
    //    qDebug()<<info.bundleName();
    //    qDebug()<<info.caching();
    //    qDebug()<<info.fileName();
    //    qDebug()<<info.filePath();
    saveagain();
}

void MyNote::onFindString(QString text)
{
    qDebug() << text;
    bool ok = ui->edit_text->find(text);
    qDebug() << "ok = " << ok;
    this->activateWindow();
}



