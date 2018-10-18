#ifndef USER_H
#define USER_H


#include <QString>
#include <vector>
#include <iostream>
#include <QDebug>
#include <QMessageBox>
#include <QObject>
using namespace std;

class user
{

public:
    user(){};
    virtual ~user(){};
    void Givename(QString& names){this->name=names;}
    void Givepass(int &num){this->password=num;}
    void Givefocus(vector<QString>&fnames){this->focus.assign(fnames.begin(),fnames.end());}
    void Giveuserid(int &num){this->userid=num;}

    void Getuserid(int &num){num=this->userid;}
    void Getpass(int &num){num=this->password;};
    void Getname(QString &names){names=this->name;};
    void Getfocus(vector<QString> &fnames){fnames.assign(this->focus.begin(), this->focus.end());}

    int Login(QString a,int pass);

    bool ADDfocus(QString n);

    void Displayfocus();

private:
    int userid;
    QString name;
    int password;
    vector<QString>focus;
};

#endif // USER_H
