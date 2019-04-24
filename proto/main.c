#define WINDOW_WIDTH 1440
#define WINDOW_LENGTH 810


/*#include "click.h"
#include "DragNDrop.h"
#include "superPosition.h"
#include "affichText.h"*/
#include "niveau2.h"

int main( int argc, char* args[] )
{
//Creation de quelques couleurs SDL, normale qu'il y est des warnings si on ne les utilises pas.
SDL_Color black = {0,0,0,255}; //noire
SDL_Color white = {255,255,255,255}; //blanc
//SDL_Color grey = {60,60,60,255}; //blanc
//SDL_Color red = {255,0,0,255}; //rouge
//SDL_Color green = {0,255,0,255}; //vert
//SDL_Color blue = {0,0,255,255}; //bleu

//Initialisation de SDL ttf
TTF_Init();

//VAR
tGame Space;//Structure de notre jeu.
Space.nGameState = 1;//Le jeu est lancé donc notre boucle de jeu doit tourné.

//Initialisation de la SDL
if (SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Echec de l'init de la sdl.\n");
return -1;
}

//Création de la fenêtre
Space.pWindow = NULL;
Space.pWindow = SDL_CreateWindow("PlaneSpace",SDL_WINDOWPOS_UNDEFINED,
                                                    SDL_WINDOWPOS_UNDEFINED,
                                                    WINDOW_WIDTH,
                                                    WINDOW_LENGTH,
                                                    SDL_WINDOW_SHOWN);

//Création du Renderer
Space.pRenderer = NULL;
Space.pRenderer=SDL_CreateRenderer(Space.pWindow,-1,SDL_RENDERER_ACCELERATED);

    while(Space.nGameState==1)//Grosse boucle du jeu qui tourne tant que le joueur ne quitte pas.
    {
        if (introduction(&Space)==1)
        {
            affichText(&Space,"./Fonts/verdana.ttf",12,white,black,"Aussi facile que de prendre la sucette d'un chiot...c'est ce qu'on dit non ?",540,400,850,40);
            SDL_RenderPresent(Space.pRenderer);
            SDL_RenderClear(Space.pRenderer);
            SDL_Delay(2000);
        }
        if (niveau1(&Space)==1)
        {
            affichText(&Space,"./Fonts/verdana.ttf",12,white,black,"WAAAAAAAAAAAAAAAAAAAAAAHHHHHHHHHHH!!!!!!!!!!!",440,200,800,50);
            SDL_RenderPresent(Space.pRenderer);
            SDL_RenderClear(Space.pRenderer);
            SDL_Delay(1500);
        }
        if (transition1(&Space)==1)
        {
            affichText(&Space,"./Fonts/verdana.ttf",12,white,black,"No problèmo Primo ! ahah... et puis comme on dit :'Enrobé, c'est expédié !  ",540,400,850,40);
            SDL_RenderPresent(Space.pRenderer);
            SDL_RenderClear(Space.pRenderer);
            SDL_Delay(2000);
        }
        if (niveau2(&Space)==1)
        {
            affichText(&Space,"./Fonts/verdana.ttf",12,white,black,"WOOOOOOOOOHHHHHHOOOOOOOOOOOOOOOOO!!!!!!!!!!!",440,200,800,50);
            SDL_RenderPresent(Space.pRenderer);
            SDL_RenderClear(Space.pRenderer);
            SDL_Delay(1500);
        }
    }
    return 0;
}

