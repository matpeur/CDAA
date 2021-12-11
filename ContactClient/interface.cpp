#include "interface.h"
#include "basededonnee.h"
#include "contact.h"
Interface::Interface(QObject *parent) : QObject(parent)
{
 //db=new Basededonnee();
}

void Interface::deleteTodo(toDo * ){/*retirer td de la BD SQL*/}
void Interface::deleteInteraction(Interaction * ){/*retirer i de la BD SQL*/}

/*void Interface::deleteContact(Contact *  e){this->db->SupprimeContact(*e);}
void Interface::ajouteContact(Contact * c){this->db->AjoutContact(*c);}
void Interface::modifieContact(Contact * neww, Contact * old){this->db->ModifiContact(*neww,*old);}*/
