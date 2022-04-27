#ifndef DIALOGCONNEXION_H
#define DIALOGCONNEXION_H

#include <QDialog>

namespace Ui {
class DialogConnexion;
}

class DialogConnexion : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConnexion(QWidget *parent = nullptr);
    ~DialogConnexion();
    QString getNom();
    QString getPrenom();


private slots:
    void on_pushButtonSeConnecter_clicked();

    void on_pushButtonAnnuler_clicked();
private:
    Ui::DialogConnexion *ui;
    QString login, mdp;
    QString nom,prenom;
    int compteurConnexions=0;
    int compteurConnexionsRestantes=2;
};

#endif // DIALOGCONNEXION_H
