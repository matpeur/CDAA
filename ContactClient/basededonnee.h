#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
class gestioncontact;
class Contact;
class todo;
class interaction;
class Basededonnee
{
public:
    Basededonnee();
    void Connexion();
    void AjoutContact(Contact);
    void SupprimeContact(Contact);
    void ModifiContact(Contact,Contact);
    void getAllContact(std::list<Contact>);
    std::list<Contact> cherchercontact(std::string,std::string);
    std::list<todo>* cherchelistetodo(std::string,std::string);
    std::list<interaction>* chercheinterraction(std::string,std::string);
    int Nombredecontact();
private:
    QSqlDatabase b;

};
#endif // BASEDEDONNEE_H
