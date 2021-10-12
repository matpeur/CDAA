
#ifndef CONTACT_H
#define CONTACT_H
#include <QObject>
#include <ctime>
#include "interaction.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;
class Contact
{
public:
    explicit Contact();
    void addinterraction(Interaction i);
    void removeinterracion(Interaction i);
    friend  ostream & operator << (std :: ostream & os, const Contact Conct );
    void setNom(string n) ;
    void setPreNom(string n) ;
    void setentrprise(string e) ;
    void settelephoen(string tel);
    void setPhoto(string photo) ;
    void setDate(date t) ;
    string getNom() ;
    string getPrenom();
    string getEntreprise();
    string gettelephone() ;
    string getPhoto() ;

private:
      string nom;
      string prenom;
      string entreprise;
      string telephone;
      string Photo;
      date d;
      list<Interaction>  Listesinterractions;
      String dernieredate;
signals:
};
#endif // CONTACT_H

