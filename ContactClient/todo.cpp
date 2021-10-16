#include "todo.h"

toDo::toDo(Interaction* i, std::string contenu)
{
    setOwner(i);
    unsigned long long const indice  = contenu.find("@date");
    if (indice != std::string::npos)
    {
        setContenu(contenu.substr(5,indice-5));
        setDate(new Date(contenu.substr(indice+5)));
    }
    else
    {
        setContenu(contenu.substr(5));
        Date *d = new Date();
        setDate(d);
    }
}

void toDo::setContenu(std::string const c) {contenu = c;}
void toDo::setDate(Date* d) {date= *d;}
void toDo::setOwner(Interaction * I) {owner = I;}

std::string toDo::getContenu() const{return contenu;}
Date toDo::getDate() const{return date;}
Interaction * toDo::getOwner() const{return owner;}

bool toDo::operator==(toDo td){return this->contenu==td.getContenu()&&this->date==td.getDate();}

