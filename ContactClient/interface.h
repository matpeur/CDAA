#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include "todo.h"
#include "gestiontodo.h"
#include "interaction.h"
#include "gestioninteraction.h"
#include "contact.h"
#include "gestioncontact.h"



class Interface : public QObject
{
    Q_OBJECT
public:
    explicit Interface(QObject *parent = nullptr);
    void deleteTodo(toDo *);
    void deleteInteraction(Interaction *);
    void deleteContact(Contact *);

signals:

};

#endif // INTERFACE_H
