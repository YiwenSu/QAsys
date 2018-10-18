#include "Answ.h"

Answ::Answ()
{
    //ctor
}

Answ::~Answ()
{
    //dtor
}
void Answ::Display()
{
    string a,au,t;
    this->GetContent(a);
    this->Getauid(au);
    this->Gettime(t);

    cout<<"Answer: "<<endl<<a<<endl<<"answer id:"<<this->id<<"   praise number: "<<this->praise<<" "<<"auid: "<<au
    <<" "<<"time: "<<t<<endl<<endl;
    //cout<<"as";


}

void Answ::Create(string s)
{
    this->Writeauid(s);
    this->Writecontent();
    this->Writetime();
    //this->Writeqid();
    this->Initpraise();
}

void Answ::Initpraise()
{
    this->praise=0;
}

void Answ::Addpraise()
{
    this->praise++;
}

/*ostream& operator<<(ostream& cout,Answ& a)
{
    string co,au,t;
    a.GetContent(co);
    a.Getauid(au);
    a.Gettime(t);
    cout<<"Answer: "<<endl<<co<<endl<<"answer id:"<<a.id<<"   praise number: "<<a.praise<<" "<<"auid: "<<au
    <<" "<<"time: "<<t<<endl<<endl;
    return cout;
}

istream& operator>>(istream& cin,Answ& a)
{
    string co;
    cin.clear();
    cin.sync();
    getline(cin,co);
    a.Givecontent(co);
    return cin;

}*/
