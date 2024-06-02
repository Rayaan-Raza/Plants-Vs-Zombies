#pragma once
#include "baseMenu.h"

class levelMenu : public baseMenu
{
public:
    levelMenu()
    {

        if (!texture.loadFromFile("C:Images/Menus/levelMenu.jpg"))
        {
            // Error 
        }
        sprite.setTexture(texture);
        if (!clickableTexture.loadFromFile("C:Images/Menus/returnButton.png"))
        {

        }
        clickableSprite.setTexture(clickableTexture);
        clickableSprite.setPosition(-10, -120);

        startGameButtonRect = sf::IntRect(100, 250, 250, 100); // Coordinates for "Start Game" button
        levelButtonRect = sf::IntRect(500, 200, 250, 100); // Coordinates for "Level" button
        instructionButtonRect = sf::IntRect(900, 250, 250, 100); // Coordinates for "Instruction" button
        exitButtonRect = sf::IntRect(100, 425, 250, 100); // Coordinates for "Exit" button
        exitButtonRect1 = sf::IntRect(500, 425, 250, 100); // Coordinates for "Exit" button
        exitButtonRect2 = sf::IntRect(900, 425, 250, 100); // Coordinates for "Exit" button

        levelToPlay = -1; // Initialize the flag to false
    }

    void update(sf::RenderWindow& window)
    {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (clickableSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
            {
                cout << "Clicked on the clickable image!" << endl;
                exit = true;
            }
            if (startGameButtonRect.contains(mousePos) && levelToPlay == -1)
            {
                cout << "Level 1" << endl;

                levelToPlay = 1;
            }
            else if (levelButtonRect.contains(mousePos) && levelToPlay == -1)
            {
                cout << "Level 2" << endl;

                levelToPlay = 2;
            }
            else if (instructionButtonRect.contains(mousePos) && levelToPlay == -1)
            {
                cout << "Level 3" << endl;

                levelToPlay = 3;
            }
            else if (exitButtonRect.contains(mousePos) && levelToPlay == -1)
            {
                cout << "Level 4" << endl;

                levelToPlay = 4;
            }
            else if (exitButtonRect1.contains(mousePos) && levelToPlay == -1)
            {
                cout << "Level 5" << endl;

                levelToPlay = 5;
            }
            else if (exitButtonRect2.contains(mousePos) && levelToPlay == -1)
            {
                cout << "Level 6" << endl;

                levelToPlay = 6;
            }
        }
        else
        {
            levelToPlay = -1;
        }
        
    }

    int getLevelToPlay()
    {
        return levelToPlay;
    }
    void display(sf::RenderWindow& window)
    {
        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = texture.getSize();

        sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
        sprite.setPosition(windowSize.x / 2, windowSize.y / 2);

        // Zoom out with a factor of 1.3
        window.draw(sprite);
        window.draw(clickableSprite);

    }
    bool getExit()
    {
        return exit;
    }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect startGameButtonRect;
    sf::IntRect levelButtonRect;
    sf::IntRect instructionButtonRect;
    sf::IntRect exitButtonRect;
    sf::IntRect exitButtonRect1;
    sf::IntRect exitButtonRect2;
    sf::Texture clickableTexture;
    sf::Sprite clickableSprite;
    bool exit = false;

    int levelToPlay = -1;
};