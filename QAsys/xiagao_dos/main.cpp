#include <iostream>
#include "Anslist.h"
#include "Answ.h"
#include "BasicInfo.h"
#include "Grid.h"
#include "Quas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "userlist.h"
using namespace std;
void test()
{

    Anslist alist;
    //alist.initquesnum();
    //alist.outoffile();
    userlist ulist;
    Grid g;
    ulist.outofuserfile();


    while(1){
    cout<<"Do you need to sign up? yes: 1  no: 2"<<endl;
    int i;
    cin>>i;
    if(i==1)
    {
        user* u= new user();
        ulist.Addperson(*u);
    }
    ulist.intouserfile();
    system("cls");

    cout<<"Your username:";
    string s;
    cin>>s;
    cout<<"Code:";
    int pass;
    cin>>pass;

    if(ulist.finduser(s,pass)>=0)
    {

       while(1)
       {
         system("cls");
         cout<<"what do you want to do ?1. ask  2.looking the question and answer 3.return 4.focuslist"
         <<endl<<"5.search by title 6:search by time"<<endl;
         alist.outoffile();
         int n;
         cin>>n;
         cout<<endl<<endl;
         switch(n)
         {
           case 1:
           {
            Quas* q=new Quas();
            q->Create(s);
            int num=alist.Getquesnum();
            //cout<<num<<endl;
            alist.addquesnum();
            alist.Addans(*q,num);
            alist.Displayques();
            alist.intofile();
            system("pause");
            break;
           }
          case 2:
            {
              while(1)
              {
                  system("cls");
                  alist.Displayques();
                  int change;
                  cout<<"do you want to go to another page? yes:1 no :2"<<endl;
                  cin>>change;
                  if(change!=1)
                     break;
              }
              g.Givethechoice(alist,ulist,s,pass);
               /*cout<<endl<<endl<<endl;

               cout<<"which question do you want to see?"<<endl;

               int qid;
               cin>>qid;
               cout<<endl;
               alist.Displayans(qid-1);


               while(1)
               {
                   cout<<endl<<"1.answer  2.applause  3. focus  4.exit"<<endl;
                   int i;
                   cin>>i;

                     if(i==1)
                  {
                      cout<<"your answer:"<<endl;
                      Answ*a=new Answ();
                      a->Create(s);
                      cout<<endl<<endl<<endl;
                      alist.Addans(*a,qid-1);
                      alist.Displayans(qid-1);
                      system("pause");
                   }

                   if(i==2)
                   {
                       cout<<"please insert the question id you want to applause:"<<endl;
                       int anid;
                       cin>>anid;
                       cout<<endl;
                       alist.Giveapplause(qid-1,anid);
                       alist.Displayans(qid-1);
                       system("pause");
                   }

                   if(i==3)
                      {
                          cout<<"please insert the person id you want to focus:"<<endl;
                          getchar();
                          string str;
                          getline(cin,str);
                          cout<<"I want to focus: "<<str;
                          //cout<<"11111111111"<<endl;
                          int x=ulist.finduser(s,pass);
                           user* u=new user();
                          //cout<<"222222222"<<endl;
                           u=ulist.returnuser(x);
                           alist.Givefocus(*u,qid-1,str);
                          //cout<<"333333333333"<<endl;
                           cout<<endl<<"My focus now:"<<endl;
                          u->Displayfocus();
                      }
                    if(i==4)
                    {
                        alist.intofile();
                        ulist.intouserfile();
                        break;
                    }

                 }*/
            }
          case 3:
             {
                alist.intofile();
                ulist.intouserfile();
                break;
             }

          case 4:
              {
              int x=ulist.finduser(s,pass);
              user* u=new user();
              u=ulist.returnuser(x);
              u->Displayfocus();
              cout<<"Whose question and answer would you like to look up?"<<endl;
              cin.clear();
              cin.sync();
              string name;
              getline(cin,name);
              system("cls");
              vector<int>qid;
              alist.SearchQuestion(name,1,qid);
              g.Givethechoice(alist,ulist,s,pass);
              system("pause");
              break;
              }
          case 5:
            {
                cout<<"the key word you want to search: "<<endl;
                cin.clear();
                cin.sync();
                string title;
                getline(cin,title);
                vector<int > qid;
                //alist.SearchQuestion(title);
                alist.SearchQuestion(title,qid);
                g.Givethechoice(alist,ulist,s,pass);

                system("pause");
                break;
            }
          case 6:
            {
                cout<<"year: "<<endl;
                cin.clear();
                cin.sync();
                string year;
                getline(cin,year);

                cout<<"Month(abbreviation e.p.Sep,Nov,June): "<<endl;
                cin.clear();
                cin.sync();
                string month;
                getline(cin,month);

                cout<<"day: "<<endl;
                cin.clear();
                cin.sync();
                string day;
                getline(cin,day);

                vector<int > qid;
                alist.SearchQuestion(year,month,day,qid);
                g.Givethechoice(alist,ulist,s,pass);
                system("pause");
                break;
            }
        default:
            break;
         }
         if(n==3)
         {
              system("cls");
              break;
         }

       }

     }
    }
}

void test1()
{
    userlist ulist;
    int i=0;
    while(i<=3)
    {
        user* u= new user();
        ulist.Addperson(*u);
        i++;
    }
    ulist.Displayusers();

    cout<<"你的用户名：";
    string a;
    cin>>a;
    cout<<"密码:";
    int pass;
    cin>>pass;

    if(ulist.finduser(a,pass)==1)
        cout<<"hahahah";
}
int main()
{
    test();
    //test1();
    system("pause");
    return 0;
}
