#include "editdialog.h"
#include "ui_editdialog.h"

editDialog::editDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editDialog)
{
    ui->setupUi(this);


}

editDialog::~editDialog()
{
    delete ui;
}


void editDialog::getCellData(QString room,QStringList courses,QStringList teacher, QStringList classes)
{
    ui->nameRoom->setText(room);


    ui->courseComboBox->clear();
    for(auto c: courses)
    ui->courseComboBox->addItem(c);

    ui->teacherComboBox->clear();
    for(auto c: teacher)
    ui->teacherComboBox->addItem(c);

    ui->classComboBox->clear();
    for(auto c: classes)
    ui->classComboBox->addItem(c);

}

void editDialog::on_pushButton_clicked()
{
    this->hide();
}

void editDialog::on_pushButton_2_clicked()
{
    emit assignClass(ui->classComboBox->currentText());
    this->hide();
}

void editDialog::on_pushButton_3_clicked()
{
    emit assignClass("");
    this->hide();
}
