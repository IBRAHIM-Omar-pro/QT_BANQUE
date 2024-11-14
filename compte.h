#ifndef COMPTE_H
#define COMPTE_H

#include <QString>
#include "client.h"

class Compte
{
private:
    QString CIN;
    double solde;
    QString rib;

public:
    Compte(QString CIN, double solde, QString rib);

    double getSolde() const;
    QString getRib() const;

    void credit(double montant);
    void debit(double montant);
    void virement(Compte &autreCompte, double montant);
    QString afficherInfoCompte() const;
};

#endif // COMPTE_H
