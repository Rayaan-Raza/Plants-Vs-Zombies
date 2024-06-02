#include "Level.h"
void Level::initWave()
{
    pArea = new PlayerArea;

    Card* c1 = new Card;
    cards = c1->makeCards(levelno + 1);
    delete c1;

    LawnMower* c2 = new LawnMower;
    cars = c2->makeLawnMowers();
    delete c2;

    if (levelno == 1)
    {
        wave1[0] = 1;
    }
    if (levelno == 2)
    {
        wave1[0] = 3;
        wave1[1] = 1;
    }
    if (levelno == 3)
    {
        backgroundTexture.loadFromFile("C:Images/assets/Background/bgsoil.jpg");
        wave1[0] = 3;
        wave1[1] = 3;
    }
    if (levelno == 4)
    {
        backgroundTexture.loadFromFile("C:Images/assets/Background/bgnight.jpg");
        wave1[0] = 3;
        wave1[1] = 2;
        wave1[2] = 1;
    }
    if (levelno == 5)
    {
        backgroundTexture.loadFromFile("C:Images/assets/Background/bgnight.jpg");
        wave1[0] = 1;
        wave1[1] = 2;
        wave1[2] = 2;
        wave1[3] = 1;
    }
    if (levelno == 6)
    {
        backgroundTexture.loadFromFile("C:Images/assets/Background/bgroof.jpg");
        wave1[0] = 0;
        wave1[1] = 1;
        wave1[2] = 0;
        wave1[3] = 1;
    }
    currWave = new Wave(wave1);

}

void Level::updateLevel(sf::RenderWindow& window)
{
    sf::Sprite background;
    background.setTexture(backgroundTexture);
    window.draw(background);
    cardToPlant = -1;

    for (int i = 0; i < levelno + 1; i++)
    {
        if (currency >= cards[i].getCost() && cards[i].getIsPressed())
        {
            cardToPlant = i;
            break;
        }
        else
        {
            cardToPlant = -1;
            cards[i].setIsPressed(false);
        }

       
    }


    if (SunSpawning.getElapsedTime().asSeconds() >= 10 && levelno != 4 && levelno != 5)
    {
        if (noOfSuns < maxSuns) {
            suns[noOfSuns++].Spawn(true);
            SunSpawning.restart();
        }
    }

    for (int i = 0; i < noOfSuns; i++) {
        if (suns[i].getisPressed()) {  // Remove inactive peas
            currency += 50;
            cout << currency << endl;
            break;
        }
    }
    // Update the position of each pea and check for active status
    for (int i = 0; i < noOfSuns; i++) {
        if (suns[i].getisPressed()) {  // Remove inactive peas
            suns[i] = suns[--noOfSuns];  // Move the last active pea to the current spot
        }

    }

    for (int i = 0; i < noOfSuns; i++)
    {
        suns[i].MainRender(window);
    }


    currencyText.setString(std::to_string(currency));
    window.draw(currencyText);
    window.draw(cSun);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (pArea != nullptr && pArea->tiles[i][j].plant != nullptr)
            {
                if (pArea->tiles[i][j].plant->getSrNo() == 6)
                {
                    if (pArea->checkRow(i, j) != 0 && pArea->checkRow(i, j) - j <= 3)
                    {
                        pArea->tiles[i][j].plant->setZombieInFront(true);
                    }
                    else
                    {
                        pArea->tiles[i][j].plant->setZombieInFront(false);
                    }
                }
                else if (pArea->checkRow(i, j))
                {
                    pArea->tiles[i][j].plant->setZombieInFront(true);
                }
                else
                {
                    pArea->tiles[i][j].plant->setZombieInFront(false);
                }
            }
        }
    }






    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (pArea != nullptr && pArea->tiles[i][j].plant != nullptr)
                if (pArea->tiles[i][j].plant->getSrNo() == 0 || pArea->tiles[i][j].plant->getSrNo() == 1|| pArea->tiles[i][j].plant->getSrNo() == 3 || pArea->tiles[i][j].plant->getSrNo() == 6|| pArea->tiles[i][j].plant->getSrNo() == 4 || pArea->tiles[i][j].plant->getSrNo() == 5 || pArea->tiles[i][j].plant->getSrNo() == 2)
                {
                    for (int l = 0; l < 5; l++)
                    {
                        if (currWave->noOfZombies[l] != 0)
                        {
                            for (int m = 0; m < currWave->noOfZombies[l]; m++)
                            {
                       

                                if (pArea->tiles[i][j].plant != nullptr && pArea->tiles[i][j].plant->getSrNo() == 4)
                                {
                                    if (l == 3)
                                    {
                                        for (int p = 0; p < currWave->totalZombies[l][m]->getnumOfBZ(); p++)
                                        {
                                            if (pArea->tiles[i][j].plant->getBoundingBox().contains(currWave->totalZombies[l][m]->getBZ()[p]->getPosition().x + 85, currWave->totalZombies[l][m]->getBZ()[p]->getPosition().y + 100))
                                            {
                                                currWave->totalZombies[l][m]->getBZ()[p]->setZombieExplode(true);
                                                currWave->totalZombies[l][m]->getBZ()[p]->setcurrFrame(0);
                                            }
                                        }
                                    }

                                    {
                                        if (pArea->tiles[i][j].plant->getBoundingBox().contains(currWave->totalZombies[l][m]->getPosition().x + 85, currWave->totalZombies[l][m]->getPosition().y + 100))
                                        {
                                            currWave->totalZombies[l][m]->setZombieExplode(true);
                                            currWave->totalZombies[l][m]->setcurrFrame(0);
                                        }
                                    }
                                }
                                if (pArea->tiles[i][j].plant != nullptr)
                                {
                                    if (pArea->tiles[i][j].plant->getSrNo() == 1 && pArea->tiles[i][j].plant->getaddScore())
                                    {
                                        currency += 50;
                                        pArea->tiles[i][j].plant->setaddscore(false);
                                    }
                                    for (int k = 0; k < pArea->tiles[i][j].plant->getnumOfProjectile(); k++)
                                    {
                                        
                                        if (l == 3)
                                        {
                                            for (int p = 0; p < currWave->totalZombies[l][m]->getnumOfBZ(); p++)
                                            {
                                                Entity* ptr = currWave->totalZombies[l][m]->getBZ()[p];
                                                if (pArea->tiles[i][j].plant->getSrNo() != 1 && pArea->tiles[i][j].plant->getProjectile()[k].collision(ptr) && !currWave->totalZombies[l][m]->getBZ()[p]->getZombieRIP())
                                                {
                                                    if (pArea->tiles[i][j].plant->getSrNo() == 5 && currWave->totalZombies[l][m]->getBZ()[p]->getSpeed() >= 0.3)
                                                    {
                                                        currWave->totalZombies[l][m]->getBZ()[p]->getFreezingClock().restart();
                                                        currWave->totalZombies[l][m]->getBZ()[p]->setSpeed(currWave->totalZombies[l][m]->getBZ()[p]->getSpeed() - 0.2);
                                                    }
                                                    currWave->totalZombies[l][m]->getBZ()[p]->setHp(currWave->totalZombies[l][m]->getBZ()[p]->getHp() - pArea->tiles[i][j].plant->getProjectile()[k].damage);
                                                    if (pArea->tiles[i][j].plant->getSrNo() != 6)
                                                        pArea->tiles[i][j].plant->getProjectile()[k].active = false;
                                                }
                                            }
                                        }
                                        Entity* ptr = currWave->totalZombies[l][m];
                                        if (pArea->tiles[i][j].plant->getSrNo() != 1 && pArea->tiles[i][j].plant->getProjectile()[k].collision(ptr) && !currWave->totalZombies[l][m]->getZombieRIP())
                                        {
                                            if (pArea->tiles[i][j].plant->getSrNo() == 5 && currWave->totalZombies[l][m]->getSpeed() >= 0.3)
                                            {
                                                currWave->totalZombies[l][m]->getFreezingClock().restart();
                                                currWave->totalZombies[l][m]->setSpeed(currWave->totalZombies[l][m]->getSpeed() - 0.2);
                                            }
                                            cout << pArea->tiles[i][j].plant->getProjectile()[k].damage;
                                            currWave->totalZombies[l][m]->setHp(currWave->totalZombies[l][m]->getHp() - pArea->tiles[i][j].plant->getProjectile()[k].damage);
                                            if (pArea->tiles[i][j].plant->getSrNo() != 6)
                                                pArea->tiles[i][j].plant->getProjectile()[k].active = false;
                                        }
                                    }
                                }
                                    
                            }
                        }
                    }
                }
        }
    }



    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (pArea != nullptr && pArea->tiles[i][j].plant != nullptr)
            {
                if (pArea->tiles[i][j].plant->getIsRIP())
                {
                    delete pArea->tiles[i][j].plant;
                    pArea->tiles[i][j].plant = nullptr;
                }

                else if (pArea->tiles[i][j].plant->getSrNo() == 4 && pArea->tiles[i][j].plant->getcurrFrame() == 5)
                {
                    pArea->tiles[i][j].plant = nullptr;

                }
                else
                {
                    pArea->tiles[i][j].plant->MainRender(window);
                    if (pArea->tiles[i][j].plant->getHp() <= 0)
                        pArea->tiles[i][j].plant = nullptr;
                }

            }
            bool flag = false;

            for (int l = 0; l < 5; l++)
            {
                if (currWave != nullptr && currWave->noOfZombies[l] != 0)
                {

                    for (int m = 0; m < currWave->noOfZombies[l]; m++)
                    {

                        for (int n = 0; n < 5 && l != 2; n++)
                        {
                            if (l == 3)
                            {
                                for (int p = 0; p < currWave->totalZombies[l][m]->getnumOfBZ(); p++)
                                {
                                    Entity* ptr = currWave->totalZombies[l][m]->getBZ()[p];

                                    if (cars[n].collision(ptr) && !cars[n].getOffzone())
                                    {
                                        currWave->totalZombies[l][m]->getBZ()[p]->setZombieRIP(true);
                                        cars[n].setTriggered(true);
                                    }
                                }
                            }
                            Entity* ptr = currWave->totalZombies[l][m];

                            if (cars[n].collision(ptr) && !cars[n].getOffzone())
                            {
                                currWave->totalZombies[l][m]->setZombieRIP(true);
                                cars[n].setTriggered(true);
                            }
                        }
                        if (l == 3)
                        {
                            for (int p = 0; p < currWave->totalZombies[l][m]->getnumOfBZ(); p++)
                            {
                                if (pArea->tiles[i][j].zone.contains(currWave->getTotalZombies()[l][m]->getBZ()[p]->getPosition().x + 85,
                                    currWave->getTotalZombies()[l][m]->getBZ()[p]->getPosition().y + 100) && !currWave->totalZombies[l][m]->getBZ()[p]->getZombieRIP())
                                {
                                    pArea->tiles[i][j].hasZombie = true;
                                    flag = true;

                                    if (pArea->tiles[i][j].plant != nullptr)
                                    {
                                        currWave->totalZombies[l][m]->getBZ()[p]->setIsCollidingWithPlant(true);
                                        pArea->tiles[i][j].plant->setBeingEaten(currWave->totalZombies[l][m]->getBZ()[p]->getDamage());
                                    }
                                    else
                                        currWave->totalZombies[l][m]->getBZ()[p]->setIsCollidingWithPlant(false);
                                }
                            }
                        }

                        if (pArea->tiles[i][j].zone.contains(currWave->totalZombies[l][m]->getPosition().x + 85, currWave->totalZombies[l][m]->getPosition().y + 100) && !currWave->totalZombies[l][m]->getZombieRIP() && l != 2)
                        {

                            pArea->tiles[i][j].hasZombie = true;
                            flag = true;
                            if (pArea->tiles[i][j].plant != nullptr)
                            {
                                currWave->totalZombies[l][m]->setIsCollidingWithPlant(true);
                                pArea->tiles[i][j].plant->setBeingEaten(currWave->totalZombies[l][m]->getDamage());
                            }
                            else
                                currWave->totalZombies[l][m]->setIsCollidingWithPlant(false);
                        }
                        else if (pArea->tiles[i][j].plant != nullptr && !pArea->tiles[i][j].hasZombie)
                        {
                            pArea->tiles[i][j].plant->setBeingEaten(false);
                        }
                        if (l == 3)
                        {
                            for (int p = 0; p < currWave->totalZombies[l][m]->getnumOfBZ(); p++)
                            {
                                if (currWave->totalZombies[l][m]->getBZ()[p]->getPosition().x <= 50 && !currWave->totalZombies[l][m]->getBZ()[p]->getZombieRIP())
                                {
                                    currWave->totalZombies[l][m]->getBZ()[p]->setZombieRIP(true);
                                    lives--;
                                    cout << lives;
                                }
                            }
                        }
                        if (currWave->totalZombies[l][m]->getPosition().x <= 50 && !currWave->totalZombies[l][m]->getZombieRIP())
                        {
                            currWave->totalZombies[l][m]->setZombieRIP(true);
                            lives--;
                            cout << lives;
                        }
                    }
                }
            }
            if (pArea != nullptr && !flag)
            {
                pArea->tiles[i][j].hasZombie = false;
            }
        }
    }


    for (int i = 0; i < 10; i++)
    {
        if (cards != nullptr && i < levelno + 1)
            cards[i].MainRender(window);
        if(i < 5)
        cars[i].MainRender(window);
    }


    if (currWave != nullptr && currWave->exists == false)
    {
        delete currWave;
        currWave = nullptr;
        for (int i = 0; i < 5; i++)
        {
            if (wave1[i] == 0)
                break;
            wave1[i]++;
        }
        Waveno++;
        prompt.setString("WAVE " + std::to_string(Waveno));
        prompt.setPosition(1300, 280);
        currWave = new Wave(wave1);
    }
    window.draw(prompt);

    prompt.setPosition(prompt.getPosition().x - 5, 310);


    if (levelClock.getElapsedTime().asSeconds() >= 180)
    {
        if (lives > 0)
            win = true;
    }
    if (lives <= 0)
        lose = true;

    livesText.setString("LIVES: " + std::to_string(lives));
    time.setString("TIME: " + to_string(static_cast <int>(180 - levelClock.getElapsedTime().asSeconds())));
    window.draw(livesText);
    window.draw(time);

    if (cardToPlant != -1)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0; k < 9; k++)
                    {
                        if (pArea->tiles[j][k].zone.contains(mousePosition.x, mousePosition.y))
                        {
                            cards[cardToPlant].setIsPressed(false);
                            if (pArea->tiles[j][k].plant == nullptr)
                            {
                                PlantFactory p1;
                                pArea->tiles[j][k].plant = p1.makePlant(cardToPlant, pArea->tiles[j][k].getCenter());
                                currency -= pArea->tiles[j][k].plant->getCost();
                                cardToPlant = -1;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}


void Level::setcurrency(int a)
{
    currency = a;
}
int Level::getcurrency()
{
    return currency;
}
