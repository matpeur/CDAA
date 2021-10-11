#include "contact.h"

Contact::Contact(QObject *parent) : QObject(parent)
{

}
void Contact::addinterraction(const Interaction &i);
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

void   Contact:: setNom(std::string n){this -> nom=n;}
void   Contact::setPreNom(std::string n){this -> prenom=n;}
void   Contact:: setentrprise(std::string e){this ->entreprise=e;}
void   Contact:: settelephoen(std::string tel){this ->telephone=tel;}
void   Contact:: setPhoto(std::string photo){this->Photo=photo;}
void   Contact:: setDate(date t){this ->d=t;}
std::string Contact:: getNom(){return this ->nom;}
std::string Contact::getPrenom(){ return this ->prenom;}
std::string Contact:: getEntreprise(){return this ->entreprise;}
std::string Contact::gettelephone(){ return this ->telephone;}
std::string Contact::getPhoto(){ return this ->Photo;}
date   Contact:: getDate(){return this->date ;}

friend Contact::std::ostream & operator << (std :: ostream & os, const Contact C )
{

os << C.getPrenom()<<",␣"<<C.getNom()<<",␣"<<C.getEntreprise()<<",␣"<<C.getPhoto()<<",␣"<<C.getDate()<<",␣"<<C.gettelephone()<<",␣"<<;
 return os ;


}

