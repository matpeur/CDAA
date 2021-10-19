#include "gestiontodo.h"
GestionToDo::GestionToDo(){}
GestionToDo::GestionToDo(Interface * interface)
{
    setInterface(interface);
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


