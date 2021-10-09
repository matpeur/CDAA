
#ifndef CONTACT_H
#define CONTACT_H

#include <QObject>
#include "interaction.h"
#include <String>
#include <list>
class Contact : public QObject
{
    Q_OBJECT
public:
    explicit Contact(QObject *parent = nullptr);
    void addinterraction(interaction i);
    void removeinterracion(Interaction i);
    friend  std :: ostream & operator < < (std :: ostream & os, const Contact Conct );
    void setNom(String n) ;
    void setPreNom(String n) ;
    void setentrprise(String e) ;
    void settelephoen(String tel);
    void setPhoto(String photo) ;
    void setDate(date t) ;
    String getNom() ;
    String getPrenom();
    String getEntreprise();
    String gettelephone() ;
    String getPhoto() ;
   // date getDate();
private:
      String nom;
      String prenom;
      String entreprise;
      String telephone;
      String Photo;
    //  date d;
      list<Interaction>  Listesinterractions;

signals:
};
#endif // CONTACT_H

