#include "contact.h"
#include <iostream>
using namespace std;
Contact::Contact()
{

}
void Contact::addinterraction(const Interaction &i);
{

 Listesinterractions.push_back(i);
 this->dernieredate=ths->d->tm;
}

void Contact::removeinterracion(Interaction i)
{

    auto it=Listesinterractions.begin();
    bool found=false;
    while(it != Listesinterractions.end() && (found==false))
    {

       if(it == i)
       {
           found =true;
           it=Listesinterractions.erase(it);
            this->dernieredate=this->d->getDateToString();
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
void   Contact:: setDate(date t){this->d=t;}
string Contact:: getNom(){return this->nom;}
string Contact::getPrenom(){ return this->prenom;}
string Contact:: getEntreprise(){return this->entreprise;}
string Contact::gettelephone(){ return this->telephone;}
string Contact::getPhoto(){ return this->Photo;}


friend Contact::ostream & operator << (ostream & os, const Contact C )
{

  os << C.getPrenom()<<",␣"<<C.getNom()<<",␣"<<C.getEntreprise()<<",␣"<<C.getPhoto()<<",␣"<<C.getDate()<<",␣"<<C.gettelephone()<<",␣"<<;
 return os ;


}

