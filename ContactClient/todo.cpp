#include "todo.h"

toDo::toDo(Interaction* i, std::string contenu)
{
    setOwner(i);
    unsigned long long const indice  = contenu.find("@date");
    if (indice != std::string::npos)
    {
        setContenu(contenu.substr(5,indice-5));
        setDate(date(contenu.substr(indice+5)));
    }
    else
    {
        setContenu(contenu.substr(5));
        this->date();
    }
}


