#include "client.h"

Client::Client(QString CIN, QString nom, QString prenom, QString numero)
    : CIN(CIN), nom(nom), prenom(prenom), numero(numero) {}

QString Client::getCIN() const {
    return CIN;
}

QString Client::getNom() const {
    return nom;
}

QString Client::getPrenom() const {
    return prenom;
}

QString Client::getNumero() const {
    return numero;
}

void Client::setNumero(const QString& nouveauNumero) {
    numero = nouveauNumero;
}
