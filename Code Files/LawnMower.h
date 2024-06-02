#pragma once
#include"Entity.h"
//fake
class LawnMower : public Entity
{
    bool isTriggered = false;
    int speed = 5;
    bool offZone = false;
public:
    bool getOffzone();
    bool getTriggered();
    void setTriggered(bool value);
    void set_speed(int a);
    int getspeed();
    void Update();
    void MainRender(sf::RenderWindow& window);
    LawnMower* makeLawnMowers();
};

