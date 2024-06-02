#pragma once
#include"Plant.h"
class Walnut : public Plant
{
    bool trigger = false;

public:
    Walnut(Coordinate P1);
    void MainRender(sf::RenderWindow& window);
    void update();
    bool getTrigger();
};

