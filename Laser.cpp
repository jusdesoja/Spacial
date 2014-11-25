//
//  Laser.cpp
//  Projet_SDL
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//

#include "Laser.hpp"
/*accesseur const*/
const int& Laser::getFiretime()const{
	return _firetime;
}
/*accesseur non const*/
int Laser::getFiretime(){
	return _firetime;
}

/*set value*/
void Laser::setFiretime(int firetime){
	std::cout<<firetime<<std::endl;
	_firetime = firetime;
}

bool Laser::TestTime(int testtime){
	if (testtime - _firetime >= LASERPERIOD){
		_visible = false;
		return 1;
}
	else
		return 0;
}