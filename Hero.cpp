//
//  Hero.cpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
#include "Hero.hpp"

const int DOT_WIDTH = 50;
const int DOT_HEIGHT = 47;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;
const int MISSILE_WIDTH = 28;
const int MISSILE_HEIGHT =8;



Hero::Hero():_score(0)
{
    //Initialize the offsets
    _x = 0;
    _y = 0;
    
    //Initialize the velocity
    _xVel = 0;
    _yVel = 0;
	
	//set visible
	_visible = true;
	
	_w = DOT_WIDTH;
	_h = DOT_HEIGHT;
	for(size_t i = 0; i<HEROMISSILE_N; ++i)
	{
		_MissileList.push_back(Missile(i,0,MISSILE_WIDTH,MISSILE_HEIGHT));		
	}
		///////////manque laser/////////
	_vie = 10;
	
}
Hero::Hero(int w,int h){
    //Initialize the offsets
    _x = 0;
    _y = 0;
    
    //Initialize the velocity
    _xVel = 0;
    _yVel = 0;
	//Initialize le taille
	_w = w;
	_h = h;
	//set visible
	_visible = true;
	
	for(size_t i = 0; i<HEROMISSILE_N; ++i)
	{
		_MissileList.push_back(Missile(i,0,MISSILE_WIDTH,MISSILE_HEIGHT));		
	}
	_vie = 10;
	
}
/*accesseur*/
const int& Hero::getScore()const{
	return _score;
}
int Hero::getScore(){
	return _score;
}
void Hero::setScore(int score){
	_score = score;
}

void Hero::LanceMissile()
{
	bool notsend = true;	
	for(std::vector<Missile>::size_type i = 0; (i < _MissileList.size())&&notsend; ++i) 
	{
		if (_MissileList[i].getVisible() == false)
		{
			//_MissileList[i].setObject_x(_object.x+20);
			_MissileList[i].setX(_x+20);
			//_MissileList[i].setObject_y(_object.y-10);
			_MissileList[i].setY(_y+30);
			//_MissileList[i].setY(-3);
			//_MissileList[i].setVie(1);
			_MissileList[i].setVisible();
			notsend = false;
		}
	}

}
void Hero::LanceLaser(int T){
	if(_laser.getVisible()==false){
		_laser.setFiretime(T);
		_laser.setX(_x+50);
		_laser.setY(_y+25);
		_laser.setVisible();
	}
}

void Hero::handle_input(Timer& T)
{
    //If a key was pressed
    if( event.type == SDL_KEYDOWN )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: _yVel -= DOT_HEIGHT / 6; break;
            case SDLK_DOWN: _yVel += DOT_HEIGHT / 6; break;
            case SDLK_LEFT: _xVel -= DOT_WIDTH / 6; break;
            case SDLK_RIGHT: _xVel += DOT_WIDTH / 6; break;
			case SDLK_SPACE: LanceMissile();break;
			case SDLK_l: LanceLaser(T.get_ticks());break;
			default:break;
        }
    }
    //If a key was released
    else if( event.type == SDL_KEYUP )
    {
        //Adjust the velocity
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: _yVel += DOT_HEIGHT / 6; break;
            case SDLK_DOWN: _yVel -= DOT_HEIGHT / 6; break;
            case SDLK_LEFT: _xVel += DOT_WIDTH / 6; break;
            case SDLK_RIGHT: _xVel -= DOT_WIDTH / 6; break;
			default:break;
        }
    }
}
void Hero::CollisionAlien(std::vector<Alien> &ObjectList){
	for(std::vector<Alien>::size_type i = 0; i < ObjectList.size(); ++i){
		if (ObjectList[i].getVisible()){
			if (CheckCollision( *this , ObjectList[i])){
				_vie -= 1;	
				ObjectList[i].setUnvisible();
				
				//PlayExplosion(ObjectList[i].getX(),ObjectList[i].getY())
				if (_vie<=0){
					_visible = false;
					//PlayExplosion(ObjectList[i].getX(),ObjectList[i].getY())
				}	
				
			}	
		}
		for(std::vector<Missile>::size_type j = 0;j<ObjectList[i]._MissileList.size();++j){
			if (ObjectList[i]._MissileList[j].getVisible()){
				if(CheckCollision(*this, ObjectList[i]._MissileList[j])){
					std::cout<<ObjectList[i]._MissileList[j].getX()<<"hit"<<_x+_w<<" "<<ObjectList[i]._MissileList[j].getY()<<"hit"<<_y+_h<<std::endl;
					_vie -= 1;
					ObjectList[i]._MissileList[j].setUnvisible();
					
					if(_vie<=0){
						_visible = false;
						//PlayExplosion(ObjectList[i].getX(),ObjectList[i].getY())
					}
				}
			}
		}		
	}
}
void Hero::AttaquerAlien(std::vector<Alien> &ObjectList){
	for(std::vector<Missile>::size_type i = 0; i < _MissileList.size(); ++i) {
		if (_MissileList[i].getVisible()){
			for(std::vector<Alien>::size_type j = 0; j < ObjectList.size(); ++j){
				if (ObjectList[j].getVisible()){
					if (CheckCollision( _MissileList[i] , ObjectList[j])){
						ObjectList[j].setVie(0);
						ObjectList[j].setUnvisible();
						
						
						_MissileList[i].setUnvisible();	
						_score += 5;
					}
				}	
			}	
		}
	}
}
void Hero::LaserAlien(std::vector<Alien> &ObjectList){
	if(_laser.getVisible()){
		for(std::vector<Alien>::size_type j = 0; j < ObjectList.size(); ++j){
			if (ObjectList[j].getVisible()){
				if (CheckCollision( _laser , ObjectList[j])){
					//ObjetList[j].setVie(0);
					ObjectList[j].setUnvisible();
					
					//ObjetList[j].setMortx(ObjetList[j].getX() + 0.5*ObjetList[j].getTaille());
					//ObjetList[j].setMorty(ObjetList[j].getY() + 0.5*ObjetList[j].getTaille());
					//ObjetList[j].setMorti(1);
					//_MissileList[i].setVie(0);
					//_MissileList[i].setUnvisible();	
					_score += 5;
				}
			}	
		}	
	}
}