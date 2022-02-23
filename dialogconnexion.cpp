#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"
#include <QString>

DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion)
{
    ui->setupUi(this);
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}


void DialogConnexion::on_pushButtonSeConnecter_clicked()
{
    QString login, mdp;
    login = ui->lineEditLogin->text();
    mdp = ui->lineEditMdp->text();

    QString requeteConnexion;
    requeteConnexion="SELECT COUNT(*) "
                     "FROM Employe "
                     "WHERE login=''";
    accept();
}

void DialogConnexion::on_pushButtonAnnuler_clicked()
{
    reject();
}
