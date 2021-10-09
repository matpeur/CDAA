#include "contact.h"

Contact::Contact(QObject *parent) : QObject(parent)
{

}
void Contact::addinterraction(cont interaction & i);
{

 Listesinterractions.push_back(i);

}

void Contact::removeinterracion(Interaction i)
{

    auto it=Listesinterractions.begin();
    bool found=false;
    while(it != Listesinterractions.end() && (found==false))
    {

       if(it == i)
       {
           found ==true;
           it=Listesinterractions.erase(it);
       }
       else
       {
           ++it;
       }


    }



}

void   Contact:: setNom(String n){this -> nom=n;}
void   Contact::setPreNom(String n){this -> prenom=n;}
void   Contact:: setentrprise(String e){this ->entreprise=e;}
void   Contact:: settelephoen(String tel){this ->telephone=tel;}
void   Contact:: setPhoto(String photo){this->Photo=photo;}
void   Contact:: setDate(date t){this ->d=t;}
String Contact:: getNom(){return this ->nom;}
String Contact::getPrenom(){ return this ->prenom;}
String Contact:: getEntreprise(){return this ->entreprise;}
String Contact::gettelephone(){ return this ->telephone;}
String Contact::getPhoto(){ return this ->Photo;}
date   Contact:: getDate(){return this->date ;}

friend Contact:: std :: ostream & operator < < (std :: ostream & os, const Contact C )
{

os << C.getPrenom()<<",␣"<<C.getNom()<<",␣"<<C.getEntreprise()<<",␣"<<C.getPhoto()<<",␣"<<C.getDate()<<",␣"<<C.gettelephone()<<",␣"<<;
 return os ;


}

