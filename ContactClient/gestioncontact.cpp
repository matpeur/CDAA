#include "gestioncontact.h"
#include "contact.h"
#include <string>
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation du consructeur par defaut
 */
GestionContact::GestionContact()
{
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation du destructeur
 */
GestionContact::~GestionContact()
{
}
/**
 * @author BELLEGUELLE TRAORE
 * @date decembre 2021
 * @brief implémentation de la methode addContact */
void GestionContact::createContact(std:: string nom, std::string prenom,  std::string entreprise, std::string tel,  std::string cheminPhoto, std::string mail, std::string date)
{
    Contact *c = new Contact( nom, prenom, entreprise, tel, cheminPhoto,mail,date);
    lcontact.push_back(c);
}
/**
 * @author BELLEGUEULLE TRAORE
 * @date octobre 2021
 * @brief créer un contact à partir de ses attributs caractÃ©ristiques
 */
void GestionContact::createContact(std:: string nom, std::string prenom,  std::string entreprise, std::string tel,  std::string cheminPhoto, std::string mail)
{
    Contact *c = new Contact(nom, prenom, entreprise, tel, cheminPhoto, mail);
    lcontact.push_back(c);
}
/**
  *
  */
void GestionContact::addContact(Contact c)
{
    lcontact.push_back(&c);
    std::cout<<"fghjkl";
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
        if(*it == Inter)
        {
            //I->deleteContact(&it);
            lcontact.remove(it);
        }
    }
    Date * d = new Date;
    derniereSuppression = * d;
    delete d;
}


 Contact* GestionContact::getContactByID( int t)
{
      auto it=lcontact.begin();
        for (int i=0;i<t;i++)
        {
             ++it;
        }
        return  *it ;

}

Interaction* GestionContact::getInterractionByID(int id)
{
    Interaction* I = nullptr;
    for(auto &it :lcontact)
    {
       for(auto &itt : it->getGestionInteraction().getInteractionList())
       {
           if(itt->getID()==id)
               I= itt;

       }
}
          return I;
}


toDo* GestionContact::gettoDoByID(int id)
{        toDo* I;
      for(auto &it :lcontact)
      {
         for(auto &itt : it->getGestionInteraction().getInteractionList())
         {
           for(auto &ittt : itt->getGestionToDo().getToDoList())
            {
             if(ittt.getID()==id)
                  I= &(ittt);
            }
           }
         }
        return I;

   }

std::list<Contact*> GestionContact::getContactList() const {return lcontact;}
unsigned int GestionContact::getSize() const {return lcontact.size();}
