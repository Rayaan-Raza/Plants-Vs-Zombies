#include "Zombie.h"

void Zombie::Ability()
{
    if (FreezingClock.getElapsedTime().asSeconds() == 10)
        speed = 0.6;
    if (isCollidingWithPlant)
    {
        T2 = true;
    }
    else if (ZombieExplode)
    {
        if (Texture3 == nullptr)
        {
            ZombieRIP = true;
        }
        else
        {
            T3 = true;
            if (currFrame == 18)
            {
                ZombieRIP = true;
            }
        }

    }
    else
    {
        T1 = true;
        position.x -= speed;
    }
}

void Zombie::update()
{
    if (hp <= 0)
    {
        ZombieRIP = true;
    }
    Zombie::Ability();
}

void Zombie::MainRender(sf::RenderWindow& window)
{
    if (!ZombieRIP)
    {
        Zombie::update();
        Entity::MainRender(window);
    }
}

Zombie::Zombie(Coordinate T1 = 0)
{
    position = T1;
    numOfTextures = 19;
    for (int i = 0; i < 19; i++)
    {
        string filename1 = "C:Images/assets/Zombies/NormalZombie/Zombie/Zombie_" + to_string(i) + ".png";
        string filename2;
        string filename3;
            filename2 = "C:Images/assets/Zombies/NormalZombie/ZombieAttack/ZombieAttack_" + to_string(i) + ".png";
        filename3 = "C:Images/assets/Zombies/NormalZombie/BoomDie/BoomDie_" + to_string(i) + ".png";

        texture1[i].loadFromFile(filename1);
        texture2[i].loadFromFile(filename2);
        texture3[i].loadFromFile(filename3);
    }
    T1 = true;
    setTextures(texture1, texture2, texture3);
}

// Virtual function implementations
int Zombie::getnumOfBZ()
{
    return -1;
}

Zombie** Zombie::getBZ()
{
    return ptr;
}

void Zombie::setHp(int newHp)
{
    hp = newHp;
}

int Zombie::getHp() const
{
    return hp;
}

void Zombie::setDamage(int newDamage)
{
    damage = newDamage;
}

int Zombie::getDamage() const
{
    return damage;
}

void Zombie::setSpeed(float newSpeed)
{
    speed = newSpeed;
}

float Zombie::getSpeed() const
{
    return speed;
}

void Zombie::setIsCollidingWithPlant(bool collisionStatus)
{
    isCollidingWithPlant = collisionStatus;
}

bool Zombie::getIsCollidingWithPlant() const
{
    return isCollidingWithPlant;
}

void Zombie::setZombieRIP(bool ripStatus)
{
    ZombieRIP = ripStatus;
}

bool Zombie::getZombieRIP() const
{
    return ZombieRIP;
}

