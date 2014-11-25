//
//  Person.hpp
//  Spacial
//
//  Created by Yiru on 08/01/2014.
//  Copyright (c) 2014 Yiru. All rights reserved.
//

#ifndef Spacial_Person_hpp
#define Spacial_Person_hpp

#include "Object.hpp"
#include "Missile.hpp"
#include <vector>

class Person : public Object{
public:
    /**constructeur**/
    Person(){}
    Person(int vie,int w,int h,int id):_vie(vie),Object(w,h,id){}
    
    /*accesseur  const*/
    const int& getVie() const;
    const int& getVieBegin() const;
    /*accesseur non const*/
    int getVie();
    int getVieBegin();
    /*set value*/
    void setVie(const int& vie);
    void setVieBegin(const int& vieBegin);
    /**deconstructeur**/
    ~Person(){}
    
    std::vector<Missile> _MissileList;
    //std::vector<Laser> _LaserList;
    
protected:
    int _vie;
    int _vieBegin;
};

#endif
