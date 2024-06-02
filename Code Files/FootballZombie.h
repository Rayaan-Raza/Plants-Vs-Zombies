#pragma once
#include "Zombie.h"
class FootballZombie : public Zombie
{
private:
    int directionToMove = 1;
    int initialPos;
    bool move = false;
    sf::Clock leftRightMoving;
    sf::Texture texture[30];
public:
    void MainRender(sf::RenderWindow& window);
    FootballZombie(Coordinate p1);
    void Ability();
};

