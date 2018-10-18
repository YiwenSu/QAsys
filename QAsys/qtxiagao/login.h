#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "userlist.h"
#include "total.h"
#include <QMessageBox>
namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_2_clicked();
    void reshow(){this->show();}
    void on_pushButton_clicked();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_2_textChanged(const QString &arg1);

signals:
void show_sign();
void show_choice();
void send_auid(QString);
private:
    Ui::login *ui;
};

#endif // LOGIN_H
