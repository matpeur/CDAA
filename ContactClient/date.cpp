#include "date.h"
#include <iostream>
#include <string>
using namespace std;
Date::Date()
{
    time_t tn = time(0) ;
    tm * tdate = localtime (& tn) ;
}

std::string Date::getDateToString() const
{
    string result = "";
    result+=to_string(this->tm_mday);+"/"+to_string(this->tm_mon+1)+"/"+to_string(this->tm_year+1900);
    return result;
}
