#pragma once
#include"Zombie.h"
#include"PlayerArea.h"
#include"Coordinate.h"
#include"zombieFactory.h"
class Wave 
{

public:

    int* noOfZombies;
    int sumofAll = 0;
    bool exists = true;
    Zombie*** totalZombies = new Zombie * *[4];
    PlayerArea a;
    Coordinate* positions;

    Wave(int* size);
    void Update(sf::RenderWindow& window);
    //~Wave();
    Zombie*** getTotalZombies();

};

