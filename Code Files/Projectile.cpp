#include "Projectile.h"
void Projectile::update()
{
    if (active)
    {
        position.x += speed * dir;
    }
    else
    {
        //call destructor
    }
}
void Projectile::MainRender(sf::RenderWindow& window)
{
    if (active)
    {
        update();
        Entity::MainRender(window);
    }
}

void Projectile::init(sf::Texture texture[], double x, double y, int dir, int Damage, int numoftextures)//constructor + para constructor
{
    numOfTextures = numoftextures;
    setTextures(texture, texture);
    cout << "texture set";
    T1 = true;
    position.x = x - 10;
    position.y = y;
    this->speed = 12;
    this->dir = dir;
    this->damage = Damage;
    active = true;
}

Projectile::Projectile(int sr, sf::Texture& texture, bool Active, double x, double y, int dir, int damage)  //constructor + para constructor
{
    numOfTextures = 1;
    Sr = sr;
    active = Active;
    sprite.setTexture(texture);
    position.x = x;
    position.y = y;
    this->speed = speed;
    this->dir = dir;
    this->damage = damage;
    active = true;
}

void Projectile::setSr(int newSr) {
    Sr = newSr;
}
int Projectile::getSr() const {
    return Sr;
}

void Projectile::setSpeed(int newSpeed) {
    speed = newSpeed;
}
int Projectile::getSpeed() const {
    return speed;
}

void Projectile::setDirection(int newDir) {
    dir = newDir;
}
int Projectile::getDirection() const {
    return dir;
}

void Projectile::setActive(bool isActive) {
    active = isActive;
}
bool Projectile::isActive() const {
    return active;
}

void Projectile::setDamage(int newDamage) {
    damage = newDamage;
}
int Projectile::getDamage() {
    return damage;
}