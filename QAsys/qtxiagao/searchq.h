#ifndef SEARCHQ_H
#define SEARCHQ_H
#include "total.h"
#include <QWidget>
#include <QWidget>
#include "Anslist.h"
#include "userlist.h"
#include <QMessageBox>
namespace Ui {
class SearchQ;
}

class SearchQ : public QWidget
{
    Q_OBJECT

public:
    explicit SearchQ(QWidget *parent = 0);
    ~SearchQ();
    void Displayques(int &chose,vector<int>qid);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

public slots:
    void reshow(){this->show();}
signals:
    void show_answer();
    void show_question();
private:
    Ui::SearchQ *ui;
    QString year;
    QString month;
    QString day;
    QString title;
    vector<int>Qid;
    int chose0;
};

#endif // SEARCHQ_H
