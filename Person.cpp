//
//  Person.cpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//

#include "Person.hpp"


const int& Person::getVie()const{
    return _vie;
}
const int& Person::getVieBegin()const{
    return _vieBegin;
}

int Person::getVie(){
    return _vie;
}

int Person::getVieBegin(){
    return _vieBegin;
}
void Person::setVie(const int& vie){
    _vie = vie;
}
void Person::setVieBegin(const int &vieBegin){
    _vieBegin = vieBegin;
}
//void virtual Person::LanceMissile