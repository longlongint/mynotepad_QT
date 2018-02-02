#ifndef MYNOTE_H
#define MYNOTE_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class MyNote;
}

class MyNote : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyNote(QWidget *parent = 0);
    ~MyNote();

public slots:
    void onNew();
    void onOpen();
    void onSaveAs();

private:
    Ui::MyNote *ui;
};

#endif // MYNOTE_H
