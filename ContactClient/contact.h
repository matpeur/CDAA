
#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include "interaction.h"
#include <string>
#include <list>
class Contact : public QObject
{
    Q_OBJECT
public:
    explicit Contact(QObject *parent = nullptr);
    void addinterraction(Interaction i);
    void removeinterracion(Interaction i);
    friend  std :: ostream & operator << (std :: ostream & os, const Contact Conct );
    void setNom(std::string n) ;
    void setPreNom(std::string n) ;
    void setentrprise(std::string e) ;
    void settelephoen(std::string tel);
    void setPhoto(std::string photo) ;
    void setDate(date t) ;
    std::string getNom() ;
    std::string getPrenom();
    std::string getEntreprise();
    std::string gettelephone() ;
    std::string getPhoto() ;
   // date getDate();
private:
      std::string nom;
      std::string prenom;
      std::string entreprise;
      std::string telephone;
      std::string Photo;
    //  date d;
      list<Interaction>  Listesinterractions;

signals:
};
#endif // CONTACT_H

