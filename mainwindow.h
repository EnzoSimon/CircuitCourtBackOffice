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

    void on_pushButtonVerifierProducteur_clicked();

    void on_tableWidgetTousProducteurs_cellClicked(int row, int column);

    void on_pushButtonModifierProducteur_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
