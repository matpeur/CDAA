#include "interaction.h"
//constructeurs
Interaction::Interaction()
{

}
Interaction::Interaction(Interface* I,Contact * c, std::string contenue)
{
    this->setContact(c);
    this->setContenu(contenue);
    time_t tn = time(0);
    setDate(new tm( *localtime (&tn)));
}

//accesseurs
void Interaction::setContenu(std::string const cont)
{
    this->contenu = "";
    std::string buffer = cont;
    while (cont.size()!=0)
    {
        int indice = buffer.find("@todo");
        contenu+=buffer.substr(0, indice); //on recupère le contenu sans tag @todo
        //on traite le @todo
        buffer = buffer.substr(indice);
        indice = buffer.find("\n");
        toDo t(this, buffer.substr(0,indice));
        addToDo(t);
        buffer = buffer.substr(indice);
    }
}

std::string Interaction::getContenu() const{return this->contenu;}
void Interaction::setDate(tm* const d ){this->date = d;}
tm Interaction::getDate() const {return *this->date;}
void Interaction::setContact(Contact* const C){this->contact = C;}
Contact* Interaction::getContact() const{return this->contact;}





void Interaction::addToDo(toDo const td){tags.push_back(td);}
void Interaction::removeToDo(toDo td)
{
    auto it=tags.begin();
    bool found=false;
    while(it != tags.end() && (found==false))
    {

       if(it == td)
       {
           found =true;
           it=tags.erase(it);
       }
       else
       {
           ++it;
       }
    }
}
