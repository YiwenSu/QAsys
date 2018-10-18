#include "Anslist.h"

void Anslist:: outoffile()
{
    QFile file("info.txt");
    try
    {
      if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           throw(runtime_error("wrong open info"));
       }
    }
    catch(runtime_error)
     {
        qDebug()<<"WRONG OPEN READ!";
        exit(1);
      }

    QTextStream in(&file);

    in>>(*this);

    file.close();
}
QTextStream& operator>>(QTextStream &in, Anslist& an)
{
        QString buffer;
        QString signal="*";
        QString signal1="**";
        int qid=0;
        if(!in.atEnd())
             buffer=in.readLine();

        while (!in.atEnd() )
          {

              //string buffer1=buffer;
              if(buffer==signal)
              {
                  BasicInfo* question=new Quas();

                  bool ok;
                  question->id=in.readLine().toInt(&ok,10);

                  QString title=in.readLine();
                  question->Givetitle(title);

                  QString cont=in.readLine();

                  question->Givecontent(cont);

                  QString auname=in.readLine();

                  question->Giveauid(auname);

                  QString time=in.readLine();
                  question->Givetime(time);
                  try
                  {
                      if(title==""||cont==""||auname==""||time==""||question->id==0)
                          throw("wrong content");

                  }
                  catch(char*)
                  {
                      qDebug()<<"WRONG CONTENT";
                      exit(1);
                  }

                  vector<BasicInfo*> b;
                  b.push_back(question);
                  an.ans.push_back(b);
                  qid++;

              }

              else if(buffer==signal1)
              {
                  BasicInfo*a=new Answ();

                  bool ok;
                  a->id=in.readLine().toInt(&ok,10);
                 // cout<<"xixi"<<endl;

                  QString cont=in.readLine();
                  a->Givecontent(cont);

                  QString auname=in.readLine();
                  a->Giveauid(auname);

                  int p=in.readLine().toInt(&ok,10);
                  a->Givepraise(p);

                  QString time=in.readLine();
                  a->Givetime(time);
                  try
                  {
                      if(cont==""||auname==""||time=="")
                          throw("wrong content1");

                  }
                  catch(char*)
                  {
                      qDebug()<<"WRONG CONTENT1";
                      exit(1);
                  }


                  an.ans[qid-1].push_back(a);


              }

             buffer=in.readLine();
              while(buffer=='\n')
              {
                  buffer=in.readLine();
              }
          }
       return in;
}

void Anslist::intofile()
{
     QFile file("info.txt");
     try
     {
     if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
      {
            throw(runtime_error("wrong write info"));

      }
     }
     catch(runtime_error)
     {
         qDebug()<<"open write failed.";
         exit(1);
     }
      QTextStream out(&file);
      out<<(*this);
      file.close();

}
QTextStream& operator<<(QTextStream &out, Anslist& an)
{
     QString au,co,title,times;
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
                       qDebug()<<times;
                       out<<"*"<<endl<<an.ans[i][j]->id<<endl<<title<<endl<<co<<endl<<au<<endl<<times<<endl<<endl;

                      }

                   else
                   {

                       an.ans[i][j]->Getauid(au);
                       qDebug()<<au;
                       an.ans[i][j]->GetContent(co);
                       qDebug()<<co;
                       an.ans[i][j]->Gettime(times);
                       qDebug()<<times;
                       an.ans[i][j]->Getpraise(praise);
                       qDebug()<<praise;
                       out<<"**"<<endl<<an.ans[i][j]->id<<endl<<co<<endl<<au<<endl<<praise<<endl<<times<<endl<<endl;
                   }


               }
    return out;
}

void Anslist::Addans(Quas& q,int qid)//add question
{
        vector<BasicInfo*> b;
        b.push_back(&q);
        this->ans.push_back(b);
        int i=ans.size();
        q.id=2017*10000+i;
}

void Anslist::Addans(Answ& an,int qid)//add answer
{
    this->ans[qid].push_back(&an);
    int i=ans[qid].size();
    an.id=1001*10000+qid*1000+i;

}

int Anslist::Givefocus(user&u,int q_id, QString&str)//focus on str
{

    for(int i=this->ans[q_id].size()-1; i>=0; i--)
   {
        BasicInfo* b=new Answ();
        b=this->ans[q_id][i];
        QString author;
        b->Getauid(author);

        if(author==str)
           {

              if(u.ADDfocus(str))
              {
              return 1;
              }
              break;
            }
   }
    return 0;
}

void Anslist::Giveapplause(int q_id,int anid)//praise to qid
{
    for(int i=this->ans[q_id].size()-1; i>0; i--)
    {
        if(anid==this->ans[q_id][i]->id)
            {
             BasicInfo* b=new Answ();
             b=this->ans[q_id][i];
             b->Addpraise();
            break;
            }
    }
     cout<<"applause complete!"<<endl;

}


void Anslist::SearchQuestion(QString author,int i,vector<int>&qid,vector<int>&flag)//use author to search
{
        QString a;

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

                   qid.push_back(i);
                   flag.push_back(j);//if is the answer, then flag=1
                   //cout<<endl;
               }
            }
        }
}

void Anslist::SearchQuestion(QString s,vector<int>&qid)
{
    QString a;

    //vector<vector<BasicInfo*> >temp;

    for(int i=0;i<this->ans.size();i++)
    {
        BasicInfo*b=new Quas();
        b=this->ans[i][0];
        b->Gettitle(a);
        //string::size_type idx = a.find(s);
        if(a.contains(s,Qt::CaseSensitive))
        {
            qid.push_back(i);
        }
    }


}


void Anslist::SearchQuestion(QString year,QString month,QString day,vector<int>&qid)
{
    QString a=month+" "+day;
    QString mix;
    for(int i=0;i<this->ans.size();i++)
    {
        BasicInfo*b=new Quas();
        b=this->ans[i][0];
        b->Gettime(mix);
        if(mix.contains(a,Qt::CaseSensitive))
        {
            if(mix.contains(year,Qt::CaseSensitive))
            {
                qid.push_back(i);
            }
        }
    }

}
