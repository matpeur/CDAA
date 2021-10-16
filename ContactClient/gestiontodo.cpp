#include "gestiontodo.h"

GestionToDo::GestionToDo()
{

}

GestionToDo::GestionToDo(Interface * interface)
{
    I = interface;
}

void GestionToDo::addToDo(toDo td)
{
    ltodo.push_back(td);
}

void GestionToDo::removeToDo(toDo td)
{

    for (auto it : ltodo)
    {

    }
}
