#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
class toDo;
class Interaction;
class Contact;




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
