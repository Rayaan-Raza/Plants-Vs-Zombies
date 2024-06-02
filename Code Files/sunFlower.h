#pragma once
#include"Plant.h"

class sunFlower : public Plant
{
    
    sf::Clock sunSpawning;
    static const int maxSuns = 100;
    bool spawnSun = false;
    int time = 10;
    Sun suns[maxSuns];
    int noOfsuns = 0;
public:
    sunFlower(Coordinate P1 = 0);

    int getnumOfProjectile() override;
    Sun* getsuns();
    void update(sf::RenderWindow& window);
    void MainRender(sf::RenderWindow& window);
};
