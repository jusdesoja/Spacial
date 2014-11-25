//
//  Object.hpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//
#ifndef Object_HPP_
#define Object_HPP_

#include <stdlib.h>
#include <iostream>
#include <string>
#include <ctime>
#include <vector> 

#include <SDL/SDL.h>


class Object{
public:
	
	/*constructeur par défaut*/
	Object(){}
	
	/*constructeur avec parametres*/
	Object(int w,int h):_w(w),_h(h),_visible(true){
		
		_x = 0;
		_y = 0;
		_xVel = 0;
		_yVel = 0;
	}
	Object(int w,int h,int id):_w(w),_h(h),_id(id),_visible(true){
		_w = w;
		_h = h;
		_x = 0;
		_y = 0;
		_xVel = 0;
		_yVel = 0;
	}
	
	/*constructeur de copie*/
	Object(const Object& o);
	/*operateur*/
	Object& operator=(const Object& o);
	
	/*accesseur const*/
	const int& getId() const;
	const int& getH() const;
    const int& getW() const;
	const bool& getVisible() const;
	//const int& getCamp() const;
	/*accesseur non const*/
	int getX();
	int getY();
	int getXVel();
	int getYVel();
	bool getVisible();
	int getCamp();
	
	/*set value*/
	
	void setW(const int& w);
    void setH(const int& h);
	void setX(const int& x);
	void setY(const int& y);
	void setXVel(const int& xv);
	void setYVel(const int& yv);
	void setId(const int & id);
	void setVisible();
	void setUnvisible();
	//void setObject_x(const int& x);
	//void setObject_y(const int& y);
	//void setCamp(const int& camp);
	/*l'objet se bouge*/
	void Move();
	/*afficher l'objet dans le plan*/
	void ObjectShow(SDL_Surface *object, SDL_Surface *screen);
	//virtual void Move(){};
	bool CheckCollision(const Object &A,const Object &B);
	/*déconstructeur*/
	~Object(){}
protected:
	//SDL_Rect _object;
	int _x,_y;
	int _xVel ; 
	int _yVel ;
	//int _taillex;
    //int _tailley;
	int _id;
	bool _visible;
	int _camp;
	int _w;
	int _h;
};
#endif
