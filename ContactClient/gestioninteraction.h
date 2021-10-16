#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H
#include "interface.h"

class GestionInteraction
{
public:
    GestionInteraction(Interface* interface);
    GestionInteraction();

private :
    Interface * I;
};

#endif // GESTIONINTERACTION_H
