#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "compte.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    client("2", "BAIBBOUT", "ILYES", "0769099855"),
    compte("0001", 100.0, "FR76 3000 4028 3798 7654 3210 943")
{
    // Création des widgets manuellement
    QWidget *centralWidget = new QWidget(this);  // Création du widget central
    setCentralWidget(centralWidget);

    // Layout principal vertical
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Création des widgets
    txtInfo = new QTextEdit(this);  // Widget QTextEdit
    txtInfo->setObjectName("txtInfo");
    txtInfo->setReadOnly(true);  // Rendre le QTextEdit non modifiable
    layout->addWidget(txtInfo);

    // Création du bouton pour afficher les infos
    QPushButton *btnAfficherInfo = new QPushButton("Afficher Infos", this);
    layout->addWidget(btnAfficherInfo);

    // Création des champs pour créditer, débiter, et faire un virement
    QLabel *labelMontant = new QLabel("Montant:", this);
    layout->addWidget(labelMontant);

    spinBoxMontant = new QSpinBox(this);
    spinBoxMontant->setRange(0, 10000);  // Plage de valeurs pour le montant
    layout->addWidget(spinBoxMontant);

    // Création des boutons de crédit, débit et virement
    QPushButton *btnCredit = new QPushButton("Créditer", this);
    layout->addWidget(btnCredit);

    QPushButton *btnDebit = new QPushButton("Débiter", this);
    layout->addWidget(btnDebit);

    QPushButton *btnVirement = new QPushButton("Virement", this);
    layout->addWidget(btnVirement);

    // Création du champ pour modifier le numéro
    QLabel *labelNumero = new QLabel("Nouveau Numéro:", this);
    layout->addWidget(labelNumero);

    lineEditNumero = new QLineEdit(this);
    layout->addWidget(lineEditNumero);

    QPushButton *btnModifierNumero = new QPushButton("Modifier Numéro", this);
    layout->addWidget(btnModifierNumero);

    // Connexion des boutons aux actions
    connect(btnAfficherInfo, &QPushButton::clicked, this, &MainWindow::on_btnAfficherInfo_clicked);
    connect(btnCredit, &QPushButton::clicked, this, &MainWindow::on_btnCredit_clicked);
    connect(btnDebit, &QPushButton::clicked, this, &MainWindow::on_btnDebit_clicked);
    connect(btnVirement, &QPushButton::clicked, this, &MainWindow::on_btnVirement_clicked);
    connect(btnModifierNumero, &QPushButton::clicked, this, &MainWindow::on_btnModifierNumero_clicked);
}

MainWindow::~MainWindow()
{

}

void MainWindow::on_btnAfficherInfo_clicked()
{
    txtInfo->clear(); // Effacer les anciennes informations
    txtInfo->append("Nom: " + client.getNom());
    txtInfo->append("Prénom: " + client.getPrenom());
    txtInfo->append("CIN: " + client.getCIN());
    txtInfo->append("Numéro: " + client.getNum());
    txtInfo->append("RIB: " + compte.getRib());
    txtInfo->append("Solde: " + QString::number(compte.getSolde()) + "€");
}

void MainWindow::on_btnCredit_clicked()
{
    double montant = spinBoxMontant->value();
    compte.credit(montant);
    txtInfo->append("Crédité " + QString::number(montant) + "€");
    txtInfo->append("Nouveau solde: " + QString::number(compte.getSolde()));
}

void MainWindow::on_btnDebit_clicked()
{
    double montant = spinBoxMontant->value();
    compte.debit(montant);
    txtInfo->append("Débité " + QString::number(montant) + "€");
    txtInfo->append("Nouveau solde: " + QString::number(compte.getSolde()));
}

void MainWindow::on_btnVirement_clicked()
{
    double montant = spinBoxMontant->value();
    Compte autreCompte("0002", 150.0, "FR76 3000 4028 3798 7654 3210 944");
    compte.virement(autreCompte, montant);
    txtInfo->append("Virement de " + QString::number(montant) + "€ effectué.");
    txtInfo->append("Nouveau solde: " + QString::number(compte.getSolde()));
}

void MainWindow::on_btnModifierNumero_clicked()
{
    QString nouveauNumero = lineEditNumero->text();
    client.setNumero(nouveauNumero);
    txtInfo->append("Numéro modifié: " + client.getNum());
}
