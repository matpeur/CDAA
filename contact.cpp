#include "contact.h"
#include <iostream>
using namespace std;
Contact::Contact(){}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2011
 * @brief implémentation du constructeur à parametre
 */
Contact::Contact(Interface * interface, string nom, string prenom,string entreprise,string tel,string cheminPhoto,string dateCreation,string mail)
{
    setInterface(interface);
    setNom(nom);
    setPrenom(prenom);
    setEntrprise(entreprise);
    setTelephone(tel);
    setPhoto(cheminPhoto);
    setMail(mail);
    setDate(dateCreation);
    this->id=1;
}
/**
 * @author BELLEGUEULLE TRAORE
 * @date octobre 2021
 * @brief constructeur pour initialiser l'instance
 */
Contact::Contact(Interface * interface, string nom, string prenom,string entreprise,string tel,string cheminPhoto, string mail)
{
    setInterface(interface);
    setNom(nom);
    setPrenom(prenom);
    setEntrprise(entreprise);
    setTelephone(tel);
    setPhoto(cheminPhoto);
    Date d;
    setDate(d.getDateToString());
    setMail(mail);
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode addInterraction
 */
void Contact::createInteraction(std::string contenu)
{
    gI.createInteraction(this, contenu);
}
/**
  *@author BELLEGUEULLE TRAORE
  *@date octobre 2021
 * @brief Ajoute une interaction déjà créer dans la liste de gestion Interaction
 * @param inter un interaction déjà créé à ajouter dans la liste
 */
void Contact::addInteraction(Interaction inter)
{
    gI.addInteraction(inter);
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode removeInterraction
 */
void Contact::removeInteraction(Interaction & i)
{
    gI.removeInteraction(i);
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2011
 * @brief implémentation des accesseurs
 */
void Contact::setMail(string mail1){this->mail=mail1;}
void   Contact:: setNom(std::string n)
{
    this->createInteraction("Changement de nom : De "+ nom + " à "+n);
    this -> nom=n;
}
void   Contact::setPrenom(std::string n)
{
    this->createInteraction("Changement de prénom : De "+ prenom + " à "+n);
    this -> prenom=n;
}
void   Contact:: setEntrprise(std::string e)
{
    this->createInteraction("Changement de nom d'entreprise : De "+ entreprise + " à "+e);
    this ->entreprise=e;
}
void   Contact:: setTelephone(std::string tel)
{
    this->createInteraction("Changement de numéro de téléphone : De "+ telephone + " à "+ tel);
    this ->telephone=tel;
}
void   Contact:: setPhoto(std::string photo)
{
    this->createInteraction("Changement du chemin de la photo : De "+ Photo + " à "+ photo);
    this->Photo=photo;
}
void   Contact:: setDate(std::string t){this->dateCreation=t;}
void   Contact:: setInterface(Interface * I)
{
    GestionInteraction Inter(I);
    gI = Inter;
}
void Contact::setId(int k){this->id=k;}
int Contact::getId(){return this->id;}
string Contact:: getNom() const {return this->nom;}
string Contact::getPrenom() const { return this->prenom;}
string Contact:: getEntreprise() const {return this->entreprise;}
string Contact::getTelephone() const { return this->telephone;}
string Contact::getPhoto() const { return this->Photo;}
string Contact::getDate() const{return dateCreation;}
string Contact::getMail() const{return this->mail;}
GestionInteraction Contact::getGestionInteraction() const{return gI;}

/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2011
 * @brief implémentation de la methode de surcharge de l'operateur <<
 */
std::ostream& operator<<(std::ostream & os, const Contact C )
{

  os << C.getPrenom()<<", "<<C.getNom()<<", "<<C.getEntreprise()<<", "<<C.getPhoto()<<", "<<C.getDate()<<", "<<C.getTelephone()<<", ";
  return os ;
}

/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2011
 * @brief implémentation de la methode de surchage de l'egalité =
 */
bool Contact::operator==(Contact test)
{
    return this->getNom() == test.getNom() && this->getPrenom() == test.getPrenom()
           && this-> getEntreprise() == test.getEntreprise() && this->getTelephone() == test.getTelephone()
           && this->getDate() == test.getDate() && this->getPhoto() == test.getPhoto();
}
