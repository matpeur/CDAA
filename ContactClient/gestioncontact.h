#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H
#include "contact.h"
#include "interface.h"

class GestionContact
{
public:
    GestionContact();
    ~GestionContact();

    void addContact(Contact);
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
