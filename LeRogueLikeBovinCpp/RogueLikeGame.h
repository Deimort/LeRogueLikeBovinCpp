#pragma once
#include <vector>
#include "InGame.h"
#include "MainMenu.h"
#include "OptionMenu.h"
#include <SFML/Graphics.hpp>

class RogueLikeGame
{
public:
	RogueLikeGame();
	~RogueLikeGame();

	void enterState(int idState);

private:
	std::vector<GameState*> m_statesList;
	GameState* m_currentState;

	sf::RenderWindow* m_gameContainer = new sf::RenderWindow(sf::VideoMode(800, 600), "Sfml");

	void initStateList();
};

