#ifndef TODO_H
#define TODO_H

#include <string>
#include <ostream>
#include "date.h"
class Interaction;
class Interface;

class toDo
{

public:

    toDo(Interaction*,std::string &);
    toDo();

    std::string getContenu() const;
    Date getDate() const;
    Interaction * getOwner() const;

    void setOwner(Interaction *);

    bool operator==(toDo );

    std::string toString();

private :

    Interaction * owner;
    std::string contenu;
    Date date;

    void setContenu(std::string const);
    void setDate(Date* const);



};

#endif // TODO_H
