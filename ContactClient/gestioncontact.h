#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H
class Contact;//#include "contact.h"
#include "date.h"
#include "contact.h"
#include "interaction.h"
#include "todo.h"
/**
 *@class Contact
 @brief permet de gerer(ajouter,supprimer des
  contacts) une liste de contacts
 */
class GestionContact
{
public:
    GestionContact();
    ~GestionContact();
    void createContact(std::string,std::string,std::string,std::string,std::string,std::string,std::string);
    void createContact(std::string,std::string,std::string,std::string,std::string,std::string);
    void addContact(Contact c);
    void removeContact(Contact);

    std::list<Contact*> getContactList() const;
    unsigned int getSize() const;
    Contact* getContactByID(int i);
    Interaction* getInterractionByID(int id);
    toDo* gettoDoByID(int id);


private :
    std::list<Contact*> lcontact;
    Date derniereSuppression;

};

#endif // GESTIONCONTACT_H
