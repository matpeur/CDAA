#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
class GestionContact;
class Contact;
class toDo;
class Interaction;

class Basededonnee
{
public:
    Basededonnee();
    void Connexion();
    void AjoutContact(Contact);
    void SupprimeContact(Contact);
    void ModifiContact(Contact,Contact);
    std::list<Contact> getAllContact();
    std::list<Contact> cherchercontactparDates(std::string,std::string);
    Contact cherchercontactparNom(std::string);
    std::list<toDo> cherchelistetodo(std::string,std::string);
    std::list<Interaction> chercheinterraction(std::string,std::string);
    int  Nombredecontact();
    void setID(int i);
    int getID();
    GestionContact getStockecontact();
    GestionContact* g;

private:
    QSqlDatabase b;
    int identifiant;

};
#endif // BASEDEDONNEE_H
