#ifndef DATE_H
#define DATE_H
#include <string>
class Date
{
public:
    Date();
    Date(std::string);
    std::string getDateToString() const;
    tm * getDate() const;
private :
    tm * tdate  ;
    void setDate(tm *);
    void setDate(std::string const);
};

#endif // DATE_H

