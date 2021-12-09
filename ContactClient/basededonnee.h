#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
class toDo;
class Interaction;
class Contact;
#include "gestioncontact.h"//class   GestionContact ;
class Basededonnee
{
public:
    Basededonnee();
    void Connexion();
    void AjoutContact(Contact);
    void SupprimeContact(Contact);
    void ModifiContact(Contact,Contact);
    GestionContact getAllContact();
    GestionContact  cherchercontactparDates(std::string,std::string);
    Contact cherchercontactparNom(std::string);
    std::list<toDo> cherchelistetodo(std::string,std::string);
    std::list<Interaction> chercheinterraction(std::string,std::string);
    Interaction getInterractionByID(int,int);
    toDo gettoDOByContact(int,int);
    int  Nombredecontact();
    void setIDContact(int i);
    int getIDContact();
    void setIDInteraction(int i);
    int getIDInteraction();
    void setIDTodo(int i);
    int getIDTodo();

private:
    QSqlDatabase b;
    int idContact;
    int idInteraction;
    int idTodo;
};
#endif // BASEDEDONNEE_H
