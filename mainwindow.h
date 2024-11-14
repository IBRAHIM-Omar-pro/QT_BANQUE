#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QLabel>
#include "client.h"
#include "compte.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAfficherInfo_clicked();
    void on_btnCredit_clicked();
    void on_btnDebit_clicked();
    void on_btnVirement_clicked();
    void on_btnModifierNumero_clicked();

private:
    // Déclaration des widgets
    QTextEdit *txtInfo;          // Pour afficher les informations du client et du compte
    QLineEdit *lineEditNumero;   // Pour modifier le numéro de téléphone
    QSpinBox *spinBoxMontant;    // Pour entrer le montant à créditer/débiter
    Client client;               // Instance de la classe Client
    Compte compte;               // Instance de la classe Compte
};

#endif // MAINWINDOW_H
