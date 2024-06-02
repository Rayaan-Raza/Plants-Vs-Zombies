#include "Sun.h"

bool Sun::getisPressed()
{
    return isPressed;
}


// Setter and getter methods for 'initialPos'
void Sun::setInitialPos(int newPosition) {
    initialPos = newPosition;
}

int Sun::getInitialPos() const {
    return initialPos;
}

// Setter and getter methods for 'Distance'
void Sun::setDistance(int newDistance) {
    Distance = newDistance;
}

int Sun::getDistance() const {
    return Distance;
}

// Setter and getter methods for 'fallingSpeed'
void Sun::setFallingSpeed(int speed) {
    fallingSpeed = speed;
}

int Sun::getFallingSpeed() const {
    return fallingSpeed;
}

void Sun::setActive(bool value)
{
    active = value;
}

bool Sun:: getActive()
{
    return active;
}

void Sun::Spawn(bool fall, Coordinate P1)
{
    position.x = P1.x+20;
    position.y = P1.y;
    hitBox.x = 40;
    hitBox.y = 40;
    isPressed = false;
    sf::Texture t1[22];
    for (int i = 0; i < 22; i++)
    {
        string filename = "C:Images/assets/Plants/Sun/Sun_" + to_string(i) + ".png";
        t1[i].loadFromFile(filename);
    }
    numOfTextures = 22;

    setTextures(t1, t1);
    T1 = true;

    FallfromSky = fall;
    if (FallfromSky)
    {
        Skyfall();
    }
    
}
/*if u give it bool fall from sky = true, it will spawn the sun in some area above the screen and it will fall*/
/*But if u give it some coordinates it will set the initial position to some very large negative value and spawn the sun on the coordinates
which is the coordinate of the flower*/

void Sun::Skyfall()
{
    srand(time(0));
    position.x = 200 + rand() % 501;
    initialPos = rand() % 601;
    initialPos *= -1;
    position.y = initialPos;
}
void Sun::Update(sf::RenderWindow& window)
{
    if (position.y <= initialPos + Distance && FallfromSky)
        position.y += fallingSpeed;

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
            cout << "here";
            isPressed = true;
            /*Pressing Logic: Change Texture*/
            // Change the sprite's texture to the second set of textures
        }
    }
}
void Sun::MainRender(sf::RenderWindow& window)
{
    if (!isPressed)
    {
        Sun::Update(window);
        Entity::MainRender(window);
    }

}
