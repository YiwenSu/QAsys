#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
class user
{
    public:
        user();
        virtual ~user();
        int Login(string a,int pass);//Log in
        void signup(string names, int pass,int id);//Sign up

        void Getuserid(int &num){num=this->userid;}
        void Getpass(int &num){num=this->password;};
        void Getname(string &names){names=this->name;};
        void Getfocus(vector<string> &fnames){fnames.assign(this->focus.begin(), this->focus.end());}

        void ADDfocus(string n);
        void Displayfocus();

        void Displayinfo();
        void Givename(string& names){this->name=names;}
        void Givepass(int &num){this->password=num;}
        void Givefocus(vector<string>&fnames){this->focus.assign(fnames.begin(),fnames.end());}
        void Giveuserid(int &num){this->userid=num;}
    protected:

    private:
        int userid;
        string name;
        int password;
        vector<string>focus;
};

#endif // USER_H
