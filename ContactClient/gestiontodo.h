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
    void createtodO(Interaction *,std::string s);
    void addToDo(toDo *);
    void removeToDo(toDo *);
    void removeAllToDo();

    void setInterface(Interface *);

    std::list<toDo*> getToDoList() const;
    int getSize() const;

    std::string toString();
    toDo* get(int);


private :

    std::list<toDo*> ltodo;


};

#endif // GESTIONTODO_H
