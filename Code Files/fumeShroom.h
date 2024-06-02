#pragma once
#include "peaShooter.h"
class fumeShroom :
    public peaShooter
{
    sf::Texture fume[5];
    double initialPos;
public:
    fumeShroom(Coordinate p1 = 0);
    void update(sf::RenderWindow& window);
    void MainRender(sf::RenderWindow& window);
};

