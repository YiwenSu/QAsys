#ifndef GRID_H
#define GRID_H
#include "Anslist.h"
#include "userlist.h"

class Grid
{
    public:
        Grid();
        virtual ~Grid();
        void Givethechoice(Anslist& alist,userlist& ulist,string s,int pass);
    protected:

    private:
};

#endif // GRID_H
