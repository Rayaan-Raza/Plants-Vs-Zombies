#include "CherryBomb.h"

CherryBomb::CherryBomb(Coordinate P1)
{
    cost = 150;
    currFrame = 0;
    isRIP = false;
    sf::Texture t1[6];
    numOfTextures = 6;
    for (int i = 0; i < 6; i++)
    {
        string filename = "C:Images/assets/Plants/CherryBomb/CherryBomb_" + to_string(i) + ".png";
        t1[i].loadFromFile(filename);
    }
    setTextures(t1, t1);
    T1 = true;
    position.x = P1.x-5;
    position.y = P1.y;
    damageArea = sf::IntRect(position.x - explosionRadius, position.y - explosionRadius,
        explosionRadius * 2, explosionRadius * 2);
}

void CherryBomb::update()
{
    if (currFrame == 5)
    {
        isRIP = true;
        return;
    }
}

void CherryBomb::MainRender(sf::RenderWindow& window)
{

    CherryBomb::update();
    Plant::MainRender(window);
}
