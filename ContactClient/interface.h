#ifndef INTERFACE_H
#define INTERFACE_H
#include <QObject>
class toDo;
class Interaction;
class Contact;
#include "basededonnee.h"



class Interface : public QObject
{
    Q_OBJECT
public:

    explicit Interface(QObject *parent = nullptr);

    void deleteTodo(toDo *);
    void deleteInteraction(Interaction *);
    void deleteContact(Contact *);
    void ajouteContact(Contact*);
    void modifieContact(Contact*,Contact*);
    Basededonnee* db;
signals:


};

#endif // INTERFACE_H
