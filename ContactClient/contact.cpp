#include "contact.h"
#include <iostream>
using namespace std;
Contact::Contact(){}
Contact::Contact(string nom,string prenom,string entreprise,string tel,string cheminPhoto)
{
    setNom(nom);
    setPrenom(prenom);
    setEntrprise(entreprise);
    setTelephone(tel);
    setPhoto(cheminPhoto);
    Date d;
    setDate(d);
}
void Contact::addInteraction(Interaction & i)
{
    gI.addInteraction(i);
}

void Contact::removeInteraction(Interaction & i)
{
    gI.removeInteraction(i);
}

void   Contact:: setNom(std::string n){this -> nom=n;}
void   Contact::setPrenom(std::string n){this -> prenom=n;}
void   Contact:: setEntrprise(std::string e){this ->entreprise=e;}
void   Contact:: setTelephone(std::string tel){this ->telephone=tel;}
void   Contact:: setPhoto(std::string photo){this->Photo=photo;}
void   Contact:: setDate(Date t){this->d=t;}
void   Contact:: setInterface(Interface * I){gI = GestionInteraction::creerGestionInteraction(I);}
string Contact:: getNom(){return this->nom;}
string Contact::getPrenom(){ return this->prenom;}
string Contact:: getEntreprise(){return this->entreprise;}
string Contact::getTelephone(){ return this->telephone;}
string Contact::getPhoto(){ return this->Photo;}
Date Contact::getDate(){return d;}

/*
friend Contact::ostream & operator<< (ostream & os, const Contact C )
{

  os << C.getPrenom()<<", "<<C.getNom()<<", "<<C.getEntreprise()<<", "<<C.getPhoto()<<", "<<C.getDate()<<", "<<C.getTelephone()<<", "<<;
 return os ;
}
*/
bool Contact::operator==(Contact test)
{
    return this->getNom() == test.getNom() && this->getPrenom() == test.getPrenom()
           && this-> getEntreprise() == test.getEntreprise() && this->getTelephone() == test.getTelephone()
           && this->getDate() == test.getDate() && this->getPhoto() == test.getPhoto();
}

static Contact creerContact(Interface * interface, string nom, string prenom, string entreprise, string tel, string cheminPhoto)
{
    Contact C(nom, prenom, entreprise, tel, cheminPhoto);
    C.setInterface(interface);
    return C;
}
