#include "BasicInfo.h"

BasicInfo::BasicInfo()
{
    //ctor
}

BasicInfo::~BasicInfo()
{
    //dtor
}
void  BasicInfo::Create(string s)
{

}
void BasicInfo::Display()
{
   cout<<"basic";
}
void BasicInfo::GetContent(string& a)
{
    a = this->content;
}

void BasicInfo::Getauid(string& author)
{
    author = this->auid;
}

void BasicInfo::Getid(int& num)
{
    id = this->id;
}

void BasicInfo::Gettime(string& a)
{
    a = this->Time;

}
void BasicInfo::Writetime()
{
    time_t timer=time(NULL);
    struct tm *tblock;

    tblock = localtime(&timer);
    this->Time= asctime (tblock);

}

void BasicInfo::Writeauid(string s)
{
    this->auid=s;
}

void BasicInfo::Writecontent()
{
    cout<<"Content: "<<endl;
    cin.clear();
    cin.sync();
    getline(cin,this->content);

}





