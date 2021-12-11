#include "gestiontodo.h"
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation des constructeurs*/
GestionToDo::GestionToDo(){}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode addTodo */

void GestionToDo::addToDo(toDo  td)
{
    ltodo.push_back(td);
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode removetodo */

void GestionToDo::createtodO(Interaction * I, std::string s)
{
  toDo t(I,s);
  this->ltodo.push_back(t);
}
void GestionToDo::removeToDo(toDo & td)
{

    for (auto it: ltodo )
    {
        if(it == td)
        {
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

 int GestionToDo::getSize() const{return (int)ltodo.size();}

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

toDo* GestionToDo::get( int t)
{
      auto it=this->ltodo.begin();
        for (int i=0;i<t;i++)
        {
             ++it;
        }
        return &( *it) ;


}
