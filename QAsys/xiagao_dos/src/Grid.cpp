#include "Grid.h"

Grid::Grid()
{
    //ctor
}

Grid::~Grid()
{
    //dtor
}
void Grid::Givethechoice(Anslist& alist,userlist& ulist,string s,int pass)
{
               cout<<endl<<endl<<endl;

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

                 }
}
