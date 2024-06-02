#include "baseMenu.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class GameOverMenu : public baseMenu {
public:
    GameOverMenu(); // Constructor

    void update(sf::RenderWindow& window); // Method to update the game over menu
    void display(sf::RenderWindow& window); // Method to display the game over menu
    bool hasGameRestarted(); // Method to check if the game has restarted

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Texture clickableTexture;
    sf::Sprite clickableSprite;

    bool gameRestarted = false;
};