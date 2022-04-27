#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString nom,QString prenom,QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void afficheTableauProducteur();
    void afficheTableauProducteurVerifies();
    void afficheTableauRayons();
    void afficherTableauVariete();
    void afficherTableauProduit();
    void afficherTableauEmployes();
    void remplirComboRayonDeVariete();
    void remplirComboVarieteDeProduit();


    void on_pushButtonVerifierProducteur_clicked();

    void on_tableWidgetTousProducteurs_cellClicked(int row, int column);

    void on_pushButtonModifierProducteur_clicked();

    void on_tableWidgetNonVerifies_cellClicked(int row, int column);

    void on_tableWidgetRayons_cellClicked(int row, int column);

    void on_pushButtonSupprimerRayon_clicked();

    void on_tableWidgetVarietes_cellClicked(int row, int column);

    void on_tableWidgetProduits_cellClicked(int row, int column);

    void on_pushButtonChangerCompte_clicked();

    void on_pushButtonAjouterRayon_clicked();

    void on_pushButtonAjouterVariete_clicked();

    void on_pushButtonSupprimerVariete_clicked();

    void on_pushButtonRechercheImage_clicked();

    void on_pushButtonSupprimerProducteur_clicked();

    void on_pushButtonAjouterProduit_clicked();

    void on_pushButtonImageProduit_clicked();

    void on_pushButtonDesactiverProducteur_clicked();

    void on_pushButtonSupprimerProducteurNonVerif_clicked();

    void on_comboBoxTypeEmploye_currentTextChanged(const QString &arg1);

    void on_lineEditRechercheEmploye_textChanged(const QString &arg1);


    void on_comboBoxEmploye_currentTextChanged(const QString &arg1);

    void on_pushButtonSupprimerEmploye_clicked();

    void on_pushButtonModifierEmploye_clicked();

private:
    Ui::MainWindow *ui;

    int maxRayon, maxVariete, maxProduit, maxProducteur;
};

#endif // MAINWINDOW_H
