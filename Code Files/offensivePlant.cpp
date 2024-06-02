#include "offensivePlant.h"
// Setter and getter for 'shootingFrequency'
void offensivePlant::setShootingFrequency(int frequency) {
    shootingFrequency = frequency;
}

int offensivePlant::getShootingFrequency() const {
    return shootingFrequency;
}

// Setter and getter for 'damage'
void offensivePlant::setDamage(int dmg) {
    Damage = dmg;
}

int offensivePlant::getDamage() const {
    return Damage;
}

// Setter and getter for 'zombieInFront'
