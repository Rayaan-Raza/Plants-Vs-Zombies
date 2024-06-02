#include "zombieFactory.h"

Zombie* zombieFactory::makeZombie(int serialOfZombie, Coordinate p1)
{
    Zombie* zombieMade;
    switch (serialOfZombie)
    {
    case 0:
        zombieMade = new Zombie(p1);
        break;
    case 1:
        zombieMade = new FootballZombie(p1);
        break;
    case 2:
        zombieMade = new FlyingZombie(p1);
        break;
    case 3:
        zombieMade = new DancingZombie(p1);
        p1.print();
        break;
    case 4:
        zombieMade = new DancingZombie(p1);
        break;
    default:
        zombieMade = nullptr;
        break;
    }
    return zombieMade;
}
