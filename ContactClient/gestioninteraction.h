#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H
#include "interface.h"
#include "interaction.h"
/**
 *@class Contact
 *@brief Classe Contact
 *nom,personne,mail,photo,entreprise en string
 *todo creer,ajouter et supprimer un conract et gerer ses interractions
*/

class GestionInteraction
{
public:
    GestionInteraction();

    void addInteraction(Interaction *);
    void createInteraction(Contact *, std::string Contenu);
    void removeInteraction(Interaction *);
    void removeAllInteraction();
    Interaction* get(int);
    std::list<Interaction*> getInteractionList() const;
    int getSize() const;

private :
    std::list<Interaction*> linteraction;

};

#endif // GESTIONINTERACTION_H
