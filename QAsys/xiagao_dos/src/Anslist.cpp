#include "Anslist.h"

Anslist::Anslist()
{
   vector<vector<BasicInfo*> >ans( 4, vector<BasicInfo*>( 13 ) );

}

Anslist::~Anslist()
{
    //dtor
}


void Anslist::Displayques()
{
  double j=(double)ans.size()/3;
  int page=ceil(j);

  int chose;
  cout<<page<<" pages in total, which do you want to see?"<<endl;
  cin>>chose;
  system("cls");
  int num =this->ans.size()-1-chose*3+3;
  //cout<<"zuida:"<<num<<endl;
  int i=num;
  cout<<"<<"<<chose<< " pages"<<">>"<<endl;
  while(i>=num-2)
  {

       if(i>=0)
       {
       cout<<"Question number:"<<i+1<<endl;
       BasicInfo* b=new Quas();//Ques是BasicInfo的派生
       b=this->ans[i][0];
       b->Display();//虚函数
       }
       else
         break;
       i--;
  }
  /*
  for(int i=this->ans.size()-1; i>=0; i--)
    {
        //cout<<i+1<<endl;
        BasicInfo* b=new Quas();//Ques是BasicInfo的派生
        b=this->ans[i][0];
        b->Display();//虚函数

    }
    */
}

void Anslist::Displayans(int qid)
{


     double j=((double)ans[qid].size()-1)/3;
     int page=ceil(j);

     if(page==0)
          page=1;
     int chose;
     int change=1;
     while(change==1)
     {

     cout<<page<<" answer pages in total, which do you want to see?"<<endl;
     cin>>chose;

    int num =this->ans[qid].size()-1-chose*3+3;

    system("cls");
    int i=num;
    cout<<"<<"<<chose<<" answer pages"<<" >>"<<endl;
    BasicInfo* x=new Answ();
    x=this->ans[qid][0];
    x->Display();
    while(i>=num-2)
  {

       if(i>0){
      BasicInfo* b=new Answ();
        b=this->ans[qid][i];
        b->Display();
       }
       else
         break;
       i--;
  }
   cout<<"would you like to go to another page? yes:1, no:2"<<endl;
   cin>>change;
     }
    /*
    for(int i=this->ans[qid].size()-1; i>0; i--)
    {
        BasicInfo* b=new Answ();
        b=this->ans[qid][i];
        b->Display();

    }
    cout<<"hahahah";*/
}
void Anslist::Giveapplause(int qid,int anid)
{
    for(int i=this->ans[qid].size()-1; i>0; i--)
    {
        if(anid==this->ans[qid][i]->id)
            {
             BasicInfo* b=new Answ();
             b=this->ans[qid][i];
             b->Addpraise();
            break;
            }
    }
     cout<<"applause complete!"<<endl;

}
 void Anslist::Givefocus(user&u,int qid, string&str)
 {

     for(int i=this->ans[qid].size()-1; i>=0; i--)
    {
         BasicInfo* b=new Answ();
         b=this->ans[qid][i];
         string author;
         b->Getauid(author);

         if(author==str)
            {u.ADDfocus(str);
            break;
            }

    }
 }
void Anslist::intofile()
{
     ofstream  out("info.txt");

    if(out.is_open())
        out<<(*this);

    out.close();

}

void Anslist::Addans(Quas& q,int qid)
{
    vector<BasicInfo*> b;
    b.push_back(&q);
    this->ans.push_back(b);
    int i=ans.size();
    q.id=2017*10000+i;
}
void Anslist::Addans(Answ& an,int qid)//0
{
    this->ans[qid].push_back(&an);
    int i=ans[qid].size();
    an.id=1001*10000+qid*1000+i;

}

void Anslist:: outoffile()
{
     ifstream in("info.txt");
     this->ans.clear();
     if (! in.is_open())
       { cout << "Error opening file info!"; exit (1); }
     in>>(*this);
    in.close();
}

istream& operator>>(istream& in,Anslist& an)
{
     string buffer;
     string signal="*";
     string signal1="**";
     int qid=0;
     while (in.peek()!=EOF )
       {
           getline(in,buffer);
           //string buffer1=buffer;
           if(buffer==signal)
           {
               BasicInfo* question=new Quas();
               char q_id[100];
               in.getline(q_id,100);
               question->id=atoi(q_id);

               string title;
               getline(in,title);
               question->Givetitle(title);

               string cont;
               getline(in,cont);
               question->Givecontent(cont);

               string auname;
                getline(in,auname);
               question->Giveauid(auname);

               string time;
               getline(in,time);
               question->Givetime(time);

               vector<BasicInfo*> b;
               b.push_back(question);
               an.ans.push_back(b);
               qid++;



           }

           else if(buffer==signal1)
           {
               Answ*a=new Answ();

               char a_id[256];
               //cout<<"haha"<<endl;
               in.getline(a_id,100);
               //cout<<"gege"<<endl;
               a->id=atoi(a_id);
              // cout<<"xixi"<<endl;

               string cont;
               getline(in,cont);
               a->Givecontent(cont);

               string auname;
                getline(in,auname);
               a->Giveauid(auname);

               string time;
               getline(in,time);
               a->Givetime(time);


               char praise[256];
               in.getline(praise,10);
               int p=atoi(praise);
               a->Givepraise(p);

               an.ans[qid-1].push_back(a);


           }
       }
    return in;
}

ofstream& operator<<(ofstream& out, Anslist &an)
{
     string au,co,title,times;
     int praise;
     int i,j;
     for(i=0;i<an.ans.size();i++)
            for(j=0;j<an.ans[i].size();j++)
               {
                   if(j==0)
                      {
                       an.ans[i][j]->Getauid(au);
                       an.ans[i][j]->GetContent(co);
                       an.ans[i][j]->Gettitle(title);
                       an.ans[i][j]->Gettime(times);

                       out<<"*"<<endl<<an.ans[i][j]->id<<endl<<title<<endl<<co<<endl<<au<<endl<<times<<endl<<endl;
                      }

                   else
                   {

                       an.ans[i][j]->Getauid(au);
                       an.ans[i][j]->GetContent(co);
                       an.ans[i][j]->Gettime(times);
                       an.ans[i][j]->Getpraise(praise);
                       out<<"**"<<endl<<an.ans[i][j]->id<<endl<<co<<endl<<au<<endl<<times<<endl<<praise<<endl<<endl;
                   }


               }
    return out;
}
void Anslist::SearchQuestion(string s,vector<int>&qid)
{
    string a;

    //vector<vector<BasicInfo*> >temp;

    for(int i=0;i<this->ans.size();i++)
    {
        BasicInfo*b=new Quas();
        b=this->ans[i][0];
        b->Gettitle(a);
        string::size_type idx = a.find(s);
        if(idx != string::npos)
        {
            qid.push_back(i);
        }
    }

    double j=(double)qid.size()/3;
    int page=ceil(j);
   while(1)
   {
    system("cls");
    int chose;
    cout<<page<<" pages in total, which do you want to see?"<<endl;
    cin>>chose;
    system("cls");
    int num =qid.size()-1-chose*3+3;
    //cout<<"zuida:"<<num<<endl;
    int i=num;
    cout<<"<<"<<chose<< " pages"<<">>"<<endl;
     while(i>=num-2)
     {
       if(i>=0)
       {
       cout<<"Question number:"<<qid[i]+1<<endl;
       BasicInfo* b=new Quas();//Ques是BasicInfo的派生
       b=this->ans[qid[i]][0];
       b->Display();//虚函数
       }
       else
         break;
       i--;
     }
     int change;
     cout<<"do you want to go to another page? yes:1 no :2"<<endl;
     cin>>change;
     if(change!=1)
        break;
   }

}

void Anslist::SearchQuestion(string year,string month,string day,vector<int>&qid)
{
    string a=month+" "+day;
    string mix;
    for(int i=0;i<this->ans.size();i++)
    {
        BasicInfo*b=new Quas();
        b=this->ans[i][0];
        b->Gettime(mix);
        string::size_type idx = mix.find(a);
        if(idx != string::npos)
        {
              string::size_type idx1 = mix.find(year);
              if(idx1 != string::npos)
               {
                   qid.push_back(i);
               }
        }
    }

    double j=(double)qid.size()/3;
    int page=ceil(j);
   while(1)
   {
    system("cls");
    int chose;
    cout<<page<<" pages in total, which do you want to see?"<<endl;
    cin>>chose;
    system("cls");
    int num =qid.size()-1-chose*3+3;
    //cout<<"zuida:"<<num<<endl;
    int i=num;
    cout<<"<<"<<chose<< " pages"<<">>"<<endl;
     while(i>=num-2)
     {
       if(i>=0)
       {
       cout<<"Question number:"<<qid[i]+1<<endl;
       BasicInfo* b=new Quas();//Ques是BasicInfo的派生
       b=this->ans[qid[i]][0];
       b->Display();//虚函数
       }
       else
         break;
       i--;
     }
     int change;
     cout<<"do you want to go to another page? yes:1 no :2"<<endl;
     cin>>change;
     if(change!=1)
        break;
   }
}

void Anslist::SearchQuestion(string author,int i,vector<int>&qid)
{
     string a;
     vector<BasicInfo*> temp;
     vector<int>flag;
     for(int i=0;i<this->ans.size();i++)
        for(int j=0;j<this->ans[i].size();j++)
     {
         if(j==0)
         {
           BasicInfo*b=new Quas();
           b=this->ans[i][0];
           b->Getauid(a);

           if(author==a)
           {
              //b->Display();
              temp.push_back(b);
              qid.push_back(i);
              flag.push_back(0);//if is the question, then flag=0
              //cout<<endl;
           }
         }

         else
         {
            BasicInfo* b=new Answ();
            b=this->ans[i][j];
            b->Getauid(a);

            if(author==a)
            {
                /*cout<<"The Question is:";
                string title;
                BasicInfo* q=new Quas();
                q=this->ans[i][0];
                q->Gettitle(title);
                cout<<" "<<title<<endl;
                b->Display();
                cout<<endl;*/
                temp.push_back(b);
                qid.push_back(i);
                flag.push_back(j);//if is the answer, then flag=1
                //cout<<endl;
            }
         }
     }

     double j=(double)qid.size()/3;
    int page=ceil(j);
   while(1)
   {
    system("cls");
    int chose;
    cout<<page<<" pages in total, which do you want to see?"<<endl;
    cin>>chose;
    system("cls");
    int num =qid.size()-1-chose*3+3;
    //cout<<"zuida:"<<num<<endl;
    int i=num;
    cout<<"<<"<<chose<< " pages"<<">>"<<endl;
     while(i>=num-2)
     {
       if(i>=0)
       {
       cout<<"Question number:"<<qid[i]+1<<endl;
         if(flag[i]==0)
         {
            BasicInfo* b=new Quas();//Ques是BasicInfo的派生
            b=this->ans[qid[i]][0];
            b->Display();//虚函数
         }
         else if(flag[i]!=0)
         {
             cout<<"reply Question number:"<<qid[i]+1<<endl;
                string title;
                BasicInfo* q=new Quas();
                q=this->ans[qid[i]][0];
                q->Gettitle(title);
                cout<<"The question title is: "<<title<<endl;
                BasicInfo* b=new Answ();
                b=this->ans[qid[i]][flag[i]];
                b->Display();

         }

       }
       else
         break;
       i--;
     }
     int change;
     cout<<"do you want to go to another page? yes:1 no :2"<<endl;
     cin>>change;
     if(change!=1)
        break;
   }
}
