#ifndef ANSWER_H
#define ANSWER_H
#include "total.h"
#include <QWidget>
#include "Quas.h"
#include "Answ.h"
#include "userlist.h"
#include "Anslist.h"
#include "QMessageBox"
namespace Ui {
class Answer;
}

class Answer : public QWidget
{
    Q_OBJECT

public:
    explicit Answer(QWidget *parent = 0);
    ~Answer();
    void Displayans(int &chose, int qid);
public slots:

    void reshow();
private slots:
    //void recieve_qid(int num){this->Qid=num;}
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();
signals:
    void show_choice();
private:
    Ui::Answer *ui;
    int Qid;
    int chose;
};

#endif // ANSWER_H
