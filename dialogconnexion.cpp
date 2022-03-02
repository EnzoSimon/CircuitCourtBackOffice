#include "dialogconnexion.h"
#include "ui_dialogconnexion.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>

DialogConnexion::DialogConnexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConnexion)
{
    ui->setupUi(this);
    ui->labelIncorrect->setVisible(0);
}

DialogConnexion::~DialogConnexion()
{
    delete ui;
}

QString DialogConnexion::getNom()
{
    return nom;
}

QString DialogConnexion::getPrenom()
{
    return prenom;
}


void DialogConnexion::on_pushButtonSeConnecter_clicked()
{
    QString login, mdp;
    login = ui->lineEditLogin->text();
    mdp = ui->lineEditMdp->text();

    QString txtRequeteConnexion;
    txtRequeteConnexion="SELECT COUNT(*) FROM Employe WHERE loginEmploye='"+ ui->lineEditLogin->text() +"' AND mdpEmploye=PASSWORD('"+ ui->lineEditMdp->text() +"')";

    QString txtRequetePersonneConnectee;
    txtRequetePersonneConnectee="SELECT numeroEmploye, nomEmploye, prenomEmploye FROM Employe WHERE loginEmploye='"+ ui->lineEditLogin->text() +"' AND mdpEmploye=PASSWORD('"+ ui->lineEditMdp->text() +"')";


    QSqlQuery requeteConnexion(txtRequeteConnexion);
    qDebug()<<txtRequeteConnexion;

    QSqlQuery requetePersonneConnectee(txtRequetePersonneConnectee);
    qDebug()<<txtRequetePersonneConnectee;

    requeteConnexion.first();

    int testConnexion = requeteConnexion.value(0).toInt();

    if(testConnexion>0){
        accept();
    }else{
        ui->labelIncorrect->setVisible(1);
        ui->lineEditLogin->setText("");
        ui->lineEditMdp->setText("");
    }




}

void DialogConnexion::on_pushButtonAnnuler_clicked()
{
    reject();
}
