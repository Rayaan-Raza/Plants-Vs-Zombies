#include "DolphinRiderZombie.h"
DolphinRiderZombie::DolphinRiderZombie(Coordinate p1) : Zombie(p1)
{
    hp = 100;
    damage = 10;
    speed = 10;
    for (int i = 0; i < numOfTextures; i++)
    {
        //setTexture
    }
}
