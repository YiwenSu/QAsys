#ifndef USERLIST_H
#define USERLIST_H
#include "user.h"
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

class userlist
{
    public:
        userlist();
        virtual ~userlist();
        void Addperson(user &u);
        void Displayusers();
        int finduser(string a,int pass);
        user* returnuser(int i){return &(this->person[i]);}
        void initusernum(){this->usernum=this->person.size();}
        void intouserfile();
        void outofuserfile();

        friend istream& operator>>(istream &in, userlist& ulist);
        friend ofstream& operator<<(ofstream &out, userlist& ulist);
    protected:

    private:
        vector<user> person;
        int usernum;
};

#endif // USERLIST_H
