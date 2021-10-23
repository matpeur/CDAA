
#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>
#include "interaction.h"
#include "gestioninteraction.h"
class Interface;
/**
 *@class Contact
 *@brief Classe Contact
 *nom,personne,mail,photo,entreprise en string
 *todo creer,ajouter et supprimer un conract et gerer ses interractions
*/

using namespace std;
class Contact
{
public:
    Contact();

    Contact(Interface *,string,string,string,string,string);
    void addInteraction(std::string);
    void removeInteraction(Interaction & i);
    friend  ostream & operator<< (std :: ostream & os, const Contact Conct );
    void setNom(string n) ;
    void setPrenom(string n) ;
    void setEntrprise(string e) ;
    void setTelephone(string tel);
    void setPhoto(string photo) ;
    void setDate(Date t) ;
    void setInterface(Interface *);
    string getNom() const;
    string getPrenom() const;
    string getEntreprise() const;
    string getTelephone() const;
    string getPhoto() const;
    Date getDate() const;
    GestionInteraction getGestionInteraction() const;
    bool operator==(Contact);


private:
      string nom;
      string prenom;
      string entreprise;
      string telephone;
      string Photo;
      Date d;
      GestionInteraction gI;

};
#endif // CONTACT_H

