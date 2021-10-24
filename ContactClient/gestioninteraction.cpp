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
 * @brief créer une Interaction et l'ajoute dans la liste */
void GestionInteraction::createInteraction(Contact * C, std::string contenu)
{
    Interaction i(I, C, contenu);
    linteraction.push_back(i);
}
/**
  *@author BELLEGUEULLE TRAORE
  *@date octobre 2021
  * @brief Ajoute une interaction déjà créer dans la liste
  */
void GestionInteraction::addInteraction(Interaction inter)
{
    linteraction.push_back(inter);
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
