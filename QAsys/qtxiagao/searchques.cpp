#include "searchques.h"
#include "ui_Search.h"

Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    this->resize(1000,1000);
    QStringList list;
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    list<<tr("qid")<<tr("Title:")<<tr("author name:")<<tr("time:");
    ui->tableWidget->setHorizontalHeaderLabels(list);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Search::~Search()
{
    delete ui;

}

void Search::on_pushButton_4_clicked()
{
    userlist ulist;
    Anslist alist;
    ulist.outofuserfile();
    alist.outoffile();

    this->Qid.clear();
    this->title=ui->lineEdit->text();
    alist.SearchQuestion(title,this->Qid);
    this->chose0=1;
    this->Displayques(this->chose0,this->Qid);
}

void Search:: Displayques(int chose,vector<int>qid)
{
       userlist ulist;
       Anslist alist;
       ulist.outofuserfile();
       alist.outoffile();

       double j=(double)qid.size()/3;
          int page=ceil(j);

       if(chose<=0||chose>page)
            QMessageBox::information(NULL, "page",
                                     "you have already reach the last or the starting page",
                                     QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

        int num =qid.size()-1-chose*3+3;

        ui->tableWidget->setRowCount(0);
        ui->tableWidget->clearContents();

        for(int i=num;i>=num-2&&i>=0;i--)
        {
        BasicInfo* b=new Quas();
        int row =ui->tableWidget->rowCount();
        QString time,au,t;
        b=this->ans[qid[i]][0];
        b->Getauid(au);
        b->Gettitle(t);
        b->Gettime(time);
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::number(qid[i]+1)));
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(t));
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(au));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(time));

        }

}
