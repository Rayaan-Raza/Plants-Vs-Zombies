#include "PlantFactory.h"

Plant* PlantFactory::makePlant(int serialOfPlant, Coordinate p1)
{
    Plant* PlantMade = nullptr;
    switch (serialOfPlant)
    {
    case 0:
        PlantMade = new peaShooter(p1);
        break;
    case 1:
        PlantMade = new sunFlower(p1);
        break;
    case 3:
        PlantMade = new repeater(p1);
        break;
    case 2:
        PlantMade = new Walnut(p1);
        break;
    case 5:
        PlantMade = new FrozenPeaShooter(p1);
        break;
    case 4:
        PlantMade = new CherryBomb(p1);
        break;
    case 6:
        PlantMade = new fumeShroom(p1);
    }
    PlantMade->setSrNo(serialOfPlant);

    return PlantMade;
}
