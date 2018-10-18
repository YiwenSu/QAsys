#ifndef QUAS_H
#define QUAS_H

#include "BasicInfo.h"


class Quas : public BasicInfo
{
    public:
        Quas();
        virtual ~Quas();
        virtual void Display();
        virtual void Create(string s);
        virtual void Addpraise(){};
        void Writetitle();

        void Gettitle(string& a){a=this->title;}
        void Givetitle(string& a){this->title=a;}
        virtual void Getpraise(int &num){}
        virtual void Givepraise(int &num){}
    protected:


    private:
         string title;
};

#endif // QUAS_H
