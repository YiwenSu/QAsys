#ifndef ANSLIST_H
#define ANSLIST_H
#include <QFile>
#include<QTextStream>
#include <QFile>
#include <QString>
#include <QObject>
#include <Answ.h>
#include <Quas.h>
#include <BasicInfo.h>
#include <vector>
#include "user.h"
#include <cstdlib>
#include <QDebug>
#include <iostream>
#include <stdexcept>
using namespace std;
class Anslist
{

public:
    Anslist(){};
    virtual ~Anslist(){};
    friend QTextStream& operator>>(QTextStream &in, Anslist& an);
    friend QTextStream& operator<<(QTextStream &out, Anslist& an);
    void outoffile();
    void intofile();
    void Addans(Quas& q,int qid);
    void Addans(Answ& an,int qid);
    int Getquesnum(){return this->Quesnum;}
    int initquesnum(){this->Quesnum=this->ans.size();}
    int addquesnum(){this->Quesnum++;}
    int Givefocus(user&u,int qid, QString& str);
    void Giveapplause(int qid,int anid);
    vector<vector<BasicInfo*> >ans;

    void SearchQuestion(QString author, int i, vector<int>&qid, vector<int> &flag);
    void SearchQuestion(QString s, vector<int>&qid);
    void SearchQuestion(QString year,QString month,QString day,vector<int>&qid);
private:
    int Quesnum;

};

#endif // ANSLIST_H
