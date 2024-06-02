#pragma once
#include"Zombie.h"
#include"Coordinate.h"
class DancingZombie : public Zombie
{
public:
    int directionToMove = 1;
    int initialPos;
    bool move = false;
    sf::Clock leftRightMoving;
    sf::Clock SpawningBZombies;
    int  time = 8000;
    Zombie** SpawnedZombies = new Zombie * [12];
    int numOfBZombies = 0;
public:

    int getnumOfBZ();
    virtual Zombie** getBZ()
    {
        return SpawnedZombies;
    }
    DancingZombie(Coordinate p1);
    void Ability();
    void MainRender(sf::RenderWindow& window);
};

