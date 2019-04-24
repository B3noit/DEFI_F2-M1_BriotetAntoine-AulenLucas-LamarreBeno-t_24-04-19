#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>

typedef struct tGame{

     SDL_Window *pWindow;    //Fenêtre du jeu
     SDL_Renderer *pRenderer;//Renderer du jeu
     SDL_Texture *pTexture;  //Texture du jeu
     SDL_Surface *pSurface;//Surface de je]
     int nGameState;         //Etat du jeu, (reste ouvert dan sque l'on joue).

}tGame;

extern void handleEvents(tGame *tGame);

#endif // GAME_H_INCLUDED
