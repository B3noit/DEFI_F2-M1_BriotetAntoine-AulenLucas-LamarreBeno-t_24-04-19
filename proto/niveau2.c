
#include "niveau2.h"

int niveau2(tGame *Space)
{
//VAR
int nClickBleu = 0;
int nClickRouge = 0;
int nClickVert = 0;
int nCpt = 0;
//Creation de quelques couleurs SDL, normale qu'il y est des warnings si on ne les utilises pas.
SDL_Color black = {0,0,0,255}; //noire
SDL_Color white = {255,255,255,255}; //blanc
SDL_Color grey = {60,60,60,255}; //blanc
SDL_Color red = {255,0,0,255}; //rouge
SDL_Color green = {0,255,0,255}; //vert
SDL_Color blue = {0,0,255,255}; //bleu

//Tableau de caractère des chemins de nos images, CF le répertoire des images.
char cSprite[100][100]={"./Assets/Images/hangar.jpg","./Assets/Images/coqpit.png","./Assets/Images/interrupteurBleuUp.png","./Assets/Images/interrupteurBleuDown.png",
                        "./Assets/Images/interrupteurRougeUp.png","./Assets/Images/interrupteurRougeDown.png","./Assets/Images/interrupteurVertUp.png",
                        "./Assets/Images/interrupteurVertDown.png","./Assets/Images/darkSpace.png"};
tSprite Hangar;
setFullSprite(&Hangar,0,-250,WINDOW_WIDTH,WINDOW_LENGTH,cSprite[0],0);
tSprite InterrupteurBleu;
setFullSprite(&InterrupteurBleu,436, 525, 192, 192, cSprite[2], 0);
tSprite InterrupteurRouge;
setFullSprite(&InterrupteurRouge, 624, 475, 192, 192, cSprite[4], 0);
tSprite InterrupteurVert;
setFullSprite(&InterrupteurVert,812, 525, 192, 192, cSprite[6], 0);



    while(Space->nGameState==1)//Grosse boucle du jeu qui tourne tant que le joueur ne quitte pas.
    {
        affichSprite(Space,&Hangar);
        affichSpriteDecor(Space,cSprite,1,0,0,WINDOW_WIDTH,WINDOW_LENGTH);
        affichSprite(Space,&InterrupteurBleu);
        affichSprite(Space,&InterrupteurRouge);
        affichSprite(Space,&InterrupteurVert);

        //On vérifie que le joueur joue et qu'il ne souhaite pas quitter la fenêtre.
        handleEvents(Space);
        testClicked(&InterrupteurBleu);
        testClicked(&InterrupteurRouge);
        testClicked(&InterrupteurVert);

        if (nCpt >=30)
        {
            setSpriteChemin(&Hangar,cSprite[8]);
            setSpriteOrigineY(&Hangar,0);
            affichSprite(Space,&Hangar);
            affichSpriteDecor(Space,cSprite,1,0,0,WINDOW_WIDTH,WINDOW_LENGTH);
            affichSprite(Space,&InterrupteurBleu);
            affichSprite(Space,&InterrupteurRouge);
            affichSprite(Space,&InterrupteurVert);
            SDL_RenderPresent(Space->pRenderer);
            SDL_RenderClear(Space->pRenderer);
            SDL_Delay(2000);
            return 1;
        }
        if ((nClickBleu % 2 == 1) && (nClickRouge % 2 == 1) && (nClickVert % 2 == 1) && (nCpt==0))
        {
            affichText(Space,"./Fonts/verdana.ttf",12,white,black,"WOUHOU!!! ÇA MARCHE, C'EST PARTI!!!",440,200,800,50);
            SDL_RenderPresent(Space->pRenderer);
            SDL_RenderClear(Space->pRenderer);
            SDL_Delay(2000);
        }


        if (InterrupteurBleu.nClicked == 1)
        {
            nClickRouge = nClickRouge + 1;
            nClickBleu = nClickBleu + 1;
            setSpriteClicked(&InterrupteurBleu,0);
        }

        if (InterrupteurRouge.nClicked == 1 && nClickRouge == 0)
        {
                affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Roooohhh! On dirait que ce levier est verrouiller ! J'ai pas de chance ! Mais alors vraiment pas !",500,400,600,20);
                affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Moi qui pensais faire décoller de vaisseau dès le premier essaie ! Holalalalalala.... Zut !!!",500,420,600,20);
                SDL_RenderPresent(Space->pRenderer);
                SDL_RenderClear(Space->pRenderer);
                setSpriteClicked(&InterrupteurRouge,0);
                SDL_Delay(8000);

        }else if (InterrupteurRouge.nClicked == 1)
            {
                nClickRouge = nClickRouge + 1;
                nClickBleu = nClickBleu + 1;
                nClickVert = nClickVert + 1;
                setSpriteClicked(&InterrupteurRouge,0);
            }

        if (InterrupteurVert.nClicked == 1)
        {
            nClickVert = nClickVert + 1;
            nClickRouge = nClickRouge + 1;
            setSpriteClicked(&InterrupteurVert,0);
        }

        if (nClickBleu % 2 == 1)
        {
            setSpriteChemin(&InterrupteurBleu,cSprite[3]);
        }else
            {
                setSpriteChemin(&InterrupteurBleu,cSprite[2]);
            }

        if (nClickRouge % 2 == 1)
        {
            setSpriteChemin(&InterrupteurRouge,cSprite[5]);
        }else
            {
                setSpriteChemin(&InterrupteurRouge,cSprite[4]);
            }

        if (nClickVert % 2 == 1)
        {
            setSpriteChemin(&InterrupteurVert,cSprite[7]);
        }else
            {
                setSpriteChemin(&InterrupteurVert,cSprite[6]);
            }

        if ((nClickBleu % 2 == 1) && (nClickRouge % 2 == 1) && (nClickVert % 2 == 1) && (nCpt==0))
        {
            affichText(Space,"./Fonts/verdana.ttf",12,white,black,"WOUHOU!!! ÇA MARCHE, C'EST PARTI!!!",440,200,800,50);
            SDL_RenderPresent(Space->pRenderer);
            SDL_RenderClear(Space->pRenderer);
            SDL_Delay(2000);

        }
        if ((nClickBleu % 2 == 1) && (nClickRouge % 2 == 1) && (nClickVert % 2 == 1) &&(nCpt < 30))
        {
                setSpriteOrigineY(&Hangar,Hangar.nOrigineY+nCpt);
                nCpt = nCpt + 1;

        }
        //On affiche tout
        SDL_RenderPresent(Space->pRenderer);
        SDL_RenderClear(Space->pRenderer);


    }

    return 0;
}
