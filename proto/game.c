
#include "game.h"

/***********************
Principe L'état du jeu est initialisé à 1, il nous sert de booléen, si l'utilisateur ferme la fenêtre il passe à 0.

Entrée :L'état du jeu, tGame.nGameState .
.
Sortie : L'état du jeu.

Note :
**********************/
void handleEvents(tGame *tGame)
{
//VAR
SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
              tGame->nGameState=0;
              break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE: tGame->nGameState=0; break;

                    default : break;
                }
                break;

        default : break;

        }
    }
}
