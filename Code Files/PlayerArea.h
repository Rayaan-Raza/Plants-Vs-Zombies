#pragma once
#include"Tile.h"

struct PlayerArea 
{
    Tile tiles[5][9];

public:
    PlayerArea();
    int checkRow(int row, int column);
};

