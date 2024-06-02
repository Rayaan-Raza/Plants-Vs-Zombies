#include "FootballZombie.h"
void FootballZombie::MainRender(sf::RenderWindow& window)
{
    Zombie::MainRender(window);
    FootballZombie::Ability();
}
FootballZombie::FootballZombie(Coordinate p1)
{
    hp = 120;
    position.x = p1.x;
    position.y = p1.y;
    numOfTextures = 30;
    for (int i = 0; i < 30; i++)
    {
        string filename1 = "C:Images/assets/Zombies/zombies_new/zombies_new/FootballZombie/Football/Football_" + to_string(i) + ".png";
        texture[i].loadFromFile(filename1);
    }
    T1 = true;
    setTextures(texture, texture);
}

void FootballZombie::Ability()
{
    Zombie::Ability();
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
}

