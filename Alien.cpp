//
//  Alien.cpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//

#include "Alien.hpp"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 480;
const int BORNE_GAUCHE = 5;
const int BULLET_WIDTH = 10;
const int BULLET_HEIGHT= 8;

Alien::Alien(){
	_xVel = ALIENVITESSE;
	_x = SCREEN_WIDTH;
	_yVel = 5;
	_y = 0;
	_vie = 1;
	_OutFlag = true;
	for(size_t i = 0; i<ALIENMISSILE_N; ++i)
	{
		_MissileList.push_back(Missile(i,1,BULLET_WIDTH,BULLET_HEIGHT));		
	}
}
Alien::Alien(int id,int w,int h){
	_xVel = ALIENVITESSE;
	_yVel = 5;
	_x = SCREEN_WIDTH;
	_y = 0;
	_id = id;
	_vie = 1;
	_OutFlag = true;
	//Initialize le taille
	_w = w;
	_h = h;
	for(size_t i = 0; i<ALIENMISSILE_N; ++i)
	{
		_MissileList.push_back(Missile(i,1,BULLET_WIDTH,BULLET_HEIGHT));		
	}
}
Alien::Alien(int id,int y,int w, int h){
	_id = id;
	_xVel = ALIENVITESSE;
	_yVel = 5;
	_x = SCREEN_WIDTH;
	_y = y;
	_vie = 1;
	_OutFlag = true;
	//Initialize le taille
	_w = w;
	_h = h;
	for(size_t i = 0; i<ALIENMISSILE_N; ++i)
	{
		_MissileList.push_back(Missile(i,1,BULLET_WIDTH,BULLET_HEIGHT));		
	}
}
bool Alien::TestOut(const int& borne){
	if (_x <= borne){
		
		_OutFlag = true;
		return true;
	}
	else
		return false;
}

const bool& Alien::getOutFlag()const{
	return _OutFlag;
}
/*accesseur non const*/
bool Alien::getOutFlag(){
	return _OutFlag;
}

void Alien::setOutFlag(bool flag){
	_OutFlag = flag;
}

void Alien::LanceMissile(){
	bool notsend = true;	
	for(std::vector<Missile>::size_type i = 0; (i < _MissileList.size())&&notsend; ++i) 
	{
		if (_MissileList[i].getVisible() == false)
		{
			//_MissileList[i].setObject_x(_object.x+20);
			_MissileList[i].setX(_x-20);
			//_MissileList[i].setObject_y(_object.y-10);
			_MissileList[i].setY(_y);
			//_MissileList[i].setY(-3);
			//_MissileList[i].setVie(1);
			_MissileList[i].setVisible();
			notsend = false;
		}
	}
}