#pragma once
#include "baseMenu.h"
class PauseMenu : public baseMenu
{
public:
    PauseMenu()
    {
        if (!texture.loadFromFile("C:Images/Menus/pausedMenu.jpg"))
        {
            // Error handling
        }
        sprite.setTexture(texture);

        if (!font.loadFromFile("C:Images/assets/fonts/serio.TTF"))
        {
            // Error handling
        }

        resumeText.setFont(font);
        resumeText.setString("Press R to resume");
        resumeText.setCharacterSize(45);
        resumeText.setFillColor(sf::Color::White);
        resumeText.setPosition(450, 400);
    }

    void update(sf::RenderWindow& window)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !gameResumed)
        {
            cout << "Game resumed" << endl;
            gameResumed = true;
        }
    }

    void display(sf::RenderWindow& window)
    {
        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = texture.getSize();

        sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
        sprite.setPosition(windowSize.x / 2, windowSize.y / 2);
        window.draw(sprite);

        window.draw(resumeText);
    }

    bool getGameResumed()
    {
        return gameResumed;
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Text resumeText;
    bool gameResumed = false;
};

