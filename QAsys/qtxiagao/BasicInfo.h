#ifndef BASICINFO_H
#define BASICINFO_H
#include <QString>
#include <iostream>
#include <ctime>
#include <cmath>
#include <QDebug>
using namespace std;

class BasicInfo
{

public:
            BasicInfo(){};
            virtual ~BasicInfo(){};
            void GetContent(QString& a){a=this->content;}
            void Getid(int& num){num=this->id;}
            void Getauid(QString& author){author=this->auid;}
            void Gettime(QString& a){a=this->Time;qDebug()<<"lalalla"<<this->Time;}
            virtual void Gettitle(QString &a)=0;
            virtual void Getpraise(int &num)=0;
            int id;
            void Givecontent(QString &a){this->content=a;}
            void Giveid(int num){this->id=num;}
            void Giveauid(QString& author){this->auid=author;}
            void Givetime(QString&t){this->Time=t;}
            void Writetime();
            virtual void Givetitle(QString&a)=0;
            virtual void Givepraise(int num)=0;
            virtual void Addpraise()=0;


private:
            QString auid;
            QString Time;
            QString content;
};

#endif // BASICINFO_H
