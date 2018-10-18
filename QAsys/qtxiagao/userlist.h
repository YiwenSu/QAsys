#ifndef USERLIST_H
#define USERLIST_H


#include "user.h"
#include <QFile>
#include<QTextStream>
#include <QFile>
#include <QObject>
#include <cstdlib>
#include <QDebug>
#include <iostream>
#include <stdexcept>
using namespace std;
class userlist
{

public:
    userlist(){};
    virtual ~userlist(){};
    void outofuserfile();
    void intouserfile();
    friend QTextStream& operator<<(QTextStream &out, userlist& ulist);
    friend QTextStream& operator>>(QTextStream &in, userlist& ulist);
    int getusernum(){return this->person.size();}
    void adduser(user &u){this->person.push_back(u);}
    int finduser(QString a,int pass);
    user* returnuser(int i){return &(this->person[i]);}
signals:

public slots:

private:
    vector<user> person;
    int usernum;
};

#endif // USERLIST_H
