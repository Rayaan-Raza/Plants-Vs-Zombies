
#pragma once
#include "baseMenu.h"
#include "User.h"
class scoreBoard : public baseMenu
{
private:
    sf::Sprite Medal1;
    sf::Sprite Medal2;
    sf::Sprite Medal3;
    sf::Texture medalTexture;
    sf::Text displayText;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    sf::Texture clickableTexture;
    sf::Sprite clickableSprite;
    bool exit = false;
public:
    scoreBoard()
    {
        medalTexture.loadFromFile("C:Images/assets/Inventory-GameScreen/Medal.png");
        Medal1.setTexture(medalTexture);
        Medal1.setPosition(470, 230);
        Medal2.setTexture(medalTexture);
        Medal2.setPosition(470, 260);
        Medal3.setTexture(medalTexture);
        Medal3.setPosition(470, 290);
        type = "scoreBoard";
        if (!texture.loadFromFile("C:Images/Menus/scoreBoardMenu.jpg"))
        {
        }
        sprite.setTexture(texture);
        if (!font.loadFromFile("C:Images/assets/fonts/serio.TTF"))
        {
            // Error handling
        }
        if (!clickableTexture.loadFromFile("C:Images/Menus/returnButton.png"))
        {

        }
        clickableSprite.setTexture(clickableTexture);
        clickableSprite.setPosition(-10, -120);
    }

    void update(sf::RenderWindow& window)
    {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !exit)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            if (clickableSprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
            {
                cout << "Clicked on the clickable image!" << endl;
                exit = true;
            }
        }
        window.clear();
        window.draw(sprite);
        window.draw(clickableSprite);

        window.display();
    }

    void display(sf::RenderWindow &window)
    {
        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = texture.getSize();

        sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
        sprite.setPosition(windowSize.x / 2, windowSize.y / 2);
    }

    void Display(sf::RenderWindow& window, User* users, int userCount)
    {
        sf::Vector2u windowSize = window.getSize();
        sf::Vector2u textureSize = texture.getSize();

        sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
        sprite.setPosition(windowSize.x / 2, windowSize.y / 2);
        
        if (true) {
            // Sort users array based on scores in descending order
            for (int i = 0; i < userCount - 1; ++i) {
                for (int j = 0; j < userCount - i - 1; ++j) {
                    if (users[j].score < users[j + 1].score) {
                        // Swap users
                        User temp = users[j];
                        users[j] = users[j + 1];
                        users[j + 1] = temp;
                    }
                }
            }

            // Display the sorted list of users and scores on the screen
            displayText.setString("");
            displayText.setFont(font);
            displayText.setCharacterSize(30);
            displayText.setPosition(500, 200);
            std::string displayString = "\n";
            for (int i = 0; i < userCount; ++i) {
                displayString += users[i].name + "      " + std::to_string(users[i].score) + "\n";
                
            }
            displayText.setString(displayString);
            window.clear();
            window.draw(sprite);
            window.draw(clickableSprite);
            window.draw(displayText);
            window.draw(Medal1);
            window.draw(Medal2);
            window.draw(Medal3);

            window.display();
           
        
        }
    }

    bool getExit()
    {
        return exit;
    }


};