#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->resize(500,400);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_2_clicked()
{
    emit show_sign();
    this->hide();
}

void login::on_pushButton_clicked()
{
    QString name=ui->lineEdit->text();
    bool ok;
    int password=ui->lineEdit_2->text().toInt(&ok,10);

    if(password==0||name=="")
       { QMessageBox::information(NULL, "Notice",
                                 "please write all of the blank",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        ui->lineEdit->clear();
        ui->lineEdit_2->clear();
       }
    else{
    userlist ulist;
    ulist.outofuserfile();
    if(ulist.finduser(name,password)>=0)
    {
        emit show_choice();
        emit send_auid(ui->lineEdit->text());
        auid=name;
        pass=password;
        this->hide();
    }
    else
    {
        QMessageBox::information(NULL, "Notice",
                                 "wrong input!",
                                 QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    }
}

void login::on_lineEdit_2_editingFinished()
{

}
void login::on_lineEdit_2_textChanged(const QString &arg1)
{
    QLineEdit *lineEdit = new QLineEdit();
    QRegExp regExp("[-]{0,1}[0-9]+");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));

}
