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
    ajoutinterraction(interaction i);
    removeinterracion(Interaction i);
   std :: ostream & operator < < (std :: ostream & , const & value );
private:
      String nom;
      String prenom;
      String entreprise;
      String telephone;
      String Photo;
      date d;
      list<Interaction>;

signals:

};

#endif // CONTACT_H
