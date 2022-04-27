#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <dialogconnexion.h>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Instanciation de la variable membre base_contact
    QSqlDatabase base = QSqlDatabase::addDatabase("QMYSQL");

    // Définition des paramètres de connexion à la base de données
    base.setHostName("localhost"); // @ip serveur MySQL
    base.setDatabaseName("db_circuitCourt"); // Nom de la base
    base.setUserName("admin"); // Nom utilisateur
    base.setPassword("admin"); // Mot de passe

    bool ok = base.open();
    qDebug()<<ok;

    DialogConnexion connexion;
    if(connexion.exec()==QDialog::Accepted)
    {
        QString nomEmploye,prenomEmploye;
        nomEmploye=connexion.getNom();
        prenomEmploye=connexion.getPrenom();

        MainWindow w(nomEmploye,prenomEmploye);
        w.show();
        return a.exec();
    }
    else{
        return 206;
    }
}
