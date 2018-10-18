#ifndef SIGNUP_H
#define SIGNUP_H
#include <QMessageBox>
#include <QWidget>
#include "userlist.h"
namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = 0);
    ~signup();
    //void Addperson(user& u);
private slots:
    void on_pushButton_clicked();
    void reshow(){this->show();}

    void on_pushButton_2_clicked();
    void on_lineEdit_2_editingFinished();

signals:
    void show_log();
private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
