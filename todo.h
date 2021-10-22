#ifndef TODO_H
#define TODO_H

#include <string>
#include <ostream>
#include "date.h"
class Interaction;
class Interface;
/**
 *@class todo
 *@brief Classe todo
 *@todo permet de de taguer des mots dans un champs de texte et capable
 * de modifier la date d'un champs de texte
*/
class toDo
{

public:

    toDo(Interaction*,std::string &);
    toDo();

    std::string getContenu() const;
    std::string getDate() const;
    std::string datestring;
    Interaction * getOwner() const;

    void setOwner(Interaction *);

    bool operator==(toDo );
    void setDate(Date* const);

   // std::string toString();
   std::string toString();
private :

    Interaction * owner;
    std::string contenu;
    Date date;

    void setContenu(std::string const);



};

#endif // TODO_H
