#include "Wave.h"

void Wave::Update(sf::RenderWindow& window)
{
    bool flag = false;
    if(totalZombies != nullptr && noOfZombies != nullptr && exists)
    for (int i = 0; i < 4; i++)
    {
        if (totalZombies[i] != nullptr && noOfZombies[i] != 0)
            for (int j = 0; j < noOfZombies[i]; j++)
            {
                if(totalZombies[i][j] != nullptr && i == 3 )
                    for (int k = 0; k < totalZombies[i][j]->getnumOfBZ(); k++)
                    {
                        if (!totalZombies[i][j]->getBZ()[k]->getZombieRIP())
                            flag = true;
                        totalZombies[i][j]->getBZ()[k]->MainRender(window);
                    }
                if (!totalZombies[i][j]->getZombieRIP())
                    flag = true;
                totalZombies[i][j]->MainRender(window);
            }
    }

    if (!flag)
    {
        cout << "WaveEnd";
        exists = false;
    }
}

Zombie*** Wave::getTotalZombies() 
{
    return totalZombies;
}

Wave::Wave(int* size)
{
    for (int i = 0; i < 4; i++)
    {
        sumofAll += size[i];
    }
    noOfZombies = size;
    srand(time(0));
    positions = new Coordinate[sumofAll];
    for (int i = 0; i < sumofAll; i++)
    {
        int j = rand() % 5;
        int k = rand() % 9;
        positions[i].x = a.tiles[j][k].getCenter().x + 1000 + i * 60;
        positions[i].y = a.tiles[j][k].getCenter().y - 50;

    }

    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        if (noOfZombies[i] != 0)
        {
            totalZombies[i] = new Zombie * [noOfZombies[i]];
            for (int j = 0; j < noOfZombies[i]; j++)
            {
                zombieFactory Zombiefactory;
                totalZombies[i][j] = Zombiefactory.makeZombie(i, positions[k++]);
            }
        }
    }
}

//Wave::~Wave() {
//    // Clean up allocated memory for totalZombies
//    for (int i = 0; i < 5 && noOfZombies[i]; i++) {
//        if (totalZombies[i] != nullptr) {
//            for (int j = 0; j < noOfZombies[i]; j++) {
//                if (totalZombies[i][j] != nullptr)
//                delete totalZombies[i][j]; // Delete each Zombie object
//            }
//            delete[] totalZombies[i]; // Delete the array of Zombie pointers
//        }
//    }
//    delete[] totalZombies; // Delete the array of arrays (totalZombies)
//    delete[] noOfZombies; // Delete the array storing number of zombies
//    delete[] positions;
//}
