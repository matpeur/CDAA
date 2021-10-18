
#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>
#include "interaction.h"
#include "gestioninteraction.h"

using namespace std;
class Contact
{
public:
    Contact();

    Contact(string,string,string,string,string);
    void addInteraction(Interaction & i);
    void removeInteraction(Interaction & i);
    friend  ostream & operator<< (std :: ostream & os, const Contact Conct );
    void setNom(string n) ;
    void setPrenom(string n) ;
    void setEntrprise(string e) ;
    void setTelephone(string tel);
    void setPhoto(string photo) ;
    void setDate(Date t) ;
    void setInterface(Interface *);
    string getNom() ;
    string getPrenom();
    string getEntreprise();
    string getTelephone() ;
    string getPhoto() ;
    Date getDate();
    bool operator==(Contact);

    static Contact creerContact(Interface *, string,string,string,string,string);


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

