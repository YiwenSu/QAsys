#include "userlist.h"


userlist::userlist()
{
    //ctor
    vector<user> person(3);
}

userlist::~userlist()
{
    //dtor
}

void userlist::Addperson(user& u)
{
    string names;
    int pass;
    cout<<"Your name:";
    cin>>names;
    cout<<"password:";
    cin>>pass;

    int num=this->person.size()+1;
    //cout<<num;

    u.signup(names,pass,num);

    this->person.push_back(u);
    system("cls");
    cout<<"You are successful sign up, enjoy your journey here!"<<endl;
    system("pause");
}

void userlist::Displayusers()
{
    for(int i=0;i<this->person.size();i++)
        this->person[i].Displayinfo();
}

int userlist::finduser(string a,int pass)
{
    for(int i=0;i<this->person.size();i++)
        if( this->person[i].Login(a,pass))
          return i;

    return -1;

}

void userlist::intouserfile()
{
    ofstream  out("users.txt");

    int password, aid;
    string name;
    vector<string>fnames;
    if(out.is_open())
        out<<(*this);



    out.close();
}


void userlist::outofuserfile()
{
    ifstream in("users.txt");
    this->person.clear();

    if (!in.is_open())
       { cout << "Error opening file info!"; exit (1); }

    in>>(*this);

    in.close();
}

istream& operator>>(istream &in, userlist& ulist)
{
      while (in.peek()!=EOF )
    {
        user u;
        string name;
        getline(in,name);
        u.Givename(name);

        char password[100];
        in.getline(password,20);
        int p=atoi(password);
        u.Givepass(p);

        char aid[100];
        in.getline(aid,20);
        int a=atoi(aid);
        u.Giveuserid(a);

        string buffer;
        string signal="***";
        vector<string>fname;

        getline(in,buffer);
        while(buffer!=signal)
        {
              fname.push_back(buffer);
              getline(in,buffer);
        }


        u.Givefocus(fname);
        ulist.person.push_back(u);

        char str[10];
        in.getline(str,10);
    }

    return in;
}

ofstream& operator<<(ofstream &out, userlist& ulist)
{
      int password, aid;
      string name;
      vector<string>fnames;
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
