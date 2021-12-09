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
    Contact recherchercontactparNom(std::string);
    std::list<toDo> recherchelistetodopardate(std::string,std::string);
    std::list<Interaction> recherchelisteinterractionpardate(std::string,std::string);
    Interaction getInterractionByID(int,int);
    toDo gettoDOByContact(int,int);
    int  Nombredecontact();
    void setIDContact(int i);
    int getIDContact();
    void setIDInteraction(int i);
    int getIDInteraction();
    void setIDTodo(int i);
    int getIDTodo();
   std::list<Interaction> rechercheInterraction(std::string,std::string,Contact,bool,bool);
   std::list<toDo> rechercheToDO(std::string,std::string,Interaction,bool,bool);

private:
    QSqlDatabase b;
    int idContact;
    int idInteraction;
    int idTodo;
};
#endif // BASEDEDONNEE_H
