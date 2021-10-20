#ifndef DATE_H
#define DATE_H
#include <string>
#include <time.h>
class Date
{
public:
    Date();
    Date(std::string);
    std::string getDateToString() const;
    tm * getDate() const;
    bool operator<(Date);
    bool operator>(Date);
    bool operator==(Date);
private :
    tm * tdate;
    void setDate(tm *);
    void setDate(std::string const);
};

#endif // DATE_H

