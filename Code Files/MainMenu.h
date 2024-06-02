

#pragma once
#include"baseMenu.h"


class MainMenu:public baseMenu {
private:
    sf::Font font;
    bool startGamePressed = false;
    bool levelPressed = false;
    bool infoPressed = false;
    bool exitPressed = false;
    bool scorePressed = false;
public:
    MainMenu() {
        font.loadFromFile("C:Images/assets/fonts/serio.TTF");
        textBox.setFont(font);
        textBox.setCharacterSize(47);
        textBox.setPosition(sf::Vector2f(200, 200));
        textBox.setFillColor(sf::Color::White);
        type = "MainMenu";
        if (!texture.loadFromFile("C:Images/Menus/mainMenu.jpg"))
        {
        }
        sprite.setTexture(texture);

        startGameButtonRect = sf::IntRect(500, 300, 210, 73); // Coordinates for "Start Game" button
        levelButtonRect = sf::IntRect(500, 374, 210, 60); // Coordinates for "Level" button
        instructionButtonRect = sf::IntRect(500, 430, 210, 40); // Coordinates for "Instruction" button
        scoreBoardButtonRect = sf::IntRect(500, 490, 210, 40);
        exitButtonRect = sf::IntRect(500, 536, 210, 73); // Coordinates for "Exit" button

         // Initialize the flag to false
    }

    void update(sf::RenderWindow& window)
    {
        

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);

            if (startGameButtonRect.contains(mousePos) && !startGamePressed)
            {
                cout << "Start Game" << endl;

                 startGamePressed = true;
            }
            else if (levelButtonRect.contains(mousePos) && !levelPressed)
            {
                cout << "Level" << endl;

                levelPressed = true;
            }
            else if (instructionButtonRect.contains(mousePos) && !infoPressed)
            {
                cout << "Instruction" << endl;

                 infoPressed = true;
            }
            else if (scoreBoardButtonRect.contains(mousePos) && !infoPressed)
            {
                cout << "ScoreBoard" << endl;

                scorePressed = true;
            }
            else if (exitButtonRect.contains(mousePos) && !exitPressed)
            {
                cout << "Exit" << endl;

                 exitPressed = true;
            }
        }
        else
        {
            startGamePressed = false;
            levelPressed = false;
            infoPressed = false;
            exitPressed = false;
        }

    }  
    bool getScoreBoardPressed()
    {
        return scorePressed;
    }
    void display(sf::RenderWindow& window)
    {
        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = texture.getSize();

        sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
        sprite.setPosition(windowSize.x / 2, windowSize.y / 2 + 50);
        sprite.setTexture(texture);
        window.draw(sprite);
    }

    bool getStartGamePressed()   { return startGamePressed; }
    void setStartGamePressed(bool value)  { startGamePressed = value; }

    bool getLevelPressed()   { return levelPressed; }
    void setLevelPressed(bool value)  { levelPressed = value; }

    bool getInfoPressed()   { return infoPressed; }
    void setInfoPressed(bool value)  { infoPressed = value; }

    bool getExitPressed()   { return exitPressed; }
    void setExitPressed(bool value)  { exitPressed = value; }

private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect startGameButtonRect;
    sf::IntRect levelButtonRect;
    sf::IntRect instructionButtonRect;
    sf::IntRect exitButtonRect;
    sf::IntRect scoreBoardButtonRect;


};