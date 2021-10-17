#include "gestiontodo.h"

GestionToDo::GestionToDo()
{

}

void GestionToDo::addToDo(toDo & td)
{
    ltodo.push_back(td);
}

void GestionToDo::removeToDo(toDo & td)
{

    for (auto it: ltodo )
    {
        if(it == td)
        {
            I->deleteTodo(&it);
            ltodo.remove(it);
        }
    }
}

void GestionToDo::removeAllToDo()
{
    for (auto it : ltodo)
    {
        I->deleteTodo(&it);
    }
    ltodo.clear();
}

std::list<toDo> GestionToDo::getToDoList() const
{
    return ltodo;
}

unsigned int GestionToDo::getSize() const{return ltodo.size();}
void GestionToDo::setInterface(Interface * I){this->I=I;}

static GestionToDo creerGestionToDo(Interface * interface)
{
    GestionToDo td;
    td.setInterface(interface);
    return td;
}
