#pragma once
#include "SFML/Audio.hpp"
#include <fstream>
#include "Level.h"
#include "baseMenu.h"
#include "MainMenu.h"
#include "InstructionMenu.h"
#include "levelMenu.h"
#include "GameOverMenu.h"
#include "PauseMenu.h"
#include "ScoreBoard.h"
#include "User.h"

class MainGame
{
public:
	std::ofstream outputFile;
	sf::Text inputText;
	sf::Font font;
	sf::Text promptText;
	std::string playerName;
	std::ifstream inputFile;
	bool pause = false;
	bool exits = false;
	Level* currLevel = nullptr;
	baseMenu* currMenu = nullptr;
	bool nameEntered = false;
	static const int MAX_USERS = 100;
	User users[MAX_USERS];
	int userCount = 0;
	bool flag = true;
	sf::SoundBuffer soundBuffer;

public:

	MainGame() : promptText("Enter your name:", font, 24), inputText("", font, 24), outputFile("Leaderboard.txt", std::ios_base::app), inputFile("Leaderboard.txt")
	{
		promptText.setPosition(100, 400);
		inputText.setPosition(100, 420);
		currMenu = new MainMenu;
		if (!font.loadFromFile("C:Images/assets/Fonts/SERIO.TTF")) {
			//        std::cout << "Failed to load font." << std::endl;
			//        return -1;
		}

		if (inputFile.is_open()) {
			while (inputFile >> users[userCount].name >> users[userCount].score) {
				userCount++;
			}
			inputFile.close();
		}
		
	}
	void display(sf::RenderWindow& window)
	{
		window.setFramerateLimit(60);
		while (window.isOpen())
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				pause = true;
			}
			else if (pause && sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				pause = false;
				delete currMenu;
				currMenu = nullptr;
			}

			// Event handling
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || exits)
					window.close();
				else if (!nameEntered && event.type == sf::Event::TextEntered)
				{
					if (event.text.unicode >= 32 && event.text.unicode <= 126)
					{
						playerName += static_cast<char>(event.text.unicode);
						inputText.setString(playerName);
					}
					else if (event.text.unicode == '\b' && playerName.size() > 0)
					{
						playerName.pop_back();
						inputText.setString(playerName);
					}
				}
				// Check for Enter key press
				if (!nameEntered && event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
				{
					flag = false;
					nameEntered = true;
					std::cout << "Player name entered: " << playerName << std::endl;

					// Generate a random score for the player
					cout << "here";
					// Store the name and score in the array
					users[userCount].name = playerName;
					users[userCount++].score = 100;

					// Open file in append mode
					if (outputFile.is_open()) {
						outputFile << playerName << "             " << users[userCount - 1].score << std::endl; // Append the name and score
						outputFile.close();
						std::cout << "Player name and score saved to file." << std::endl;
					}
					else {
						std::cout << "Failed to open the file for writing." << std::endl;
					}
				}
			}

			window.clear();
			// Clear the window
			MainGame::update();

			// Draw the background image
			if (currMenu != nullptr)
			{
				if (currMenu->getType() == "scoreBoard")
					currMenu->Display(window, users, userCount);
				else
					currMenu->display(window);

				currMenu->update(window);

			}
			else if (currLevel != nullptr && !pause)
			{
				currLevel->updateLevel(window);
				currLevel->currWave->Update(window);
			}
			if (flag)
			{
				window.draw(promptText);
				window.draw(inputText);
			}

			window.display();
		}
	}

	void update()
	{

		if (currMenu != nullptr && currMenu->hasGameRestarted())
		{
			int temp = currLevel->levelno;
			delete currLevel;
			delete currMenu;
			currMenu = nullptr;
			currLevel = new Level(temp);
			currLevel->initWave();
		}
		if (currMenu != nullptr && currMenu->getScoreBoardPressed() && currLevel == nullptr)
		{
			delete currMenu;
			currMenu = new scoreBoard;

		}
		else if (currMenu != nullptr && currMenu->getInfoPressed() && currLevel == nullptr)
		{
			delete currMenu;
			currMenu = new instructionMenu;

		}
		else if (currMenu != nullptr && currMenu->getLevelPressed() && currLevel == nullptr)
		{
			delete currMenu;
			currMenu = new levelMenu;
		}
		else if (currMenu != nullptr && currMenu->getStartGamePressed() && currLevel == nullptr)
		{
			delete currMenu;
			currMenu = new levelMenu;
		}
		if (currMenu != nullptr && currMenu->getExitPressed() && currLevel == nullptr)
		{

			exits = true;
		}
		else if (currMenu != nullptr && currMenu->getExit() && currLevel == nullptr)
		{
			delete currMenu;
			currMenu = new MainMenu;
		}
		else if (currMenu != nullptr && currMenu->getLevelToPlay() != -1 && currLevel == nullptr)
		{
			currLevel = new Level(currMenu->getLevelToPlay());
			currLevel->initWave();
			delete currMenu;
			currMenu = nullptr;
		}
		else if (currLevel != nullptr && currLevel->win)
		{
			users[userCount - 1].score += 100;
			delete currLevel;
			currLevel = nullptr;
			currMenu = new MainMenu;
		}
		else if (currLevel != nullptr && currLevel->lose)
		{
			currMenu = new GameOverMenu;
		}
		if (pause)
		{
			currMenu = new PauseMenu;
		}


	}
};

