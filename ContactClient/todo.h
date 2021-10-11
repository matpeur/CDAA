#ifndef TODO_H
#define TODO_H

#include <string>
#include "date.h"
#include "interaction.h"

class toDo
{

public:
    toDo(Interaction*, std::string);

    std::string getContenu() const;


private :
    Interaction * owner;
    std::string contenu;
    Date date;
    void setContenu(std::string const);
    void setDate(Date* const);
    void setOwner(Interaction *const);


};

#endif // TODO_H
