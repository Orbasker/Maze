/********************************************************************************
** Form generated from reading UI file 'mazrcontroller.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAZRCONTROLLER_H
#define UI_MAZRCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MazrController
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MazrController)
    {
        if (MazrController->objectName().isEmpty())
            MazrController->setObjectName("MazrController");
        MazrController->resize(800, 600);
        centralwidget = new QWidget(MazrController);
        centralwidget->setObjectName("centralwidget");
        MazrController->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MazrController);
        menubar->setObjectName("menubar");
        MazrController->setMenuBar(menubar);
        statusbar = new QStatusBar(MazrController);
        statusbar->setObjectName("statusbar");
        MazrController->setStatusBar(statusbar);

        retranslateUi(MazrController);

        QMetaObject::connectSlotsByName(MazrController);
    } // setupUi

    void retranslateUi(QMainWindow *MazrController)
    {
        MazrController->setWindowTitle(QCoreApplication::translate("MazrController", "MazrController", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MazrController: public Ui_MazrController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAZRCONTROLLER_H
