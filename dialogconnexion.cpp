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
    ui->labelNbConnexions->setVisible(0);
    ui->labelConnexion->setVisible(0);
    ui->labelAttention->setVisible(0);


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
    //Récupération des champs
    QString login, mdp;
    login = ui->lineEditLogin->text();
    mdp = ui->lineEditMdp->text();

    //Création des requêtes
    QString txtRequeteConnexion;
    txtRequeteConnexion="SELECT COUNT(*) FROM Employe WHERE loginEmploye='"+ ui->lineEditLogin->text() +"' AND mdpEmploye=PASSWORD('"+ ui->lineEditMdp->text() +"')";

    QString txtRequetePersonneConnectee;
    txtRequetePersonneConnectee="SELECT numeroEmploye, nomEmploye, prenomEmploye FROM Employe WHERE loginEmploye='"+ ui->lineEditLogin->text() +"' AND mdpEmploye=PASSWORD('"+ ui->lineEditMdp->text() +"')";

    //Exécution des requêtes
    QSqlQuery requeteConnexion(txtRequeteConnexion);
    qDebug()<<txtRequeteConnexion;

    QSqlQuery requetePersonneConnectee(txtRequetePersonneConnectee);
    qDebug()<<txtRequetePersonneConnectee;

    requeteConnexion.first();

    int testConnexion = requeteConnexion.value(0).toInt();

    //Si il y a une personne correspondante dans la base alors on accepte
    if(testConnexion>0){
        accept();
    }
    //Sinon on affiche une erreur et on quitte le programme au bout de 3 essais
    else
    {
        ui->labelIncorrect->setVisible(1);
        ui->labelNbConnexions->setVisible(1);
        ui->labelNbConnexions->setText(QString::number(compteurConnexionsRestantes));

        if(compteurConnexionsRestantes == 1){
            ui->labelConnexion->setText("connexion restante ! --");
        }

        ui->labelConnexion->setVisible(1);
        ui->labelAttention->setVisible(1);

        ui->lineEditLogin->setText("");
        ui->lineEditMdp->setText("");

        compteurConnexions++;
        compteurConnexionsRestantes--;

        //Si il y a 3 essais réalisés on quitte le programme
        if(compteurConnexions == 3){
            reject();
        }
    }
}

void DialogConnexion::on_pushButtonAnnuler_clicked()
{
    //Bouton pour quitter l'application
    reject();
}
