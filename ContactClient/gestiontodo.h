#ifndef GESTIONTODO_H
#define GESTIONTODO_H
#include "todo.h"
#include "interface.h"

class GestionToDo
{
public:
    GestionToDo();

    void addToDo(toDo);
    void removeToDo(toDo);
    void removeAllToDo();

    void setInterface(Interface *);

    std::list<toDo> getToDoList() const;
    unsigned int getSize() const;

    static toDo creerGestionToDo(Interface*);
private :

    std::list<toDo> ltodo;
    Interface * I;

};

#endif // GESTIONTODO_H
