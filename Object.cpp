//
//  Object.cpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//
#include "Object.hpp"

const int DOT_WIDTH = 20;
const int DOT_HEIGHT = 20;
const int SCREEN_WIDTH = 620;///pas tout à fait parraille avec ce qui dans test.cpp
const int SCREEN_HEIGHT = 460;///
const int SCREEN_BPP = 32;
using namespace std;

Object::Object(const Object& o){
	*this = o;
}
Object& Object::operator=(const Object& o){
//	_object = o._object;
	_x = o._x;
	_y = o._y;
	_xVel = o._xVel;
	_yVel = o._yVel;
	_id = o._id;
	_w = o._w;
    _h = o._h;
	_visible = o._visible;
	return *this;
}


/*accesseur const*/
const int& Object::getId() const{
	return _id;
}
const int& Object::getW() const{
	return _w;
}
const int& Object::getH() const{
	return _h;
}
const bool& Object::getVisible() const{
	return _visible;
}
//const int& getCamp() const;
/*accesseur non const*/
int Object::getX(){
	return _x;
}
int Object::getY(){
	return _y;
}
int Object::getXVel(){
	return _xVel;
}
int Object::getYVel(){
	return _yVel;
}
bool Object::getVisible(){
	return _visible;
}
//int getCamp();

/*set value*/

void Object::setW(const int& w){
	_w = w;
}
void Object::setH(const int& h){
    _h = h;
}
void Object::setX(const int& x){
	_x = x;
}
void Object::setY(const int& y){
	_y = y;
}
void Object::setXVel(const int& xv){
	_xVel = xv;
}
void Object::setYVel(const int& yv){
	_yVel = yv;
}
void Object::setId(const int & id){
	_id = id;
}
void Object::setVisible(){
	_visible = true;
}
void Object::setUnvisible(){
	_visible = false;
}
//void Object::setObject_x(const int& x){_object.x=x;}
//void Object::setObject_y(const int& y){_object.y=y;}

//void setCamp(const int& camp);


/*afficher l'objet dans le plan*/
void Object::ObjectShow(SDL_Surface *object, SDL_Surface *screen){
	SDL_Rect offset;
	//offset.x = _object.x;
	//offset.y = _object.y;
    offset.x = _x;
    offset.y = _y;
	SDL_BlitSurface(object,NULL,screen,&offset);
}

/*L'objet se bouge*/
void Object::Move()
{
    //Move the dot left or right
    _x += _xVel;
    
    //If the dot went too far to the left or right
    if( ( _x < 0 ) || ( _x + DOT_WIDTH > (SCREEN_WIDTH) ) )
    {
        //move back
        _x -= _xVel;
    }
    
    //Move the dot up or down
    _y += _yVel;
    
    //If the dot went too far up or down
    if( ( _y < 0 ) || ( _y + DOT_HEIGHT > (SCREEN_HEIGHT) ) )
    {
        //move back
        _y -= _yVel;
    }
}

bool Object::CheckCollision(const Object &A,const Object &B){
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;
	///** calculer les bords d'A 
	leftA = A._x;
	rightA = A._x + A._w;
	topA = A._y;
	bottomA = A._y + A._h;
	///** calculer les bords de B 
	leftB = B._x;
	rightB = B._x + B._w;
	topB = B._y;
	bottomB = B._y + B._h;

	if( bottomA <= topB ){
		return false;
	}
	if( topA >= bottomB ){
		return false;
	}
	if( rightA <= leftB ){
		return false;
	}
	if( leftA >= rightB ){
		return false;
	}
	return true;
}