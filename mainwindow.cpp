#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogconnexion.h"
#include <QSqlQuery>
#include <QDebug>
#include <QCheckBox>

MainWindow::MainWindow(QString nom,QString prenom, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    afficheTableauProducteur();
    afficheTableauProducteurVerifies();
}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::afficheTableauProducteur()
{
    qDebug()<<"void MainWindow::afficheTableauProducteur()";

    //création de la requête d'affichage pour le tableau
    QString maRequeteTableau;
    maRequeteTableau = "SELECT numeroProducteur,nomProducteur,prenomProducteur,adresseProducteur,mailProducteur,Abonnement.numeroAbonnement FROM Producteur INNER JOIN Abonnement ON Producteur.numeroAbonnement=Abonnement.numeroAbonnement ";
    qDebug()<<maRequeteTableau;
    QSqlQuery maRequete(maRequeteTableau);

    //Reset du tableau
    ui->tableWidgetTousProducteurs->clear();
    ui->tableWidgetTousProducteurs->setRowCount(0);
    //Redimensionnement des colonnes en fonction de la taille du tableau
    ui->tableWidgetTousProducteurs->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Ajout des entêtes du tableau
    QStringList ColumnProducteur;
    ColumnProducteur<<"Numéro"<<"Nom"<<"Prénom"<<"Adresse"<<"Mail"<<"Abonnement";
    ui->tableWidgetTousProducteurs->setHorizontalHeaderLabels(ColumnProducteur);

    int maLigne=0;

    //mise en place du tableau
    while (maRequete.next()) {
        ui->tableWidgetTousProducteurs->insertRow(maLigne);
        ui->tableWidgetTousProducteurs->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroProducteur").toString()));
        ui->tableWidgetTousProducteurs->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("nomProducteur").toString()));
        ui->tableWidgetTousProducteurs->setItem(maLigne, 2, new QTableWidgetItem(maRequete.value("prenomProducteur").toString()));
        ui->tableWidgetTousProducteurs->setItem(maLigne, 3, new QTableWidgetItem(maRequete.value("adresseProducteur").toString()));
        ui->tableWidgetTousProducteurs->setItem(maLigne, 4, new QTableWidgetItem(maRequete.value("mailProducteur").toString()));
        ui->tableWidgetTousProducteurs->setItem(maLigne, 5, new QTableWidgetItem(maRequete.value("numeroAbonnement").toString()));

        maLigne++;
    }

}

void MainWindow::afficheTableauProducteurVerifies()
{
    qDebug()<<"void MainWindow::afficheTableauProducteurVerifies()";

    //création de la requête d'affichage pour le tableau
    QString maRequeteTableau;
    maRequeteTableau = "SELECT numeroProducteur,nomProducteur,prenomProducteur,adresseProducteur,mailProducteur,telProducteur,Abonnement.numeroAbonnement, validiteProducteur FROM Producteur INNER JOIN Abonnement ON Producteur.numeroAbonnement=Abonnement.numeroAbonnement ";
    qDebug()<<maRequeteTableau;
    QSqlQuery maRequete(maRequeteTableau);

    //Reset du tableau
    ui->tableWidgetNonVerifies->clear();
    ui->tableWidgetNonVerifies->setRowCount(0);
    //Redimensionnement des colonnes en fonction de la taille du tableau
    ui->tableWidgetNonVerifies->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Ajout des entêtes du tableau
    QStringList ColumnProducteur;
    ColumnProducteur<<"Numéro"<<"Nom"<<"Prénom"<<"Adresse"<<"Mail"<<"Téléphone"<<"Abonnement";
    ui->tableWidgetNonVerifies->setHorizontalHeaderLabels(ColumnProducteur);

    int maLigne=0;

    //mise en place du tableau
    while (maRequete.next() && maRequete.value("validiteProducteur")==0) {
        ui->tableWidgetNonVerifies->insertRow(maLigne);
        ui->tableWidgetNonVerifies->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("nomProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 2, new QTableWidgetItem(maRequete.value("prenomProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 3, new QTableWidgetItem(maRequete.value("adresseProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 4, new QTableWidgetItem(maRequete.value("mailProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 5, new QTableWidgetItem(maRequete.value("telProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 6, new QTableWidgetItem(maRequete.value("numeroAbonnement").toString()));

        maLigne++;
    }

}



void MainWindow::on_pushButtonVerifierProducteur_clicked()
{
    QString maRequeteVerificationProducteur;
    maRequeteVerificationProducteur = "UPDATE Producteur SET validiteProducteur=1 WHERE numeroProducteur="+ui->tableWidgetNonVerifies->item(ui->tableWidgetNonVerifies->currentRow(),0)->text();
    qDebug()<<maRequeteVerificationProducteur;
    QSqlQuery maRequete(maRequeteVerificationProducteur);

    //Reset du tableau
    ui->tableWidgetNonVerifies->clear();
    ui->tableWidgetNonVerifies->setRowCount(0);

    afficheTableauProducteur();
    afficheTableauProducteurVerifies();
}

void MainWindow::on_tableWidgetTousProducteurs_cellClicked(int row, int column)
{
    ui->lineEditNomProducteur->setText(ui->tableWidgetTousProducteurs->item(ui->tableWidgetTousProducteurs->currentRow(),1)->text());
    ui->lineEditPrenomProducteur->setText(ui->tableWidgetTousProducteurs->item(ui->tableWidgetTousProducteurs->currentRow(),2)->text());
    ui->lineEditAdresseProducteur->setText(ui->tableWidgetTousProducteurs->item(ui->tableWidgetTousProducteurs->currentRow(),3)->text());
    ui->lineEditMailProducteur->setText(ui->tableWidgetTousProducteurs->item(ui->tableWidgetTousProducteurs->currentRow(),4)->text());
    ui->lineEditTelephoneProducteur->setText(ui->tableWidgetTousProducteurs->item(ui->tableWidgetTousProducteurs->currentRow(),5)->text());
}

void MainWindow::on_pushButtonModifierProducteur_clicked()
{
    QString maRequeteModificationProducteur;
    maRequeteModificationProducteur = "UPDATE Producteur SET nomProducteur='"+ui->lineEditNomProducteur->text()+"', prenomProducteur='"+ui->lineEditPrenomProducteur->text()+"', adresseProducteur='"+ui->lineEditAdresseProducteur->text()+"',mailProducteur='"+ui->lineEditMailProducteur->text()+"',telProducteur='"+ui->lineEditTelephoneProducteur->text()+"' WHERE numeroProducteur="+ui->tableWidgetTousProducteurs->item(ui->tableWidgetTousProducteurs->currentRow(),0)->text();
    qDebug()<<maRequeteModificationProducteur;
    QSqlQuery maRequete(maRequeteModificationProducteur);

    //Reset du tableau
    ui->tableWidgetTousProducteurs->clear();
    ui->tableWidgetTousProducteurs->setRowCount(0);

    afficheTableauProducteur();
}
