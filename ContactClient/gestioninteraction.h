#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H
#include "interface.h"
#include "interaction.h"


class GestionInteraction
{
public:
    GestionInteraction(Interface*);
    GestionInteraction();
    void addInteraction(Interaction);
    void deleteInteraction(Interaction);
    void deleteallInteraction();

    Interaction * getInteraction(unsigned int) const;
    unsigned int getSize() const;

private :
    Interface * I;
    std::list<Interaction> lI;
};

#endif // GESTIONINTERACTION_H
