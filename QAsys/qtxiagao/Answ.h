#ifndef ANSW_H
#define ANSW_H


#include "BasicInfo.h"

class Answ : public BasicInfo
{

public:
    Answ(){};
    virtual ~Answ(){};
    virtual void Getpraise(int &num){num=this->praise;}
    virtual void Givepraise(int num){this->praise=num;}
    virtual void Gettitle(QString &a){}
    virtual void Givetitle(QString&a){}
    void initpraise(){this->praise=0;}
    virtual void Addpraise(){this->praise++;};


private:
    int praise;


};

#endif // ANSW_H
