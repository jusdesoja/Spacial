//
//  Laser.hpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//

#ifndef __Projet_SDL__Laser__HPP
#define __Projet_SDL__Laser__HPP

//#include <iostream>

#include "Object.hpp"
#define LASERPERIOD 1
#define LASER_WIDTH 600
#define LASER_HEIGHT 5
class Laser: public Object{
public:
	Laser(){
		_xVel = 0;
		_yVel = 0;
		//Initialize le taille
		_w = LASER_WIDTH;
		_h = LASER_HEIGHT;
	}
    Laser(int id){
    	_visible = false;
		_id = id;
		_xVel = 0;
		_yVel = 0;
		//Initialize le taille
		_w = LASER_WIDTH;
		_h = LASER_HEIGHT;
    }
	
	/*accesseur const*/
	const int& getFiretime()const;
	/*accesseur non const*/
	int getFiretime();
	
	/*set value*/
	void setFiretime(int firetime);
	
	bool TestTime(int time);
	
	
protected:
	int _firetime;
	
};
#endif /* defined(__Projet_SDL__Laser__) */
