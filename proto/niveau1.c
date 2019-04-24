
#include "niveau1.h"

int niveau1(tGame *Space)
{
//Creation de quelques couleurs SDL, normale qu'il y est des warnings si on ne les utilises pas.
SDL_Color black = {0,0,0,255}; //noire
SDL_Color white = {255,255,255,255}; //blanc
SDL_Color grey = {60,60,60,255}; //blanc
SDL_Color red = {255,0,0,255}; //rouge
SDL_Color green = {0,255,0,255}; //vert
SDL_Color blue = {0,0,255,255}; //bleu

//Tableau de caractère des chemins de nos images, CF le répertoire des images.
char cSprite[100][100]={"./Assets/Images/disjoncteurVide.png","./Assets/Images/porteFerme.png","./Assets/Images/space.jpg","./Assets/Images/fusibleBleu.png","./Assets/Images/porteOuverte.png",
                        "./Assets/Images/vaisseau.jpg","./Assets/Images/cartonOuvert.png","./Assets/Images/FusibleVert.png"};

tSprite Porte;//On déclare un sprite avec lequel le joueur peut interagir,
setFullSprite(&Porte, 630, 280, 450,450, cSprite[1], 0);//on l'initialise.
tSprite Disjoncteur;
setFullSprite(&Disjoncteur,50, 300, 150, 150, cSprite[0], 0);
tSprite FusibleBleu;
setFullSprite(&FusibleBleu, 100, 740, 64, 64, cSprite[3], 0);
tSprite FusibleVert;
setFullSprite(&FusibleVert, 1315, 710, 64, 64, cSprite[7], 0);
tSprite Carton;
setFullSprite(&Carton,1307,682,128,128,cSprite[6],0);

    while(Space->nGameState==1)//Grosse boucle du jeu qui tourne tant que le joueur ne quitte pas.
    {
        //Dans un premier temps on charge toutes les images.
        affichSpriteDecor(Space,cSprite,5,0,0,WINDOW_WIDTH,WINDOW_LENGTH);
        affichSpriteDecor(Space,cSprite,2,650,300,400,400);//Les éléments de décor inamovible non pas de structure donc on déclare tout la procedure d'affichage dédiée.
        affichSprite(Space,&Disjoncteur);
        affichSprite(Space,&Porte);
        affichSprite(Space,&FusibleBleu);
        affichSprite(Space,&FusibleVert);
        affichSprite(Space,&Carton);


        //On vérifie que le joueur joue et qu'il ne souhaite pas quitter la fenêtre.
        handleEvents(Space);

        dragNDrop(&FusibleBleu);
        dragNDrop(&Carton);
        dragNDrop(&FusibleVert);

        testClicked(&Porte);
        if (Porte.nClicked == 1)
        {
            if (testSuperpose(&FusibleBleu, &Disjoncteur)==1 && testSuperpose(&FusibleVert, &Disjoncteur)==1)
            {
                affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Ok ! Résumons, j'ouvre cette porte, toute la marchandise est perdu dans le vide et moi aussi... un instant...",500,400,665,20);
                affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"toute la marchandise est perdu dans le vide... et moi aussi... bah ça vaut bien ces 500 quantum-crédits de prime.",500,420,675,20);
                SDL_RenderPresent(Space->pRenderer);
                SDL_RenderClear(Space->pRenderer);
                SDL_Delay(6000);
                setSpriteChemin(&Porte,cSprite[4]);
                affichSpriteDecor(Space,cSprite,2,650,300,400,400);
                affichSprite(Space,&Porte);
                setSpriteClicked(&Porte,0);
                return 1;

            } else
            {
                affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"La porte est bloquée ! Il faut que je trouve un moyen de l'ouvrire, sinon 'Adieu la prime'...",500,400,600,20);
                affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Je suis payé pour saboter la marchandise de vaisseau et je vais y arriver ! Enfin... sans doute...",500,420,620,20);
                SDL_RenderPresent(Space->pRenderer);
                SDL_RenderClear(Space->pRenderer);
                SDL_Delay(8000);
                setSpriteClicked(&Porte,0);
            }
        }

        testClicked(&Disjoncteur);
        if (Disjoncteur.nClicked == 1)
        {
            if (testSuperpose(&FusibleBleu, &Disjoncteur)==1 && testSuperpose(&FusibleVert, &Disjoncteur)==1)
            {
                affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Je ne pense pas qu'il ai besoin de plus de fusible, si la porte ne fonctionne pas, j'abandonne !",100,400,600,20);
                SDL_RenderPresent(Space->pRenderer);
                SDL_RenderClear(Space->pRenderer);
                SDL_Delay(3000);
                setSpriteClicked(&Disjoncteur,0);

            }else if (testSuperpose(&FusibleBleu, &Disjoncteur)==1 || testSuperpose(&FusibleVert, &Disjoncteur)==1)
                {
                    affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Ça ne marche toujours pas ! On dirait que j'ai besoin d'un second fusible, la poisse !",100,400,600,20);
                    SDL_RenderPresent(Space->pRenderer);
                    SDL_RenderClear(Space->pRenderer);
                    SDL_Delay(3000);
                    setSpriteClicked(&Disjoncteur,0);
                }else
                    {
                        affichText(Space,"./Fonts/verdana.ttf",12,white,grey,"Le disjoncteur est vide, peut-être qu'avec des fusibles on pourrait le remettre en route.",100,400,600,20);
                        SDL_RenderPresent(Space->pRenderer);
                        SDL_RenderClear(Space->pRenderer);
                        SDL_Delay(3000);
                        setSpriteClicked(&Disjoncteur,0);
                    }
        }
        //On affiche tout
        SDL_RenderPresent(Space->pRenderer);
        SDL_RenderClear(Space->pRenderer);//Ecoute, moi du futur, j'ai la solution pour le lag dégeulasse quand le tete est affiché, je cré une variable pour le SDL delay de mon render,
                                        //quand je veux afficher du texte il faut le mettent le nombre de tic voulu et bim pb règlé
    }
    return 0;
}
