#include "contact.h"
#include <iostream>
using namespace std;
Contact::Contact(){}

Contact::Contact(Interface * interface, string nom, string prenom,string entreprise,string tel,string cheminPhoto)
{
    setInterface(interface);
    setNom(nom);
    setPrenom(prenom);
    setEntrprise(entreprise);
    setTelephone(tel);
    setPhoto(cheminPhoto);
    Date d;
    setDate(d);
}
void Contact::addInteraction(std::string contenu)
{
    gI.addInteraction(this, contenu);
}

void Contact::removeInteraction(Interaction & i)
{
    gI.removeInteraction(i);
}

void   Contact:: setNom(std::string n)
{
    this->addInteraction("Changement de nom : De "+ nom + " à "+n);
    this -> nom=n;
}
void   Contact::setPrenom(std::string n)
{
    this->addInteraction("Changement de prénom : De "+ prenom + " à "+n);
    this -> prenom=n;
}
void   Contact:: setEntrprise(std::string e)
{
    this->addInteraction("Changement de nom d'entreprise : De "+ entreprise + " à "+e);
    this ->entreprise=e;
}
void   Contact:: setTelephone(std::string tel)
{
    this->addInteraction("Changement de numéro de téléphone : De "+ telephone + " à "+ tel);
    this ->telephone=tel;
}
void   Contact:: setPhoto(std::string photo)
{
    this->addInteraction("Changement du chemin de la photo : De "+ Photo + " à "+ photo);
    this->Photo=photo;
}
void   Contact:: setDate(Date t){this->d=t;}
void   Contact:: setInterface(Interface * I)
{
    GestionInteraction Inter(I);
    gI = Inter;
}
string Contact:: getNom() const {return this->nom;}
string Contact::getPrenom() const { return this->prenom;}
string Contact:: getEntreprise() const {return this->entreprise;}
string Contact::getTelephone() const { return this->telephone;}
string Contact::getPhoto() const { return this->Photo;}
Date Contact::getDate() const{return d;}
GestionInteraction Contact::getGestionInteraction() const{return gI;}


std::ostream& operator<<(std::ostream & os, const Contact C )
{

  os << C.getPrenom()<<", "<<C.getNom()<<", "<<C.getEntreprise()<<", "<<C.getPhoto()<<", "<<C.getDate().getDateToString()<<", "<<C.getTelephone()<<", ";
  return os ;
}


bool Contact::operator==(Contact test)
{
    return this->getNom() == test.getNom() && this->getPrenom() == test.getPrenom()
           && this-> getEntreprise() == test.getEntreprise() && this->getTelephone() == test.getTelephone()
           && this->getDate() == test.getDate() && this->getPhoto() == test.getPhoto();
}
