#include "PlayerArea.h"

int PlayerArea::checkRow(int row, int column)
{
    for (int i = column; i < 9; i++)
    {
        if (tiles[row][i].getHasZombie())
            return i;
    }
    return 0;
}

PlayerArea::PlayerArea()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            tiles[i][j].setPositionX(250 + j * 82);
            tiles[i][j].setPositionY(85 + i * 97);
            tiles[i][j].setHitboxX(82);
            tiles[i][j].setHitboxY(97);
            tiles[i][j].setzone();
        }
    }
}