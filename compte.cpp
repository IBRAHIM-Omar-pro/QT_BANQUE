#include "compte.h"

Compte::Compte(QString CIN, double solde, QString rib)
    : CIN(CIN), solde(solde), rib(rib) {}

double Compte::getSolde() const {
    return solde;
}

QString Compte::getRib() const {
    return rib;
}

void Compte::credit(double montant) {
    solde += montant;
}

void Compte::debit(double montant) {
    if (solde >= montant) {
        solde -= montant;
    } else {
        // Si le solde est insuffisant, on affiche un message d'erreur
    }
}

void Compte::virement(Compte &autreCompte, double montant) {
    if (solde >= montant) {
        debit(montant);
        autreCompte.credit(montant);
    } else {
        // Si le solde est insuffisant pour effectuer un virement
    }
}

QString Compte::afficherInfoCompte() const {
    return QString("Solde: %1\nRIB: %2").arg(solde).arg(rib);
}
