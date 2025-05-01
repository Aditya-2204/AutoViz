/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Project;
    QAction *action_pdf;
    QAction *action_json;
    QAction *actionRun;
    QAction *actionRun_Debug;
    QWidget *centralwidget;
    QLabel *background;
    QTableView *viewProjects;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *openProjects;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuExport_Robot_Data;
    QMenu *menuRun;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen_Project = new QAction(MainWindow);
        actionOpen_Project->setObjectName("actionOpen_Project");
        action_pdf = new QAction(MainWindow);
        action_pdf->setObjectName("action_pdf");
        action_json = new QAction(MainWindow);
        action_json->setObjectName("action_json");
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName("actionRun");
        actionRun_Debug = new QAction(MainWindow);
        actionRun_Debug->setObjectName("actionRun_Debug");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        background = new QLabel(centralwidget);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 811, 581));
        background->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	background-color: rgb(30,30,30);\n"
"}"));
        viewProjects = new QTableView(centralwidget);
        viewProjects->setObjectName("viewProjects");
        viewProjects->setGeometry(QRect(155, 1, 651, 581));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 155, 51));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(10, 0, 10, 0);
        openProjects = new QPushButton(layoutWidget);
        openProjects->setObjectName("openProjects");
        openProjects->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border-radius: 0px;\n"
"	background: rgb(0,57,77);\n"
"\n"
"	padding: 10px;\n"
"}"));

        verticalLayout->addWidget(openProjects);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuExport_Robot_Data = new QMenu(menuFile);
        menuExport_Robot_Data->setObjectName("menuExport_Robot_Data");
        menuRun = new QMenu(menubar);
        menuRun->setObjectName("menuRun");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuRun->menuAction());
        menuFile->addAction(actionOpen_Project);
        menuFile->addAction(menuExport_Robot_Data->menuAction());
        menuExport_Robot_Data->addSeparator();
        menuExport_Robot_Data->addAction(action_pdf);
        menuExport_Robot_Data->addAction(action_json);
        menuRun->addAction(actionRun);
        menuRun->addAction(actionRun_Debug);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_Project->setText(QCoreApplication::translate("MainWindow", "Open Project", nullptr));
        action_pdf->setText(QCoreApplication::translate("MainWindow", ".pdf", nullptr));
        action_json->setText(QCoreApplication::translate("MainWindow", ".json", nullptr));
        actionRun->setText(QCoreApplication::translate("MainWindow", "Run", nullptr));
        actionRun_Debug->setText(QCoreApplication::translate("MainWindow", "Run & Debug", nullptr));
        background->setText(QString());
        openProjects->setText(QCoreApplication::translate("MainWindow", "Open Project", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuExport_Robot_Data->setTitle(QCoreApplication::translate("MainWindow", "Export Robot Data", nullptr));
        menuRun->setTitle(QCoreApplication::translate("MainWindow", "Run", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
