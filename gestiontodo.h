#ifndef GESTIONTODO_H
#define GESTIONTODO_H
#include "todo.h"
#include <list>
#include "interface.h"
/**
 *@class gestiontodo
 *@brief Classe gestiontodo
 *@todo gere(ajouter,supprimer) une liste de todo
 */
class GestionToDo
{
public:
    GestionToDo();
    GestionToDo(Interface *);

    void addToDo(toDo &);
    void removeToDo(toDo &);
    void removeAllToDo();

    void setInterface(Interface *);

    std::list<toDo> getToDoList() const;
    unsigned int getSize() const;

    std::string toString();


private :

    std::list<toDo> ltodo;
    Interface * I;

};

#endif // GESTIONTODO_H