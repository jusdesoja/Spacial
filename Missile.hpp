//
//  Missile.hpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//

#ifndef __Spacial__Missile__HPP
#define __Spacial__Missile__HPP

#include "Object.hpp"
#define MISSILEVITESSE 15
class Missile : public Object{
public:
    Missile(int id,int camp,int w,int h){
		if(camp == 0)
			_xVel = MISSILEVITESSE;
    	else 
			_xVel = -MISSILEVITESSE;
		_visible = false;
		_yVel = 0;
		_x = 0;
		_y = 0;
		_id = id;
		//Initialize le taille
		_w = w;
		_h = h;
    }
    Missile(int id,int camp,int x,int y,int w,int h){
		if(camp == 0)
			_xVel = MISSILEVITESSE;
    	else
			_xVel = -MISSILEVITESSE;
		_x = x;
		_y = y;
		_yVel = 0;
		_visible = false;
		//Initialize le taille
		_w = w;
		_h = h;
    }
	
	bool TestOut(const int width);
	
};

#endif /* defined(__Spacial__Missile__) */
