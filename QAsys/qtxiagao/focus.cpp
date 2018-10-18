#include "focus.h"
#include "ui_focus.h"

focus::focus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::focus)
{
    ui->setupUi(this);
    this->resize(1000,500);

    userlist ulist;
    Anslist alist;
    ulist.outofuserfile();
    alist.outoffile();

    QStringList list;
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->tableWidget->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    list<<tr("fucus name:");
    ui->tableWidget->setHorizontalHeaderLabels(list);
    QStringList listq;

    ui->tableWidget_2->setRowCount(1);
    ui->tableWidget_2->setColumnCount(5);
    ui->tableWidget_2->setSelectionBehavior ( QAbstractItemView::SelectRows); //设置选择行为，以行为单位
    ui->tableWidget_2->setSelectionMode ( QAbstractItemView::SingleSelection); //设置选择模式，选择单行
    listq<<tr("type:")<<tr("question number:")<<tr("title")<<tr("content")<<tr("time");
    ui->tableWidget_2->setHorizontalHeaderLabels(listq);

    QHeaderView* headerView = ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    QHeaderView* headerView2 = ui->tableWidget_2->horizontalHeader();
    headerView2->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget->setRowCount(0);
    ui->tableWidget->clearContents();
    ui->tableWidget_2->setRowCount(0);
    ui->tableWidget_2->clearContents();
}

focus::~focus()
{
    delete ui;
}
void focus::Displayfocus(int &chose)
{
    userlist ulist;
    Anslist alist;
    ulist.outofuserfile();
    alist.outoffile();


    vector<QString>fnames;
    int x=ulist.finduser(auid,pass);
    user* u=new user();
    u=ulist.returnuser(x);
    u->Getfocus(fnames);


    double j=(double)fnames.size()/3;
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

    int num =fnames.size()-1-chose*3+3;
    for(int i=num;i>=num-2&&i>=0;i--)
    {

    int row =ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(fnames[i]));

    }
}

void focus::on_pushButton_2_clicked()
{
    this->chose0=1;
    this->Displayfocus(this->chose0);
}

void focus::on_tableWidget_doubleClicked(const QModelIndex &index)
{
    userlist ulist;
    Anslist alist;
    ulist.outofuserfile();
    alist.outoffile();
    this->Qid.clear();
    this->flag.clear();

    QString author=ui->tableWidget->currentItem()->text();
    alist.SearchQuestion(author,1,this->Qid,this->flag);
    this->chose1=1;
    Displayqanda(this->chose1, this->Qid, this->flag);

}

void focus::Displayqanda(int &chose, vector<int>qid,vector<int>flag)
{

    userlist ulist;
    Anslist alist;
    ulist.outofuserfile();
    alist.outoffile();
    double j=(double)qid.size()/3;
    int page=ceil(j);
    if(page==0)
        page=1;
    if(chose<=0||chose>page)
            QMessageBox::information(NULL, "page", "you have already reach the last or the starting page", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(chose<=0)
        chose=1;
    else if(chose>page)
        chose=page;
        ui->tableWidget_2->setRowCount(0);
        ui->tableWidget_2->clearContents();


        int num =qid.size()-1-chose*3+3;

        for(int i=num;i>=num-2&&i>=0;i--)
        {

           //cout<<"Question number:"<<qid[i]+1<<endl;
             if(flag[i]==0)
             {
                BasicInfo* b=new Quas();//Ques是BasicInfo的派生
                b=alist.ans[qid[i]][0];

                int row =ui->tableWidget_2->rowCount();
                QString time,au,t,co;

                b->Getauid(au);
                b->Gettitle(t);
                b->Gettime(time);
                b->GetContent(co);
                ui->tableWidget_2->insertRow(row);
                ui->tableWidget_2->setItem(row,0,new QTableWidgetItem("Question"));
                ui->tableWidget_2->setItem(row,1,new QTableWidgetItem(QString::number(qid[i]+1)));
                ui->tableWidget_2->setItem(row,2,new QTableWidgetItem(t));
                ui->tableWidget_2->setItem(row,3,new QTableWidgetItem(co));
                ui->tableWidget_2->setItem(row,4,new QTableWidgetItem(time));
             }
             else if(flag[i]!=0)
             {

                    BasicInfo* b=new Answ();
                    b=alist.ans[qid[i]][flag[i]];
                    int row =ui->tableWidget_2->rowCount();
                    QString time,au,co;

                    QString title;
                    BasicInfo* q=new Quas();
                    q=alist.ans[qid[i]][0];
                    q->Gettitle(title);

                    b->Getauid(au);
                    //b->Gettitle(t);
                    b->Gettime(time);
                    b->GetContent(co);

                    ui->tableWidget_2->insertRow(row);
                    ui->tableWidget_2->setItem(row,0,new QTableWidgetItem("ANSWER"));
                    ui->tableWidget_2->setItem(row,1,new QTableWidgetItem(QString::number(qid[i]+1)));
                    ui->tableWidget_2->setItem(row,2,new QTableWidgetItem(title));
                    ui->tableWidget_2->setItem(row,3,new QTableWidgetItem(co));
                    ui->tableWidget_2->setItem(row,4,new QTableWidgetItem(time));
             }

        }
}

void focus::on_tableWidget_2_doubleClicked(const QModelIndex &index)
{
    int row=ui->tableWidget_2->currentRow();
    bool ok;
    qid=ui->tableWidget_2->item(row,1)->text().toInt(&ok,10);
    int num=qid;
    this->close();
    emit show_answer();

}

void focus::on_pushButton_4_clicked()
{
    emit show_question();
    this->hide();
    ui->tableWidget->clearContents();
    ui->tableWidget_2->clearContents();

}

void focus::on_pushButton_6_clicked()
{

    this->chose1++;
    this->Displayqanda(this->chose1, this->Qid, this->flag);

}

void focus::on_pushButton_5_clicked()
{

    this->chose1--;
    this->Displayqanda(this->chose1, this->Qid, this->flag);
}

void focus::on_pushButton_clicked()
{
    this->chose0++;
    this->Displayfocus(this->chose0);
}

void focus::on_pushButton_3_clicked()
{
    this->chose0--;
    this->Displayfocus(this->chose0);
}
