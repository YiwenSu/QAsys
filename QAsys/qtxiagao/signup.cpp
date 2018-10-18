#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    this->resize(500,400);

}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    user  u;
    userlist ulist;
    ulist.outofuserfile();
    QString names=ui->lineEdit->text();


    bool ok;
    int pass=ui->lineEdit_2->text().toInt(&ok,10);
    int id=ulist.getusernum()+1;
    if(pass==0||names=="")
        QMessageBox::information(NULL, "Notice",
                                 "please fill all the blank! password can just be number",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    else{
    u.Givename(names);
    u.Givepass(pass);
    u.Giveuserid(id);

    ulist.adduser(u);
    ulist.intouserfile();

    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    emit show_log();
    this->hide();
    }
}

void signup::on_pushButton_2_clicked()
{
    emit show_log();
    this->hide();
}

void signup::on_lineEdit_2_editingFinished()
{
    QLineEdit *lineEdit = new QLineEdit();
    QRegExp regExp("[-]{0,1}[0-9]+");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

}
