#include "user.h"

user::user()
{
    //ctor
    vector<string*>focus(3);
}

user::~user()
{
    //dtor
}

void user::ADDfocus(string n)
{
    this->focus.push_back(n);
}
void user::Displayfocus()
{
    for(int i=0;i<this->focus.size();i++)
        cout<<this->focus[i]<<"    ";
}

int user::Login(string a,int pass)
{
    if(a==this->name&&pass==this->password)
        return 1;
    else
        return 0;
}

void user::signup(string names, int pass, int id)
{
    this->Givename(names);
    this->Givepass(pass);
    this->Giveuserid(id);
    //cout<<this->userid<<endl;
}

void user::Displayinfo()
{
    cout<<"ÓÃ»§Ãû:"<<this->name<<"  "<<"ÃÜÂë£º"<<this->password<<endl;
}
