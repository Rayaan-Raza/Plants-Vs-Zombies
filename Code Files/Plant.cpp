#include "Plant.h"
void Plant::update()
{
    if (hp <= 0)
    {
        isRIP = true;
    }
    if (beingEaten)
    {
        if (eatingclock.getElapsedTime().asMilliseconds() >= 2000)
        {
            cout << "Damage\n";
            hp -= 20;
            eatingclock.restart();
        }
    }
}

void Plant::MainRender(sf::RenderWindow& window)
{
    if (!isRIP)
    {
        Plant::update();
        Entity::MainRender(window);
    }
}

int Plant::getSrNo() const {
    return SrNo;
}

int Plant::getCost() const {
    return cost;
}

bool Plant::getIsPressed() const {
    return isPressed;
}

int Plant::getHp() const {
    return hp;
}

bool Plant::getIsRIP() const {
    return isRIP;
}

int Plant::getBeingEaten() const {
    return beingEaten;
}

// Setters
void Plant::setSrNo(int value) {
    SrNo = value;
}

void Plant::setCost(int value) {
    cost = value;
}

void Plant::setIsPressed(bool value) {
    isPressed = value;
}

void Plant::setHp(int value) {
    hp = value;
}

void Plant::setIsRIP(bool value) {
    isRIP = value;
}

void Plant::setBeingEaten(int value) {
    beingEaten = value;
}

void Plant::setZombieInFront(bool inFront) {
    zombieInFront = inFront;
}

bool Plant::isZombieInFront() const {
    return zombieInFront;
}