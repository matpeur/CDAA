#include "date.h"

using namespace std;

Date::Date()
{
    time_t tn = time(0) ;
    tdate = localtime (& tn) ;
}

Date::Date(std::string date)
{
    setDate(date);
}

std::string Date::getDateToString() const
{
    string result = "";
    result+=to_string(tdate->tm_mday);+"/"+to_string(tdate->tm_mon+1)+"/"+to_string(tdate->tm_year+1900);
    return result;
}

tm * Date::getDate() const{return tdate;}

void Date::setDate(tm * d){tdate = d;}

void Date::setDate(const std::string dateS)
{
    int jour = stoi(dateS.substr(2));
    int mois = stoi(dateS.substr(3,2));
    int annee = stoi(dateS.substr(5,4));

    if(jour<=0 || jour>31)
        throw "Format jour errone";
    if (mois<=0 || mois>12)
        throw "Format mois errone";
    if (annee <1900)
        throw "Format annee errone";
    time_t tempsvide;
    tm* Odate;

    time(& tempsvide);
    Odate= localtime(&tempsvide);
    Odate -> tm_year = annee - 1900;
    Odate -> tm_mon = mois -1;
    Odate -> tm_mday = jour;

    setDate(Odate);
}

bool Date::operator>(Date d){return this->tdate>d.getDate();}
bool Date::operator<(Date d){return this->tdate<d.getDate();}
bool Date::operator==(Date d){return this->tdate==d.getDate();}

