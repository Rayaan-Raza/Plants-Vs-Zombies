#include "FrozenPeaShooter.h"

FrozenPeaShooter::FrozenPeaShooter(Coordinate P1 = 0)
{
    cost = 200;
    Damage = 20;
    shootingFrequency = 3000;
    numOfTextures = 13;
    position = P1;
    for (int i = 0; i < 13; i++)
    {
        projectileTexture[0].loadFromFile("C:Images/assets/Bullets/peaIce/icepea.png");
        string filename = "C:Images/assets/Plants/SnowPea/SnowPea_" + to_string(i) + ".png";
        texture1[i].loadFromFile(filename);
        texture2[i].loadFromFile(filename);
        T1 = true;
    }
    setTextures(texture1, texture2);
}

void FrozenPeaShooter::update()
{
    if (hp <= 0)
    {
        isRIP = true;
        return;
    }
    // Check for zombie presence and shooting frequency
    if (zombieInFront && shootingClock.getElapsedTime().asMilliseconds() >= shootingFrequency) {
        if (noOfpeas < maxPeas) {  // Ensure there is space for a new pea
            peas[noOfpeas++].init(projectileTexture, position.x + hitBox.x, position.y + hitBox.y / 2, 1, Damage);
            shootingClock.restart();
        }
    }

    // Update the position of each pea and check for active status
    for (int i = 0; i < noOfpeas; ) {
        if (!peas[i].active) {  // Remove inactive peas
            peas[i] = peas[--noOfpeas];  // Move the last active pea to the current spot
        }
        else {
            peas[i].update();  // Move active peas
            i++;
        }
    }
}
