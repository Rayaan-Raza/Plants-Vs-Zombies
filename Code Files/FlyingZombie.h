#pragma once
#include "Zombie.h"
class FlyingZombie : public Zombie
{
    sf::Texture texture[21]; //added logic

public:
    FlyingZombie(Coordinate p1);
    
    // Additional methods or attributes specific to FlyingZombie
};

