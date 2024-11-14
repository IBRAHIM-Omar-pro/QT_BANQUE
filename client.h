#ifndef CLIENT_H
#define CLIENT_H

#include <QString>  // Assure-toi d'inclure cette bibliothèque pour utiliser QString

class Client
{
public:
    Client(QString CIN, QString nom, QString prenom, QString numero)
        : CIN(CIN), nom(nom), prenom(prenom), numero(numero) {}

    QString getCIN() const { return CIN; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    QString getNum() const { return numero; }

    void setNumero(QString newNumero) { numero = newNumero; }

private:
    QString CIN;
    QString nom;
    QString prenom;
    QString numero;
};

#endif // CLIENT_H
