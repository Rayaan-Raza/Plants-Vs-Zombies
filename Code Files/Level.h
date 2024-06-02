#pragma once
#include"Plant.h"
#include"PlayerArea.h"
#include"Card.h"
#include"Wave.h"
#include"PlantFactory.h"
#include "LawnMower.h"
class Level
{
public:
    int sunsdelted = 0;
    int cardToPlant = -1;
    sf::Text prompt;
    int Waveno = 1;
    int levelno = 1;
    int lives = 3;
    bool win = false;
    bool lose = false;
    static const int maxSuns = 100;
    Sun suns[maxSuns];
    int noOfSuns = 0;
    sf::Text currencyText;
    sf::Text time;
    sf::Text livesText;
    sf::Sprite cSun;
    sf::Texture currencySun;
    sf::Clock SunSpawning;
    sf::Font font;
    sf::Font font1;
    // Load the background image
    sf::Texture backgroundTexture;
    sf::Clock levelClock;
    LawnMower* cars;
    Plant*** Plants = nullptr;
    Card* cards ;
    int wave1[5] = { 0,0,0,0 };

    Wave* currWave = nullptr;
    PlayerArea* pArea = nullptr;
    int currency = 100;
public:
    Level(int i = 0)
    {
        std::string imagePath = "C:Images/assets/Background/bgday.jpg";

        // Load the background image
        if (!backgroundTexture.loadFromFile(imagePath))
        {
            // Handle error if image fails to load
        }
        currencySun.loadFromFile("C:Images/assets/Plants/Sun/Sun_0.png");
        cSun.setTexture(currencySun);
        cSun.setPosition(1010, 7);
        levelno = i;
        if (!font1.loadFromFile("C:Images/assets/fonts/Samdan.ttf")) {
            cout << "no";
        }
        currencyText.setFont(font1); // Set the font
        currencyText.setCharacterSize(35); // Set the character size
        currencyText.setPosition(1100, 20);

        livesText.setFont(font1); // Set the font
        livesText.setCharacterSize(35); // Set the character size
        livesText.setPosition(900, 20);

        time.setFont(font1); // Set the font
        time.setCharacterSize(45); // Set the character size
        time.setPosition(700, 20);
        if (!font.loadFromFile("C:Images/assets/fonts/full Pack 2025.ttf")) {
            cout << "no";
        }
        prompt.setFillColor(sf::Color::Yellow);
        prompt.setString("WAVE " + std::to_string(Waveno));
        prompt.setFont(font); // Set the font
        prompt.setCharacterSize(75); // Set the character size
        prompt.setPosition(1300, 250);
    }
    void setcurrency(int a);
    int getcurrency();
    void initWave();
    void updateLevel(sf::RenderWindow& window);

};

