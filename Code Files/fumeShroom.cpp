#include "fumeShroom.h"


fumeShroom::fumeShroom(Coordinate p1)
{
    cost = 75;
    Damage = 5;
    initialPos = p1.x;
    sf::Texture t1[14];
    position = p1;
    shootingFrequency = 3000;
    numOfTextures = 14;
    for (int i = 0; i < 14; i++)
    {
        string filename;
        if (i < 5)
        {
            filename = "C:Images/assets/Bullets/BulletMushRoom/BulletMushRoom_" + to_string(i) + ".png";
            fume[i].loadFromFile(filename);
        }
        filename = "C:Images/assets/Plants/fume/fume/fumeShroom (" + to_string(i+1) + ").png";
        t1[i].loadFromFile(filename);
    }
    setTextures(t1, t1);
    T1 = true;
}

void fumeShroom::MainRender(sf::RenderWindow& window)
{
    fumeShroom::update(window);
    Plant::MainRender(window);
}

void fumeShroom::update(sf::RenderWindow &window)
{

    if (hp <= 0)
    {
        isRIP = true;
        return;
    }

    // Check for zombie presence and shooting frequency
    if (zombieInFront && shootingClock.getElapsedTime().asMilliseconds() >= 1500) {
        if (noOfpeas < maxPeas) {  // Ensure there is space for a new pea
            peas[noOfpeas++].init(fume, position.x + hitBox.x, position.y + hitBox.y / 2, 1, Damage, 5);
            shootingClock.restart();

        }
    }


    // Update the position of each pea and check for active status
    for (int i = 0; i < noOfpeas; ) {
        if (!peas[i].active || peas[i].getPosition().x >= initialPos + 300) {  // Remove inactive peas
            peas[i] = peas[--noOfpeas];  // Move the last active pea to the current spot
        }
        else {
            peas[i].MainRender(window);  // Move active peas
            i++;
        }
    }
}
