#ifndef DATE_H
#define DATE_H
#include <string>
#include <time.h>
/**
 *@class date
 *@brief Classe date
 *tdate de type tm
 *todo permet de creer une nouvelle date courante,
 * de la modifier et de la retourner sous forme de chaine
*/
class Date
{
public:
    /**
     les deux constructeurs

    */
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

