#ifndef INTERACTION_H
#define INTERACTION_H

#include<string>
#include <ctime>
#include <todo.h>
#include <contact.h>

class Interaction
{

public:
    Interaction();
    Interaction(Contact*, std::string);

    std::string getContenu() const;
    tm getDate() const;
    Contact* getContact() const;



private:
    tm * date;
    std::string contenu;
    std::list<toDo> tags;
    Contact* contact;

    void setDate(tm* const);
    void setContenu(const std::string);
    void setContact(Contact* const);
    void addToDo(toDo const);
    void removeToDo(toDo const);

};

#endif // INTERACTION_H
