#pragma once
#include "Entity.h"

class Card : public Entity
{
protected:
    int SrNo;
    int cost;
    string type;
    bool isPressed = false;
    bool unlocked = true;
public:
    int getSrNo() const;
    int getCost() const;
    std::string getType() const;
    bool getIsPressed() const;
    bool getUnlocked() const;
    // Setters
    void setSrNo(int value);
    void setCost(int value);
    void setType(const std::string& value);
    void setIsPressed(bool value);
    void setUnlocked(bool value);
    Card* makeCards(int i = 0);
    void update(sf::RenderWindow& window);
    void MainRender(sf::RenderWindow& window);
};
