#include "choicepage.h"
#include <QApplication>
#include "signup.h"
#include "login.h"
#include "answer.h"
#include "focus.h"
#include "searchq.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    choicepage w;
    login log;
    signup sign;
    Answer as;
    focus f;
    SearchQ s;
    log.show();
    QObject::connect(&log,SIGNAL(show_sign()),&sign,SLOT(reshow()));
    QObject::connect(&sign,SIGNAL(show_log()),&log,SLOT(reshow()));

    QObject::connect(&log,SIGNAL(show_choice()),&w,SLOT(reshow()));
    QObject::connect(&log,SIGNAL(send_auid(QString)),&w,SLOT(recieve_auid(QString)));

    QObject::connect(&w,SIGNAL(show_answer()),&as,SLOT(reshow()));
    QObject::connect(&as,SIGNAL(show_choice()),&w,SLOT(reshow()));


    QObject::connect(&w,SIGNAL(show_focus()),&f,SLOT(reshow()));
    QObject::connect(&f,SIGNAL(show_answer()),&as,SLOT(reshow()));
    QObject::connect(&f,SIGNAL(show_question()),&w,SLOT(reshow()));

    QObject::connect(&w,SIGNAL(show_search()),&s,SLOT(reshow()));

    QObject::connect(&s,SIGNAL(show_answer()),&as,SLOT(reshow()));
     QObject::connect(&s,SIGNAL(show_question()),&w,SLOT(reshow()));
      QObject::connect(&w,SIGNAL(show_log()),&log,SLOT(reshow()));
    return a.exec();
}
