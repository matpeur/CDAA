#include "date.h"

Date::Date()
{

}

std::string Date::getDateToString() const
{
    std::string result = "";
    tm d=*this->date;
    result+=std::to_string(d.tm_mday);+"/"+std::to_string(d.tm_mon+1)+"/"+std::to_string(d.tm_year+1900);
    return result;
}
