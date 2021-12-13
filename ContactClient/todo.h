#ifndef TODO_H
#define TODO_H

#include <string>
#include <ostream>
#include "date.h"
class Interaction;
class Interface;
/**
 *@class todo
 *@brief permet de de taguer des mots dans un champs de texte et capable
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
    void setDate(std::string const);

   std::string toString();
   void setContenu(std::string const);
   void setID(int i);
   int getID();
private :

    Interaction * owner;
    std::string contenu;
    std::string date;
    int id;



};

#endif // TODO_H
