#pragma once
#include "SFML/Graphics.hpp"
#include "User.h"
#include <iostream>
using namespace std;
class baseMenu
{
protected:
    string type = "";
    sf::Text textBox;
    string inputText;
public:
    virtual void Display(sf::RenderWindow& window, User* users, int userCount)
    {
        return;
    }
    string getType()
    {
        return type;
    }
	virtual void display(sf::RenderWindow& window) = 0;
	virtual void update(sf::RenderWindow& window) = 0;

    virtual bool getGameResumed()
    {
        return false;
    }
    virtual sf::Text getText()
    {
        return textBox;
    }
    void setString(string value)
    {
        inputText = value;
    }
    string& getString()
    {
        return inputText;
    }
    virtual bool getScoreBoardPressed()
    {
        return false;
    }
    virtual bool hasGameRestarted()  { return false; }
    virtual bool getExit()  { return false; }
    virtual int getLevelToPlay()  { return -1; }
    virtual bool getStartGamePressed()  { return false; }
    virtual bool getLevelPressed()  { return false; }
    virtual bool getInfoPressed()  { return false; }
    virtual bool getExitPressed()  { return false; }
};

