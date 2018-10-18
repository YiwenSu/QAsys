#ifndef BASICINFO_H
#include <math.h>
#define BASICINFO_H
//#include <time.h>
#include <ctime>
#include <string>
#include <iostream>
#include<windows.h>
#include <stdio.h>
#include <user.h>
using namespace std;
class BasicInfo
{
    public:
        BasicInfo();
        virtual ~BasicInfo();
        virtual void Display()=0;
        virtual void Create(string s)=0;
        virtual void Addpraise()=0;
        void Writetime();

        void Writeqid();
        void Writeauid(string s);
        void Writecontent();

        void GetContent(string& a);
        void Getid(int& num);
        void Getauid(string& author);
        void Gettime(string& a);
        virtual void Gettitle(string &a)=0;
        virtual void Getpraise(int &num)=0;

        void Givecontent(string &a){this->content=a;}
        void Giveid(int num){this->id=num;}
        void Giveauid(string& author){this->auid=author;}
        void Givetime(string&t){this->Time=t;}
        virtual void Givetitle(string&a)=0;
        virtual void Givepraise(int &num)=0;
        int id;
    protected:

    private:
         string auid;
         string Time;
         string content;
};

#endif // BASICINFO_H
