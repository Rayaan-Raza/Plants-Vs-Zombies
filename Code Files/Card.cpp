#include "Card.h"



Card* Card::makeCards(int noOfcards)
{
    Card* cards = new Card[noOfcards];
    sf::Texture pea1[1];
    sf::Texture pea2[1];

    for (int i = 0; i < noOfcards; ++i)
    {
        // Set initial position for each card
        cards[i].position = { 0, static_cast<float>(i * 91) };
        cards[i].hitBox = { 150, static_cast<float>(95) };// Adjust x and y coordinates as needed
        // Load textures for the cards
        switch (i)
        {
        case 0:
            pea1[0].loadFromFile("C:Images/assets/Cards/peashooterCard.png");
            pea2[0].loadFromFile("C:Images/assets/Cards/peashooterCard2.png");
            cards[i].setSrNo(i);
            cards[i].cost = 100;
            break;
        case 1:
            pea1[0].loadFromFile("C:Images/assets/Cards/sunflowerCard.png");
            pea2[0].loadFromFile("C:Images/assets/Cards/sunflowerCard2.png");
            cards[i].setSrNo(i);
            cards[i].cost = 100;

            break;
        case 2:
            pea1[0].loadFromFile("C:Images/assets/Cards/wallnutCard.png");
            pea2[0].loadFromFile("C:Images/assets/Cards/wallnutCard2.png");
            cards[i].setSrNo(i);
            cards[i].cost = 50;

            break;
        case 3:
            pea1[0].loadFromFile("C:Images/assets/Cards/repeaterCard.png");
            pea2[0].loadFromFile("C:Images/assets/Cards/repeaterCard2.png");
            cards[i].setSrNo(i);
            cards[i].cost = 200;

            break;
        case 4:
            pea1[0].loadFromFile("C:Images/assets/Cards/cherrybombCard.png");
            pea2[0].loadFromFile("C:Images/assets/Cards/cherrybombCard2.png");
            cards[i].setSrNo(i);
            cards[i].cost = 150;

            break;
        case 5:
            pea1[0].loadFromFile("C:Images/assets/Cards/FrozenPea.jpg");
            pea2[0].loadFromFile("C:Images/assets/Cards/FrozenPea2.jpg");
            cards[i].setSrNo(i);
            cards[i].cost = 200;

            break;
        case 6:
            pea1[0].loadFromFile("C:Images/assets/Cards/7.png");
            pea2[0].loadFromFile("C:Images/assets/Cards/72.png");
            cards[i].setSrNo(i);
            cards[i].cost = 75;

            break;
        }
        cards[i].numOfTextures = 1;
        cards[i].setTextures(pea1, pea2);
        cards[i].T2 = true;
    }
    return cards;
}
void Card::update(sf::RenderWindow& window)
{
    if (!isPressed)
        T1 = true;

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    sf::FloatRect hitBoxArea(
        sprite.getPosition().x, // Offset x position of the hit box from the sprite's origin
        sprite.getPosition().y, // Offset y position of the hit box from the sprite's origin
        hitBox.getX(), // Width of the hit box
        hitBox.getY()  // Height of the hit box
    );

    // Check if the mouse position is within the hit box
    if (hitBoxArea.contains((mousePos.x), (mousePos.y)))
    {
        /*Hovering Logic: Change Texture*/
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            isPressed = true;
            /*Pressing Logic: Change Texture*/
            // Change the sprite's texture to the second set of textures
            T2 = true;
        }
    }

}

void Card::MainRender(sf::RenderWindow& window)
{
    update(window);
    Entity::MainRender(window);
}

// Getters
int Card::getSrNo() const {
    return SrNo;
}

int Card::getCost() const {
    return cost;
}

std::string Card::getType() const {
    return type;
}

bool Card::getIsPressed() const {
    return isPressed;
}

bool Card::getUnlocked() const {
    return unlocked;
}

// Setters
void Card::setSrNo(int value) {
    SrNo = value;
}

void Card::setCost(int value) {
    cost = value;
}

void Card::setType(const std::string& value) {
    type = value;
}

void Card::setIsPressed(bool value) {
    isPressed = value;
}

void Card::setUnlocked(bool value) {
    unlocked = value;
}