
#include "transition1.h"


int transition1(tGame *Space)
{
//Creation de quelques couleurs SDL, normale qu'il y est des warnings si on ne les utilises pas.
SDL_Color black = {0,0,0,255}; //noire
SDL_Color white = {255,255,255,255}; //blanc
SDL_Color grey = {60,60,60,255}; //blanc
SDL_Color red = {255,0,0,255}; //rouge
SDL_Color green = {0,255,0,255}; //vert
SDL_Color blue = {0,0,255,255}; //bleu

//Tableau de caractère des chemins de nos images, CF le répertoire des images.
char cSprite[100][100]={"./Assets/Images/darkSpace.png","./Assets/Images/comptoirePrimo.png","./Assets/Images/cartonFerme.png","./Assets/Images/cartonOuvert.png",
                        "./Assets/Images/tetePrimo.png","./Assets/Images/ok.png"};

tSprite Primo;//On déclare un sprite avec lequel le joueur peut interagir,
setFullSprite(&Primo, 900, 394, 416,416, cSprite[1], 0);//on l'initialise.
tSprite ok;
setFullSprite(&ok,700,500,128,128, cSprite[5], 0);


while(Space->nGameState==1)//Grosse boucle du jeu qui tourne tant que le joueur ne quitte pas.
{

    affichSpriteDecor(Space,cSprite,0,0,0,WINDOW_WIDTH,WINDOW_LENGTH);
    affichSpriteDecor(Space,cSprite,2,0,682,128,128);
    affichSpriteDecor(Space,cSprite,3,130,682,128,128);
    affichSpriteDecor(Space,cSprite,2,260,682,128,128);
    affichSpriteDecor(Space,cSprite,2,390,682,128,128);

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
        affichSpriteDecor(Space,cSprite,4,100,100,130,130);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Hahaha ! Te revoilà, t'as eu de la chance, je t'ai récuperé au beau milieu des cartons !",231,100,680,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Hahah ! t'aurais vu ta tête ! ELLE ÉTAIT BLEUE !! AHHHAHHHHAAAAH ! alala il faut que je me calme...",231,120,700,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"D'abord merci ! J'aurais bien aimé te donner tes 500 QUANTUM-CRÉDITs tout de suite mais...",231,140,680,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"le commanditaire a dit qu'il te donnerai 10 fois plus de prime si tu acceptait de voler un certain vaisseau...",231,160,720,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Et ça c'est une offre que tu pouvais pas refuser pas vrai ! Imagine, 5000 QUANTUM-CRÉDITs alors écoute...",231,180,710,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Tu vas voler un vieux vaisseau, qui vaut une coquette somme, tu le ramènes ici et BIM! la prime est pour toi.",231,200,720,20);
        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Et t'inquiètes pas, ces vieux vaisseaux sont facile à piloter, tu sauras te débrouiller. ALLER ! VAMOOOS !!",231,220,720,20);
        affichSprite(Space,&ok);
    }


    //On affiche tout
    SDL_RenderPresent(Space->pRenderer);
    SDL_RenderClear(Space->pRenderer);//Ecoute, moi du futur, j'ai la solution pour le lag dégeulasse quand le tete est affiché, je cré une variable pour le SDL delay de mon render,
                                        //quand je veux afficher du texte il faut le mettent le nombre de tic voulu et bim pb règlé
}
return 0;
}
