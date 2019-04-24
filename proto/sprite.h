#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <string.h>

#include "game.h"

/*
La structure Sprite est nécessiare pour les éléments avec lequel le joueur peut interagir,
cependant pour les éléments de décors elle n'est pas nécessaire.
*/
typedef struct tSprite{

    int nOrigineX;//L'abscisse du point d'origine.
    int nOrigineY;//L'ordonnée du point d'origine.
    int nWidthSprite;// La largeur de l'image
    int nLengthSprite;// La longueur de l'image.
    char cChemin[100]; //Le chemin de l'image.
    int nClicked;//Vaut 1 quand le joueur click sur l'image sinon vaut 0, nous sert de Bool

}tSprite;

//Affichage des sprites
extern void affichSpriteDecor(tGame *tGame, char cChemin[100][100], int nSprite, int nOrigineX, int nOrigineY, int nWidthSprite, int nLengthSprite);
extern void affichSprite(tGame *tGame, tSprite *tSprite);

///GET ET SET
//Origine
extern int getSpriteOrigineX(tSprite *tSprite);
extern void setSpriteOrigineX(tSprite *tSprite, int nOrigineX);
extern int getSpriteOrigineY(tSprite *tSprite);
extern void setSpriteOrigineY(tSprite *tSprite, int nOrigineY);
//Largeur et longueur
extern int getSpriteWidth(tSprite *tSprite);
extern void setSpriteWidth(tSprite *tSprite, int nWidth);
extern int getSpriteLength(tSprite *tSprite);
extern void setSpriteLength(tSprite *tSprite, int nLength);
//Chemin
extern void setSpriteChemin(tSprite *tSprite, char cChemin[100]);
//Clicked
extern int getSpriteClicked(tSprite *tSprite);
extern void setSpriteClicked(tSprite *tSprite, int nClicked);

extern void setFullSprite(tSprite *tSprite, int nOrigineX, int nOrigineY, int nWidth, int nLength, char cChemin[100], int nClicked);
extern void moveSprite(tSprite *tSprite, int nOrigineX, int nOrigineY);



#endif // SPRITE_H_INCLUDED
