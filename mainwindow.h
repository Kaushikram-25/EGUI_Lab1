#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QRegularExpression>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "editdialog.h"
#include "dialogeditdict.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void readJsontoTable();
    void initJson();
    QJsonDocument loadJson(QString fileName);
    void saveJson(QJsonDocument document, QString fileName);

    struct Tabledata {

        QStringList classes;
        QStringList courses;
        QStringList rooms;
        QStringList teachers;
        QVector<QVector<QPair<QString,QString>>> activities;

        Tabledata(){

        }
    };

    Tabledata struct_tableData;
    DialogEditDict *dialogEditDict;
    editDialog *dialogEditCellData;
private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);
Q_SLOT    void updateRoomSelectionComboBox();
Q_SLOT    void getClassCellData(QString classes);

private:
    Ui::MainWindow *ui;



};
#endif // MAINWINDOW_H
