#ifndef MYNOTE_H
#define MYNOTE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QDateTime>
#include <QFontDialog>
#include <QColorDialog>
#include "finddialog.h"
#include <QLabel>
#include <cstdlib>

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
    void onAddDateTime();
    void onFindString(QString text, int direction_find);
    void onAutoLine(bool ok);
    void onSetFont();
    void onSetColor();
    void onShowNumber();
    void onToolBar(bool ok);
private:
    Ui::MyNote *ui;
    FindDialog *findDialog;
    QLabel *lbl_status;
    QString currentEditTextNamePath;
};

#endif // MYNOTE_H
