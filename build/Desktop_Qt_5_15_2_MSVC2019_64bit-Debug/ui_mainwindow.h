/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QLabel *label;
    QLineEdit *lineEdit_studentID;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_age;
    QLabel *label_5;
    QLineEdit *lineEdit_score;
    QComboBox *comboBox_gender;
    QPushButton *pushButton_create;
    QPushButton *pushButton_insert;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_modify;
    QPushButton *pushButton_select;
    QPushButton *pushButton_findall;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 1000);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/SQLite_logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(36, 36));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(0, 0, 900, 1000));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(920, 50, 54, 35));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(12);
        label->setFont(font);
        lineEdit_studentID = new QLineEdit(centralwidget);
        lineEdit_studentID->setObjectName(QString::fromUtf8("lineEdit_studentID"));
        lineEdit_studentID->setGeometry(QRect(990, 50, 191, 35));
        lineEdit_studentID->setFont(font);
        lineEdit_name = new QLineEdit(centralwidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setGeometry(QRect(990, 120, 191, 35));
        lineEdit_name->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(920, 120, 54, 35));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(920, 190, 54, 35));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(920, 260, 54, 35));
        label_4->setFont(font);
        lineEdit_age = new QLineEdit(centralwidget);
        lineEdit_age->setObjectName(QString::fromUtf8("lineEdit_age"));
        lineEdit_age->setGeometry(QRect(990, 260, 191, 35));
        lineEdit_age->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(920, 330, 54, 35));
        label_5->setFont(font);
        lineEdit_score = new QLineEdit(centralwidget);
        lineEdit_score->setObjectName(QString::fromUtf8("lineEdit_score"));
        lineEdit_score->setGeometry(QRect(990, 330, 191, 35));
        lineEdit_score->setFont(font);
        comboBox_gender = new QComboBox(centralwidget);
        comboBox_gender->addItem(QString());
        comboBox_gender->addItem(QString());
        comboBox_gender->setObjectName(QString::fromUtf8("comboBox_gender"));
        comboBox_gender->setGeometry(QRect(990, 190, 191, 35));
        comboBox_gender->setFont(font);
        pushButton_create = new QPushButton(centralwidget);
        pushButton_create->setObjectName(QString::fromUtf8("pushButton_create"));
        pushButton_create->setGeometry(QRect(950, 420, 200, 50));
        QFont font1;
        font1.setPointSize(12);
        pushButton_create->setFont(font1);
        pushButton_insert = new QPushButton(centralwidget);
        pushButton_insert->setObjectName(QString::fromUtf8("pushButton_insert"));
        pushButton_insert->setGeometry(QRect(950, 520, 200, 50));
        pushButton_insert->setFont(font1);
        pushButton_delete = new QPushButton(centralwidget);
        pushButton_delete->setObjectName(QString::fromUtf8("pushButton_delete"));
        pushButton_delete->setGeometry(QRect(950, 620, 200, 50));
        pushButton_delete->setFont(font1);
        pushButton_modify = new QPushButton(centralwidget);
        pushButton_modify->setObjectName(QString::fromUtf8("pushButton_modify"));
        pushButton_modify->setGeometry(QRect(950, 720, 200, 50));
        pushButton_modify->setFont(font1);
        pushButton_select = new QPushButton(centralwidget);
        pushButton_select->setObjectName(QString::fromUtf8("pushButton_select"));
        pushButton_select->setGeometry(QRect(950, 820, 200, 50));
        pushButton_select->setFont(font1);
        pushButton_findall = new QPushButton(centralwidget);
        pushButton_findall->setObjectName(QString::fromUtf8("pushButton_findall"));
        pushButton_findall->setGeometry(QRect(950, 920, 200, 40));
        pushButton_findall->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SQLite 1.1", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\255\246\345\217\267\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\200\247\345\210\253\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\271\264\351\276\204\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\210\220\347\273\251\357\274\232", nullptr));
        comboBox_gender->setItemText(0, QCoreApplication::translate("MainWindow", "\347\224\267", nullptr));
        comboBox_gender->setItemText(1, QCoreApplication::translate("MainWindow", "\345\245\263", nullptr));

        pushButton_create->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\350\241\250", nullptr));
        pushButton_insert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\350\256\260\345\275\225", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
        pushButton_modify->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\350\256\260\345\275\225", nullptr));
        pushButton_select->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276\350\256\260\345\275\225", nullptr));
        pushButton_findall->setText(QCoreApplication::translate("MainWindow", "\346\237\245\346\211\276\346\211\200\346\234\211\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
