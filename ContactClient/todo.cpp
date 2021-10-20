#include "todo.h"
#include <iostream>

toDo::toDo(){}
toDo::toDo(Interaction * O, std::string & contenu)
{
    setOwner(O);
    unsigned long long const indice  = contenu.find("@date");
    if (indice != std::string::npos)
    {
        setContenu(contenu.substr(5,indice-5));
        Date d(contenu.substr(indice+5));
        setDate(&d);
    }
    else
    {
        setContenu(contenu.substr(5));
        Date d;
        setDate(&d);
    }
    std::cout<<toString()<<std::endl;
}

void toDo::setContenu(std::string const c) {contenu = c;}
void toDo::setDate(Date* d) {date= *d;}
void toDo::setOwner(Interaction * I) {owner = I;}

std::string toDo::getContenu() const{return contenu;}
Date toDo::getDate() const{return date;}
Interaction * toDo::getOwner() const{return owner;}

bool toDo::operator==(toDo td){return this->contenu==td.getContenu()&&this->date==td.getDate();}


std::string toDo::toString()
{
    std::string result ="";
    std::cout<<getDate().getDate()->tm_mday<<std::endl;
    result = "@todo" + getContenu() + " @date " + getDate().getDateToString();
    return result;
}

