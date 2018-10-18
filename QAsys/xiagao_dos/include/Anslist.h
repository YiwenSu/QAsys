#ifndef ANSLIST_H
#define ANSLIST_H
#include "Answ.h"
#include "Quas.h"
#include "vector"
#include "BasicInfo.h"
#include "user.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Anslist
{
    public:
        Anslist();
        virtual ~Anslist();
        void Addans(Answ& an,int qid);
        void Addans(Quas& q,int qid);
        void Displayans(int qid);
        void Displayques();
        int Getquesnum(){return this->Quesnum;}
        int initquesnum(){this->Quesnum=this->ans.size();}
        int addquesnum(){this->Quesnum++;}
        void Giveapplause(int qid,int anid);
        void Givefocus(user&u,int qid, string& str);

        void intofile();
        void outoffile();

        friend istream& operator>>(istream& in,Anslist& an);
        friend ofstream& operator<<(ofstream& out, Anslist &an);

        void SearchQuestion(string s);
        void SearchQuestion(string year,string month,string day,vector<int>&qid);
        void SearchQuestion(string author,int i,vector<int>&qid);
        void SearchQuestion(string s,vector<int>&qid);
    protected:

    private:
        vector<vector<BasicInfo*> >ans;
        //vector<Quas>qus;
        int Quesnum;

};

#endif // ANSLIST_H
