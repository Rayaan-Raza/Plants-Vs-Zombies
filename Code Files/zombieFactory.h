#pragma once
#include"Zombie.h"
#include"Coordinate.h"
#include "FootballZombie.h"
#include "FlyingZombie.h"
#include "DancingZombie.h"
#include "DolphinRiderZombie.h"
class zombieFactory
{
public:
    Coordinate posToMake;
    Zombie* makeZombie(int serialOfZombie, Coordinate p1);

};

