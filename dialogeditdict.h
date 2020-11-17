#ifndef DIALOGEDITDICT_H
#define DIALOGEDITDICT_H

#include <QDialog>
#include <QList>

namespace Ui {
class DialogEditDict;
}

class DialogEditDict : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEditDict(QWidget *parent = nullptr, QStringList *LIST = new QStringList() );
    ~DialogEditDict();
    void setList(QStringList *LIST);

private slots:
    void on_pushButtonClose_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonRemove_clicked();

public: signals:
    void updateRooms();
private:
    Ui::DialogEditDict *ui;
    QStringList *list;
};

#endif // DIALOGEDITDICT_H
