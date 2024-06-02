#include "LawnMower.h"

bool LawnMower::getOffzone()
{
    return offZone;
}
LawnMower* LawnMower::makeLawnMowers()
{
    LawnMower* cars = new LawnMower[5];
    sf::Texture t1[1];
    t1[0].loadFromFile("C:Images/assets/Inventory-GameScreen/car.png");
    for (int i = 0; i < 5; i++)
    {
        cars[i].position = { 170, static_cast<float>(100 + i * 95) };
        cars[i].hitBox = { 80, static_cast<float>(65) };
        cars[i].numOfTextures = 1;
        cars[i].setTextures(t1, t1);
        cars[i].T1 = true;
    }
    return cars;
}
void LawnMower::Update()
{
    if (position.x >= 906)
    {
        offZone = true;
    }
    if (isTriggered == true)
    {
        {
            position.x += speed;
        }
    }
}
void LawnMower::MainRender(sf::RenderWindow& window)
{
    if (!offZone)
    {
        Update();
        Entity::MainRender(window);
    }

}

void LawnMower::set_speed(int a)
{
    this->speed = a;
}
int LawnMower::getspeed()
{
    return this->speed;
}

bool LawnMower::getTriggered()
{
    return isTriggered;
}
void LawnMower::setTriggered(bool value)
{
    isTriggered = value;
}