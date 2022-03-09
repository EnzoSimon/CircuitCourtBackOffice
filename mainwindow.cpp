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
    afficheTableauRayons();
    afficherTableauVariete();
    afficherTableauProduit();

    remplirComboRayonDeVariete();
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

    //Je désactive mon bouton de modification pour empécher les modifications
    ui->pushButtonModifierProducteur->setEnabled(false);
    ui->pushButtonModifierProducteur->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");

}

void MainWindow::afficheTableauProducteurVerifies()
{
    qDebug()<<"void MainWindow::afficheTableauProducteurVerifies()";

    //création de la requête d'affichage pour le tableau
    QString maRequeteTableau;
    maRequeteTableau = "SELECT numeroProducteur,nomProducteur,prenomProducteur,adresseProducteur,mailProducteur,telProducteur,Abonnement.numeroAbonnement, validiteProducteur FROM Producteur INNER JOIN Abonnement ON Producteur.numeroAbonnement=Abonnement.numeroAbonnement WHERE validiteProducteur=0";
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

    //Je désactive mon bouton de vérification pour empécher les validations
    ui->pushButtonVerifierProducteur->setEnabled(false);
    ui->pushButtonVerifierProducteur->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");

}

void MainWindow::afficheTableauRayons()
{
    qDebug()<<"void MainWindow::afficheTableauRayons()";

    //création de la requête d'affichage pour le tableau
    QString maRequeteTableau;
    maRequeteTableau = "SELECT numeroRayon,nomRayon,imgRayon FROM Rayon";
    qDebug()<<maRequeteTableau;
    QSqlQuery maRequete(maRequeteTableau);

    //Reset du tableau
    ui->tableWidgetRayons->clear();
    ui->tableWidgetRayons->setRowCount(0);
    //Redimensionnement des colonnes en fonction de la taille du tableau
    ui->tableWidgetRayons->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Ajout des entêtes du tableau
    QStringList ColumnProducteur;
    ColumnProducteur<<"Numéro"<<"Nom"<<"Chemin de l'image";
    ui->tableWidgetRayons->setHorizontalHeaderLabels(ColumnProducteur);

    int maLigne=0;

    //mise en place du tableau
    while (maRequete.next()) {
        ui->tableWidgetRayons->insertRow(maLigne);
        ui->tableWidgetRayons->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroRayon").toString()));
        ui->tableWidgetRayons->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("nomRayon").toString()));
        ui->tableWidgetRayons->setItem(maLigne, 2, new QTableWidgetItem(maRequete.value("imgRayon").toString()));

        maLigne++;
    }

    //Je désactive mon bouton de vérification pour empécher les validations
    ui->pushButtonAjouterRayon->setEnabled(false);
    ui->pushButtonAjouterRayon->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");
    ui->pushButtonSupprimerRayon->setEnabled(false);
    ui->pushButtonSupprimerRayon->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");

}

void MainWindow::afficherTableauVariete()
{
    qDebug()<<"void MainWindow::afficherTableauVariete()";

    //création de la requête d'affichage pour le tableau
    QString maRequeteTableau;
    maRequeteTableau = "SELECT Variete.numeroVariete,Variete.nomVariete,Variete.descriptionVariete,Rayon.numeroRayon,Rayon.nomRayon FROM Variete INNER JOIN Rayon ON Variete.numeroRayon=Rayon.numeroRayon";
    qDebug()<<maRequeteTableau;
    QSqlQuery maRequete(maRequeteTableau);

    //Reset du tableau
    ui->tableWidgetVarietes->clear();
    ui->tableWidgetVarietes->setRowCount(0);
    //Redimensionnement des colonnes en fonction de la taille du tableau
    ui->tableWidgetVarietes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Ajout des entêtes du tableau
    QStringList ColumnProducteur;
    ColumnProducteur<<"Numéro"<<"Nom"<<"Description"<<"Numéro du Rayon";
    ui->tableWidgetVarietes->setHorizontalHeaderLabels(ColumnProducteur);

    int maLigne=0;

    //mise en place du tableau
    while (maRequete.next()) {
        ui->tableWidgetVarietes->insertRow(maLigne);
        ui->tableWidgetVarietes->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroVariete").toString()));
        ui->tableWidgetVarietes->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("nomVariete").toString()));
        ui->tableWidgetVarietes->setItem(maLigne, 2, new QTableWidgetItem(maRequete.value("descriptionVariete").toString()));
        ui->tableWidgetVarietes->setItem(maLigne, 3, new QTableWidgetItem(maRequete.value("nomRayon").toString()));

        maLigne++;
    }

    //Je désactive mes boutons des Variétés
    ui->pushButtonAjouterVariete->setEnabled(false);
    ui->pushButtonAjouterVariete->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");
    ui->pushButtonSupprimerVariete->setEnabled(false);
    ui->pushButtonSupprimerVariete->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");
}

void MainWindow::afficherTableauProduit()
{
    qDebug()<<"void MainWindow::afficherTableauProduit()";

    //création de la requête d'affichage pour le tableau
    QString maRequeteTableau;
    maRequeteTableau = "SELECT Produit.numeroProduit,Produit.nomProduit,Produit.informationProduit,Produit.imageProduit,Produit.quantiteProduit,Variete.numeroVariete FROM Produit INNER JOIN Variete ON Produit.numeroVariete=Variete.numeroVariete";
    qDebug()<<maRequeteTableau;
    QSqlQuery maRequete(maRequeteTableau);

    //Reset du tableau
    ui->tableWidgetProduits->clear();
    ui->tableWidgetProduits->setRowCount(0);
    //Redimensionnement des colonnes en fonction de la taille du tableau
    ui->tableWidgetProduits->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Ajout des entêtes du tableau
    QStringList ColumnProducteur;
    ColumnProducteur<<"Numéro"<<"Nom"<<"Informations du produit"<<"Image du produit"<<"Quantité"<<"Numéro de Variété";
    ui->tableWidgetProduits->setHorizontalHeaderLabels(ColumnProducteur);

    int maLigne=0;

    //mise en place du tableau
    while (maRequete.next()) {
        ui->tableWidgetProduits->insertRow(maLigne);
        ui->tableWidgetProduits->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroProduit").toString()));
        ui->tableWidgetProduits->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("nomProduit").toString()));
        ui->tableWidgetProduits->setItem(maLigne, 2, new QTableWidgetItem(maRequete.value("informationProduit").toString()));
        ui->tableWidgetProduits->setItem(maLigne, 3, new QTableWidgetItem(maRequete.value("imageProduit").toString()));
        ui->tableWidgetProduits->setItem(maLigne, 4, new QTableWidgetItem(maRequete.value("quantiteProduit").toString()));
        ui->tableWidgetProduits->setItem(maLigne, 5, new QTableWidgetItem(maRequete.value("numeroVariete").toString()));

        maLigne++;
    }

    //Je désactive mes boutons des Produits
    ui->pushButtonAjouterProduit->setEnabled(false);
    ui->pushButtonAjouterProduit->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");
    ui->pushButtonSupprimerProduit->setEnabled(false);
    ui->pushButtonSupprimerProduit->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");
}

void MainWindow::remplirComboRayonDeVariete()
{
    qDebug()<<"void MainWindow::remplirComboRayonDeVariete()";

    QString nomRayon,txtMaRequete;
    txtMaRequete = "SELECT numeroRayon,nomRayon FROM Rayon";
    QSqlQuery maRequete(txtMaRequete);

    while (maRequete.next())
    {
        nomRayon = maRequete.value("nomRayon").toString();
        ui->comboBoxRayonDeVariete->addItem(nomRayon,maRequete.value("numeroRayon").toString());
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

    //J'active mon bouton de modification
    ui->pushButtonModifierProducteur->setEnabled(true);
    ui->pushButtonModifierProducteur->setStyleSheet("");
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

void MainWindow::on_pushButtonAjouterVariete_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonAjouterVariete_clicked()";

    //Récupération du plus grand id
    QSqlQuery max("SELECT IFNULL((SELECT MAX(numeroVariete)+1 FROM Variete),0)");
    max.next();
    maxVariete = max.value(0).toInt();

    //On écrit la requète Ajout de Variété
    QString requeteVariete;
    requeteVariete = "INSERT INTO Variete VALUES ("+QString::number(maxVariete)+",'"+ui->lineEditNomVariete->text()+"','"+ui->textEditDescriptionVariete->toPlainText()+"','"+ui->comboBoxRayonDeVariete->currentData().toString()+"')";
    QSqlQuery requeteInsertionVariete(requeteVariete);
    qDebug()<<requeteVariete;

    afficherTableauVariete();
}

void MainWindow::on_pushButtonSupprimerVariete_clicked()
{
    QString maRequeteModificationProducteur;
    maRequeteModificationProducteur = "DELETE FROM Variete WHERE numeroVariete = '"+ui->tableWidgetRayons->item(ui->tableWidgetRayons->currentRow(),0)->text()+"'";
    qDebug()<<maRequeteModificationProducteur;
    QSqlQuery maRequete(maRequeteModificationProducteur);

    //Reset du tableau
    ui->tableWidgetVarietes->clear();
    ui->tableWidgetVarietes->setRowCount(0);

    afficherTableauVariete();
}

void MainWindow::on_tableWidgetNonVerifies_cellClicked(int row, int column)
{
    ui->pushButtonVerifierProducteur->setEnabled(true);
    ui->pushButtonVerifierProducteur->setStyleSheet("");
}


void MainWindow::on_tableWidgetRayons_cellClicked(int row, int column)
{
    ui->lineEditNomRayon->setText(ui->tableWidgetRayons->item(ui->tableWidgetRayons->currentRow(),1)->text());
    ui->lineEditCheminImageRayon->setText(ui->tableWidgetRayons->item(ui->tableWidgetRayons->currentRow(),2)->text());

    //J'active mes boutons des Rayons
    ui->pushButtonAjouterRayon->setEnabled(true);
    ui->pushButtonAjouterRayon->setStyleSheet("");
    ui->pushButtonSupprimerRayon->setEnabled(true);
    ui->pushButtonSupprimerRayon->setStyleSheet("");
}


void MainWindow::on_pushButtonSupprimerRayon_clicked()
{
    QString maRequeteModificationProducteur;
    maRequeteModificationProducteur = "DELETE FROM Rayon WHERE numeroRayon='"+ui->tableWidgetRayons->item(ui->tableWidgetRayons->currentRow(),0)->text()+"'";
    qDebug()<<maRequeteModificationProducteur;
    QSqlQuery maRequete(maRequeteModificationProducteur);

    //Reset du tableau
    ui->tableWidgetRayons->clear();
    ui->tableWidgetRayons->setRowCount(0);

    afficheTableauRayons();
}


void MainWindow::on_tableWidgetVarietes_cellClicked(int row, int column)
{
    ui->lineEditNomVariete->setText(ui->tableWidgetVarietes->item(ui->tableWidgetVarietes->currentRow(),1)->text());
    ui->textEditDescriptionVariete->setText(ui->tableWidgetVarietes->item(ui->tableWidgetVarietes->currentRow(),2)->text());
    ui->comboBoxRayonDeVariete->setCurrentText(ui->tableWidgetVarietes->item(ui->tableWidgetVarietes->currentRow(),3)->text());


    //J'active mes boutons des Variétés
    ui->pushButtonAjouterVariete->setEnabled(true);
    ui->pushButtonAjouterVariete->setStyleSheet("");
    ui->pushButtonSupprimerVariete->setEnabled(true);
    ui->pushButtonSupprimerVariete->setStyleSheet("");
}


void MainWindow::on_tableWidgetProduits_cellClicked(int row, int column)
{
    //J'active mes boutons des Produits
    ui->pushButtonAjouterProduit->setEnabled(true);
    ui->pushButtonAjouterProduit->setStyleSheet("");
    ui->pushButtonSupprimerProduit->setEnabled(true);
    ui->pushButtonSupprimerProduit->setStyleSheet("");
}


void MainWindow::on_pushButtonChangerCompte_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonChangerCompte_clicked()";

    DialogConnexion fenConnexion(this);
    fenConnexion.exec();
}


void MainWindow::on_pushButtonAjouterRayon_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonAjouterRayon_clicked()";

    //Récupération du plus grand id
    QSqlQuery max("SELECT IFNULL((SELECT MAX(numeroRayon)+1 FROM Rayon),0)");
    max.next();
    maxRayon = max.value(0).toInt();

    //On écrit la requète Ajout de Rayon
    QString requeteRayon;
    requeteRayon = "INSERT INTO Rayon VALUES ("+QString::number(maxRayon)+",'"+ui->lineEditNomRayon->text()+"','"+ui->lineEditCheminImageRayon->text()+"')";
    QSqlQuery requeteInsertionRayon(requeteRayon);
    qDebug()<<requeteRayon;

    afficheTableauRayons();
}




