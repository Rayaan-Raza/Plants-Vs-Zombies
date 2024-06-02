#pragma once
#include "Card.h"
#include"Projectile.h"
#include"Sun.h"

class Plant : public Entity
{
protected:
    bool addScore = 0;
    sf::IntRect boundingArea;
    int SrNo;
    int cost;
    bool isPressed = false;
    int hp = 100;
    bool zombieInFront = false;
    bool isRIP = false;
    int beingEaten = 0;
    sf::Clock eatingclock;
public:
    void update();
    Plant()
    {
        hitBox.x = 55;
        hitBox.y = 5;
    }
    bool getaddScore()
    {
        return addScore;
    }
    void setaddscore(bool value)
    {
        addScore = value;
    }
    virtual bool getTrigger()
    {
        return false;
    }
    virtual sf::IntRect getBoundingBox() {
        return boundingArea;

    }
    virtual Projectile* getProjectile()
    {
        return nullptr;
    }
    virtual Sun* getsuns()
    {
        return nullptr;
    }
    virtual int getnumOfProjectile()
    {
        return 0;
    }
    void MainRender(sf::RenderWindow& window);
    int getSrNo() const;
    int getCost() const;
    bool getIsPressed() const;
    int getHp() const;
    bool getIsRIP() const;
    int getBeingEaten() const;
    bool isZombieInFront() const;
    // Setters
    void setSrNo(int value);
    void setCost(int value);
    void setIsPressed(bool value);
    void setHp(int value);
    void setIsRIP(bool value);
    void setBeingEaten(int value);
    void setZombieInFront(bool inFront);

};

