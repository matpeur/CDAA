#ifndef GESTIONTODO_H
#define GESTIONTODO_H
#include "todo.h"
#include "interface.h"

class GestionToDo
{
public:
    GestionToDo(Interface *);
    GestionToDo();

    void addToDo(toDo);
    void removeToDo(toDo);
    void removeAllToDo();

    toDo * getToDo(unsigned int) const;
    unsigned int getSize() const;
private :
    std::list<toDo> ltodo;
    Interface * I;

};

#endif // GESTIONTODO_H
