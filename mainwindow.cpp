#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_studentID->setText("20250917");
    ui->comboBox_gender->setEditText("男");
    ui->lineEdit_score->setText("30");
    ui->lineEdit_name->setText("李华");
    ui->lineEdit_age->setText("18");

    // QStandardItemModel负责保存数据
    model = new QStandardItemModel();
    /*设置列字段名*/
    model->setColumnCount(5); // 设置这个数据模型为5列 , 设置 一行有5列
    model->setHeaderData(0,Qt::Horizontal, tr("学号")); // 第一列名 序号
    model->setHeaderData(1,Qt::Horizontal, tr("姓名")); // 第二列名 姓名
    model->setHeaderData(2,Qt::Horizontal, tr("性别")); // 第3列名 性别
    model->setHeaderData(3,Qt::Horizontal, tr("年龄")); // 第4列名 年龄
    model->setHeaderData(4,Qt::Horizontal, tr("分数")); // 第5列名 分数
    /*设置好后，模型要安装*/
    // 把 数据模型和显示模型进行关联
    ui->tableView->setModel(model) ; // 给tableview 安装一个数据模型 model ， 数据此时就显示出来了

    // 让tableview显示宽度
    ui->tableView->horizontalHeader()->setDefaultSectionSize(180); //设置水平头宽度
    ui->tableView->verticalHeader()->setHidden(true); // 行名隐藏
    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 去掉tableView的水平滚动条
    ui->tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QStringList lists = QSqlDatabase::drivers() ;
    foreach (QString l, lists) {
        qDebug()<<"支持的数据库驱动为:" << l ;
    }
    db = QSqlDatabase::addDatabase("QSQLITE");  // 设置要打开数据库的类型，这个数据库类型是SQlite3
    db.setDatabaseName("my.db");                // 要打开数据库的名称
    bool ok = db.open() ;                       // 如果不存在则创建， 存在车打开
    if(!ok)                                     // 打开数据库失败
    {
        QMessageBox::warning(this,tr("SQLite3"),tr("数据库打开失败"));
    }

    showAll();                                  // 运行后显示界面


}

MainWindow::~MainWindow()
{
    delete ui;
}

// 创建表按钮
void MainWindow::on_pushButton_create_clicked()
{
    // 创建数据库的表
    // 执行一个sql语句， 使用QSqlQuery
    QString sql = "create table student("
                  "number bigint primary key,"
                  "name varchar(50) not null,"
                  "gender char(2) check(gender in ('男', '女', '其他')),"
                  "age int check (age > 0 and age < 150),"
                  "score decimal(5, 2) check(score >= 0 and score <= 100) "
                  ");" ;
    QSqlQuery query ; //创建一个执行sql语句的对象
    bool ok = query.exec(sql) ; // 执行数据库语句
    if(!ok) // 执行sql语句失败
    {
        // 获取错误信息
        qDebug() << query.lastError().text() ;
        QMessageBox::critical(this,tr("创建表错误"),query.lastError().text());
        return ;
    }
    else // 创建表成功
    {
        QMessageBox::information(this,tr("创建数据库成功"),tr("创建student表成功"));
    }
}

// 插入数据按钮
void MainWindow::on_pushButton_insert_clicked()
{
    // 插入数据
    // 执行一个sql语句， 使用QSqlQuery
    QString sql = tr("insert into student values(%0, '%1', '%2', %3, %4);")
                      .arg(ui->lineEdit_studentID->text().toUInt())
                      .arg(ui->lineEdit_name->text())
                      .arg(ui->comboBox_gender->currentText())
                      .arg(ui->lineEdit_age->text().toUInt())
                      .arg(ui->lineEdit_score->text().toFloat())
        ;
    QSqlQuery query ; //创建一个执行sql语句的对象
    bool ok = query.exec(sql) ; // 执行数据库语句
    if(!ok) // 执行sql语句失败
    {
        // 获取错误信息
        qDebug() << query.lastError().text() ;
        QMessageBox::critical(this,tr("插入数据成功"),query.lastError().text());
        return ;
    }
    else // 插入表成功
    {
        QMessageBox::information(this,tr("插入数据"),tr("向student表插入数据成功"));
        qDebug() << "向student表插入数据成功" ;
    }
    showAll();
}

// 删除数据按钮
void MainWindow::on_pushButton_delete_clicked()
{
    // 执行删除
    // 执行一个sql语句， 使用QSqlQuery
    QString sql = tr("delete from student where number = %0 ;")
                      .arg(ui->lineEdit_studentID->text().toUInt()) ;

    QSqlQuery query ;                   //创建一个执行sql语句的对象
    bool ok = query.exec(sql) ;         // 执行数据库语句
    if(!ok)                             // 执行sql语句失败
    {
        // 获取错误信息
        qDebug() << query.lastError().text() ;
        QMessageBox::critical(this,tr("删除数据错误"),query.lastError().text());
        return ;
    }
    else                                // 删除数据成功
    {
        QMessageBox::information(this,tr("删除数据"),tr("向student表删除数据成功"));
        qDebug() << "向student表删除数据成功" ;
    }
    showAll();
}

// 修改数据按钮
void MainWindow::on_pushButton_modify_clicked()
{
    // 修改数据
    // 执行一个sql语句， 使用QSqlQuery
    QString sql = tr("update student set name = '%0', gender = '%1', age = %2, score = %3 where number = %4;")
                      .arg(ui->lineEdit_name->text())
                      .arg(ui->comboBox_gender->currentText())
                      .arg(ui->lineEdit_age->text().toUInt())
                      .arg(ui->lineEdit_score->text().toFloat())
                      .arg(ui->lineEdit_studentID->text().toUInt());

    QSqlQuery query ;                   //创建一个执行sql语句的对象
    bool ok = query.exec(sql) ;         // 执行数据库语句
    if(!ok)                             // 执行sql语句失败
    {
        // 获取错误信息
        qDebug() << query.lastError().text() ;
        QMessageBox::critical(this,tr("修改数据错误"),query.lastError().text());
        return ;
    }
    else                                // 修改数据成功
    {
        QMessageBox::information(this,tr("修改数据"),tr("向student表修改数据成功"));
        qDebug() << "向student表修改数据成功" ;

    }
    showAll();
}

// 按学号查找按钮
void MainWindow::on_pushButton_select_clicked()
{
    // 先清空显示的数据
    model->removeRows(0, lineCount);
    lineCount = 0;

    // 执行一个sql语句， 使用QSqlQuery
    QString sql = tr("select * from student where number = %0;")
                      .arg(ui->lineEdit_studentID->text().toUInt());

    QSqlQuery query ;                   //创建一个执行sql语句的对象
    bool ok = query.exec(sql) ;         // 执行数据库语句
    if(!ok)                             // 执行sql语句失败
    {
        // 获取错误信息
        qDebug() << query.lastError().text() ;
        QMessageBox::critical(this,tr("查找数据错误"),query.lastError().text());
        return ;
    }
    else                                // // 查询成功
    {
        //获取记录中的内容
        //如果返回假，没有找到记录
        //如果返回为真，找到记录，执行一次会自动往后移动一个记录， 直到返回为假为止

        if (query.next())
        {
            qDebug() << "number: " << query.value(0).toInt() ;        // 第1列
            qDebug() << "  name: " << query.value(1).toString() ;      // 第2列
            qDebug() << "gender: " << query.value(2).toString() ;     // 第3列
            qDebug() << "   age: " << query.value(3).toInt() ;         // 第4列
            qDebug() << " score: " << query.value(4).toInt() ;         // 第5列

            // 添加数据到model中
            if (model != nullptr) {
                /*设置一条数据*/
                // lineCount : 是数据的第几行
                // 0 : 第几列
                for(int i = 0; i < model->columnCount(); ++ i)
                {
                    qDebug() << "lineCount = " << lineCount;
                    model->setItem(lineCount, i, new QStandardItem(query.value(i).toString())); // 添加数据到tableView中
                    model->item(lineCount, i)->setTextAlignment(Qt::AlignCenter);               // 设置linecount行的0列 居中显示
                }
                // 一条数据添加完成后，linecount++，表示下一行
                lineCount ++;

                // 给tableview安装模型
                ui->tableView->setModel(model);
            }
        }

    }
    qDebug() << "lineCount = " << lineCount;
    // 检查是否有数据
    if(lineCount == 0) {
        QMessageBox::information(this, tr("查询结果"), tr("未找到匹配的学生记录"));
    }
}

// 查询所有数据
void MainWindow::showAll()
{
    // 先清空显示的数据
    model->removeRows(0, lineCount);
    lineCount = 0;

    // 执行一个sql语句， 使用QSqlQuery
    QString sql = tr("select * from student;");
    qDebug() << "sql = " << sql;
    QSqlQuery query ;                   //创建一个执行sql语句的对象
    bool ok = query.exec(sql) ;         // 执行数据库语句
    if(!ok)                             // 执行sql语句失败
    {
        // 获取错误信息
        qDebug() << query.lastError().text() ;
        QMessageBox::critical(this,tr("查找数据错误"),query.lastError().text());
        return ;
    }
    else                                // 查询成功
    {
        //获取记录中的内容
        //如果返回假，没有找到记录
        //如果返回为真，找到记录，执行一次会自动往后移动一个记录， 直到返回为假为止
        // if ()
        //qDebug() << " query.next() : " << query.next();
        while (query.next())
        {
            qDebug() << "number: " << query.value(0).toInt() ;        // 第1列
            qDebug() << "  name: " << query.value(1).toString() ;      // 第2列
            qDebug() << "gender: " << query.value(2).toString() ;     // 第3列
            qDebug() << "   age: " << query.value(3).toInt() ;         // 第4列
            qDebug() << " score: " << query.value(4).toInt() ;         // 第5列

            //lineCount = 0;
            // 添加数据到model中
            if (model != nullptr) {
                /*设置一条数据*/
                // lineCount : 是数据的第几行
                // 0 : 第几列
                for(int i = 0; i < model->columnCount(); ++ i)
                {
                    qDebug() << "lineCount = " << lineCount;
                    model->setItem(lineCount, i, new QStandardItem(query.value(i).toString())); // 添加数据到tableView中
                    model->item(lineCount, i)->setTextAlignment(Qt::AlignCenter);               // 设置linecount行的0列 居中显示
                }
                lineCount++;                                                                    // 一条数据添加完成后，linecount++，表示下一行
                // 给tableview安装模型
                ui->tableView->setModel(model);
            }

        }
        // 检查是否有数据
        if(lineCount == 0) {
            QMessageBox::information(this, tr("提示"), tr("表中暂无数据"));
        }

    }
}

// 显示所有数据按钮
void MainWindow::on_pushButton_findall_clicked()
{
    showAll();                                                         // 调用显示所有数据
}

// 点击tableView后自动获取选中的行数据填充到右侧中
// 实现选中行处理槽函数
void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    qDebug() << "实现选中行处理槽函数on_tableView_activated: " << index;
    qDebug() << "实现选中行处理槽函数on_tableView_activated: " << index;

    // 1. 获取被激活单元格所在的行号（整行数据的关键）
    int selectedRow = index.row();

    // 2. 安全校验：确保行号有效，且model中对应行的item不为空
    if (selectedRow < 0 || selectedRow >= model->rowCount()) {
        qDebug() << "无效的行号";
        return;
    }

    // 3. 按列索引提取数据（对应数据库的：学号0、姓名1、性别2、年龄3、分数4）
    // 学号（第0列）
    QStandardItem *itemID = model->item(selectedRow, 0);
    if (itemID) { // 避免空指针崩溃
        ui->lineEdit_studentID->setText(itemID->text());
    }

    // 姓名（第1列）
    QStandardItem *itemName = model->item(selectedRow, 1);
    if (itemName) {
        ui->lineEdit_name->setText(itemName->text());
    }

    // 性别（第2列，填充到comboBox）
    QStandardItem *itemGender = model->item(selectedRow, 2);
    if (itemGender) {
        QString genderText = itemGender->text();
        // 找到comboBox中对应的选项索引，避免直接setText（可能匹配失败）
        int genderIdx = ui->comboBox_gender->findText(genderText);
        if (genderIdx != -1) { // 找到对应选项才设置
            ui->comboBox_gender->setCurrentIndex(genderIdx);
        }
    }

    // 年龄（第3列）
    QStandardItem *itemAge = model->item(selectedRow, 3);
    if (itemAge) {
        ui->lineEdit_age->setText(itemAge->text());
    }

    // 分数（第4列）
    QStandardItem *itemScore = model->item(selectedRow, 4);
    if (itemScore) {
        ui->lineEdit_score->setText(itemScore->text());
    }
}

