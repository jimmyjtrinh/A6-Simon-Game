/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *redButton;
    QPushButton *blueButton;
    QPushButton *startButton;
    QProgressBar *progressBar;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        redButton = new QPushButton(centralwidget);
        redButton->setObjectName(QString::fromUtf8("redButton"));
        redButton->setEnabled(false);
        redButton->setGeometry(QRect(190, 210, 181, 161));
        blueButton = new QPushButton(centralwidget);
        blueButton->setObjectName(QString::fromUtf8("blueButton"));
        blueButton->setEnabled(false);
        blueButton->setGeometry(QRect(400, 210, 181, 161));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(320, 450, 131, 91));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(320, 130, 118, 23));
        progressBar->setValue(0);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 10, 471, 81));
        QFont font;
        font.setPointSize(50);
        font.setBold(true);
        font.setUnderline(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        redButton->setText(QCoreApplication::translate("MainWindow", "Red", nullptr));
        blueButton->setText(QCoreApplication::translate("MainWindow", "Blue", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "SIMON GAME", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
