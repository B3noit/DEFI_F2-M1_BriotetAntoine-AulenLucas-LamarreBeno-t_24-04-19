
#include "introduction.h"

int introduction(tGame *Space)
{
//Creation de quelques couleurs SDL, normale qu'il y est des warnings si on ne les utilises pas.
SDL_Color black = {0,0,0,255}; //noire
SDL_Color white = {255,255,255,255}; //blanc
SDL_Color grey = {60,60,60,255}; //blanc
SDL_Color red = {255,0,0,255}; //rouge
SDL_Color green = {0,255,0,255}; //vert
SDL_Color blue = {0,0,255,255}; //bleu

//Tableau de caract�re des chemins de nos images, CF le r�pertoire des images.
char cSprite[100][100]={"./Assets/Images/darkSpace.png","./Assets/Images/comptoirePrimo.png","./Assets/Images/tetePrimo.png","./Assets/Images/ok.png"};

tSprite Primo;//On d�clare un sprite avec lequel le joueur peut interagir,
setFullSprite(&Primo, 900, 394, 416,416, cSprite[1], 0);//on l'initialise.
tSprite ok;
setFullSprite(&ok,700,500,128,128, cSprite[3], 0);

while(Space->nGameState==1)//Grosse boucle du jeu qui tourne tant que le joueur ne quitte pas.
{

    affichSpriteDecor(Space,cSprite,0,0,0,WINDOW_WIDTH,WINDOW_LENGTH);
    affichSprite(Space,&Primo);

    //On v�rifie que le joueur joue et qu'il ne souhaite pas quitter la fen�tre.
    handleEvents(Space);

    testClicked(&ok);
    if (ok.nClicked == 1 && Primo.nClicked == 1)
    {
        return 1;
    }

    testClicked(&Primo);
    if (Primo.nClicked == 1)
    {
        setSpriteClicked(&ok,0);//Au cas ou le joueur clique sur la position du OK avant

        affichSpriteDecor(Space,cSprite,2,100,100,130,130);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Hey ! Toi l� ! Tu veux te faire des cr�dits faciles ! Viens viens ! Allez viens !",231,100,660,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Y a des gars qui sont pr�ts � donner des fortunes pour des petites t�ches toute simple !",231,120,680,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"�a t'int�resse hein !? Ouaaaii j'aime ton regard, toi rien ne peux t'arr�ter pas vrai !?",231,140,680,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Pour ta premi�re mission, je vais y aller molo, je sais pas si t'es digne de confiance, alors �coute ...",230,160,720,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Je vais t'infiltrer dans un vaisseau cargo, tu vas balancer la marcahndise dans le vide et moi,",231,180,700,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"je la r�cup�re, et juste pour �a, t'es pay� 500 QUANTUM-CREDITS !!! Et oui ! Magnifique hein !?",231,200,700,20);
        affichSprite(Space,&ok);
    }


    //On affiche tout
    SDL_RenderPresent(Space->pRenderer);
    SDL_RenderClear(Space->pRenderer);//Ecoute, moi du futur, j'ai la solution pour le lag d�geulasse quand le tete est affich�, je cr� une variable pour le SDL delay de mon render,
                                        //quand je veux afficher du texte il faut le mettent le nombre de tic voulu et bim pb r�gl�
}
return 0;
}
