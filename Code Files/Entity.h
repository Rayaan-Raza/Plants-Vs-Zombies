#pragma once
#include"SFML/Graphics.hpp"
#include"Coordinate.h"
#include <iostream>
using namespace std;
class Entity {
protected:
    sf::Sprite sprite;
    Coordinate position;
    Coordinate hitBox;
    sf::Texture* currTexture;
    int numOfTextures;
    sf::Texture* Texture1;
    sf::Texture* Texture2;
    sf::Texture* Texture3;
    sf::Clock clock;
    bool T1 = false;
    bool T2 = false;
    bool T3 = false;
    int currFrame = 0;
public:
    void Animate();
    void render(sf::RenderWindow& window);
    void virtual MainRender(sf::RenderWindow& window);
    void virtual update();
    void setcurrFrame(int value);
    int getcurrFrame();
    bool collision(Entity* E1);
    void swapTextures();
    void setTextures(sf::Texture T1[], sf::Texture T2[], sf::Texture T3[] = nullptr);
    Coordinate getHitbox();
    void setHitboxX(int x);
    void setHitboxY(int y);
    void setT2(bool value);

    Coordinate getPosition();
    void setPositionX(int x);
    void setPositionY(int y);
};
