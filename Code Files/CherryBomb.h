#pragma once
#include"Plant.h"

class CherryBomb : public Plant
{
private:
    sf::Clock explosionClock;  // Timer to manage explosion delay
    int explosionDelay = 2000; // Delay in milliseconds before explosion
    int damage = 150;          // Damage caused by the explosion
    int explosionRadius = 200; // Radius of the explosion effect
    bool hasExploded = false;  // Flag to check if explosion has happened
    bool flag = false;
    Coordinate p1 = position;
    sf::IntRect damageArea;
public:
    CherryBomb()
    {

    }
    sf::IntRect getBoundingBox() {
        return damageArea;

    }
    CherryBomb(Coordinate P1);

    void update();

    void MainRender(sf::RenderWindow& window);
};

