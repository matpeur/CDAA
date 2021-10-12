#ifndef DATE_H
#define DATE_H
#include <string>
class Date
{
public:
    Date();
    Date(std::string);
    std::string getDateToString() const;
private :
    time_t tn  ;
    tm * tdate  ;
};

#endif // DATE_H

