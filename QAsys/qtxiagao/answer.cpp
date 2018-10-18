#include "answer.h"
#include "ui_answer.h"

Answer::Answer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Answer)
{
    ui->setupUi(this);

   this->resize(1000,1000);
    QStringList list;
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(6);
    list<<tr("Title:")<<tr("content")<<tr("author name:")<<tr("praise:")<<tr("time")<<tr("id");
    ui->tableWidget->setHorizontalHeaderLabels(list);
    //ui->tableWidget->setHorizontalHeaderLabels(list);
    QHeaderView* headerView = ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

}
void Answer::reshow()
{
     this->show();
     this->resize(1000,1000);
     QStringList list;
     ui->tableWidget->setRowCount(1);
     ui->tableWidget->setColumnCount(6);
     list<<tr("Title:")<<tr("content")<<tr("author name:")<<tr("praise:")<<tr("time")<<tr("id");
     ui->tableWidget->setHorizontalHeaderLabels(list);
     //ui->tableWidget->setHorizontalHeaderLabels(list);
     QHeaderView* headerView = ui->tableWidget->horizontalHeader();
     headerView->setSectionResizeMode(QHeaderView::Stretch);
}
Answer::~Answer()
{
    delete ui;
}

void Answer::Displayans(int &chose,int qid)
{
    userlist ulist;
    Anslist alist;
    ulist.outofuserfile();
    alist.outoffile();

    double j=((double)alist.ans[qid].size()-1)/3;
    int page=ceil(j);
    if(page==0)
        page=1;

    if(chose<=0||chose>page)
        QMessageBox::information(NULL, "page", "you have already reach the last or the starting page", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(chose<=0)
        chose=1;
    else if(chose>page)
        chose=page;
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearContents();

    int num =alist.ans[qid].size()-1-chose*3+3;

    int row =ui->tableWidget->rowCount();
    BasicInfo* b=new Quas();
    QString time,au,co,t;
    alist.ans[qid][0]->Gettitle(t);
    alist.ans[qid][0]->Getauid(au);
    alist.ans[qid][0]->Gettime(time);
    alist.ans[qid][0]->GetContent(co);

    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(t));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(co));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(au));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(" "));
    ui->tableWidget->setItem(row,4,new QTableWidgetItem(time));
    ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(alist.ans[qid][0]->id)));

    for(int i=num;i>=num-2&&i>=1;i--)
    {
    BasicInfo* b=new Answ();
    row =ui->tableWidget->rowCount();
    QString time,au,co;
    int praise;
    alist.ans[qid][i]->Getauid(au);
    alist.ans[qid][i]->Gettime(time);
    alist.ans[qid][i]->GetContent(co);
    alist.ans[qid][i]->Getpraise(praise);
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(""));
    ui->tableWidget->setItem(row,1,new QTableWidgetItem(co));
    ui->tableWidget->setItem(row,2,new QTableWidgetItem(au));
    ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString::number(praise)));
    ui->tableWidget->setItem(row,4,new QTableWidgetItem(time));
    ui->tableWidget->setItem(row,5,new QTableWidgetItem(QString::number(alist.ans[qid][i]->id)));
    }
    QHeaderView* headerView = ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);
}

void Answer::on_pushButton_4_clicked()
{
    this->chose=1;

    this->Displayans(this->chose,qid-1);
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QHeaderView* headerView = ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);
}

void Answer::on_pushButton_clicked()
{
    this->chose++;
    this->Displayans(this->chose,qid-1);
}

void Answer::on_pushButton_2_clicked()
{
    this->chose--;
    this->Displayans(this->chose,qid-1);
}

void Answer::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    userlist ulist;
    Anslist alist;
    ulist.outofuserfile();
    alist.outoffile();
    int col = ui->tableWidget->currentItem()->column();
    if (col==1)
    {
    QString str = ui->tableWidget->currentItem()->text();
    QMessageBox::information(NULL,tr("content"),str);
    //QMessageBox::about(NULL, "About", str);
    }
    if(col==2)
     {
        QString str1 = ui->tableWidget->currentItem()->text();
        int x=ulist.finduser(auid,pass);
        user* u=new user();
        u=ulist.returnuser(x);
        if(alist.Givefocus(*u,qid-1,str1)==1)
        {QMessageBox::information(NULL,tr("FOCUS"),tr("successful"));
        u->Displayfocus();
        alist.intofile();
        ulist.intouserfile();}
     }
    if(col==3)
    {
        int row = ui->tableWidget->currentItem()->row();
        bool ok;
        int anid=ui->tableWidget->item(row,5)->text().toInt(&ok,10);
        alist.Giveapplause(qid-1,anid);

         QMessageBox::information(NULL,tr("PRAISE"),tr("successful"));
         alist.intofile();
         ulist.intouserfile();
         this->Displayans(this->chose,qid-1);

    }
}


void Answer::on_pushButton_3_clicked()
{
    userlist ulist;
    Anslist alist;
    ulist.outofuserfile();
    alist.outoffile();

    QString content=ui->textEdit->toPlainText();

    Answ*a=new Answ();
    a->Givecontent(content);
    //a->Givetitle(title);
    a->Giveauid(auid);
    a->Writetime();
    QString times;
    a->Gettime(times);

    qDebug()<<"charu:"<<times;
    a->Givepraise(0);

    alist.Addans(*a,qid-1);
    alist.intofile();

    this->chose=1;
    ui->textEdit->clear();
    this->Displayans(this->chose,qid-1);

}

void Answer::on_pushButton_5_clicked()
{
    this->close();
    emit show_choice();

    ui->tableWidget->clear();
    ui->textEdit->clear();
}
