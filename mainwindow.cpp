#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogconnexion.h"
#include <QSqlQuery>
#include <QDebug>
#include <QCheckBox>
#include <QFileDialog>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>


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
    afficherTableauEmployes();

    remplirComboRayonDeVariete();
    remplirComboVarieteDeProduit();

    ui->groupBoxInfosEmploye->setVisible(0);

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
    maRequeteTableau = "SELECT numeroProducteur,nomProducteur,prenomProducteur,adresseProducteur,mailProducteur,telProducteur,TypeAbonnement.numeroTypeAbonnement,TypeAbonnement.libelleTypeAbonnement FROM Producteur INNER JOIN TypeAbonnement ON Producteur.numeroAbonnement=TypeAbonnement.numeroTypeAbonnement WHERE validiteProducteur=1";
    qDebug()<<maRequeteTableau;
    QSqlQuery maRequete(maRequeteTableau);

    //Reset du tableau
    ui->tableWidgetTousProducteurs->clear();
    ui->tableWidgetTousProducteurs->setRowCount(0);
    //Redimensionnement des colonnes en fonction de la taille du tableau
    ui->tableWidgetTousProducteurs->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Ajout des entêtes du tableau
    QStringList ColumnProducteur;
    ColumnProducteur<<"Numéro"<<"Nom"<<"Prénom"<<"Adresse"<<"Mail"<<"Téléphone"<<"Abonnement";
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
        ui->tableWidgetTousProducteurs->setItem(maLigne, 5, new QTableWidgetItem(maRequete.value("telProducteur").toString()));
        ui->tableWidgetTousProducteurs->setItem(maLigne, 6, new QTableWidgetItem(maRequete.value("libelleTypeAbonnement").toString()));

        //Centrage des cellules
        ui->tableWidgetTousProducteurs->item(maLigne,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousProducteurs->item(maLigne,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousProducteurs->item(maLigne,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousProducteurs->item(maLigne,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousProducteurs->item(maLigne,4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousProducteurs->item(maLigne,5)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousProducteurs->item(maLigne,6)->setTextAlignment(Qt::AlignCenter);


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
    maRequeteTableau = "SELECT numeroProducteur,nomProducteur,prenomProducteur,adresseProducteur,mailProducteur,telProducteur,TypeAbonnement.numeroTypeAbonnement,TypeAbonnement.libelleTypeAbonnement FROM Producteur INNER JOIN TypeAbonnement ON Producteur.numeroAbonnement=TypeAbonnement.numeroTypeAbonnement WHERE validiteProducteur=0";
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
    while (maRequete.next()) {
        ui->tableWidgetNonVerifies->insertRow(maLigne);
        ui->tableWidgetNonVerifies->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("nomProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 2, new QTableWidgetItem(maRequete.value("prenomProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 3, new QTableWidgetItem(maRequete.value("adresseProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 4, new QTableWidgetItem(maRequete.value("mailProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 5, new QTableWidgetItem(maRequete.value("telProducteur").toString()));
        ui->tableWidgetNonVerifies->setItem(maLigne, 6, new QTableWidgetItem(maRequete.value("libelleTypeAbonnement").toString()));

        //Centrage des cellules
        ui->tableWidgetNonVerifies->item(maLigne,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetNonVerifies->item(maLigne,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetNonVerifies->item(maLigne,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetNonVerifies->item(maLigne,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetNonVerifies->item(maLigne,4)->setTextAlignment(Qt::AlignCenter);

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
    ColumnProducteur<<"Numéro"<<"Nom"<<"Image";
    ui->tableWidgetRayons->setHorizontalHeaderLabels(ColumnProducteur);

    int maLigne=0;

    //mise en place du tableau
    while (maRequete.next()) {
        // création de l'image
        QLabel* sonImage = new QLabel();
        sonImage->setPixmap(QPixmap(maRequete.value("imgRayon").toString()));
        sonImage->setScaledContents(true);
        sonImage->setStyleSheet("max-width: 130px;");


        ui->tableWidgetRayons->insertRow(maLigne);
        ui->tableWidgetRayons->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroRayon").toString()));
        ui->tableWidgetRayons->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("nomRayon").toString()));
        ui->tableWidgetRayons->setCellWidget(maLigne,2,sonImage);

        //Centrage des cellules
        ui->tableWidgetRayons->item(maLigne,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetRayons->item(maLigne,1)->setTextAlignment(Qt::AlignCenter);


        maLigne++;
    }

    ui->tableWidgetRayons->resizeColumnsToContents();
    ui->tableWidgetRayons->resizeRowsToContents();

    //Je désactive mon bouton de vérification pour empécher les validations
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

        //Centrage des cellules
        ui->tableWidgetVarietes->item(maLigne,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetVarietes->item(maLigne,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetVarietes->item(maLigne,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetVarietes->item(maLigne,3)->setTextAlignment(Qt::AlignCenter);

        maLigne++;
    }

    //Je désactive mes boutons des Variétés
    ui->pushButtonSupprimerVariete->setEnabled(false);
    ui->pushButtonSupprimerVariete->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");
}

void MainWindow::afficherTableauProduit()
{
    qDebug()<<"void MainWindow::afficherTableauProduit()";

    //création de la requête d'affichage pour le tableau
    QString maRequeteTableau;
    maRequeteTableau = "SELECT Produit.numeroProduit,Produit.nomProduit,Produit.informationProduit,Produit.imageProduit,Produit.quantiteProduit,Variete.numeroVariete,Variete.nomVariete FROM Produit INNER JOIN Variete ON Produit.numeroVariete=Variete.numeroVariete";
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

        // création de l'image
        QLabel* sonImage = new QLabel();
        sonImage->setPixmap(QPixmap(maRequete.value("imageProduit").toString()));
        sonImage->setScaledContents(true);
        sonImage->setStyleSheet("max-width: 130px;");

        ui->tableWidgetProduits->insertRow(maLigne);
        ui->tableWidgetProduits->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroProduit").toString()));
        ui->tableWidgetProduits->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("nomProduit").toString()));
        ui->tableWidgetProduits->setItem(maLigne, 2, new QTableWidgetItem(maRequete.value("informationProduit").toString()));
        ui->tableWidgetProduits->setCellWidget(maLigne,3,sonImage);
        ui->tableWidgetProduits->setItem(maLigne, 4, new QTableWidgetItem(maRequete.value("quantiteProduit").toString()));
        ui->tableWidgetProduits->setItem(maLigne, 5, new QTableWidgetItem(maRequete.value("nomVariete").toString()));

        //Centrage des cellules
        ui->tableWidgetProduits->item(maLigne,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetProduits->item(maLigne,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetProduits->item(maLigne,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetProduits->item(maLigne,4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetProduits->item(maLigne,5)->setTextAlignment(Qt::AlignCenter);

        maLigne++;
    }


    ui->tableWidgetProduits->resizeColumnsToContents();
    ui->tableWidgetProduits->resizeRowsToContents();

    //Je désactive le bouton des suppressions de Produits
    ui->pushButtonSupprimerProduit->setEnabled(false);
    ui->pushButtonSupprimerProduit->setStyleSheet("background-color: #d0e1f7; border: 2px solid #83a4cc; color: #4d4d4d;");
}

void MainWindow::afficherTableauEmployes()
{
    qDebug()<<"void MainWindow::afficherTableauEmployes()";

    //Reset du tableau
    ui->tableWidgetTousEmployes->clear();
    ui->tableWidgetTousEmployes->setRowCount(0);

    //création de la requête d'affichage pour le tableau
    QString maRequeteTableau;
    maRequeteTableau = "SELECT numeroEmploye,loginEmploye,nomEmploye,prenomEmploye,villeEmploye,rueEmploye,codePostalEmploye,mailEmploye,telEmploye,TypeEmploye.numeroTypeEmploye,TypeEmploye.libelleTypeEmploye FROM Employe INNER JOIN TypeEmploye ON Employe.numeroTypeEmploye=TypeEmploye.numeroTypeEmploye";
    qDebug()<<maRequeteTableau;
    QSqlQuery maRequete(maRequeteTableau);

    //Reset du tableau
    ui->tableWidgetTousEmployes->clear();
    ui->tableWidgetTousEmployes->setRowCount(0);
    //Redimensionnement des colonnes en fonction de la taille du tableau
    ui->tableWidgetTousEmployes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Ajout des entêtes du tableau
    QStringList ColumnProducteur;
    ColumnProducteur<<"Numéro"<<"Login"<<"Nom"<<"Prénom"<<"Adresse"<<"Ville"<<"Mail"<<"Téléphone"<<"Type";
    ui->tableWidgetTousEmployes->setHorizontalHeaderLabels(ColumnProducteur);

    int maLigne=0;

    //mise en place du tableau
    while (maRequete.next()) {
        ui->tableWidgetTousEmployes->insertRow(maLigne);
        ui->tableWidgetTousEmployes->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("loginEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 2, new QTableWidgetItem(maRequete.value("nomEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 3, new QTableWidgetItem(maRequete.value("prenomEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 4, new QTableWidgetItem(maRequete.value("rueEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 5, new QTableWidgetItem(maRequete.value("villeEmploye").toString()+" / "+maRequete.value("codePostalEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 6, new QTableWidgetItem(maRequete.value("mailEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 7, new QTableWidgetItem(maRequete.value("telEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 8, new QTableWidgetItem(maRequete.value("libelleTypeEmploye").toString()));

        //Centrage des cellules
        ui->tableWidgetTousEmployes->item(maLigne,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,5)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,6)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,7)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,8)->setTextAlignment(Qt::AlignCenter);

        maLigne++;
    }
}



void MainWindow::remplirComboRayonDeVariete()
{
    qDebug()<<"void MainWindow::remplirComboRayonDeVariete()";
    ui->comboBoxRayonDeVariete->clear();

    QString nomRayon,txtMaRequete;
    txtMaRequete = "SELECT numeroRayon,nomRayon FROM Rayon";
    QSqlQuery maRequete(txtMaRequete);

    while (maRequete.next())
    {
        nomRayon = maRequete.value("nomRayon").toString();
        ui->comboBoxRayonDeVariete->addItem(nomRayon,maRequete.value("numeroRayon").toString());
    }
}

void MainWindow::remplirComboVarieteDeProduit()
{
    qDebug()<<"void MainWindow::remplirComboVarieteDeProduit()";
    ui->comboBoxVarieteDuProduit->clear();

    QString nomRayon,txtMaRequete;
    txtMaRequete = "SELECT numeroVariete,nomVariete FROM Variete";
    QSqlQuery maRequete(txtMaRequete);

    while (maRequete.next())
    {
        nomRayon = maRequete.value("nomVariete").toString();
        ui->comboBoxVarieteDuProduit->addItem(nomRayon,maRequete.value("numeroVariete").toString());
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
    if(!ui->lineEditNomVariete->text().isEmpty() && !ui->plainTextEditDescriptionVariete->toPlainText().isEmpty()) {
    //Récupération du plus grand id
    QSqlQuery max("SELECT IFNULL((SELECT MAX(numeroVariete)+1 FROM Variete),0)");
    max.next();
    maxVariete = max.value(0).toInt();

    //On écrit la requète Ajout de Variété
    QString requeteVariete;
    requeteVariete = "INSERT INTO Variete VALUES ("+QString::number(maxVariete)+",'"+ui->lineEditNomVariete->text()+"','"+ui->plainTextEditDescriptionVariete->toPlainText()+"','"+ui->comboBoxRayonDeVariete->currentData().toString()+"')";
    QSqlQuery requeteInsertionVariete(requeteVariete);
    qDebug()<<requeteVariete;

    afficherTableauVariete();
    }
    else{
        ui->lineEditNomVariete->setStyleSheet("background: #f7c1c1; min-width: 200px;");
        ui->plainTextEditDescriptionVariete->setStyleSheet("background: #f7c1c1; max-height: 100px; min-width: 150px;");
        ui->statusBar->setStyleSheet("color: #eb3131; font-weight: 700;");
        ui->statusBar->showMessage("Remplissez les champs :)",3000);
    }

    remplirComboVarieteDeProduit();
}


void MainWindow::on_pushButtonSupprimerVariete_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSupprimerVariete_clicked()";

    QString maRequeteModificationProducteur;
    maRequeteModificationProducteur = "DELETE FROM Variete WHERE numeroVariete = "+ui->tableWidgetVarietes->item(ui->tableWidgetVarietes->currentRow(),0)->text();
    qDebug()<<maRequeteModificationProducteur;
    QSqlQuery maRequete(maRequeteModificationProducteur);

    //Reset du tableau
    ui->tableWidgetVarietes->clear();
    ui->tableWidgetVarietes->setRowCount(0);

    afficherTableauVariete();
    remplirComboVarieteDeProduit();
}

void MainWindow::on_tableWidgetNonVerifies_cellClicked(int row, int column)
{
    ui->pushButtonVerifierProducteur->setEnabled(true);
    ui->pushButtonVerifierProducteur->setStyleSheet("");
}


void MainWindow::on_tableWidgetRayons_cellClicked(int row, int column)
{
    QString requeteImageTxt;
    requeteImageTxt="SELECT imgRayon FROM Rayon WHERE numeroRayon="+ui->tableWidgetRayons->item(ui->tableWidgetRayons->currentRow(),0)->text();
    QSqlQuery requeteImage(requeteImageTxt);
    requeteImage.next();

    ui->lineEditNomRayon->setText(ui->tableWidgetRayons->item(ui->tableWidgetRayons->currentRow(),1)->text());
    ui->lineEditCheminImageRayon->setText(requeteImage.value("imgRayon").toString());

    //J'active mes boutons des Rayons
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
    remplirComboRayonDeVariete();
}


void MainWindow::on_tableWidgetVarietes_cellClicked(int row, int column)
{
    ui->lineEditNomVariete->setText(ui->tableWidgetVarietes->item(ui->tableWidgetVarietes->currentRow(),1)->text());
    ui->plainTextEditDescriptionVariete->setPlainText(ui->tableWidgetVarietes->item(ui->tableWidgetVarietes->currentRow(),2)->text());
    ui->comboBoxRayonDeVariete->setCurrentText(ui->tableWidgetVarietes->item(ui->tableWidgetVarietes->currentRow(),3)->text());


    //J'active mes boutons des Variétés
    ui->pushButtonSupprimerVariete->setEnabled(true);
    ui->pushButtonSupprimerVariete->setStyleSheet("");
}


void MainWindow::on_tableWidgetProduits_cellClicked(int row, int column)
{
    QString requeteImageTxt;
    requeteImageTxt="SELECT imageProduit FROM Produit WHERE numeroProduit="+ui->tableWidgetProduits->item(ui->tableWidgetProduits->currentRow(),0)->text();
    QSqlQuery requeteImage(requeteImageTxt);
    requeteImage.next();


    ui->lineEditNomProduit->setText(ui->tableWidgetProduits->item(ui->tableWidgetProduits->currentRow(),1)->text());
    ui->plainTextEditInfosProduit->setPlainText(ui->tableWidgetProduits->item(ui->tableWidgetProduits->currentRow(),2)->text());
    ui->lineEditImageProduit->setText(requeteImage.value("imageProduit").toString());
    ui->doubleSpinBoxQuantiteProduit->setValue(ui->tableWidgetProduits->item(ui->tableWidgetProduits->currentRow(),4)->text().toDouble());
    ui->comboBoxVarieteDuProduit->setCurrentText(ui->tableWidgetProduits->item(ui->tableWidgetProduits->currentRow(),5)->text());

    //J'active mes boutons des Produits
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
    if(!ui->lineEditCheminImageRayon->text().isEmpty() && !ui->lineEditNomRayon->text().isEmpty()) {
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
    }else{
        ui->lineEditNomRayon->setStyleSheet("background: #f7c1c1;");
        ui->lineEditCheminImageRayon->setStyleSheet("background: #f7c1c1; min-width: 400px;");
        ui->statusBar->setStyleSheet("color: #eb3131; font-weight: 700;");
        ui->statusBar->showMessage("Remplissez les champs :)",3000);
    }

    remplirComboRayonDeVariete();
}





void MainWindow::on_pushButtonRechercheImage_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Selectionnez l'image"), "/home", tr("Image Files (*.jpeg .jpg .png)"));

    ui->lineEditCheminImageRayon->setText(fileName);

    ui->labelImage->setPixmap(QPixmap(fileName));

    //ui->labelImage->setProperty("sourceImage",fileName);
}


void MainWindow::on_pushButtonDesactiverProducteur_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonAjouterProducteur_clicked()";

    QString maRequeteDesactivationProducteur;
    maRequeteDesactivationProducteur = "UPDATE Producteur SET validiteProducteur=0 WHERE numeroProducteur="+ui->tableWidgetTousProducteurs->item(ui->tableWidgetTousProducteurs->currentRow(),0)->text();
    qDebug()<<maRequeteDesactivationProducteur;
    QSqlQuery maRequete(maRequeteDesactivationProducteur);

    //Reset du tableau
    ui->tableWidgetNonVerifies->clear();
    ui->tableWidgetNonVerifies->setRowCount(0);

    afficheTableauProducteur();
    afficheTableauProducteurVerifies();
}


void MainWindow::on_pushButtonSupprimerProducteur_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSupprimerProducteur_clicked()";

    QString maRequeteSupprimerProducteur;
    maRequeteSupprimerProducteur = "DELETE FROM Producteur WHERE numeroProducteur = "+ui->tableWidgetTousProducteurs->item(ui->tableWidgetTousProducteurs->currentRow(),0)->text();
    qDebug()<<maRequeteSupprimerProducteur;
    QSqlQuery maRequete(maRequeteSupprimerProducteur);

    //Reset du tableau
    ui->tableWidgetTousProducteurs->clear();
    ui->tableWidgetTousProducteurs->setRowCount(0);

    afficheTableauProducteur();
}


void MainWindow::on_pushButtonAjouterProduit_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonAjouterProduit_clicked()";

    if(!ui->lineEditNomProduit->text().isEmpty() && !ui->plainTextEditInfosProduit->toPlainText().isEmpty()) {
    //Récupération du plus grand id
    QSqlQuery max("SELECT IFNULL((SELECT MAX(numeroProduit)+1 FROM Produit),0)");
    max.next();
    maxProduit = max.value(0).toInt();

    //On écrit la requète Ajout de Produit
    QString requeteProduit;
    requeteProduit = "INSERT INTO Produit VALUES ("+QString::number(maxProduit)+",'"+ui->lineEditNomProduit->text()+"','"+ui->plainTextEditInfosProduit->toPlainText()+"','"+ui->lineEditImageProduit->text()+"',"+ui->doubleSpinBoxQuantiteProduit->text()+",'"+ui->comboBoxVarieteDuProduit->currentData().toString()+"')";
    QSqlQuery requeteInsertionProduit(requeteProduit);
    qDebug()<<requeteProduit;

    afficherTableauProduit();
    }
    else{
        ui->lineEditNomVariete->setStyleSheet("background: #f7c1c1; min-width: 200px;");
        ui->plainTextEditDescriptionVariete->setStyleSheet("background: #f7c1c1; max-height: 100px; min-width: 150px;");
        ui->statusBar->setStyleSheet("color: #eb3131; font-weight: 700;");
        ui->statusBar->showMessage("Remplissez les champs :)",3000);
    }

}


void MainWindow::on_pushButtonImageProduit_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Selectionner l'image du produit"), "", tr("Image Files (*.jpg .png .jpeg)"));

    ui->lineEditImageProduit->setText(fileName);
}



void MainWindow::on_pushButtonSupprimerProducteurNonVerif_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSupprimerProducteurNonVerif_clicked()";

    QString maRequeteSupprimerProducteur;
    maRequeteSupprimerProducteur = "DELETE FROM Producteur WHERE numeroProducteur = "+ui->tableWidgetNonVerifies->item(ui->tableWidgetNonVerifies->currentRow(),0)->text();
    qDebug()<<maRequeteSupprimerProducteur;
    QSqlQuery maRequete(maRequeteSupprimerProducteur);

    //Reset du tableau
    ui->tableWidgetNonVerifies->clear();
    ui->tableWidgetNonVerifies->setRowCount(0);

    afficheTableauProducteurVerifies();
}


void MainWindow::on_comboBoxTypeEmploye_currentTextChanged(const QString &arg1)
{
    qDebug()<<"void MainWindow::on_comboBoxTypeEmploye_currentTextChanged(const QString &arg1)";

    //création de la requête d'affichage pour le tableau
    QString maRequeteTableau;

    if(ui->comboBoxTypeEmploye->currentText() == "Tous les types"){
        maRequeteTableau = "SELECT numeroEmploye,loginEmploye,nomEmploye,prenomEmploye,villeEmploye,rueEmploye,codePostalEmploye,mailEmploye,telEmploye,TypeEmploye.numeroTypeEmploye,TypeEmploye.libelleTypeEmploye FROM Employe INNER JOIN TypeEmploye ON Employe.numeroTypeEmploye=TypeEmploye.numeroTypeEmploye";
    }else if(ui->comboBoxTypeEmploye->currentText() == "Modérateur"){
        maRequeteTableau = "SELECT numeroEmploye,loginEmploye,nomEmploye,prenomEmploye,villeEmploye,rueEmploye,codePostalEmploye,mailEmploye,telEmploye,TypeEmploye.numeroTypeEmploye,TypeEmploye.libelleTypeEmploye FROM Employe INNER JOIN TypeEmploye ON Employe.numeroTypeEmploye=TypeEmploye.numeroTypeEmploye WHERE TypeEmploye.numeroTypeEmploye=1";
    }else if(ui->comboBoxTypeEmploye->currentText() == "Administrateur"){
        maRequeteTableau = "SELECT numeroEmploye,loginEmploye,nomEmploye,prenomEmploye,villeEmploye,rueEmploye,codePostalEmploye,mailEmploye,telEmploye,TypeEmploye.numeroTypeEmploye,TypeEmploye.libelleTypeEmploye FROM Employe INNER JOIN TypeEmploye ON Employe.numeroTypeEmploye=TypeEmploye.numeroTypeEmploye WHERE TypeEmploye.numeroTypeEmploye=2";
    }else if(ui->comboBoxTypeEmploye->currentText() == "Super-Administrateur"){
        maRequeteTableau = "SELECT numeroEmploye,loginEmploye,nomEmploye,prenomEmploye,villeEmploye,rueEmploye,codePostalEmploye,mailEmploye,telEmploye,TypeEmploye.numeroTypeEmploye,TypeEmploye.libelleTypeEmploye FROM Employe INNER JOIN TypeEmploye ON Employe.numeroTypeEmploye=TypeEmploye.numeroTypeEmploye WHERE TypeEmploye.numeroTypeEmploye=3";
    }

    qDebug()<<maRequeteTableau;
    QSqlQuery maRequete(maRequeteTableau);

    //Reset du tableau
    ui->tableWidgetTousEmployes->clear();
    ui->tableWidgetTousEmployes->setRowCount(0);
    //Redimensionnement des colonnes en fonction de la taille du tableau
    ui->tableWidgetTousEmployes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //Ajout des entêtes du tableau
    QStringList ColumnProducteur;
    ColumnProducteur<<"Numéro"<<"Login"<<"Nom"<<"Prénom"<<"Adresse"<<"Ville"<<"Mail"<<"Téléphone"<<"Type";
    ui->tableWidgetTousEmployes->setHorizontalHeaderLabels(ColumnProducteur);

    int maLigne=0;

    //mise en place du tableau
    while (maRequete.next()) {
        ui->tableWidgetTousEmployes->insertRow(maLigne);
        ui->tableWidgetTousEmployes->setItem(maLigne, 0, new QTableWidgetItem(maRequete.value("numeroEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 1, new QTableWidgetItem(maRequete.value("loginEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 2, new QTableWidgetItem(maRequete.value("nomEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 3, new QTableWidgetItem(maRequete.value("prenomEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 4, new QTableWidgetItem(maRequete.value("rueEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 5, new QTableWidgetItem(maRequete.value("villeEmploye").toString()+" / "+maRequete.value("codePostalEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 6, new QTableWidgetItem(maRequete.value("mailEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 7, new QTableWidgetItem(maRequete.value("telEmploye").toString()));
        ui->tableWidgetTousEmployes->setItem(maLigne, 8, new QTableWidgetItem(maRequete.value("libelleTypeEmploye").toString()));

        //Centrage des cellules
        ui->tableWidgetTousEmployes->item(maLigne,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,4)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,5)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,6)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,7)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidgetTousEmployes->item(maLigne,8)->setTextAlignment(Qt::AlignCenter);

        maLigne++;
    }
}


void MainWindow::on_lineEditRechercheEmploye_textChanged(const QString &arg1)
{
    if(ui->lineEditRechercheEmploye->text().length()==0){
        ui->comboBoxEmploye->clear();
        ui->groupBoxInfosEmploye->setVisible(0);
    }else {
        ui->comboBoxEmploye->clear();

        //création de la requête d'affichage pour le tableau
        QString maRequeteTableauGestionEmploye;
        maRequeteTableauGestionEmploye="SELECT numeroEmploye,nomEmploye,prenomEmploye "
                                       "FROM Employe "
                                       "WHERE nomEmploye LIKE '"+ui->lineEditRechercheEmploye->text()+"%' "
                                       "OR prenomEmploye LIKE '"+ui->lineEditRechercheEmploye->text()+"%'";
        qDebug()<<maRequeteTableauGestionEmploye;
        QSqlQuery maRequete(maRequeteTableauGestionEmploye);

        while (maRequete.next())
        {
            ui->comboBoxEmploye->addItem(maRequete.value("nomEmploye").toString()+" "+maRequete.value("prenomEmploye").toString(),maRequete.value("numeroEmploye").toString());

            if(ui->comboBoxEmploye->currentText().length()!=0){
                ui->groupBoxInfosEmploye->setVisible(1);
            }
        }
    }
}



void MainWindow::on_comboBoxEmploye_currentTextChanged(const QString &arg1)
{
    ui->comboBoxChangerTypeUtilisateur->clear();

    QString maRequeteTableauGestionEmploye;
    maRequeteTableauGestionEmploye="SELECT Employe.numeroEmploye, Employe.loginEmploye, Employe.nomEmploye, Employe.prenomEmploye, Employe.villeEmploye, Employe.codePostalEmploye, Employe.rueEmploye, Employe.mailEmploye, Employe.telEmploye, TypeEmploye.numeroTypeEmploye, TypeEmploye.libelleTypeEmploye "
                                   "FROM Employe INNER JOIN TypeEmploye ON Employe.numeroTypeEmploye=TypeEmploye.numeroTypeEmploye "
                                   "WHERE numeroEmploye ="+ui->comboBoxEmploye->currentData().toString();
    qDebug()<<maRequeteTableauGestionEmploye;
    QSqlQuery maRequete(maRequeteTableauGestionEmploye);
    maRequete.next();

    ui->lineEditChangerLoginEmploye->setText(maRequete.value("loginEmploye").toString());
    ui->lineEditChangerNomEmploye->setText(maRequete.value("nomEmploye").toString());
    ui->lineEditChangerPrenomEmploye->setText(maRequete.value("prenomEmploye").toString());
    ui->lineEditChangerVilleEmploye->setText(maRequete.value("villeEmploye").toString());
    ui->lineEditChangerCPEmploye->setText(maRequete.value("codePostalEmploye").toString());
    ui->lineEditChangerRueEmploye->setText(maRequete.value("rueEmploye").toString());
    ui->lineEditChangerMailEmploye->setText(maRequete.value("mailEmploye").toString());
    ui->lineEditChangerTelEmploye->setText(maRequete.value("telEmploye").toString());

    //création de la requête d'affichage pour le tableau
    QString txtMaRequeteTypeEmploye;
    txtMaRequeteTypeEmploye="SELECT numeroTypeEmploye,libelleTypeEmploye "
                                   "FROM TypeEmploye";
    qDebug()<<txtMaRequeteTypeEmploye;
    QSqlQuery maRequeteTypeEmploye(txtMaRequeteTypeEmploye);

    while (maRequeteTypeEmploye.next())
    {
        ui->comboBoxChangerTypeUtilisateur->addItem(maRequeteTypeEmploye.value("libelleTypeEmploye").toString(),maRequete.value("numeroTypeEmploye").toString());
    }

    ui->comboBoxChangerTypeUtilisateur->setCurrentText(maRequete.value("libelleTypeEmploye").toString());


}


void MainWindow::on_pushButtonSupprimerEmploye_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSupprimerEmploye_clicked()";

    QString maRequeteSuppressionEmploye;
    maRequeteSuppressionEmploye = "DELETE FROM Employe WHERE numeroEmploye = "+ui->tableWidgetTousEmployes->item(ui->tableWidgetTousEmployes->currentRow(),0)->text();
    qDebug()<<maRequeteSuppressionEmploye;
    QSqlQuery maRequete(maRequeteSuppressionEmploye);

    afficherTableauEmployes();
}


void MainWindow::on_pushButtonModifierEmploye_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonModifierEmploye_clicked()";

    QString login,nom,prenom,ville,cp,rue,mail,tel,type;

    login=ui->lineEditChangerLoginEmploye->text();
    nom=ui->lineEditChangerNomEmploye->text();
    prenom=ui->lineEditChangerPrenomEmploye->text();
    ville=ui->lineEditChangerVilleEmploye->text();
    cp=ui->lineEditChangerCPEmploye->text();
    rue=ui->lineEditChangerRueEmploye->text();
    mail=ui->lineEditChangerMailEmploye->text();
    tel=ui->lineEditChangerTelEmploye->text();
    type=ui->comboBoxChangerTypeUtilisateur->currentData().toString();

    QString maRequeteModifierEmploye;
    maRequeteModifierEmploye = "UPDATE Employe SET loginEmploye="+login+", "
                               "nomEmploye="
                               "WHERE numeroEmploye=";

}

