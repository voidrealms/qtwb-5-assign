#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

#include <QPushButton>
#include <QIcon>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void load();
    void save();
    void clear();
    void accepted();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
