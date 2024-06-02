#include "sunFlower.h"

sunFlower::sunFlower(Coordinate P1)
{
    position = P1;
    cost = 100;
    numOfTextures = 18;
    sf::Texture t1[18];
    string filename;
    for (int i = 0; i < 18; i++)
    {
        filename = "C:Images/assets/Plants/SunFlower/SunFlower_" + to_string(i) + ".png";
        t1[i].loadFromFile(filename);
    }
    T1 = true;

    setTextures(t1, t1);
}
int sunFlower::getnumOfProjectile()
{
    return noOfsuns;
}

Sun* sunFlower::getsuns()
{
    return suns;
}
void sunFlower::MainRender(sf::RenderWindow& window)
{
    for (int i = 0; i < noOfsuns; i++)
    {
        suns[i].MainRender(window);
    }
    sunFlower::update(window);
    Plant::MainRender(window);
}

void sunFlower::update(sf::RenderWindow& window)
{
    if (hp <= 0)
    {
        isRIP = true;
        return;
    }
    if (sunSpawning.getElapsedTime().asSeconds() >= time)
    {
        if (noOfsuns < maxSuns)
        {
            cout << "Spawn\n";
            suns[noOfsuns++].Spawn(false, position);
            sunSpawning.restart();
        }

    }
    for (int i = 0; i < noOfsuns; i++) {
        if (suns[i].getisPressed()) { 
            addScore = true;// Remove inactive peas
            suns[i] = suns[--noOfsuns];  // Move the last active pea to the current spot
        }

    }

}