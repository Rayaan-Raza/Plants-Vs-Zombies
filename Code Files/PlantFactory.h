#pragma once

#include"Plant.h"
#include "peaShooter.h"
#include "repeater.h"
#include "CherryBomb.h"
#include"Walnut.h"
#include "FrozenPeaShooter.h"
#include "sunFlower.h"
#include "fumeShroom.h"
class PlantFactory
{
public:
    Coordinate posToMake;
    Plant* makePlant(int serialOfPlant, Coordinate p1);
};

