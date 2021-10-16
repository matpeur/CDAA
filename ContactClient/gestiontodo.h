#ifndef GESTIONTODO_H
#define GESTIONTODO_H
#include "todo.h"
#include "interface.h"

class GestionToDo
{
public:
    GestionToDo(Interface * interface);

    void addToDo(toDo td);
    void removeToDo(toDo td);
    void removeAllToDo();

private :
    std::list<toDo> ltodo;
    Interface * I;

};

#endif // GESTIONTODO_H
