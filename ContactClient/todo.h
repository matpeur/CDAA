#ifndef TODO_H
#define TODO_H

#include <string>

class toDo
{

public:
    toDo(std::string);

    std::string getContenu() const;


private :
    std::string contenu;
    tm* date;


};

#endif // TODO_H
