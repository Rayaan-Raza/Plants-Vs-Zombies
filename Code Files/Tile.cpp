#include "Tile.h"

void Tile::setzone()
{
    zone = sf::IntRect(position.x, position.y, hitBox.x, hitBox.y);
}
bool Tile::getHasZombie()
{
    return  hasZombie;
}

Coordinate Tile::getCenter()
{
    Coordinate center;
    center.x = position.x;
    center.y = position.y;
    return center;
}
