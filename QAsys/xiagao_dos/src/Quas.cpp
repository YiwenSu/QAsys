#include "Quas.h"

Quas::Quas()
{
    //ctor
}

Quas::~Quas()
{
    //dtor
}

void Quas::Display()
{
    string a,au,t;
    int i;
    this->GetContent(a);
    this->Getauid(au);
    this->Gettime(t);
    this->Getid(i);
   cout<<"TITLE: "<<this->title<<endl<<"CONTENT:"<<endl<<a<<endl<<"id:"<<this->id <<"  "<<"auid: "<<au
       <<" "<<"time: "<<t<<endl<<endl<<endl;
}

void Quas::Create(string s)
{
    this->Writeauid(s);
    this->Writetitle();
    this->Writecontent();
    //this->Writeqid();
    this->Writetime();

}

void Quas::Writetitle()
{
    cout<<"TITLE: ";
    getchar();
    getline(cin,this->title);

}












