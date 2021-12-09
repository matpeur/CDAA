#include "todo.h"
#include <iostream>
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation des constructeurs*/
toDo::toDo(){setID(0);}
toDo::toDo(Interaction * O, std::string  & contenu)
{   setID(0);
    setOwner(O);
    unsigned long long const indice  = contenu.find("@date");
    if (indice != std::string::npos)
    {
        setContenu(contenu.substr(5,indice-5));
        Date d(contenu.substr(indice+5));
        setDate(d.getDateToString());
    }
    else
    {
        setContenu(contenu.substr(5));
        Date d;
        setDate(d.getDateToString());
    }
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation des accesseurs */

void toDo::setContenu(std::string const c) {contenu = c;}
//dans cette methode on stock directement la valeur en string de la nouvelle date
//comme ça on ne risque pas de perte d'information(probleme qu'on a eu à confronté)
void toDo::setDate(std::string d) {date= d;}
void toDo::setOwner(Interaction * I) {owner = I;}

std::string toDo::getContenu() const{return contenu;}
std::string toDo::getDate() const{return datestring;}
Interaction * toDo::getOwner() const{return owner;}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de l'operateur de surcharge == et*/
bool toDo::operator==(toDo td){return this->contenu==td.getContenu()&&this->date==td.getDate();}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode tostring pour l'affichage*/

std::string toDo::toString()
{
    std::string result ="";
    //std::cout<<getDate().getDate()->tm_mday<<std::endl;
    result = "@todo" + getContenu() + " @date " + getDate();//.getDateToString();
    return result;
}


void toDo:: setID(int i){this->id=i;}
int toDo:: getID(){return this->id;}



