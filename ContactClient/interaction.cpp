#include "interaction.h"
//constructeurs
Interaction::Interaction()
{

}

Interaction::Interaction(Interface* inter,Contact * c,std::string contenu)
{
    setContact(c);
    setInterface(inter);
    this->setContenu(contenu);
}

//accesseurs
void Interaction::setContenu(std::string  & cont)
{
    this->contenu = "";
    gTD.removeAllToDo();
    std::string buffer = cont;
    while (cont.size()!=0)
    {
        unsigned long indice = buffer.find("@todo");
        contenu+=buffer.substr(0, indice); //on recupère le contenu sans tag @todo
        //on traite le @todo
        buffer = buffer.substr(indice);
        indice = buffer.find("\n");
        std::string s = buffer.substr(0,indice);
        toDo t (this, s);
        addToDo(t);
        buffer = buffer.substr(indice);
    }
    setDate(new Date());
}

std::string Interaction::getContenu() const{return this->contenu;}
void Interaction::setDate(Date * d ){this->date = *d; delete d;}
Date Interaction::getDate() const {return this->date;}
void Interaction::setContact(Contact* const C){this->contact = C;}
Contact* Interaction::getContact() const{return this->contact;}

void Interaction::setInterface(Interface * I)
{
    GestionToDo td(I);
    gTD = td;
}

void Interaction::addToDo(toDo & td){gTD.addToDo(td);}
void Interaction::removeToDo(toDo & td){ gTD.removeToDo(td);}

bool Interaction::operator==(Interaction test){return this->getContact()== test.getContact() && this->getContenu()== test.getContenu() && this->getDate() == test.getDate();}
/*
static Interaction creerInteraction( std::string & contenu)
{
    Interaction i(contenu);
    i.setContact(c);
    i.setInterface(inter);
    return i;
}

*/
