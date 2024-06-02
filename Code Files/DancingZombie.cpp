#include "DancingZombie.h"
void DancingZombie::Ability()
{
    Coordinate C1 = position, C2 = position, C3 = position, C4 = position;
    C1.x += 100;
    C3.x += 200;
    C4.x += 300;
    if (leftRightMoving.getElapsedTime().asMilliseconds() >= 4000)
    {
        move = true;
        leftRightMoving.restart();
        directionToMove *= -1;
    }
    if (position.y <= 100)
    {
        directionToMove = 1;
    }
    else if (position.y >= 800)
    {
        directionToMove = -1;
    }
    if (position.y >= initialPos + 100 && directionToMove == 1)
    {
        cout << "end";
        move = false;
        initialPos = position.y;
    }
    else if (position.y <= initialPos - 100 && directionToMove == -1)
    {
        cout << "end";
        move = false;
        initialPos = position.y;

    }
    if (move)
    {
        position.y += speed * directionToMove;

    }
    if (SpawningBZombies.getElapsedTime().asMilliseconds() >= 10000 && move == false)
    {
        SpawnedZombies[numOfBZombies++] = new Zombie(C1);
        SpawnedZombies[numOfBZombies++] = new Zombie(C3);
        SpawnedZombies[numOfBZombies++] = new Zombie(C4);
        SpawningBZombies.restart();
    }
}


int DancingZombie::getnumOfBZ()
{
    return numOfBZombies;
}
void DancingZombie::MainRender(sf::RenderWindow& window)
{
    if(!ZombieRIP)
    DancingZombie::Ability();
    Zombie::MainRender(window);
}

DancingZombie::DancingZombie(Coordinate p1)
{
    sf::Texture textures2[11], textures1[11];
    initialPos = p1.y;
    position = p1;
    speed = 0.9;
    hp = 100;
    damage = 10;
    numOfTextures = 11;
    for (int i = 0; i < 11; i++)
    {
        string filename1 = "C:Images/assets/Zombies/FlagZombie/FlagZombie/FlagZombie_" + to_string(i) + ".png";
        string filename2;
        filename2 = "C:Images/assets/Zombies/FlagZombie/FlagZombieAttack/FlagZombieAttack_" + to_string(i) + ".png";
        textures1[i].loadFromFile(filename1);
        textures2[i].loadFromFile(filename2);
    }
    T1 = true;
    setTextures(textures1, textures2);
}
