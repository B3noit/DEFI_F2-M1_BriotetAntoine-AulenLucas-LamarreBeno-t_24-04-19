
#include "click.h"
/*****************************************
Principe : On test les coordonnées de la souris quand le joueur click pour savoir si il click sur un sprite avec lequel il peut interagir.

Entrée : La structure du sprite clickable.

Sortie : Un entier, le nClicked su sprite.

Note : Si le joueur click sur l'image son nClicked passe à 1 il faut le remettre à zéro dans le code principale
        pour évité une boucle infini ou une condition qui est toujours remplit
        ex :
        if (Disjoncteur.nClicked == 1)
        {
            affichText(&Space,white,grey,"Le disjoncteur est vide, peut-être qu'avec des fusibles on pourrait le remettre en route.",100,400,600,20);
            SDL_RenderPresent(Space.pRenderer);
            SDL_RenderClear(Space.pRenderer);
            SDL_Delay(3000);
            setSpriteClicked(&Disjoncteur,0);
        }
*************************************/
extern void testClicked(tSprite *tSprite)
{//VAR
    SDL_Event eventClick;
    int nMousX = 0;
    int nMousY = 0;

    //SDL_GetMouseState(&nMousX, &nMousY);

    //SDL_PollEvent(&eventClick);
    if (eventClick.type == SDL_MOUSEBUTTONDOWN)
    {
        SDL_GetMouseState(&nMousX, &nMousY);
        if(nMousX >= tSprite->nOrigineX && nMousY >= tSprite->nOrigineY && nMousX <= tSprite->nOrigineX + tSprite->nWidthSprite && nMousY <= tSprite->nOrigineY + tSprite->nLengthSprite)
        {
            tSprite->nClicked = 1;//On click sur l'image 1 vaut TRUE.
        }
    }
}
