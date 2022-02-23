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

private slots:
    void on_pushButtonSeConnecter_clicked();

    void on_pushButtonAnnuler_clicked();

    QString login, mdp;

private:
    Ui::DialogConnexion *ui;
};

#endif // DIALOGCONNEXION_H
