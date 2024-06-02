#pragma once
#include "Entity.h"

class Projectile : public Entity
{
public:

    int Sr = -999;
    int speed = 10;
    int dir;
    bool active;
    int damage = 0;

    Projectile()
    {
        hitBox.x = 30;
        hitBox.y = 30;
    }
    Projectile(int sr, sf::Texture& texture, bool Active = false, double x = 6000, double y = 6000, int dir = 0, int damage = 0);  //constructor + para constructor

    void init(sf::Texture texture[], double x, double y, int dir = 0, int damage = 0, int numoftextures = 1);  //constructor + para constructor
    void update();
    void MainRender(sf::RenderWindow& window);
    ~Projectile() {}

    // Getter and setter methods
    void setSr(int newSr);
    int getSr() const;

    void setSpeed(int newSpeed);
    int getSpeed() const;

    void setDirection(int newDir);
    int getDirection() const;

    void setActive(bool isActive);
    bool isActive() const;

    void setDamage(int newDamage);
    int getDamage();
};
