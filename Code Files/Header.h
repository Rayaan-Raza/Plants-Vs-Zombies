//#pragma once
//#include <iostream>
//#include "SFML/Graphics.hpp"
//using namespace std;
//
//struct Coordinate
//{
//    double x, y;
//
//public:
//    Coordinate(double x = 0, double y = 0) : x(x), y(y) {}
//
//    // Setter methods
//    void setX(double x) { this->x = x; }
//    void setY(double y) { this->y = y; }
//
//    double getX() const { return x; }
//    double getY() const { return y; }
//
//
//    // Print coordinates
//    void print() const {
//        std::cout << "Coordinate(" << x << ", " << y << ")" << std::endl;
//    }
//};
//
//class Entity {
//public:
//    sf::Sprite sprite;
//    Coordinate position;
//    Coordinate hitBox;
//    sf::Texture* currTexture;
//    int numOfTextures;
//    sf::Texture* Texture1;
//    sf::Texture* Texture2;
//    sf::Clock clock;
//    bool T1 = false;
//    bool T2 = false;
//    int currFrame = 0;
//
//    void Animate();
//    void render(sf::RenderWindow& window);
//    void virtual MainRender(sf::RenderWindow& window);
//    void virtual update();
//    bool collision(Entity* E1);
//    void swapTextures();
//    void setTextures(sf::Texture T1[], sf::Texture T2[]);
//
//};
//
//void Entity::setTextures(sf::Texture T1[], sf::Texture T2[])
//{
//    currTexture = new sf::Texture[numOfTextures];
//    Texture1 = new sf::Texture[numOfTextures];
//    Texture2 = new sf::Texture[numOfTextures];
//    for (int i = 0; i < numOfTextures; i++)
//    {
//        Texture1[i] = T1[i];
//        Texture2[i] = T2[i];
//    }
//}
//
//void Entity::update()
//{
//    sprite.setPosition(position.x, position.y);
//}
//void Entity::Animate()
//{
//    swapTextures();
//    if (clock.getElapsedTime().asSeconds() > 0.1)
//    {
//        {
//            currFrame = (currFrame + 1) % numOfTextures;
//            sprite.setTexture(currTexture[currFrame]);
//            clock.restart();
//        }
//    }
//}
//void Entity::render(sf::RenderWindow& window)
//{
//    window.draw(sprite);
//}
//void Entity::MainRender(sf::RenderWindow& window)
//{
//    Animate();
//    Entity::update();
//    render(window);
//}
//
//bool Entity::collision(Entity* E1)
//{
//    int thisLeft = position.getX();
//    int thisRight = position.getX() + hitBox.getY();
//    int thisTop = position.getY();
//    int thisBottom = position.getY() + hitBox.getY();
//    int otherLeft = E1->position.getX();
//    int otherRight = E1->position.getX() + E1->hitBox.getX();
//    int otherTop = E1->position.getY();
//    int otherBottom = E1->position.getY() + E1->hitBox.getY();
//
//    if (thisRight >= otherLeft && thisLeft <= otherRight &&
//        thisBottom >= otherTop && thisTop <= otherBottom) {
//        return true;
//    }
//
//    return false;
//}
//
//void Entity::swapTextures()
//{
//    if (T1)
//    {
//        for (int i = 0; i < numOfTextures; ++i)
//        {
//            currTexture[i] = Texture1[i];
//        }
//        T1 = false;
//    }
//    else if (T2)
//    {
//        for (int i = 0; i < numOfTextures; ++i)
//        {
//            currTexture[i] = Texture2[i];
//        }
//        T2 = false;
//    }
//
//}
//
//class Card : public Entity
//{
//public:
//    int SrNo;
//    int cost;
//    string type;
//    bool isPressed = false;
//    bool unlocked = false;
//public:
//    Card* makeCards();
//    void update(sf::RenderWindow& window);
//    void MainRender(sf::RenderWindow& window);
//};
//
//Card* Card::makeCards()
//{
//    Card* cards = new Card[5]; // Create five cards
//    sf::Texture T1, T2;
//    sf::Texture pea1[1];
//    sf::Texture pea2[1];
//
//    for (int i = 0; i < 5; ++i)
//    {
//        // Set initial position for each card
//        cards[i].position = { 0, static_cast<float>(50 + i * 110) };
//        cards[i].hitBox = { 200, static_cast<float>(110) };// Adjust x and y coordinates as needed
//        // Load textures for the cards
//        switch (i)
//        {
//        case 0:
//            pea1[0].loadFromFile("C:Images/assets/Cards/peashooterCard.png");
//            pea2[0].loadFromFile("C:Images/assets/Cards/peashooterCard.png");
//            break;
//        case 1:
//            pea1[0].loadFromFile("C:Images/assets/Cards/sunflowerCard.png");
//            pea2[0].loadFromFile("C:Images/assets/Cards/peashooterCard.png");
//            break;
//        case 2:
//            pea1[0].loadFromFile("C:Images/assets/Cards/wallnutCard.png");
//            pea2[0].loadFromFile("C:Images/assets/Cards/peashooterCard.png");
//            break;
//        case 3:
//            pea1[0].loadFromFile("C:Images/assets/Cards/repeaterCard.png");
//            pea2[0].loadFromFile("C:Images/assets/Cards/peashooterCard.png");
//            break;
//        case 4:
//            pea1[0].loadFromFile("C:Images/assets/Cards/cherrybombCard.png");
//            pea2[0].loadFromFile("C:Images/assets/Cards/peashooterCard.png");
//            break;
//        }
//        cards[i].numOfTextures = 1;
//        cards[i].setTextures(pea1, pea2);
//        cards[i].T1 = true;
//    }
//    return cards;
//}
//void Card::update(sf::RenderWindow& window)
//{
//    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//
//    sf::FloatRect hitBoxArea(
//        sprite.getPosition().x, // Offset x position of the hit box from the sprite's origin
//        sprite.getPosition().y, // Offset y position of the hit box from the sprite's origin
//        hitBox.getX(), // Width of the hit box
//        hitBox.getY()  // Height of the hit box
//    );
//
//    // Check if the mouse position is within the hit box
//    if (hitBoxArea.contains((mousePos.x), (mousePos.y)))
//    {
//        /*Hovering Logic: Change Texture*/
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//        {
//            isPressed = true;
//            /*Pressing Logic: Change Texture*/
//            // Change the sprite's texture to the second set of textures
//            T2 = true;
//        }
//    }
//}
//
//void Card::MainRender(sf::RenderWindow& window)
//{
//    update(window);
//    Entity::MainRender(window);
//}
//
//
//
//
//
//
//
//
//class Plant : public Card
//{
//protected:
//    int hp = 100;
//    bool isRIP = false;
//public:
//    virtual Projectile* getProjectile()
//    {
//        return nullptr;
//    }
//    virtual Sun* getsuns()
//    {
//        return nullptr;
//    }
//    virtual int getnumOfProjectile()
//    {
//        return -1;
//    }
//    void MainRender(sf::RenderWindow& window);
//};
//
//void Plant::MainRender(sf::RenderWindow& window)
//{
//    if (!isRIP)
//        Entity::MainRender(window);
//}
//
//class Zombie : public Entity
//{
//public:
//    Zombie** ptr;
//    int hp = 100;
//    int damage = 10;
//    int speed = 1;
//    bool isCollidingWithPlant = false;
//    bool ZombieRIP = false;
//    sf::Texture texture1[22];
//    sf::Texture texture2[22];
//public:
//    Zombie()
//    {
//
//    }
//    Zombie(Coordinate T1)
//    {
//        position.x = T1.x;
//        position.y = T1.y;
//        numOfTextures = 22;
//        for (int i = 0; i < 22; i++)
//        {
//            string filename = "C:Images/assets/Zombies/NormalZombie/Zombie/Zombie_" + to_string(i) + ".png";
//            texture1[i].loadFromFile(filename);
//            texture2[i].loadFromFile(filename);
//        }
//        T1 = true;
//        setTextures(texture1, texture2);
//    }
//    virtual int getnumOfBZ()
//    {
//        return -1;
//    }
//    virtual Zombie** getBZ()
//    {
//        return ptr;
//    }
//    void virtual Ability();
//    void update();
//    void MainRender(sf::RenderWindow& window);
//
//};
//
//void Zombie::Ability()
//{
//    if (isCollidingWithPlant)
//    {
//        T2 = true;
//    }
//    else
//    {
//        T1 = true;
//        position.x -= speed;
//    }
//}
//
//void Zombie::update()
//{
//    Zombie::Ability();
//}
//
//void Zombie::MainRender(sf::RenderWindow& window)
//{
//    Zombie::update();
//    Entity::MainRender(window);
//}
//
//class FootballZombie : public Zombie {
//private:
//
//public:
//
//    FootballZombie(Coordinate p1) : Zombie(p1)
//    {
//        hp = 100;
//        damage = 10;
//        speed = 0;
//        numOfTextures = 1; //changes 8 to 1
//        sf::Texture Texture1[1];
//        Texture1[0].loadFromFile("C:/Users/armuj/Desktop/Project/Project/Images/assets/Zombies/NormalZombie/Zombie/Zombie_0.png");
//        this->T1 = true;
//        setTextures(Texture1, Texture1);
//        position = T1;
//    }
//};
//
//class FlyingZombie : public Zombie {
//public:
//    FlyingZombie(Coordinate p1) : Zombie(p1)
//    {
//        hp = 100;
//        damage = 10;
//        speed = 10;
//        numOfTextures = 1;
//        sf::Texture Texture1[1]; //added logic
//        Texture1[0].loadFromFile("C:/Users/armuj/Desktop/Project/Project/Images/assets/Zombies/NormalZombie/Zombie/Zombie_1.png");
//        this->T1 = true;
//        setTextures(Texture1, Texture1);
//        position = T1;
//    }
//    // Additional methods or attributes specific to FlyingZombie
//};
//
//class DancingZombie : public Zombie
//{
//public:
//    int  time = 8000;
//    Zombie** SpawnedZombies = new Zombie * [12];
//    int numOfBZombies = 0;
//public:
//    int getnumOfBZ()
//    {
//        return numOfBZombies;
//    }
//    virtual Zombie** getBZ()
//    {
//        return SpawnedZombies;
//    }
//    DancingZombie(Coordinate p1) : Zombie(p1)
//    {
//
//        hp = 100;
//        damage = 10;
//        speed = 10;
//        for (int i = 0; i < numOfTextures; i++)
//        {
//            
//        }
//    }
//    void Ability();
//};
//
//void DancingZombie::Ability()
//{
//    Coordinate C1 = position, C2 = position, C3 = position, C4 = position;
//    C1.x += 85;
//    C2.x -= 85;
//    C3.y += 100;
//    C4.y -= 100;
//    if (clock.getElapsedTime().asMilliseconds() >= time)
//    {
//        SpawnedZombies[numOfBZombies++] = new Zombie(C1);
//        SpawnedZombies[numOfBZombies++] = new Zombie(C2);
//        SpawnedZombies[numOfBZombies++] = new Zombie(C3);
//        SpawnedZombies[numOfBZombies++] = new Zombie(C4);
//    }
//}
//
//class DolphinRiderZombie : public Zombie {
//public:
//    DolphinRiderZombie(Coordinate p1) : Zombie(p1)
//    {
//        hp = 100;
//        damage = 10;
//        speed = 10;
//        for (int i = 0; i < numOfTextures; i++)
//        {
//            //setTexture
//        }
//    }
//    // Additional methods or attributes specific to DolphinRiderZombie
//};
//
//class Sun : public Entity
//{
//    bool active = false;
//    int value;
//    int initialPos;
//    bool isPressed;
//    bool FallfromSky;
//    int Distance;
//    int fallingSpeed;
//public:
//    void setActive(bool value);
//    bool getActive()
//    {
//        return active;
//    }
//    void Spawn(bool fall = true, Coordinate P1 = 0);
//    void Skyfall();
//    void Update(sf::RenderWindow& window);
//    void MainRender(sf::RenderWindow& window);
//};
//
//void Sun::setActive(bool value)
//{
//    active = value;
//}
//
//void Sun::Spawn(bool fall, Coordinate P1 )
//{
//    active = true;
//    FallfromSky = fall;
//    if (FallfromSky)
//    {
//        Skyfall();
//    }
//    else
//    {
//        position = P1;
//    }
//}
///*if u give it bool fall from sky = true, it will spawn the sun in some area above the screen and it will fall*/
///*But if u give it some coordinates it will set the initial position to some very large negative value and spawn the sun on the coordinates
//which is the coordinate of the flower*/
//
//void Sun::Skyfall()
//{
//    srand(time(0));
//    position.x = 100 + rand() % 501;
//    initialPos = rand() % 601;
//    initialPos *= -1;
//    position.y = initialPos;
//}
//void Sun::Update(sf::RenderWindow& window)
//{
//    if (position.y <= initialPos + Distance && FallfromSky)
//        position.y += fallingSpeed;
//
//    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
//
//    sf::FloatRect hitBoxArea(
//        sprite.getPosition().x, // Offset x position of the hit box from the sprite's origin
//        sprite.getPosition().y, // Offset y position of the hit box from the sprite's origin
//        hitBox.getX(), // Width of the hit box
//        hitBox.getY()  // Height of the hit box
//    );
//
//    // Check if the mouse position is within the hit box
//    if (hitBoxArea.contains((mousePos.x), (mousePos.y)))
//    {
//        /*Hovering Logic: Change Texture*/
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//        {
//            isPressed = true;
//            active = false;
//            /*Pressing Logic: Change Texture*/
//            // Change the sprite's texture to the second set of textures
//        }
//    }
//}
//void Sun::MainRender(sf::RenderWindow& window)
//{
//    if (active)
//    {
//        Update(window);
//        Entity::MainRender(window);
//    }
//}
//
//class Projectile : public Entity
//{
//public:
//    int Sr = -999;
//    int speed = 1;
//    int dir;
//    bool active;
//    int damage;
//    Projectile()
//    {
//
//
//    }
//    Projectile(int sr, sf::Texture& texture, bool Active = false, double x = 6000, double y = 6000, int dir = 0, int damage = 0)  //constructor + para constructor
//    {
//        numOfTextures = 1;
//        Sr = sr;
//        active = Active;
//        sprite.setTexture(texture);
//        position.x = x;
//        position.y = y;
//        this->speed = speed;
//        this->dir = dir;
//        this->damage = damage;
//        active = true;
//    }
//    void init(sf::Texture texture[], double x, double y, int dir = 0, int damage = 0)  //constructor + para constructor
//    {
//        setTextures(texture, texture);
//        T1 = true;
//        position.x = x;
//        position.y = y;
//        this->speed = speed;
//        this->dir = dir;
//        this->damage = damage;
//        active = true;
//    }
//    void update();
//    void MainRender(sf::RenderWindow& window);
//    ~Projectile() {}
//};
//
//void Projectile::update()
//{
//    if (active)
//    {
//        position.x += speed * dir;
//    }
//    else
//    {
//        //call destructor
//    }
//}
//void Projectile::MainRender(sf::RenderWindow& window)
//{
//    if (active)
//    {
//        update();
//        Entity::MainRender(window);
//    }
//}
//
//class LawnMower : public Entity
//{
//    bool isTriggered = false;
//    int speed;
//public:
//    void Update();
//    void MainRender(sf::RenderWindow& window);
//};
//
//void LawnMower::Update()
//{
//    if (isTriggered == true)
//    {
//        {
//            position.x += speed;
//        }
//    }
//}
//void LawnMower::MainRender(sf::RenderWindow& window)
//{
//    Update();
//    Entity::MainRender(window);
//}
//
//class Tile : public Entity
//{
//public:
//    bool isFull = false;
//    bool hasZombie = false;
//    Plant* plant;
//    bool isPressed;
//    sf::IntRect zone;
//public:
//    void setzone();
//    bool getHasZombie();
//    Coordinate getCenter();
//};
//
//void Tile::setzone()
//{
//    zone = sf::IntRect(position.x, position.y, hitBox.x, hitBox.y);
//}
//bool Tile::getHasZombie()
//{
//    return  hasZombie;
//}
//
//Coordinate Tile::getCenter()
//{
//    Coordinate center;
//    center.x = position.x;
//    center.y = position.y;
//    return center;
//}
//
//struct PlayerArea 
//{
//    Tile tiles[5][9];
//
//public:
//    PlayerArea()
//    {
//        for (int i = 0; i < 5; i++)
//        {
//            for (int j = 0; j < 9; j++)
//            {
//                tiles[i][j].position.x = 250 + j * 82;
//                tiles[i][j].position.y = 85 + i * 97;
//                tiles[i][j].hitBox.x = 82;
//                tiles[i][j].hitBox.y = 97;
//                tiles[i][j].setzone();
//            }
//        }
//    }
//    bool checkRow(int row);
//};
//
//bool PlayerArea::checkRow(int row)
//{
//    for (int i = 0; i < 9; i++)
//    {
//        if (tiles[row][i].getHasZombie())
//            return true;
//    }
//    return false;
//}
//
//class zombieFactory 
//{
//public:
//    Coordinate posToMake;
//    Zombie* makeZombie(int serialOfZombie, Coordinate p1);
//
//};
//
//Zombie* zombieFactory::makeZombie(int serialOfZombie, Coordinate p1)
//{
//    Zombie* zombieMade;
//    switch (serialOfZombie)
//    {
//    case 0:
//        zombieMade = new Zombie(p1);
//        break;
//    case 1:
//        zombieMade = new FootballZombie(p1);
//        break;
//    case 2:
//        zombieMade = new FlyingZombie(p1);
//        break;
//    case 3:
//        zombieMade = new DancingZombie(p1);
//        break;
//    case 4:
//        zombieMade = new DolphinRiderZombie(p1);
//        break;
//    default:
//        zombieMade = new Zombie(p1);
//        break;
//    }
//    int x = 0;
//    return zombieMade;
//}
//
//class Wave {
//
//public:
//
//    int* noOfZombies;
//    int sumofAll = 10;
//    bool exists;
//    Zombie*** totalZombies = new Zombie * *[5];
//    PlayerArea a;
//    Coordinate* positions = new Coordinate[sumofAll];
//
//    Wave(int* size)
//    {
//        noOfZombies = size;
//        srand(time(0));
//
//        for (int i = 0; i < sumofAll; i++)
//        {
//            int j = rand() % 5;
//            int k = rand() % 9;
//            positions[i].x = a.tiles[j][k].getCenter().x + 1000 + i * 60;
//            positions[i].y = a.tiles[j][k].getCenter().y - 40;
//
//        }
//
//        int k = 0;
//        for (int i = 0; i < 5; i++)
//        {
//            if (noOfZombies[i] != 0)
//            {
//                totalZombies[i] = new Zombie * [noOfZombies[i]];
//                for (int j = 0; j < noOfZombies[i]; j++)
//                {
//                    zombieFactory Zombiefactory;
//                    totalZombies[i][j] = Zombiefactory.makeZombie(i, positions[k++]);
//                }
//            }
//        }
//    }
//    void Update(sf::RenderWindow& window);
//};
//
//void Wave::Update(sf::RenderWindow& window)
//{
//    for (int i = 0; i < 5; i++)
//    {
//        if (noOfZombies[i] != 0)
//            for (int j = 0; j < noOfZombies[i]; j++)
//            {
//                /*if(i == 3)
//                    for (int k = 0; k < totalZombies[i][j]->getnumOfBZ(); k++)
//                    {
//                        totalZombies[i][j]->getBZ()[k]->MainRender(window);
//                    }*/
//                totalZombies[i][j]->MainRender(window);
//            }
//    }
//
//
//    if (sumofAll == 0 && exists == false)
//    {
//        //delete
//    }
//}
//
//class offensivePlant : public Plant
//{
//protected:
//    int shootingfrequency;
//    int Damage;
//    bool zombieInFront = true;
//    int shootingFrequency; // in milliseconds
//    int damage;
//    sf::Clock shootingClock;
//
//};
//
//
//class peaShooter : public offensivePlant
//{
//protected:
//    static const int maxPeas = 100;
//    Projectile peas[maxPeas];
//    int noOfpeas = 0;
//    sf::Texture projectileTexture[1];
//    sf::Texture texture1[13];
//    sf::Texture texture2[13];
//
//
//public:
//    peaShooter(Coordinate P1)
//    {
//        shootingFrequency = 3000;
//        numOfTextures = 13;
//        position = P1;
//        for (int i = 0; i < 13; i++)
//        {
//            hitBox.x = 55;
//            hitBox.y = 5;
//            projectileTexture[0].loadFromFile("C:Images/assets/Bullets/peaNormal/pea.png");
//            string filename = "C:Images/assets/Plants/Peashooter/Peashooter_" + to_string(i) + ".png";
//            texture1[i].loadFromFile(filename);
//            texture2[i].loadFromFile(filename);
//            T1 = true;
//        }
//        setTextures(texture1, texture2);
//    }
//    peaShooter()
//    {
//
//    }
//    void update();
//    void MainRender(sf::RenderWindow& window);
//};
//
////void peaShooter::update()
////{
////    if (hp <= 0)
////    {
////        isRIP = true;
////        return;
////    }
////    // Check for zombie presence and shooting frequency
////    if (zombieInFront && shootingClock.getElapsedTime().asMilliseconds() >= shootingFrequency) {
////        if (noOfpeas < maxPeas) {
////            cout << "Pea Shot\n";// Ensure there is space for a new pea
////            peas[noOfpeas++].init(projectileTexture, position.x + hitBox.x, position.y + hitBox.y / 2, 1, Damage);
////            shootingClock.restart();
////        }
////    }
////
////    // Update the position of each pea and check for active status
////    for (int i = 0; i < noOfpeas; ) {
////        if (!peas[i].active) {  // Remove inactive peas
////            peas[i] = peas[--noOfpeas];  // Move the last active pea to the current spot
////        }
////        else {
////            i++;
////        }
////    }
////}
////
////void peaShooter::MainRender(sf::RenderWindow& window)
////{
////    for (int i = 0; i < noOfpeas; i++)
////    {
////        peas[i].MainRender(window);
////    }
////    update();
////    Plant::MainRender(window);
////}
////
////class repeater : public peaShooter
////{
////    sf::Clock secondaryClock;
////    bool shootSecondPea = false;
////public:
////    repeater(Coordinate P1)
////    {
////
////    }
////    void update();
////};
////
////void repeater::update()
////{
////
////    if (hp <= 0)
////    {
////        isRIP = true;
////        return;
////    }
////    // Check for zombie presence and shooting frequency
////    if (zombieInFront && shootingClock.getElapsedTime().asMilliseconds() >= shootingFrequency) {
////        if (noOfpeas < maxPeas) {  // Ensure there is space for a new pea
////            peas[noOfpeas++].init(projectileTexture, position.x + hitBox.x, position.y + hitBox.y / 2, 1, Damage);
////            shootingClock.restart();
////            secondaryClock.restart();
////            shootSecondPea = true;
////        }
////    }
////
////    if (shootSecondPea && secondaryClock.getElapsedTime().asMilliseconds() >= shootingFrequency / 2)
////    {
////        peas[noOfpeas++].init(projectileTexture, position.x + hitBox.x, position.y + hitBox.y / 2, 1, Damage);
////        shootSecondPea = false;
////    }
////
////    // Update the position of each pea and check for active status
////    for (int i = 0; i < noOfpeas; ) {
////        if (!peas[i].active) {  // Remove inactive peas
////            peas[i] = peas[--noOfpeas];  // Move the last active pea to the current spot
////        }
////        else {
////            peas[i].update();  // Move active peas
////            i++;
////        }
////    }
////}
////
////
////class CherryBomb : public Plant {
////private:
////    sf::Clock explosionClock;  // Timer to manage explosion delay
////    int explosionDelay = 2000; // Delay in milliseconds before explosion
////    int damage = 150;          // Damage caused by the explosion
////    int explosionRadius = 100; // Radius of the explosion effect
////    bool hasExploded = false;  // Flag to check if explosion has happened
////    bool flag = false;
////    Coordinate p1 = position;
////    sf::IntRect damageArea;
////public:
////    CherryBomb(Coordinate P1)
////    {
////        position = P1;
////        damageArea = sf::IntRect(p1.x - explosionRadius, position.y - explosionRadius,
////            explosionRadius * 2, explosionRadius * 2);
////    }
////
////    void update() {
////        if (hp <= 0)
////        {
////            isRIP = true;
////            return;
////        }
////        if (!hasExploded && explosionClock.getElapsedTime().asMilliseconds() >= explosionDelay) {
////
////            hasExploded = true;
////            T2 = true;
////            flag = true;
////        }
////        if (flag && currFrame == numOfTextures)
////            isRIP = true;
////    }
////
////    void MainRender(sf::RenderWindow& window) {
////
////        update();
////        Plant::MainRender(window);
////    }
////};
////
////class Walnut : public Plant
////{
////public:
////    Walnut(Coordinate P1)
////    {
////        
////    }
////};
////
////class FrozenPeaShooter : public peaShooter {
////public:
////    FrozenPeaShooter(Coordinate P1)
////    {
////
////    }
////    void update();
////};
////
////class sunFlower : public Plant
////{
////    static const int maxSuns = 100;
////    bool spawnSun = false;
////    int time = 3000;
////    Sun suns[maxSuns];
////    int noOfsuns = 0;
////public:
////    sunFlower(Coordinate P1 = 0)
////    {
////        position = P1;
////    }
////    int getnumOfProjectile();
////    void update();
////    void MainRender(sf::RenderWindow& window);
////};
////
////int sunFlower::getnumOfProjectile()
////{
////    return noOfsuns;
////}
////
////
////void sunFlower::MainRender(sf::RenderWindow& window)
////{
////    Plant::MainRender(window);
////}
////
////void sunFlower::update()
////{
////    if (hp <= 0)
////    {
////        isRIP = true;
////        return;
////    }
////    if (clock.getElapsedTime().asMilliseconds() >= time) {
////        if (noOfsuns < maxSuns)
////        {
////            suns[noOfsuns].Spawn(false, position);
////            suns[noOfsuns++].setActive(true);
////            clock.restart();
////        }
////    }
////    for (int i = 0; i < noOfsuns; i++) {
////        if (!suns[i].getActive()) {  // Remove inactive peas
////            suns[i] = suns[--noOfsuns];  // Move the last active pea to the current spot
////        }
////        else {
////            suns[i].update();  // Move active peas
////            i++;
////        }
////    }
////}
////void FrozenPeaShooter::update()
////{
////    if (hp <= 0)
////    {
////        isRIP = true;
////        return;
////    }
////    // Check for zombie presence and shooting frequency
////    if (zombieInFront && shootingClock.getElapsedTime().asMilliseconds() >= shootingFrequency) {
////        if (noOfpeas < maxPeas) {  // Ensure there is space for a new pea
////            peas[noOfpeas++].init(projectileTexture, position.x + hitBox.x, position.y + hitBox.y / 2, 1, Damage);
////            shootingClock.restart();
////        }
////    }
////
////    // Update the position of each pea and check for active status
////    for (int i = 0; i < noOfpeas; ) {
////        if (!peas[i].active) {  // Remove inactive peas
////            peas[i] = peas[--noOfpeas];  // Move the last active pea to the current spot
////        }
////        else {
////            peas[i].update();  // Move active peas
////            i++;
////        }
////    }
////}
////
////class PlantFactory 
////{
////public:
////    Coordinate posToMake;
////    Plant* makePlant(int serialOfPlant, Coordinate p1);
////};
////
////Plant* PlantFactory::makePlant(int serialOfPlant, Coordinate p1)
////{
////    Plant* PlantMade;
////    switch (serialOfPlant)
////    {
////    case 0:
////        PlantMade = new peaShooter(p1);
////        break;
////    case 1:
////        PlantMade = new sunFlower(p1);
////        break;
////    case 2:
////        PlantMade = new repeater(p1);
////        break;
////    case 3:
////        PlantMade = new Walnut(p1);
////        break;
////    case 4:
////        PlantMade = new FrozenPeaShooter(p1);
////        break;
////    case 5:
////        PlantMade = new CherryBomb(p1);
////        break;
////    }
////    int x = 0;
////    return PlantMade;
////}
////
////class Level
////{
////    //int numOfPlants[6] = { 0 };
////    Plant*** Plants = nullptr;
////    Card* cards = nullptr;
////    int wave1[5] = { 0,0,0,0,0 };
////    int wave2[5] = { 0,0,0,0,0 };
////    int wave3[5] = { 0,0,0,0,0 };
////    Wave* currWave = nullptr;
////    PlayerArea* pArea = nullptr;
////    int currency;
////public:
////    void initWave();
////    void updateLevel(sf::RenderWindow& window);
////};
////
////void Level::initWave()
////{
////    pArea = new PlayerArea;
////    Plants = new Plant * *[6];
////    for (int i = 0; i < 6; i++)
////    {
////        Plants[i] = new Plant * [9];
////        for (int j = 0; j < 9; j++)
////        {
////            Plants[i][j] = nullptr;
////        }
////    }
////
////    Card* c1 = new Card;
////    cards = c1->makeCards();
////
////    currWave = new Wave(wave1);
////}
////
////void Level::updateLevel(sf::RenderWindow& window)
////{
////    for (int i = 0; i < 5; i++)
////    {
////        if (cards[i].unlocked && cards[i].isPressed)
////        {
////            sf::Event event;
////            while (window.pollEvent(event))
////            {
////                if (event.type == sf::Event::Closed)
////                {
////                    window.close();
////                }
////                else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
////                {
////                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
////                    for (int j = 0; j < 5; j++)
////                    {
////                        for (int k = 0; k < 9; k++)
////                        {
////                            if (pArea->tiles[j][k].zone.contains(mousePosition.x, mousePosition.y))
////                            {
////                                cards[i].isPressed = false;
////                                if (pArea->tiles[j][k].plant == nullptr)
////                                {
////                                    PlantFactory p1;
////                                    pArea->tiles[j][k].plant = p1.makePlant(i, pArea->tiles[j][k].getCenter());
////                                    currency -= pArea->tiles[j][k].plant->cost;
////                                    break;
////                                }
////                            }
////                        }
////                    }
////                }
////            }
////        }
////    }
////
////    for (int i = 0; i < 5; i++)
////    {
////        for (int j = 0; j < 9; j++)
////        {
////            if (pArea->tiles[i][j].plant->SrNo == 2)
////            {
////                for (int k = 0; k < pArea->tiles[i][j].plant->getnumOfProjectile(); k++)
////                {
////                    if (pArea->tiles[i][j].plant->getsuns()[k].getisPressed())
////                    {
////                        currency += 50;
////                    }
////                }
////            }
////
////            if (pArea->tiles[i][j].plant->SrNo == 1 || pArea->tiles[i][j].plant->SrNo == 3 || pArea->tiles[i][j].plant->SrNo == 4)
////            {
////                for (int k = 0; k < pArea->tiles[i][j].plant->getnumOfProjectile(); k++)
////                {
////                    for (int l = 0; l < 5; l++)
////                    {
////                        if (currWave->noOfZombies[l] != 0)
////                        {
////                            for (int m = 0; m < currWave->noOfZombies[l]; m++)
////                            {
////                                Entity* ptr = currWave->totalZombies[l][m];
////                                pArea->tiles[i][j].plant->getProjectile()[k].collision(ptr);
////                                currWave->totalZombies[l][m]->hp -= pArea->tiles[i][j].plant->getProjectile()[k].damage;
////                                pArea->tiles[i][j].plant->getProjectile()[k].active = false;
////                            }
////                        }
////                    }
////                }
////            }
////        }
////    }
////}