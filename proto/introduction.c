
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

//Tableau de caractère des chemins de nos images, CF le répertoire des images.
char cSprite[100][100]={"./Assets/Images/darkSpace.png","./Assets/Images/comptoirePrimo.png","./Assets/Images/tetePrimo.png","./Assets/Images/ok.png"};

tSprite Primo;//On déclare un sprite avec lequel le joueur peut interagir,
setFullSprite(&Primo, 900, 394, 416,416, cSprite[1], 0);//on l'initialise.
tSprite ok;
setFullSprite(&ok,700,500,128,128, cSprite[3], 0);

while(Space->nGameState==1)//Grosse boucle du jeu qui tourne tant que le joueur ne quitte pas.
{

    affichSpriteDecor(Space,cSprite,0,0,0,WINDOW_WIDTH,WINDOW_LENGTH);
    affichSprite(Space,&Primo);

    //On vérifie que le joueur joue et qu'il ne souhaite pas quitter la fenêtre.
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
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Hey ! Toi là ! Tu veux te faire des crédits faciles ! Viens viens ! Allez viens !",231,100,660,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Y a des gars qui sont prêts à donner des fortunes pour des petites tâches toute simple !",231,120,680,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Ça t'intéresse hein !? Ouaaaii j'aime ton regard, toi rien ne peux t'arrêter pas vrai !?",231,140,680,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Pour ta première mission, je vais y aller molo, je sais pas si t'es digne de confiance, alors écoute ...",230,160,720,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Je vais t'infiltrer dans un vaisseau cargo, tu vas balancer la marcahndise dans le vide et moi,",231,180,700,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"je la récupère, et juste pour ça, t'es payé 500 QUANTUM-CREDITS !!! Et oui ! Magnifique hein !?",231,200,700,20);
        affichSprite(Space,&ok);
    }


    //On affiche tout
    SDL_RenderPresent(Space->pRenderer);
    SDL_RenderClear(Space->pRenderer);//Ecoute, moi du futur, j'ai la solution pour le lag dégeulasse quand le tete est affiché, je cré une variable pour le SDL delay de mon render,
                                        //quand je veux afficher du texte il faut le mettent le nombre de tic voulu et bim pb règlé
}
return 0;
}
