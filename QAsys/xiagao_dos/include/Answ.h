#ifndef ANSW_H
#define ANSW_H

#include "BasicInfo.h"

using namespace std;
class Answ : public BasicInfo
{
    public:
        Answ();
        virtual ~Answ();
        virtual void Display();
        virtual void Create(string s);
        virtual void Getpraise(int &num){num=this->praise;}
        virtual void Givepraise(int &num){this->praise=num;}
        void Initpraise();
        virtual void Addpraise();
        void Gettitle(string &a){}
        virtual void Givetitle(string&a){}

    protected:

    private:
        int praise;
};

#endif // ANSW_H
