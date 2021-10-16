#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H
#include "contact.h"
#include "interface.h"

class GestionContact
{
public:
    GestionContact();
    void ajoutContact(Contact);
    Interface * getInterface();

private :
    list<Contact> lcontact;
    Interface* I;
};

#endif // GESTIONCONTACT_H
