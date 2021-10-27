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
    QLabel *title;
    QLabel *loseLabel;
    QLabel *highScoreLabel;
    QLabel *scoreLabel;
    QLabel *lastGameScoreLabel;
    QLabel *lastScoreLabel;
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
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(160, 10, 471, 81));
        QFont font;
        font.setPointSize(50);
        font.setBold(true);
        font.setUnderline(true);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);
        loseLabel = new QLabel(centralwidget);
        loseLabel->setObjectName(QString::fromUtf8("loseLabel"));
        loseLabel->setEnabled(true);
        loseLabel->setGeometry(QRect(80, 110, 641, 301));
        QFont font1;
        font1.setPointSize(69);
        loseLabel->setFont(font1);
        loseLabel->setAutoFillBackground(true);
        loseLabel->setAlignment(Qt::AlignCenter);
        highScoreLabel = new QLabel(centralwidget);
        highScoreLabel->setObjectName(QString::fromUtf8("highScoreLabel"));
        highScoreLabel->setGeometry(QRect(230, 330, 171, 41));
        QFont font2;
        font2.setPointSize(16);
        highScoreLabel->setFont(font2);
        highScoreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        scoreLabel = new QLabel(centralwidget);
        scoreLabel->setObjectName(QString::fromUtf8("scoreLabel"));
        scoreLabel->setGeometry(QRect(410, 333, 81, 41));
        scoreLabel->setFont(font2);
        scoreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lastGameScoreLabel = new QLabel(centralwidget);
        lastGameScoreLabel->setObjectName(QString::fromUtf8("lastGameScoreLabel"));
        lastGameScoreLabel->setGeometry(QRect(230, 360, 171, 41));
        lastGameScoreLabel->setFont(font2);
        lastGameScoreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lastScoreLabel = new QLabel(centralwidget);
        lastScoreLabel->setObjectName(QString::fromUtf8("lastScoreLabel"));
        lastScoreLabel->setGeometry(QRect(410, 370, 81, 41));
        lastScoreLabel->setFont(font2);
        lastScoreLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
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
        redButton->setText(QString());
        blueButton->setText(QString());
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        title->setText(QCoreApplication::translate("MainWindow", "SIMON GAME", nullptr));
        loseLabel->setText(QCoreApplication::translate("MainWindow", "You Lose", nullptr));
        highScoreLabel->setText(QCoreApplication::translate("MainWindow", "High Score:", nullptr));
        scoreLabel->setText(QString());
        lastGameScoreLabel->setText(QCoreApplication::translate("MainWindow", "Last Game Score:", nullptr));
        lastScoreLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
