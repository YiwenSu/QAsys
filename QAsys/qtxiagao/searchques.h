#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include "Anslist.h"
#include "userlist.h"
#include <QMessageBox>
namespace Ui {
class Search;
}

class Search : public QWidget
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();
    void Displayques(int chose,vector<int>qid);
private slots:
    void on_pushButton_4_clicked();
public slots:
    void reshow(){this->show();}

private:
    Ui::Search *ui;
    QString year;
    QString month;
    QString day;
    QString title;
    vector<int>Qid;
    int chose0;
};

#endif // SEARCH_H
