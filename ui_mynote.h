/********************************************************************************
** Form generated from reading UI file 'mynote.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYNOTE_H
#define UI_MYNOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyNote
{
public:
    QAction *actionnew;
    QAction *actionopen;
    QAction *actionsave;
    QAction *actionsaveAs;
    QAction *action_pag_set;
    QAction *action_print;
    QAction *action_close;
    QAction *action_cancel;
    QAction *action_cut;
    QAction *action_copy;
    QAction *action_past;
    QAction *action_del;
    QAction *action1_find;
    QAction *action_find_next;
    QAction *action_replace;
    QAction *action_turn_to;
    QAction *action_select_all;
    QAction *action_date;
    QAction *action_auto_line;
    QAction *action_font;
    QAction *action_status;
    QAction *action_help;
    QAction *action_about;
    QAction *action_color;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *edit_text;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MyNote)
    {
        if (MyNote->objectName().isEmpty())
            MyNote->setObjectName(QStringLiteral("MyNote"));
        MyNote->resize(655, 418);
        MyNote->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        actionnew = new QAction(MyNote);
        actionnew->setObjectName(QStringLiteral("actionnew"));
        actionopen = new QAction(MyNote);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionsave = new QAction(MyNote);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionsaveAs = new QAction(MyNote);
        actionsaveAs->setObjectName(QStringLiteral("actionsaveAs"));
        action_pag_set = new QAction(MyNote);
        action_pag_set->setObjectName(QStringLiteral("action_pag_set"));
        action_print = new QAction(MyNote);
        action_print->setObjectName(QStringLiteral("action_print"));
        action_close = new QAction(MyNote);
        action_close->setObjectName(QStringLiteral("action_close"));
        action_cancel = new QAction(MyNote);
        action_cancel->setObjectName(QStringLiteral("action_cancel"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/tool/tool_png/undo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_cancel->setIcon(icon);
        action_cut = new QAction(MyNote);
        action_cut->setObjectName(QStringLiteral("action_cut"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/tool/tool_png/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_cut->setIcon(icon1);
        action_copy = new QAction(MyNote);
        action_copy->setObjectName(QStringLiteral("action_copy"));
        action_past = new QAction(MyNote);
        action_past->setObjectName(QStringLiteral("action_past"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/tool/tool_png/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_past->setIcon(icon2);
        action_del = new QAction(MyNote);
        action_del->setObjectName(QStringLiteral("action_del"));
        action1_find = new QAction(MyNote);
        action1_find->setObjectName(QStringLiteral("action1_find"));
        action_find_next = new QAction(MyNote);
        action_find_next->setObjectName(QStringLiteral("action_find_next"));
        action_replace = new QAction(MyNote);
        action_replace->setObjectName(QStringLiteral("action_replace"));
        action_turn_to = new QAction(MyNote);
        action_turn_to->setObjectName(QStringLiteral("action_turn_to"));
        action_select_all = new QAction(MyNote);
        action_select_all->setObjectName(QStringLiteral("action_select_all"));
        action_date = new QAction(MyNote);
        action_date->setObjectName(QStringLiteral("action_date"));
        action_auto_line = new QAction(MyNote);
        action_auto_line->setObjectName(QStringLiteral("action_auto_line"));
        action_font = new QAction(MyNote);
        action_font->setObjectName(QStringLiteral("action_font"));
        action_status = new QAction(MyNote);
        action_status->setObjectName(QStringLiteral("action_status"));
        action_help = new QAction(MyNote);
        action_help->setObjectName(QStringLiteral("action_help"));
        action_about = new QAction(MyNote);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_color = new QAction(MyNote);
        action_color->setObjectName(QStringLiteral("action_color"));
        centralWidget = new QWidget(MyNote);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        edit_text = new QTextEdit(centralWidget);
        edit_text->setObjectName(QStringLiteral("edit_text"));
        QFont font;
        font.setPointSize(20);
        edit_text->setFont(font);
        edit_text->setStyleSheet(QStringLiteral("border-image: url(:/images/images/193529-106.jpg);"));

        horizontalLayout->addWidget(edit_text);

        MyNote->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MyNote);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 655, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        menu_5 = new QMenu(menuBar);
        menu_5->setObjectName(QStringLiteral("menu_5"));
        MyNote->setMenuBar(menuBar);
        statusBar = new QStatusBar(MyNote);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyNote->setStatusBar(statusBar);
        toolBar = new QToolBar(MyNote);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMaximumSize(QSize(16777215, 20));
        toolBar->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 127);"));
        MyNote->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_5->menuAction());
        menu->addAction(actionnew);
        menu->addAction(actionopen);
        menu->addAction(actionsave);
        menu->addAction(actionsaveAs);
        menu->addSeparator();
        menu->addAction(action_pag_set);
        menu->addAction(action_print);
        menu->addSeparator();
        menu->addAction(action_close);
        menu_2->addSeparator();
        menu_2->addAction(action_copy);
        menu_2->addAction(action_del);
        menu_2->addSeparator();
        menu_2->addAction(action1_find);
        menu_2->addAction(action_find_next);
        menu_2->addAction(action_replace);
        menu_2->addAction(action_turn_to);
        menu_2->addSeparator();
        menu_2->addAction(action_select_all);
        menu_2->addAction(action_date);
        menu_3->addAction(action_auto_line);
        menu_3->addAction(action_font);
        menu_3->addAction(action_color);
        menu_4->addAction(action_status);
        menu_5->addAction(action_help);
        menu_5->addAction(action_about);
        toolBar->addAction(action_cancel);
        toolBar->addAction(action_past);
        toolBar->addAction(action_cut);

        retranslateUi(MyNote);

        QMetaObject::connectSlotsByName(MyNote);
    } // setupUi

    void retranslateUi(QMainWindow *MyNote)
    {
        MyNote->setWindowTitle(QApplication::translate("MyNote", "MyNote", 0));
        actionnew->setText(QApplication::translate("MyNote", "\346\226\260\345\273\272(&N)", 0));
        actionnew->setShortcut(QApplication::translate("MyNote", "Ctrl+N", 0));
        actionopen->setText(QApplication::translate("MyNote", "\346\211\223\345\274\200(&O)", 0));
        actionopen->setShortcut(QApplication::translate("MyNote", "Ctrl+O", 0));
        actionsave->setText(QApplication::translate("MyNote", "\344\277\235\345\255\230(&S)", 0));
        actionsave->setShortcut(QApplication::translate("MyNote", "Ctrl+S", 0));
        actionsaveAs->setText(QApplication::translate("MyNote", "\345\217\246\345\255\230\344\270\272(&A)...", 0));
        actionsaveAs->setShortcut(QApplication::translate("MyNote", "Ctrl+Shift+S", 0));
        action_pag_set->setText(QApplication::translate("MyNote", "\351\241\265\351\235\242\350\256\276\347\275\256(&U)", 0));
        action_print->setText(QApplication::translate("MyNote", "\346\211\223\345\215\260(&P)...", 0));
        action_print->setShortcut(QApplication::translate("MyNote", "Ctrl+P", 0));
        action_close->setText(QApplication::translate("MyNote", "\351\200\200\345\207\272(&X)", 0));
        action_cancel->setText(QApplication::translate("MyNote", "\346\222\244\351\224\200(&U)", 0));
        action_cancel->setShortcut(QApplication::translate("MyNote", "Ctrl+Z", 0));
        action_cut->setText(QApplication::translate("MyNote", "\345\211\252\345\210\207(&T)", 0));
        action_cut->setShortcut(QApplication::translate("MyNote", "Ctrl+X", 0));
        action_copy->setText(QApplication::translate("MyNote", "\345\244\215\345\210\266(&C)", 0));
        action_copy->setShortcut(QApplication::translate("MyNote", "Ctrl+C", 0));
        action_past->setText(QApplication::translate("MyNote", "\347\262\230\350\264\264(&P)", 0));
        action_past->setShortcut(QApplication::translate("MyNote", "Ctrl+V", 0));
        action_del->setText(QApplication::translate("MyNote", "\345\210\240\351\231\244(&L)", 0));
        action_del->setShortcut(QApplication::translate("MyNote", "Del", 0));
        action1_find->setText(QApplication::translate("MyNote", "\346\237\245\346\211\276(&F)", 0));
        action1_find->setShortcut(QApplication::translate("MyNote", "Ctrl+F", 0));
        action_find_next->setText(QApplication::translate("MyNote", "\346\237\245\346\211\276\344\270\213\344\270\200\344\270\252(&N)", 0));
        action_find_next->setShortcut(QApplication::translate("MyNote", "F3", 0));
        action_replace->setText(QApplication::translate("MyNote", "\346\233\277\346\215\242(&R)", 0));
        action_replace->setShortcut(QApplication::translate("MyNote", "Ctrl+H", 0));
        action_turn_to->setText(QApplication::translate("MyNote", "\350\275\254\345\210\260(&G)", 0));
        action_turn_to->setShortcut(QApplication::translate("MyNote", "Ctrl+G", 0));
        action_select_all->setText(QApplication::translate("MyNote", "\345\205\250\351\200\211(&A)", 0));
        action_select_all->setShortcut(QApplication::translate("MyNote", "Ctrl+A", 0));
        action_date->setText(QApplication::translate("MyNote", "\346\227\266\351\227\264/\346\227\245\346\234\237(&D)", 0));
        action_date->setShortcut(QApplication::translate("MyNote", "F5", 0));
        action_auto_line->setText(QApplication::translate("MyNote", "\350\207\252\345\212\250\346\215\242\350\241\214(&W)", 0));
        action_font->setText(QApplication::translate("MyNote", "\345\255\227\344\275\223(&F)", 0));
        action_status->setText(QApplication::translate("MyNote", "\345\267\245\345\205\267\346\240\217(&S)", 0));
        action_help->setText(QApplication::translate("MyNote", "\346\237\245\347\234\213\345\270\256\345\212\251(&H)", 0));
        action_about->setText(QApplication::translate("MyNote", "\345\205\263\344\272\216\350\256\260\344\272\213\346\234\254(&A)", 0));
        action_color->setText(QApplication::translate("MyNote", "\351\242\234\350\211\262(&C)", 0));
        menu->setTitle(QApplication::translate("MyNote", "\346\226\207\344\273\266(&F)", 0));
        menu_2->setTitle(QApplication::translate("MyNote", "\347\274\226\350\276\221(&E)", 0));
        menu_3->setTitle(QApplication::translate("MyNote", "\346\240\274\345\274\217(&O)", 0));
        menu_4->setTitle(QApplication::translate("MyNote", "\346\237\245\347\234\213(&V)", 0));
        menu_5->setTitle(QApplication::translate("MyNote", "\345\270\256\345\212\251(&H)", 0));
        toolBar->setWindowTitle(QApplication::translate("MyNote", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MyNote: public Ui_MyNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYNOTE_H
