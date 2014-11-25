//
//  Space.hpp
//  spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//
#ifndef Space_hpp_
#define Space_hpp_
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Object.hpp"
#include "Missile.hpp"
#include "Hero.hpp"
#include "Person.hpp"

#include "Laser.hpp"
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <cassert>
//le nombre d'alien comme enemie
#define ALIEN_N 3
#define DOT_WIDTH 50
#define DOT_HEIGHT 47
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP 32
#define ALIEN_WIDTH 50
#define ALIEN_HEIGHT 47
#define FRAMES_PER_SECOND 20

class Space{
public:
	Space(){}
	~Space(){}
	void Init_Alien();
	void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination);
	SDL_Surface *load_image( std::string filename );
	bool init();
	bool load_files();
	void clean_up();
	void MoveAllObject();
	void TestCollision(Hero& hero);
	void ShowAllObject();
	void RecordScore(int score,std::string name);
	void ReadScore(std::string filename);
	int Battle();
	void ShowInformation(Hero myHero,SDL_Surface * screen);
	Hero getHero();
	void ResetGame();
	std::string itos(int i);
protected:
	//The dimensions of the dot
	/*const int DOT_WIDTH = 50;
	const int DOT_HEIGHT = 47;

	//Screen attributes
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int SCREEN_BPP = 32;

	//Taille d'alien
	const int ALIEN_WIDTH = 50;
	const int ALIEN_HEIGHT = 47;
	//The frame rate
	const int FRAMES_PER_SECOND = 20;
*/
	//The surfaces
	SDL_Surface *dot ;
	SDL_Surface *background ;
	SDL_Surface *screen ;
	SDL_Surface *missile ;
	SDL_Surface *laser ;
	SDL_Surface *alien ;
	SDL_Surface *alien_bullet ;
	SDL_Surface *explosion;
	SDL_Surface *information1;
	SDL_Surface *information2;
	SDL_Surface *information3;
	SDL_Surface *information4;
	SDL_Color textColor;
	TTF_Font *font;
	Mix_Music *musique;
	//The background music
	//Mix_Music * music = NULL;
	//déclaration de Hero
	Hero myHero;

	//The Aliens
	std::vector<Alien> _AlienList;
    //The frame rate regulator
    Timer fps;
	
};
#endif