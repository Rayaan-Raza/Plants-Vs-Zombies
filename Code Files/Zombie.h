#pragma once
#include"Entity.h"

class Zombie : public Entity
{
protected:
    sf::Clock FreezingClock;
    Zombie** ptr;
    int hp = 60;
    int damage = 10;
    double speed = 0.6;
    bool isCollidingWithPlant = false;
    bool ZombieRIP = false;
    bool ZombieExplode = false;
    sf::Texture texture1[19];
    sf::Texture texture2[19];
    sf::Texture texture3[19];
public:

    Zombie()
    {
        hitBox.x = 100;
        hitBox.y = 100;
    }
    Zombie(Coordinate T1);
    // Getter and setter methods
    void setHp(int newHp);
    int getHp() const;

    sf::Clock getFreezingClock()
    {
        return FreezingClock;
    }
    void setDamage(int newDamage);
    int getDamage() const;

    void setSpeed(float newSpeed);
    float getSpeed() const;

    void setIsCollidingWithPlant(bool collisionStatus);
    bool getIsCollidingWithPlant() const;

    void setZombieExplode(bool value)
    {
        ZombieExplode = value;
    }
    void setZombieRIP(bool ripStatus);
    bool getZombieRIP() const;
    virtual int getnumOfBZ();
    virtual Zombie** getBZ() ;
    void virtual Ability();
    void update();
    void MainRender(sf::RenderWindow& window);

};

