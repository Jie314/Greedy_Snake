/********************************************************************************
** Form generated from reading UI file 'Greedy_Snake.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GREEDY_SNAKE_H
#define UI_GREEDY_SNAKE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Greedy_SnakeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Greedy_SnakeClass)
    {
        if (Greedy_SnakeClass->objectName().isEmpty())
            Greedy_SnakeClass->setObjectName(QString::fromUtf8("Greedy_SnakeClass"));
        Greedy_SnakeClass->resize(600, 400);
        menuBar = new QMenuBar(Greedy_SnakeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Greedy_SnakeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Greedy_SnakeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Greedy_SnakeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Greedy_SnakeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Greedy_SnakeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Greedy_SnakeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Greedy_SnakeClass->setStatusBar(statusBar);

        retranslateUi(Greedy_SnakeClass);

        QMetaObject::connectSlotsByName(Greedy_SnakeClass);
    } // setupUi

    void retranslateUi(QMainWindow *Greedy_SnakeClass)
    {
        Greedy_SnakeClass->setWindowTitle(QCoreApplication::translate("Greedy_SnakeClass", "Greedy_Snake", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Greedy_SnakeClass: public Ui_Greedy_SnakeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GREEDY_SNAKE_H
