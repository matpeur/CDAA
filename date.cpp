#include "date.h"
#include <iostream>

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
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2011
 * @brief implémentation de la methode getDateTostring()
 */
std::string Date::getDateToString() const
{
    string result = "";
    int jour = tdate->tm_mday;
    int mois = tdate->tm_mon+1;
    int an = tdate->tm_year+1900;
    result+=to_string(jour)+"-";
    result+=to_string(mois)+"-";
    result+=to_string(an);
    return result;
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2011
 * @brief implémentation des accesseurs
 */
tm * Date::getDate() const{return tdate;}

void Date::setDate(tm * d){tdate = d;}

void Date::setDate(const std::string dateS)
{
    unsigned long long indice1 = dateS.find('-');
    unsigned long long indice2 = dateS.find('-', indice1+1);
    if(indice1>dateS.size()||indice2>dateS.size())
       throw "Format date érroné";
    int jour = std::stoi(dateS.substr(indice1-2,2));
    int mois = std::stoi(dateS.substr(indice1+1,2));
    int annee = std::stoi(dateS.substr(indice2+1,4));

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
    mktime( Odate);
    std::cout<<Odate ->tm_mday<<std::endl;
    setDate(Odate);
    std::cout<<this->getDate()->tm_mday<<std::endl;
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2011
 * @brief implémentation de la surcharge des operateurs de comparaison == ><
 */
bool Date::operator>(Date d){return this->tdate>d.getDate();}
bool Date::operator<(Date d){return this->tdate<d.getDate();}
bool Date::operator==(Date d){return this->tdate==d.getDate();}

