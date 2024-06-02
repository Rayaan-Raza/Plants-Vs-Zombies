/*
    NAME: M.AWAIS BASHEER(23I-0506), M.RAYAAN RAZA(23I-0535)
    SECTION: BS-CS

*/




#include<iostream>
#include "Level.h"
#include <SFML/Graphics.hpp>
#include "sunFlower.h"
#include "MainGame.h"
#include "MainMenu.h"
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 700), "SFML Window");
    MainGame g;
    g.display(window);

    return 0;

}
