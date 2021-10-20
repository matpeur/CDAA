#include "gestioninteraction.h"
GestionInteraction::GestionInteraction(){}

GestionInteraction::GestionInteraction(Interface * interface)
{
    setInterface(interface);
}

void GestionInteraction::addInteraction(Contact * C, std::string contenu)
{
    Interaction i(I, C, contenu);
    linteraction.push_back(i);
}

void GestionInteraction::removeInteraction(Interaction & Inter)
{

    for (auto &it : linteraction  )
    {
        if(it == Inter)
        {
            I->deleteInteraction(&it);
            linteraction.remove(it);
        }
    }
}

void GestionInteraction::removeAllInteraction()
{
    for (auto it : linteraction)
    {
        I->deleteInteraction(&it);
    }
    linteraction.clear();
}

std::list<Interaction> GestionInteraction::getInteractionList() const {return linteraction;}
unsigned int GestionInteraction::getSize() const{return linteraction.size();}
void GestionInteraction::setInterface(Interface * I){this->I=I;}
