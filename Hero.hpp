//
//  Hero.hpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
#ifndef Hero_HPP_
#define Hero_HPP_
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
//#include "SDL/SDL_mixer.h"
#include "Person.hpp"
#include "Laser.hpp"
#include "Timer.hpp"
#include "Alien.hpp"
#include <vector>
#define HEROMISSILE_N 40////////////

class Hero : public Person {
public:
    //Initializes the variables
    Hero();
	Hero(int w,int h);
	//Hero( SDL_Surface* Screen):screen(Screen){}
	~Hero(){}
    /*accesseur*/
	const int& getScore()const;
	int getScore();
	void setScore(int score);
    //Takes key presses and adjusts the dot's velocity
    void handle_input(Timer& T);
    //Lance the missile
	void LanceMissile();
	void LanceLaser(int T);
	
	Laser _laser;
	//Mix_Music *bombe;
	SDL_Event event;
	
	
	void CollisionAlien(std::vector<Alien> &ObjectList);
	void AttaquerAlien(std::vector<Alien> &ObjectList);
	void LaserAlien(std::vector<Alien> &ObjectList);
	
protected:
	int _score;
	
	
};


#endif