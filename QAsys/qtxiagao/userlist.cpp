#include "userlist.h"

void userlist::outofuserfile()
{

     QFile f("users.txt");
     try
     {
     if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
      {
           throw(runtime_error("wrong open user"));
      }
     }
     catch(runtime_error)
     {
         qDebug()<<"wrong read user";
         exit(1);
     }

     QTextStream in(&f);

     in>>(*this);

     f.close();
}

QTextStream& operator>>(QTextStream &in, userlist& ulist)
{
     while(!in.atEnd())
      {
        user u;
       try{
        QString name=in.readLine();
        u.Givename(name);

        bool ok;
        int password=in.readLine().toInt(&ok,10);
        u.Givepass(password);


        int a=in.readLine().toInt(&ok,10);//user's id
        u.Giveuserid(a);

            if(name==""||password==0||a==0)
                throw("wrong user");
        }
        catch(runtime_error RunTimeError)
        {
            qDebug()<<"WRONG USER";
            exit(1);
        }

        QString buffer;
        QString signal="***";
        vector<QString>fname;

        buffer=in.readLine();
        while(buffer!=signal)
        {
              fname.push_back(buffer);
               buffer=in.readLine();
        }

        u.Givefocus(fname);
        ulist.person.push_back(u);

        QString str=in.readLine();
    }

    return in;
}

void userlist::intouserfile()
{

    QFile file("users.txt");
    try
    {
        if (!file.open(QIODevice::WriteOnly| QIODevice::Text))
             throw(runtime_error("wrong open user"));
    }
    catch(runtime_error)
    {
        qDebug()<<"wrong out user";
        exit(1);
    }

    QTextStream out(&file);
    out<<(*this);


    file.close();
}

QTextStream& operator<<(QTextStream &out, userlist& ulist)
{
          int password, aid;
          QString name;
          vector<QString>fnames;
         for(int i=0;i<ulist.person.size();i++)
            {
                ulist.person[i].Getpass(password);
                ulist.person[i].Getname(name);
                ulist.person[i].Getuserid(aid);
                ulist.person[i].Getfocus(fnames);

                out<<name<<endl<<password<<endl<<aid<<endl;

                for(int j=0;j<fnames.size();j++)
                    out<<fnames[j]<<endl;

                out<<"***"<<endl<<endl;
            }

         return out;
}

int userlist::finduser(QString a,int pass)
{
    for(int i=0;i<this->person.size();i++)
        if( this->person[i].Login(a,pass))
           {
            return i;
            break;
           }

    return -1;

}
