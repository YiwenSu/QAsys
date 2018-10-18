#include "user.h"


int user::Login(QString a,int pass)
{
    if(a==this->name&&pass==this->password)
        return 1;
    else
        return 0;
}

bool user::ADDfocus(QString n)
{
    QString a;
    for(int i=0;i<this->focus.size();i++)
   {
        this->Getname(a);
        if(a==n)
              {QMessageBox::information(NULL,"FOCUS","you have focused him");
              return false;
              //break;
              }
    }
    this->focus.push_back(n);
    return true;
}
void user::Displayfocus()
{
    for(int i=0;i<this->focus.size();i++)
        qDebug()<<this->focus[i]<<"    ";
}
