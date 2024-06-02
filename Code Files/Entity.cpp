#include "Entity.h"
void Entity::setTextures(sf::Texture T1[], sf::Texture T2[], sf::Texture T3[])
{
    currTexture = new sf::Texture[numOfTextures];
    Texture1 = new sf::Texture[numOfTextures];
    Texture2 = new sf::Texture[numOfTextures];
    
    if (T3 != nullptr)
        Texture3 = new sf::Texture[numOfTextures];
    for (int i = 0; i < numOfTextures; i++)
    {
        Texture1[i] = T1[i];
        Texture2[i] = T2[i];
        if(T3!=nullptr)
        Texture3[i] = T3[i];
    }
}
void Entity::setcurrFrame(int value)
{
    currFrame = value;
}

void Entity::update()
{
    sprite.setPosition(position.x, position.y);
}
void Entity::Animate()
{
    swapTextures();
    if (clock.getElapsedTime().asSeconds() > 0.1)
    {
        {
            currFrame = (currFrame + 1) % numOfTextures;
            sprite.setTexture(currTexture[currFrame]);
            clock.restart();
        }
    }
}
void Entity::render(sf::RenderWindow& window)
{
    window.draw(sprite);
}
void Entity::MainRender(sf::RenderWindow& window)
{
    Animate();
    Entity::update();
    render(window);
}

bool Entity::collision(Entity* E1)
{
    if (position.x + hitBox.x - 55 >= E1->position.x &&
        position.x - hitBox.x - 30 <= E1->position.x &&
        position.y + hitBox.y - 55 >= E1->position.y &&
        position.y - hitBox.y - 30 <= E1->position.y
        )
    {
        return true;
    }

    return false;
}

int Entity::getcurrFrame()
{
    return currFrame;
}

Coordinate Entity::getHitbox()
{
    return  hitBox;
}
void Entity::setHitboxX(int x)
{
    hitBox.x = x;
}
void Entity::setHitboxY(int y)
{
    hitBox.y = y;
}

Coordinate Entity::getPosition()
{
    return position;
}
void Entity::setPositionX(int x)
{
    position.x = x;
}
void Entity::setPositionY(int y)
{
    position.y = y;
}
void Entity::setT2(bool value)
{
    T2 = value;
}
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

void Entity::swapTextures()
{
    if (T1)
    {
        for (int i = 0; i < numOfTextures; ++i)
        {
            currTexture[i] = Texture1[i];
        }
        T1 = false;
    }
    else if (T2)
    {
        for (int i = 0; i < numOfTextures; ++i)
        {
            currTexture[i] = Texture2[i];
        }
        T2 = false;
    }
    else if (T3)
    {
        for (int i = 0; i < numOfTextures; ++i)
        {
            currTexture[i] = Texture3[i];
        }
        cout << "Texture 3\n";
        T3 = false;
    }

}