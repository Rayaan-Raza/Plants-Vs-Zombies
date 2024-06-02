#include "GameOverMenu.h"

GameOverMenu::GameOverMenu() {
    if (!texture.loadFromFile("C:Images/Menus/gameOverMenu.jpg")) {
        // Handle error if texture fails to load
    }
    sprite.setTexture(texture);

    if (!clickableTexture.loadFromFile("C:Images/Menus/returnButton.png")) {
        // Handle error if clickable texture fails to load
    }
    clickableSprite.setTexture(clickableTexture);
    clickableSprite.setPosition(-10, -120);
}

void GameOverMenu::update(sf::RenderWindow& window) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        std::cout << "Restarting the game..." << std::endl;
        gameRestarted = true;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !gameRestarted) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        if (clickableSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            std::cout << "Clicked on the clickable image!" << std::endl;
            gameRestarted = true;
        }
    }
}

void GameOverMenu::display(sf::RenderWindow& window) {
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture.getSize();

    sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
    sprite.setPosition(windowSize.x / 2, windowSize.y / 2);
    window.draw(sprite);
}

bool GameOverMenu::hasGameRestarted() {
    return gameRestarted;
}