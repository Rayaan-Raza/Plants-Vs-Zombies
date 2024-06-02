#include "peaShooter.h"

void peaShooter::update()
{
    // Check for zombie presence and shooting frequency
    if (zombieInFront && shootingClock.getElapsedTime().asMilliseconds() >= 1200) {
        if (noOfpeas < maxPeas) {
            cout << "Pea Shot\n";// Ensure there is space for a new pea
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
            i++;
        }
    }
}

void peaShooter::MainRender(sf::RenderWindow& window)
{
    for (int i = 0; i < noOfpeas; i++)
    {
        peas[i].MainRender(window);
    }
    peaShooter::update();
    Plant::MainRender(window);
}

peaShooter::peaShooter(Coordinate P1 = 0)
{
    cost = 100;
    Damage = 20;
    shootingFrequency = 3000;
    numOfTextures = 13;
    position = P1;
    for (int i = 0; i < 13; i++)
    {
        projectileTexture[0].loadFromFile("C:Images/assets/Bullets/peaNormal/pea.png");
        string filename = "C:Images/assets/Plants/Peashooter/Peashooter_" + to_string(i) + ".png";
        texture1[i].loadFromFile(filename);
        texture2[i].loadFromFile(filename);
        T1 = true;
    }
    setTextures(texture1, texture2);
}
