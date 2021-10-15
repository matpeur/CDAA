#include "date.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
Date::Date()
{
    time_t tn = time(0) ;
    tdate = localtime (& tn) ;
}

std::string Date::getDateToString() const
{
    string result = "";
    result+=to_string(tdate->tm_mday);+"/"+to_string(tdate->tm_mon+1)+"/"+to_string(tdate->tm_year+1900);
    return result;
}
