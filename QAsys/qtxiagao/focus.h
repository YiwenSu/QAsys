#ifndef FOCUS_H
#define FOCUS_H

#include <QWidget>
#include "user.h"
#include "Anslist.h"
#include "userlist.h"
#include "total.h"
#include <QMessageBox>
#include "answer.h"
namespace Ui {
class focus;
}

class focus : public QWidget
{
    Q_OBJECT

public:
    explicit focus(QWidget *parent = 0);
    ~focus();
    void Displayfocus(int &chose);
    void Displayqanda(int &chose, vector<int> qid, vector<int> flag);
public slots:
    void reshow(){this->show();}

private slots:
    void on_pushButton_2_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_tableWidget_2_doubleClicked(const QModelIndex &index);
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

signals:
    void show_answer();
    void show_question();
private:
    Ui::focus *ui;
    vector<int>Qid;
    vector<int>flag;
    Answer* a=new Answer;
    int chose0;
    int chose1;
};

#endif // FOCUS_H
