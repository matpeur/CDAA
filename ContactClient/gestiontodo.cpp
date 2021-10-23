#include "gestiontodo.h"
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation des constructeurs*/
GestionToDo::GestionToDo(){}
GestionToDo::GestionToDo(Interface * interface)
{
    setInterface(interface);
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode addTodo */

void GestionToDo::addToDo(toDo & td)
{
    ltodo.push_back(td);
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode removetodo */

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
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode removealltodo*/
void GestionToDo::removeAllToDo()
{
    for (auto it : ltodo)
    {
        I->deleteTodo(&it);
    }
    ltodo.clear();
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation des accesseurs*/
std::list<toDo> GestionToDo::getToDoList() const
{
    return ltodo;
}

unsigned int GestionToDo::getSize() const{return ltodo.size();}
void GestionToDo::setInterface(Interface * I){this->I=I;}

/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode toString() */
std::string GestionToDo::toString()
{
    std::string result = "";
    for (auto it : ltodo)
        result += it.toString()+"\n";
    return result;

}


