
#include "InstructionMenu.h"
#include "instructionMenu.h"
#include <iostream>

instructionMenu::instructionMenu() {
    if (!texture.loadFromFile("C:Images/Menus/infoMenu.jpg")) {
        // Handle error if texture fails to load
    }
    sprite.setTexture(texture);

    if (!clickableTexture.loadFromFile("C:Images/Menus/returnButton.png")) {
        // Handle error if clickable texture fails to load
    }
    clickableSprite.setTexture(clickableTexture);
    clickableSprite.setPosition(-10, -120);

    if (!font.loadFromFile("C:Images/assets/fonts/serio.TTF")) {
        // Handle error if font fails to load
    }
    text.setFont(font);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);
    text.setPosition(430, 140);
    text.setString("- You have 3 lives\n\n- Survive the waves by placing defences against the \nzombies\n\n- Make sure you have enough Sun to buy Plants\n\n- Each Level is 3 minutes long\n\n- Press 'P' to Pause the game at any time\n\n- To Place plants click on the desired card and then \nclick where you want to place that plant\n\n- Most Importantly!!! Enjoy the game\n\n");
}

void instructionMenu::update(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !exit) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        if (clickableSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            std::cout << "Clicked on the clickable image!" << std::endl;
            exit = true;
        }
    }
}

void instructionMenu::display(sf::RenderWindow& window) {
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = texture.getSize();

    sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
    sprite.setPosition(windowSize.x / 2, windowSize.y / 2);
    window.draw(sprite);

    // Set the view and draw the text and clickable sprite
    sf::View view(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
    text.setFont(font);
    window.draw(text);
    window.draw(clickableSprite);
}

bool instructionMenu::getExit() {
    return exit;
}
