#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QPushButton *btnAccept = new QPushButton(QIcon(":/resources/images/accept.png"),"Ok");
    QPushButton *btnReject = new QPushButton(QIcon(":/resources/images/cancel.png"),"Cancel");

    ui->buttonBox->addButton(btnAccept,QDialogButtonBox::ButtonRole::AcceptRole);
    ui->buttonBox->addButton(btnReject,QDialogButtonBox::ButtonRole::RejectRole);

    connect(btnAccept,&QPushButton::clicked,this,&Dialog::accepted);
    connect(btnReject,&QPushButton::clicked,this,&Dialog::reject);
    connect(ui->btnSave,&QPushButton::clicked,this,&Dialog::save);
    connect(ui->btnClear,&QPushButton::clicked,this,&Dialog::clear);

    load();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::load()
{
    QFile file("data.txt");
    if(!file.exists()) return;
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    ui->txtName->setText(stream.readAll());
    file.close();
}

void Dialog::save()
{
    QFile file("data.txt");
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error", file.errorString());
        return;
    }

    QTextStream stream(&file);
    stream << ui->txtName->text();
    file.close();
}

void Dialog::clear()
{
    ui->txtName->setText("");
}

void Dialog::accepted()
{
    QMessageBox::information(this,"Hello","Hello " + ui->txtName->text());
    accept();
}

