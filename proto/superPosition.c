#ifndef SUPERPOSITION_C_INCLUDED
#define SUPERPOSITION_C_INCLUDED

#include "superPosition.h"

/*****************************************
Principe : On test les coordonnées de deux images pour savoir si elles se suerposent. On retourn 1 pour VRAI et 0 pour FAUX

Entrée : les structures des deux srpites

Sortie : Un entier, soit 0 pour FAUX ou 1 pour Vrai.

Note : Le premier sprite est le contenu, le second est le contenant.
*************************************/
int testSuperpose(tSprite *tSprite1, tSprite *tSprite2)
{//VAR
    int nTest = 0;//FAUX

    if(tSprite1->nOrigineX >= tSprite2->nOrigineX && tSprite1->nOrigineY >= tSprite2->nOrigineY &&
       tSprite1->nOrigineX <= tSprite2->nOrigineX + tSprite2->nWidthSprite && tSprite1->nOrigineY <= tSprite2->nOrigineY + tSprite2->nLengthSprite)
    {
        nTest = 1; //Les images sont superposées, donc on retourne 1 pour TRUE
    }
    return nTest;//VRAI
}
#endif // SUPERPOSITION_C_INCLUDED
