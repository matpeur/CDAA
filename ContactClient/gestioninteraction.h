#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H
#include "interface.h"
#include "interaction.h"


class GestionInteraction
{
public:
    GestionInteraction();
    void addInteraction(Interaction &);
    void removeInteraction(Interaction &);
    void removeAllInteraction();

    std::list<Interaction> getInteractionList() const;
    unsigned int getSize() const;
    void setInterface(Interface *);

    static GestionInteraction creerGestionInteraction(Interface *);

private :
    Interface * I;
    std::list<Interaction> linteraction;
};

#endif // GESTIONINTERACTION_H
