#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QDate>
class toDo;
class Interaction;
class Contact;
#include "gestioncontact.h"//class   GestionContact ;
class Basededonnee
{
public:
    Basededonnee();
    void Connexion();
    void AjoutContact(Contact *);
    void AjoutInter(Interaction *);
    void SupprimeContact(Contact*);
    void ModifiContact(Contact*);
    void getAllContact();
    std::list<Contact*>  recherchercontactparDates(std::string ,std::string );
    std::list<Contact*>recherchercontactparNom(std::string );
    std::list<Contact*> recherchecontact(std::string ,std::string ,std::string ,bool,bool);
    std::list<toDo*> recherchelistetodopardate(std::string ,std::string );
    std::list<toDo*> recherchelistetodopaContact(int idCONTACT);
    std::list<toDo*> recherchelistetodo(std::string ,std::string ,int  idCONTACT,bool,bool);
    std::list<Interaction*> recherchelisteinterractionpardate(std::string ,std::string );
    std::list<Interaction*> recherchelisteinterractionparContact(int idCONTACT);
    std::list<Interaction*> rechercheInterraction(std::string ,std::string ,int idCONTACT,bool,bool);
    Interaction getInterractionByID(int,int);
    toDo gettoDOByContact(int,int);
    int  Nombredecontact();
    void setIDContact(int i);
    int getIDContact();
    void setIDInteraction(int i);
    int getIDInteraction();
    void setIDTodo(int i);
    int getIDTodo();
    void sauvegarder();
     GestionContact gc;
private:
    QSqlDatabase b;
    int idContact;
    int idInteraction;
    int idTodo;

};
#endif // BASEDEDONNEE_H
