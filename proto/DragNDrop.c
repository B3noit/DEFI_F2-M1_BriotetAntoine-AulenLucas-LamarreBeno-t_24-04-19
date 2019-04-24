
#include "DragNDrop.h"

/*****************************************
Principe : Qaund le joueur click on vérifie si la souris se trouve sur un élément affecter par le dag n drop. Si oui,
            alors quand le joueur relâche la souris, les coordonnées de l'image sont mises à jours avec les coordonnées de la souris.

Entrée : la structure du sprite.

Sortie : la nouvelle position du sprite.

Note : pour l'instant le sprite se "teleporte" lorsque l'on relâche le clic.
*************************************/
void dragNDrop(tSprite *tSprite)
{//VAR
    SDL_Event event;
    int nMousX = 0;
    int nMousY = 0;

    SDL_GetMouseState(&nMousX, &nMousY);

     if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(nMousX >= tSprite->nOrigineX && nMousY >= tSprite->nOrigineY && nMousX <= tSprite->nOrigineX + tSprite->nWidthSprite && nMousY <= tSprite->nOrigineY + tSprite->nLengthSprite)
        {
            tSprite->nClicked = 1;//On click sur l'image 1 vaut TRUE.
        }
    }


    if (event.type == SDL_MOUSEBUTTONUP)
    {
        if(tSprite->nClicked == 1)
        {
        moveSprite(tSprite, nMousX, nMousY);
        }
        tSprite->nClicked = 0;//Le joueur n'st plus entrain de clicker.
    }
}
