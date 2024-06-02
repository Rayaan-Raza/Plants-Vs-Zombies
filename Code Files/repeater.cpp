#include "repeater.h"

repeater::repeater(Coordinate P1)
{
    cost = 200;
    sf::Texture t1[15];
    position = P1;
    Damage = 20;
    shootingFrequency = 3000;
    numOfTextures = 15;
    for (int i = 0; i < 15; i++)
    {
        projectileTexture[0].loadFromFile("C:Images/assets/Bullets/peaNormal/pea.png");
        string filename = "C:Images/assets/Plants/RepeaterPea/RepeaterPea_" + to_string(i) + ".png";
        t1[i].loadFromFile(filename);
    }
    setTextures(t1, t1);
    T1 = true;
}

void repeater::MainRender(sf::RenderWindow& window)
{
    repeater::update(window);
    Plant::MainRender(window);
}

void repeater::update(sf::RenderWindow& window)
{

    if (hp <= 0)
    {
        isRIP = true;
        return;
    }

    // Check for zombie presence and shooting frequency
    if (zombieInFront && shootingClock.getElapsedTime().asMilliseconds() >= 1500) {
        if (noOfpeas < maxPeas) {  // Ensure there is space for a new pea
            peas[noOfpeas++].init(projectileTexture, position.x + hitBox.x, position.y + hitBox.y / 2, 1, Damage);
            shootSecondPea = true;
            secondaryClock.restart();
            shootingClock.restart();

        }
    }

    if (shootSecondPea && secondaryClock.getElapsedTime().asMilliseconds() >= 200)
    {
        cout << "SecondPea";
        peas[noOfpeas++].init(projectileTexture, position.x + hitBox.x, position.y + hitBox.y / 2, 1, Damage);

        shootSecondPea = false;
        shootingClock.restart();
    }

    // Update the position of each pea and check for active status
    for (int i = 0; i < noOfpeas; ) {
        if (!peas[i].active) {  // Remove inactive peas
            peas[i] = peas[--noOfpeas];  // Move the last active pea to the current spot
        }
        else {
            peas[i].MainRender(window);  // Move active peas
            i++;
        }
    }
}
