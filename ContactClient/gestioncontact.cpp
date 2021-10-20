#include "gestioncontact.h"

GestionContact::GestionContact()
{
    I = new Interface();
}

GestionContact::~GestionContact()
{

    delete I;
}

void GestionContact::addContact( string nom, string prenom,string entreprise,string tel,string cheminPhoto)
{
    Contact c(I, nom, prenom, entreprise, tel, cheminPhoto);
    lcontact.push_back(c);
}

void GestionContact::removeContact(Contact Inter)
{

    for (auto &it : lcontact  )
    {
        if(it == Inter)
        {
            I->deleteContact(&it);
            lcontact.remove(it);
        }
    }
    Date * d = new Date;
    derniereSuppression = * d;
    delete d;
}

std::list<Contact> GestionContact::getContactList() const {return lcontact;}
unsigned int GestionContact::getSize() const {return lcontact.size();}

