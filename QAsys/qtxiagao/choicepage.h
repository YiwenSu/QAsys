#ifndef CHOICEPAGE_H
#define CHOICEPAGE_H
#include<QHeaderView>
#include <QMainWindow>
#include <Anslist.h>
#include <userlist.h>
#include <QtGui>
#include <QMessageBox>
#include "login.h"
#include "total.h"
#include "focus.h"

namespace Ui {
class choicepage;
}

class choicepage : public QMainWindow
{
    Q_OBJECT

public:
    explicit choicepage(QWidget *parent = 0);
    ~choicepage();
    void Displayques(int &chose);

public slots:
    void reshow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void recieve_auid(QString au){this->auid=au;}
    void on_tableWidget_doubleClicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

signals:
    //void send_qid(int qid);
    void show_answer();
    void show_focus();
    void show_search();
    void show_log();
private:
    Ui::choicepage *ui;
    focus*f=new focus;
    int page;
    QString auid;
};

#endif // CHOICEPAGE_H
