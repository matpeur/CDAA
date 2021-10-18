#ifndef INTERACTION_H
#define INTERACTION_H

#include<string>
#include <ctime>
#include "todo.h"
#include "gestiontodo.h"
class Contact;
class Interface;


class Interaction
{

public:
    Interaction();

    Interaction(Interface *, Contact *,std::string);

    std::string getContenu() const;
    Date getDate() const;
    Contact* getContact() const;
    void setContact(Contact* const);
    void setInterface(Interface * );
    bool operator==(Interaction  );
    //static Interface creerInteraction();

private:
    Date date;
    std::string contenu;

    Contact * contact;
    GestionToDo gTD;

    void setDate(Date *);
    void setContenu(std::string &);

    void addToDo(toDo &);
    void removeToDo(toDo &);

};

#endif // INTERACTION_H
