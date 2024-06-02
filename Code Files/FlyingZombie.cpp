#include "FlyingZombie.h"

FlyingZombie::FlyingZombie(Coordinate p1)
{
    position = p1;
    hp = 100;
    damage = 10;
    speed = 0.6;
    numOfTextures = 21;
    for (int i = 0; i < 21; i++)
    {
        string filename1 = "C:Images/assets/Zombies/zombies_new/zombies_new/BalloonZombie/balloon/Balloon_" + to_string(i) + ".png";
        texture[i].loadFromFile(filename1);
    }
    this->T1 = true;
    setTextures(texture, texture);
}
