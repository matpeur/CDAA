#include "gestioninteraction.h"
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation des consructeurs
 */
GestionInteraction::GestionInteraction(){}

GestionInteraction::GestionInteraction(Interface * interface)
{
    setInterface(interface);
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode addInterraction */
void GestionInteraction::addInteraction(Contact * C, std::string contenu)
{
    Interaction i(I, C, contenu);
    linteraction.push_back(i);
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode removeInterraction*/
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
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode removeAllInterraction*/
void GestionInteraction::removeAllInteraction()
{
    for (auto it : linteraction)
    {
        I->deleteInteraction(&it);
    }
    linteraction.clear();
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation des accesseurs*/
std::list<Interaction> GestionInteraction::getInteractionList() const {return linteraction;}
unsigned int GestionInteraction::getSize() const{return linteraction.size();}
void GestionInteraction::setInterface(Interface * I){this->I=I;}
