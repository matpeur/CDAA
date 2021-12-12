#include "gestioninteraction.h"
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation des consructeurs
 */
GestionInteraction::GestionInteraction(){}
/**
 * @author BELLEGUEULLE TRAORE
 * @date octobre 2021
 * @brief  retourne l'indice courant +1 de la liste d'interaction
 */
int GestionInteraction::indicecourant(){return getSize();}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief créer une Interaction et l'ajoute dans la liste */
void GestionInteraction::createInteraction(Contact * C, std::string contenu)
{
    Interaction *i = new Interaction(C, contenu);
    i->setID(indicecourant());
    linteraction.push_back(i);
}


/**
  *@author BELLEGUEULLE TRAORE
  *@date octobre 2021
  * @brief Ajoute une interaction déjà créer dans la liste
  */
void GestionInteraction::addInteraction(Interaction* inter)
{
    inter->setID(indicecourant());
    linteraction.push_back(inter);
}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode removeInterraction*/
void GestionInteraction::removeInteraction(Interaction * Inter)
{

    for (auto &it : linteraction  )
    {
        if(it == Inter)
        {
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
    linteraction.clear();
}


/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation de la methode get()*/

Interaction* GestionInteraction::get( int t)
{
      auto it=this->linteraction.begin();
        for (int i=0;i<t;i++)
        {
             ++it;
        }
        return *it ;


}
/**
 * @author BELLEGUELLE TRAORE
 * @date octobre 2021
 * @brief implémentation des accesseurs*/
int GestionInteraction::getSize() const{return linteraction.size();}
std::list<Interaction*> GestionInteraction::getInteractionList() const {return linteraction;}

