#include "choicepage.h"
#include "ui_choicepage.h"

choicepage::choicepage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::choicepage)
{
        ui->setupUi(this);

        this->resize(1000,1000);
        QStringList list;
        ui->tableWidget->setRowCount(1);
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
        ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
        list<<tr("Title:")<<tr("author name:")<<tr("time:")<<tr("id");
        ui->tableWidget->setHorizontalHeaderLabels(list);
        QHeaderView* headerView = ui->tableWidget->horizontalHeader();
        headerView->setSectionResizeMode(QHeaderView::Stretch);
        this->page=1;
        Displayques(this->page);
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->resizeRowsToContents();
        ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        //this->Displayques(this->page);
}


choicepage::~choicepage()
{
    delete ui;
}

void choicepage::reshow()
{
    this->show();

    this->page=1;
    Displayques(this->page);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView* headerView = ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);
}
void choicepage::Displayques(int &chose)
{
           userlist ulist;
           Anslist alist;
           ulist.outofuserfile();
           alist.outoffile();

           double j=(double)alist.ans.size()/3;
           int page=ceil(j);

           if(chose<=0||chose>page)
               QMessageBox::information(NULL, "page", "you have already reach the last or the starting page", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
           if(chose<=0)
               chose=1;
           else if(chose>page)
               chose=page;
           ui->tableWidget->setRowCount(0);
           ui->tableWidget->clearContents();

           int num =alist.ans.size()-1-chose*3+3;
           for(int i=num;i>=num-2&&i>=0;i--)
           {
           BasicInfo* b=new Quas();
           int row =ui->tableWidget->rowCount();
           QString time,au,t;

           alist.ans[i][0]->Getauid(au);
           alist.ans[i][0]->Gettitle(t);
           alist.ans[i][0]->Gettime(time);
           ui->tableWidget->insertRow(row);
           ui->tableWidget->setItem(row,0,new QTableWidgetItem(t));
           ui->tableWidget->setItem(row,1,new QTableWidgetItem(au));
           ui->tableWidget->setItem(row,2,new QTableWidgetItem(time));
           ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(alist.ans[i][0]->id)));
           }
}

void choicepage::on_pushButton_3_clicked()
{
    this->page++;
    this->Displayques(this->page);
}

void choicepage::on_pushButton_2_clicked()
{
    this->page--;
    this->Displayques(this->page);
}

void choicepage::on_pushButton_clicked()
{
    userlist* ulist=new userlist();
    Anslist* alist=new Anslist();
    ulist->outofuserfile();
    alist->outoffile();
    QString title;
    QString content;

    title=ui->lineEdit->text();
    content=ui->textEdit->toPlainText();

    if(title==""||content=="")
        QMessageBox::information(NULL, "Notice",
                                 "please write all of the blank",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

   else{
    Quas* q=new Quas();
    q->Givecontent(content);
    q->Givetitle(title);
    q->Giveauid(this->auid);
    q->Writetime();
    /*QString times;
    q->Gettime(times);
    qDebug()<<"charu1:"<<times;*/
    int num=alist->ans.size();
    //alist.addquesnum();

    alist->Addans(*q,num);
    alist->intofile();
    this->page=1;
    this->Displayques(this->page);
    ui->lineEdit->clear();
    ui->textEdit->clear();
    }
}

void choicepage::on_tableWidget_doubleClicked(const QModelIndex &index)
{
       userlist ulist;
       Anslist alist;
       ulist.outofuserfile();
       alist.outoffile();

       int row=ui->tableWidget->currentRow();
       QString strqid=ui->tableWidget->item(row,3)->text();
       bool ok;
       qid=strqid.toInt(&ok,10)-20170000;
       //emit send_qid(qid);
       emit show_answer();
       this->hide();

}

void choicepage::on_pushButton_4_clicked()
{
    this->hide();
    ui->lineEdit->clear();
    ui->textEdit->clear();
    emit show_focus();

}

void choicepage::on_pushButton_5_clicked()
{
    this->close();
    ui->lineEdit->clear();
    ui->textEdit->clear();
    emit show_search();
}

void choicepage::on_pushButton_6_clicked()
{
    ui->lineEdit->clear();
    ui->tableWidget->clearContents();
    ui->textEdit->clear();
    this->close();
    emit show_log();
}
