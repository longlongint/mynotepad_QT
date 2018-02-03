#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QLayout>
#include <QtWidgets>
#include <QRadioButton>

class FindDialog : public QDialog
{
    Q_OBJECT

public://公有成员
    FindDialog(QWidget *parent = 0);
    ~FindDialog();

    void initUi();

signals://信号
    void sigSendString(QString);
public slots://槽函数
    void onBtnMoreClicked(bool ok);
    void onBtnFindClicked();
    void onTextChanged(QString text);

private://私有成员
    QLabel *lbl_text;
    QLineEdit *edit_text;
    QPushButton *btn_find;
    QPushButton *btn_close;
    QPushButton *btn_more;

    QRadioButton *cb_up;
    QRadioButton *cb_down;
    QCheckBox *cb_case;
    QCheckBox *cb_whole;

    QWidget *widget_up;
    QWidget *widget_down;

    QGridLayout *glayout;
    QVBoxLayout *vbox_down;
    QVBoxLayout *mainbox;

};

#endif // WIDGET_H
