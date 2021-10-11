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
    Interaction(Contact c, std::string contenu);

    std::string getContenu() const;
    tm getDate() const;
    std::string getDateToString() const;
    Contact* getContact() const;



private:
    tm * date;
    std::string contenu;
    std::list<toDo> tags;
    Contact* C;

    void setDate(tm* const date);
    void setContenu(const std::string contenu);
    void setContact(Contact* const C);

};

#endif // INTERACTION_H
