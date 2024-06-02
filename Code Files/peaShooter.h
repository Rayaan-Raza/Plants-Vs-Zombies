#pragma once
#include"offensivePlant.h"
class peaShooter : public offensivePlant
{
protected:
    static const int maxPeas = 100;
    Projectile peas[maxPeas];
    int noOfpeas = 0;
    sf::Texture projectileTexture[1];
    sf::Texture texture1[13];
    sf::Texture texture2[13];


public:
    peaShooter()
    {
        Damage = 20;

    }
    Projectile* getProjectile()
    {
        return peas;
    }
    int getnumOfProjectile()
    {
        return noOfpeas;
    }
    peaShooter(Coordinate P1);
    void update();
    void MainRender(sf::RenderWindow& window);
};

