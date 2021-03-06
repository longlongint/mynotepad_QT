#include "mynote.h"
#include "ui_mynote.h"

MyNote::MyNote(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyNote)
{
    ui->setupUi(this);
    //实例化查找对话框
    findDialog = new FindDialog(this);
    //currentEditTextNamePath = new QString;
    connect(findDialog,SIGNAL(sigSendString(QString,int)),this,SLOT(onFindString(QString,int)));
    connect(ui->actionnew,SIGNAL(triggered(bool)),this,SLOT(onNew()));
    connect(ui->actionopen,SIGNAL(triggered(bool)),this,SLOT(onOpen()));
    connect(ui->actionsaveAs,SIGNAL(triggered(bool)),this,SLOT(onSaveAs()));
    connect(ui->actionsave,SIGNAL(triggered(bool)),this,SLOT(onSave()));
    connect(ui->action_close,SIGNAL(triggered(bool)),this,SLOT(close()));
    connect(ui->action1_find,SIGNAL(triggered(bool)),findDialog,SLOT(show()));
    connect(ui->action_copy,SIGNAL(triggered(bool)),ui->edit_text,SLOT(copy()));
    connect(ui->action_past,SIGNAL(triggered(bool)),ui->edit_text,SLOT(paste()));
    connect(ui->action_cut,SIGNAL(triggered(bool)),ui->edit_text,SLOT(cut()));
    connect(ui->action_cancel,SIGNAL(triggered(bool)),ui->edit_text,SLOT(undo()));
    connect(ui->action_del,SIGNAL(triggered(bool)),ui->edit_text,SLOT(cut()));//删除不会
    connect(ui->action_date,SIGNAL(triggered(bool)),this,SLOT(onAddDateTime()));

    ui->action_auto_line->setCheckable(true);
    ui->action_auto_line->setChecked(true);
    ui->action_status->setCheckable(true);
    ui->action_status->setChecked(false);
    ui->toolBar->hide();

    connect(ui->action_status,SIGNAL(triggered(bool)),this,SLOT(onToolBar(bool)));
    connect(ui->action_auto_line,SIGNAL(triggered(bool)),this,SLOT(onAutoLine(bool)));
    connect(ui->action_font,SIGNAL(triggered(bool)),this,SLOT(onSetFont()));
    connect(ui->action_color,SIGNAL(triggered(bool)),this,SLOT(onSetColor()));

    lbl_status = new QLabel;
    ui->statusBar->addPermanentWidget(lbl_status);
    lbl_status->setText("第 1 行，第 1 列");
    connect(ui->edit_text,SIGNAL(cursorPositionChanged()),this,SLOT(onShowNumber()));
}

MyNote::~MyNote()
{
    delete ui;
}


//保存路径已知的保存
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
            msgBox.setButtonText(QMessageBox::Save,"保存");
            msgBox.setButtonText(QMessageBox::Discard,"不保存");
            msgBox.setButtonText(QMessageBox::Cancel,"取消");
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
                //delete currentEditTextNamePath;
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
//打开文件
void MyNote::onOpen()
{
    currentEditTextNamePath = QFileDialog::getOpenFileName(this);
    if(currentEditTextNamePath.isEmpty())
    {
        //delete currentEditTextNamePath;
        currentEditTextNamePath=nullptr;
        return ;
    }
    QFile file(currentEditTextNamePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"提示","打开失败"+file.errorString());
        return ;
    }
    //设置窗口标题
    QFileInfo info(currentEditTextNamePath);
    this->setWindowTitle(info.fileName());
    //读取文件
    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString text= in.readAll();
    file.close();
    ui->edit_text->setText(text);
}
//保存文件
void MyNote::onSave()
{
    if(currentEditTextNamePath==0)
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
                    onSaveAs();//另存为
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
/*        qDebug()<<info.absoluteDir();
        qDebug()<<info.absoluteFilePath();
        qDebug()<<info.absolutePath();
        qDebug()<<info.baseName();
        qDebug()<<info.bundleName();
        qDebug()<<info.caching();
        qDebug()<<info.fileName();
        qDebug()<<info.filePath();      */
    saveagain();
}

void MyNote::onAddDateTime()
{
    QString dt=QDateTime::currentDateTime().toString("yyyy/mm/dd hh:mm:ss dddd");
    ui->edit_text->insertPlainText(dt);
}

void MyNote::onFindString(QString text,int direction_find)
{
    qDebug() << text;
    QTextDocument::FindFlags options = QTextDocument::FindFlags(direction_find);
    bool ok = ui->edit_text->find(text,options);
    qDebug() << "ok = " << ok;
    this->activateWindow();
}

void MyNote::onAutoLine(bool ok)
{
    if(ok)
        ui->edit_text->setWordWrapMode(QTextOption::WrapAtWordBoundaryOrAnywhere);
    else{
        ui->edit_text->setWordWrapMode(QTextOption::NoWrap);
    }
}

void MyNote::onSetFont()
{
    bool ok;
    QFont my_font=QFontDialog::getFont(&ok);
    if(ok){
        ui->edit_text->setFont(my_font);
    }
}

void MyNote::onSetColor()
{
    QColor my_color = QColorDialog::getColor();
    ui->edit_text->setTextColor(my_color);
}

void MyNote::onShowNumber()
{
    //1.获取
    int row = ui->edit_text->textCursor().blockNumber()+1;
    int col = ui->edit_text->textCursor().columnNumber()+1;
    //2.显示
    QString msg = QString("第 %1 行,第 %2 列").arg(row).arg(col);
    lbl_status->setText(msg);
}

void MyNote::onToolBar(bool ok)
{
    if(ok){
        ui->toolBar->show();
    }else{
        ui->toolBar->hide();
    }
}



