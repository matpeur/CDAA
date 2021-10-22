#include "interface.h"

Interface::Interface(QObject *parent) : QObject(parent)
{

}

void Interface::deleteTodo(toDo * ){/*retirer td de la BD SQL*/}
void Interface::deleteInteraction(Interaction * ){/*retirer i de la BD SQL*/}
void Interface::deleteContact(Contact * ){/*retirer c de la BD SQL*/}
