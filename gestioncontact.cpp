#include "gestioncontact.h"
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation du consructeur par defaut
 */
GestionContact::GestionContact()
{
    I = new Interface();
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation du destructeur
 */
GestionContact::~GestionContact()
{
    delete I;
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode addContact */
void GestionContact::createContact( string nom, string prenom,string entreprise,string tel,string cheminPhoto,string mail,string date)
{
    Contact c(I, nom, prenom, entreprise, tel, cheminPhoto,mail,date);
    lcontact.push_back(c);
}
/**
  *
  */
void GestionContact::addContact(Contact c)
{
    lcontact.push_back(c);

}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode removeContact
 */
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


 Contact GestionContact::get( int t)
{
      auto it=lcontact.begin();
        for (int i=0;i<t;i++)
        {
             ++it;
        }
        return  *it ;


}


std::list<Contact> GestionContact::getContactList() const {return lcontact;}
unsigned int GestionContact::getSize() const {return lcontact.size();}
