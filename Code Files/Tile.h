#pragma once
#include"Entity.h"
#include"Plant.h"

class Tile : public Entity
{
public:
    bool isFull = false;
    bool hasZombie = false;
    Plant* plant = nullptr;
    sf::IntRect zone;
public:
    void setzone();
    bool getHasZombie();
    Coordinate getCenter();
};

