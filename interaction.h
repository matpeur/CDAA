#ifndef INTERACTION_H
#define INTERACTION_H

#include<string>
#include <ostream>
#include "todo.h"
#include "gestiontodo.h"
#include <string>
class Contact;
class Interface;
/**
 * @brief The Interaction class
 */

class Interaction
{

public:
    Interaction();

    Interaction(Interface *, Contact *,std::string);

    std::string getContenu() const;
    std::string getDate() const;
    Contact* getContact() const;
    GestionToDo getGestionToDo() const;
    void setContact(Contact* const);
    void setInterface(Interface * );
    bool operator==(Interaction  );
    void addToDo(toDo &);
    friend std::ostream& operator<<(std::ostream &, const Interaction);

private:
    //Date date;
    std::string contenu;
    std::string datestring;
    Contact * contact;
    GestionToDo gTD;
    void setDate(Date *);
    void setContenu(std::string &);
    void removeToDo(toDo &);

};

#endif // INTERACTION_H
