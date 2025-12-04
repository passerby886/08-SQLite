#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QStandardItemModel>
#include <QItemSelection>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showAll();                            // 显示所有数据

private slots:
    void on_pushButton_create_clicked();

    void on_pushButton_insert_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_modify_clicked();

    void on_pushButton_select_clicked();

    void on_pushButton_findall_clicked();

    void on_tableView_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;                                            // 定义一个数据库对象
    QStandardItemModel *model = nullptr;                        // Qt 中用于管理数据的标准模型类，常与视图组件主要作用包括：以行列结构存储数据（类似表格）支持添加、删除、修改数据项提供数据索引，供视图组件访问和显示数据可通过 QStandardItem 类创建具体的数据项并添加到模型中
    quint64 lineCount = 0;                                          // tableView 关联的行号
};
#endif // MAINWINDOW_H
