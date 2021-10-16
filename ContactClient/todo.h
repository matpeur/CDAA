#ifndef TODO_H
#define TODO_H

#include <string>
#include "date.h"
#include "interaction.h"

class toDo
{

public:

    toDo(Interaction *, std::string);
    toDo();

    std::string getContenu() const;
    Date getDate() const;
    Interaction * getOwner() const;
    bool operator==(toDo);

private :
    Interaction * owner;
    std::string contenu;
    Date date;
    void setContenu(std::string const);
    void setDate(Date* const);
    void setOwner(Interaction *const);


};

#endif // TODO_H
