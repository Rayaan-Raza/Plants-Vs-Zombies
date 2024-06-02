
#pragma once
#include "baseMenu.h"


class instructionMenu : public baseMenu {
public:
    instructionMenu(); // Constructor

    void update(sf::RenderWindow& window); // Method to update the menu
    void display(sf::RenderWindow& window); // Method to display the menu
    bool getExit(); // Method to check if the menu should exit

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Texture clickableTexture;
    sf::Sprite clickableSprite;
    sf::Text text;

    bool exit = false;
};
