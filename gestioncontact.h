#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H
#include "contact.h"
#include "interface.h"
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

    void addContact(std::string,std::string,std::string,std::string,std::string);
    void removeContact(Contact);
    Interface * getInterface();
    std::list<Contact> getContactList() const;
    unsigned int getSize() const;

private :
    std::list<Contact> lcontact;
    Interface* I;
    Date derniereSuppression;

};

#endif // GESTIONCONTACT_H
