#include "Walnut.h"

void Walnut::update()
{
    if (hp <= 30)
    {
        trigger = true;

    }
    if (trigger)
    {
        T2 = true;
        position.x += 5;
    }
    if (position.x >= 906)
    {
        isRIP = true;
    }
}
Walnut::Walnut(Coordinate P1)
{
    cost = 50;
    position = P1;
    isRIP = false;
    hp = 200;
    sf::Texture t1[15];
    sf::Texture t2[15];
    numOfTextures = 15;
    for (int i = 0; i < 15; i++)
    {
        string filename = "C:Images/assets/Plants/WallNut/WallNut/WallNut_" + to_string(i) + ".png";
        t1[i].loadFromFile(filename);
        filename = "C:Images/assets/Plants/WallNut/Wallnutb/New folder/Walnutb (" + to_string(i+1) + ").png";
        t2[i].loadFromFile(filename);
    }
    setTextures(t1, t2);
    T1 = true;
}

bool Walnut::getTrigger()
{
    return trigger;
}

void Walnut::MainRender(sf::RenderWindow& window)
{
    update();
    Plant::MainRender(window);
}
