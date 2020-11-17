#include "dialogeditdict.h"
#include "ui_dialogeditdict.h"

DialogEditDict::DialogEditDict(QWidget *parent, QStringList *LIST) :
    QDialog(parent),
    ui(new Ui::DialogEditDict)
{
    ui->setupUi(this);
 //   list = LIST;



//    for( auto item : *list)
//    {
//        ui->listWidget->addItem(item);
//    }


}
void DialogEditDict::setList(QStringList *LIST)
{

    ui->listWidget->clear();
    list = LIST;



    for( auto item : *list)
    {
        ui->listWidget->addItem(item);
    }

}

DialogEditDict::~DialogEditDict()
{
    delete ui;
}

void DialogEditDict::on_pushButtonClose_clicked()
{
    this->hide();
}

void DialogEditDict::on_pushButtonAdd_clicked()
{
    list->push_back(ui->lineEditData->text());
    ui->listWidget->addItem(ui->lineEditData->text());

    emit updateRooms();
}

void DialogEditDict::on_pushButtonRemove_clicked()
{
    list->removeAt(ui->listWidget->currentIndex().row());
    ui->listWidget->clear();

    for( auto item : *list)
    {
        ui->listWidget->addItem(item);
    }

    emit updateRooms();

}
