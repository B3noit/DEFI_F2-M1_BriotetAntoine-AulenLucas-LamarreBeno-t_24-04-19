
#include "affichText.h"
/*****************************************
Principe : On affiche un texte à l'écran, de la couleur, taille, position ue l'on veut.
            On ouvre le fichier contenant notre police, on crée la surface, on y crée la texture a partir dela surface,
            On crée le rectangle qui acceuil notre message, on copie le tout dans le renderer,
            On femrela police, on libère la surface et on détruit la texture pour optimiser la mémoire.

Entrée : la structure du jeu, le chemin de la police que l'on veut utiliser, son PointSize, la couleur du texte,
         la couleur du background(rectangle dans lequel est affiché l'image), la chaine à afficher,
         l'abscisse du point d'origine du recangle, l'ordonnées du point d'origine du rectangle, sa larguer et sa longueur.

Sortie : Un entier, soit 0 pour FAUX ou 1 pour Vrai.

Note : Le premier sprite est le contenu, le second est le contenant.
*************************************/
void affichText(tGame *tGame, char* cPolice, int nPtSize, SDL_Color cText,SDL_Color cBackground, char* Text,int x, int y, int nWidth, int nLength)
{
    TTF_Font* police = TTF_OpenFont(cPolice, nPtSize);
    tGame->pSurface = TTF_RenderText_Shaded(police, Text, cText, cBackground);
    tGame->pTexture = SDL_CreateTextureFromSurface(tGame->pRenderer, tGame->pSurface);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = nWidth;
    Message_rect.h = nLength;
    SDL_RenderCopy(tGame->pRenderer, tGame->pTexture, NULL, &Message_rect);
    TTF_CloseFont(police);
    SDL_FreeSurface(tGame->pSurface);
    SDL_DestroyTexture(tGame->pTexture);
}
