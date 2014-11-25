//
//  Object.cpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
#include "Space.hpp"
#define LARGEUR_FENETRE   640  //TAILLE_BLOC * NB_BLOCS_LARGEUR
#define HAUTEUR_FENETRE  480 
int main( int argc, char* args[] ){
	Space space;
	
	SDL_Surface *ecran = NULL, *menu = NULL;
	SDL_Rect positionMenu;
	SDL_Event event;
	SDL_Surface *instruc = NULL;
	int continuer = 1;
	int flag;
	SDL_Init(SDL_INIT_VIDEO);

	//SDL_WM_SetIcon(IMG_Load("caisse.jpg"), NULL); // L'icÙne doit Ítre chargÈe avant SDL_SetVideoMode
	ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Conquête Spacial", NULL);

	menu = IMG_Load("images/menu1.jpg");
	instruc = IMG_Load("images/instruc.jpg");
	positionMenu.x = 0;
	positionMenu.y = 0;

	while (continuer)
	{
		SDL_WaitEvent(&event);
	    switch(event.type)
	    {
	        case SDL_QUIT:
				continuer = 0;
	            break;
	        case SDL_KEYDOWN:
	            switch(event.key.keysym.sym)
	            {
	                case SDLK_ESCAPE: // Veut arrÍter le jeu
	                    continuer = 0;
	                    break;
	                case SDLK_SPACE: // Demande à jouer
						continuer = 1;
						SDL_BlitSurface(instruc, NULL, ecran, &positionMenu);
						SDL_Flip(ecran);
						SDL_Delay(1000);
	                  	flag = space.Battle();
						if ((flag == 1)||(flag == 3))
							continuer = 0;
						else if (flag == 2)
							space.RecordScore(space.getHero().getScore(),"Yiru");///////enregistrer le score
													
	                        break;
	                case SDLK_s: // Demande l'Èditeur de niveaux
						continuer = 1;
					    space.ReadScore("record.dat");
	                    break;
	                }
	                break;
	        }

	        // Effacement de l'Ècran
	        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
	        SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
	        SDL_Flip(ecran);
	    }

	    SDL_FreeSurface(menu);
	    SDL_Quit();

	    return EXIT_SUCCESS;
	

}