#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>

namespace Ui {
class editDialog;
}

class editDialog : public QDialog
{
    Q_OBJECT

public:
    explicit editDialog(QWidget *parent = nullptr);
    ~editDialog();

    void getCellData(QString room,QStringList courses,QStringList teacher, QStringList classes);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public: signals:
    void assignClass(QString classes);
private:
    Ui::editDialog *ui;
};

#endif // EDITDIALOG_H
