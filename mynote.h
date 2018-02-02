#ifndef MYNOTE_H
#define MYNOTE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include "finddialog.h"

namespace Ui {
class MyNote;
}

class MyNote : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyNote(QWidget *parent = 0);
    ~MyNote();
    void saveagain();
public slots:
    void onNew();
    void onOpen();
    void onSave();
    void onSaveAs();
    void onFindString(QString text);
private:
    Ui::MyNote *ui;
    FindDialog *findDialog;
    QString currentEditTextNamePath;
};

#endif // MYNOTE_H
