#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //init table widget item

    QStringList headerStrings;
    headerStrings << "Mon" << "Tue" << "Web" << "Thur" << "Fri";

    QStringList rowStrings;
    rowStrings << "8:00-8:45" << "8:55-9:40" << "9:50-10:35" << "10:45-11:30" << "11:40-12:25" << "12:35-13:20" << "13:30-14:15"
               << "14:25-15:10" << "15:20-16:05" << "16:15-17:00";

    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->horizontalHeader()->setStyleSheet("color: #000000; background-color: #000000;");
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setStyleSheet("color: #000000; background-color: #000000;");
    ui->tableWidget->setHorizontalHeaderLabels(headerStrings);
    ui->tableWidget->setVerticalHeaderLabels(rowStrings);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setStyleSheet("border: none; background-color: rgb(0, 0, 0);selection-background-color: #999; color: #FFFFFF"); //for demo purposes



    //readJsontoTable();
    initJson();

    dialogEditCellData = new editDialog();
     dialogEditDict = new DialogEditDict;
     connect(ui->actionClasses, &QAction::triggered, [this]() { dialogEditDict->setList(&struct_tableData.classes);
     dialogEditDict->show();});

     connect(ui->actionCourses, &QAction::triggered, [this]() { dialogEditDict->setList(&struct_tableData.courses);
     dialogEditDict->show();});

     connect(ui->actionRoom, &QAction::triggered, [this]() { dialogEditDict->setList(&struct_tableData.rooms);
     dialogEditDict->show();});

     connect(ui->actionTeacher, &QAction::triggered, [this]() { dialogEditDict->setList(&struct_tableData.teachers);
     dialogEditDict->show();});

     connect(ui->actionQuit, &QAction::triggered, [this]() { this->close();});

     connect(dialogEditDict, SIGNAL(updateRooms()), this, SLOT(updateRoomSelectionComboBox()));


     connect(dialogEditCellData,SIGNAL(assignClass(QString)),this,SLOT(getClassCellData(QString)));

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateRoomSelectionComboBox()
{
    ui->comboBoxRoom->clear();

    for(auto str: struct_tableData.rooms)
        ui->comboBoxRoom->addItem(str);
}


void MainWindow::initJson()
{


    struct_tableData.rooms.push_back("110");
    struct_tableData.rooms.push_back("112");
    struct_tableData.rooms.push_back("120");
    struct_tableData.rooms.push_back("121");

    struct_tableData.classes.push_back("1a");
    struct_tableData.classes.push_back("1b");
    struct_tableData.classes.push_back("2a");
    struct_tableData.classes.push_back("2b");
    struct_tableData.classes.push_back("3a");
    struct_tableData.classes.push_back("3b");
    struct_tableData.classes.push_back("4a");
    struct_tableData.classes.push_back("5b");

    struct_tableData.courses.push_back("mat");
    struct_tableData.courses.push_back("geo");
    struct_tableData.courses.push_back("eng");
    struct_tableData.courses.push_back("phys");
    struct_tableData.courses.push_back("bio");

    struct_tableData.teachers.push_back("kowalski");
    struct_tableData.teachers.push_back("nowak");
    struct_tableData.teachers.push_back("smith");
    struct_tableData.teachers.push_back("clarkson");
    struct_tableData.teachers.push_back("may");
    struct_tableData.teachers.push_back("hammond");
    struct_tableData.teachers.push_back("atkinson");


    QJsonObject recordObject;

    QJsonObject obj;
    obj.insert("room","110");
    obj.insert("group","1a");
    obj.insert("class","mat");
    obj.insert("slot","1");
    obj.insert("teacher","kowalski");


    QJsonArray rooms;
    rooms.push_back("110");
    rooms.push_back("111");
    rooms.push_back("120");
    rooms.push_back("121");
    recordObject.insert("rooms", rooms);


    QJsonArray groups;
    groups.push_back("1a");
    groups.push_back("1b");
    groups.push_back("1c");
    groups.push_back("2a");
    groups.push_back("2b");
    groups.push_back("3a");
    groups.push_back("3b");
    groups.push_back("4a");
    groups.push_back("4b");
    recordObject.insert("groups", groups);

    QJsonArray classes;
    classes.push_back("mat");
    classes.push_back("geo");
    classes.push_back("eng");
    classes.push_back("phys");
    classes.push_back("bio");
    recordObject.insert("classes", classes);

    QJsonArray teachers;
    teachers.push_back("kowalski");
    teachers.push_back("nowak");
    teachers.push_back("smith");
    teachers.push_back("clarkson");
    teachers.push_back("may");
    teachers.push_back("hammond");
    teachers.push_back("atkinson");
    recordObject.insert("teachers", teachers);


    QJsonDocument doc(recordObject);


    saveJson(doc, "data.json");

}


QJsonDocument MainWindow::loadJson(QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}

void MainWindow::saveJson(QJsonDocument document, QString fileName) {
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{   
    dialogEditCellData->getCellData(ui->comboBoxRoom->currentText(),struct_tableData.courses,struct_tableData.teachers,struct_tableData.classes);
    dialogEditCellData->show();
}

void MainWindow::getClassCellData(QString classes)
{

ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(), new QTableWidgetItem(classes));
}
