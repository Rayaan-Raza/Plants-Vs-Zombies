#pragma once
#include"Entity.h"

class Sun : public Entity
{
    bool active = false;
    int initialPos;
    bool isPressed = false;
    bool FallfromSky;
    int Distance = 500;
    int fallingSpeed = 2;
public:

    // Setter and getter methods for 'initialPos'
    void setInitialPos(int newPosition);
    int getInitialPos() const;

    // Setter and getter methods for 'Distance'
    void setDistance(int newDistance);
    int getDistance() const;

    // Setter and getter methods for 'fallingSpeed'
    void setFallingSpeed(int speed);
    int getFallingSpeed() const;

    void setActive(bool value);
    bool getActive();

    bool getisPressed();

    void Spawn(bool fall = true, Coordinate P1 = 0);
    void Skyfall();
    void Update(sf::RenderWindow& window);
    void MainRender(sf::RenderWindow& window);
};

