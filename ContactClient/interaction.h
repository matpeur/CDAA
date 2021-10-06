#ifndef INTERACTION_H
#define INTERACTION_H

#include<string>
#include <ctime>

class Interaction
{

public:
    Interaction(std::string contenu);

    std::string getContenu() const;
    void setContenu(const std::string contenu);
    time_t getDate() const;
    std::string getDateToString() const;



private:
    time_t date;
    std::string contenu;

};

#endif // INTERACTION_H
