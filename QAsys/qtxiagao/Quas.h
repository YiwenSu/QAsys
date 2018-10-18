#ifndef QUAS_H
#define QUAS_H


#include "BasicInfo.h"
#include <QDebug>
class Quas : public BasicInfo
{
public:
    Quas(){};
    virtual ~Quas(){};
    virtual void Gettitle(QString& a){a=this->title;}
    virtual void Givetitle(QString& a){this->title=a;}
    virtual void Getpraise(int &num){}
    virtual void Givepraise(int num){}
    virtual void Addpraise(){};

private:
    QString title;
};

#endif // QUAS_H
