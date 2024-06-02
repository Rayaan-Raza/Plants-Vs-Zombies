#pragma once
#include"Plant.h"
class offensivePlant : public Plant
{
protected:
    int shootingfrequency;
    int Damage;

    int shootingFrequency = 600; // in milliseconds
    sf::Clock shootingClock;

public:
    // Getter and setter for 'shootingFrequency'
    void setShootingFrequency(int frequency);
    int getShootingFrequency() const;

    // Getter and setter for 'damage'
    void setDamage(int dmg);
    int getDamage() const;

    // Getter and setter for 'zombieInFront'



};

