//
//  Missile.cpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//

#include "Missile.hpp"
bool Missile::TestOut(const int width){
	
	if ((_x >= width)||(_x<11))
		return true;
	else
		return false;
}
