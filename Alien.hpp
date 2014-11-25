//
//  Alien.hpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//
#ifndef Spacial_Alien_hpp
#define Spacial_Alien_hpp

#include "Person.hpp"

#define ALIENVITESSE -5
#define ALIENMISSILE_N 1
class Alien: public Person{
public:
	Alien();
	Alien(int y,int w,int h);
	Alien(int id,int y,int w,int h);
	/*accesseur const*/
	const bool& getOutFlag()const; 
	/*accesseur non const*/
	bool getOutFlag();
	
	void setOutFlag(bool flag);
	bool TestOut(const int& borne);
	void LanceMissile();
protected:
	bool _OutFlag;
};

#endif