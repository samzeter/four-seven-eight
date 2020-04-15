/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReset;
    QAction *actionQuit;
    QAction *actionSound;
    QWidget *centralwidget;
    QLabel *label_2;
    QLabel *lbl_count_down;
    QProgressBar *progressBar_in;
    QLabel *label;
    QLabel *lbl_num_of_repetitions;
    QProgressBar *progressBar_hold;
    QProgressBar *progressBar_out;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(366, 367);
        MainWindow->setMaximumSize(QSize(366, 367));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionReset->setCheckable(true);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionSound = new QAction(MainWindow);
        actionSound->setObjectName(QString::fromUtf8("actionSound"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 50, 81, 16));
        lbl_count_down = new QLabel(centralwidget);
        lbl_count_down->setObjectName(QString::fromUtf8("lbl_count_down"));
        lbl_count_down->setGeometry(QRect(180, 50, 59, 16));
        progressBar_in = new QProgressBar(centralwidget);
        progressBar_in->setObjectName(QString::fromUtf8("progressBar_in"));
        progressBar_in->setEnabled(true);
        progressBar_in->setGeometry(QRect(60, 90, 211, 61));
        progressBar_in->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"QProgressBar::chunk {\n"
"    background-color: #CD96CD;\n"
"    width: 10px;\n"
"    margin: 0px;\n"
"}"));
        progressBar_in->setMaximum(4);
        progressBar_in->setValue(0);
        progressBar_in->setTextVisible(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 20, 111, 16));
        lbl_num_of_repetitions = new QLabel(centralwidget);
        lbl_num_of_repetitions->setObjectName(QString::fromUtf8("lbl_num_of_repetitions"));
        lbl_num_of_repetitions->setGeometry(QRect(180, 20, 16, 16));
        progressBar_hold = new QProgressBar(centralwidget);
        progressBar_hold->setObjectName(QString::fromUtf8("progressBar_hold"));
        progressBar_hold->setEnabled(true);
        progressBar_hold->setGeometry(QRect(60, 170, 211, 61));
        progressBar_hold->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"QProgressBar::chunk {\n"
"    background-color: green;\n"
"    width: 10px;\n"
"    margin: 0px;\n"
"}"));
        progressBar_hold->setMaximum(7);
        progressBar_hold->setValue(0);
        progressBar_hold->setTextVisible(false);
        progressBar_out = new QProgressBar(centralwidget);
        progressBar_out->setObjectName(QString::fromUtf8("progressBar_out"));
        progressBar_out->setEnabled(true);
        progressBar_out->setGeometry(QRect(60, 250, 211, 61));
        progressBar_out->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"QProgressBar::chunk {\n"
"    background-color: black;\n"
"    width: 10px;\n"
"    margin: 0px;\n"
"}"));
        progressBar_out->setMaximum(8);
        progressBar_out->setValue(0);
        progressBar_out->setTextVisible(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 100, 59, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(290, 190, 59, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(290, 270, 59, 16));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Time", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionSound->setText(QCoreApplication::translate("MainWindow", "Sound", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Count down", nullptr));
        lbl_count_down->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Cycles Remaining", nullptr));
        lbl_num_of_repetitions->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "IN", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "HOLD", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "OUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
