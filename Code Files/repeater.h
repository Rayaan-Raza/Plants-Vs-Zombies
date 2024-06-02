#pragma once
#include"peaShooter.h"
class repeater : public peaShooter
{
    sf::Clock secondaryClock;
    bool shootSecondPea = false;
public:
    repeater()
    {

    }
    repeater(Coordinate P1);
    void update(sf::RenderWindow& window);
    void MainRender(sf::RenderWindow& window);
};

