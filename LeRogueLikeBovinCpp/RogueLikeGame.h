#pragma once
#include <vector>
#include "InGame.h"
#include "MainMenu.h"
#include "InputOptionMenu.h"
#include "ResourceLoader.h"
#include "SFML/Graphics.hpp"

class RogueLikeGame
{
public:
	RogueLikeGame();
	~RogueLikeGame();

	void enterState(int idState);

private:
	std::vector<GameState*> m_statesList;
	GameState* m_currentState;

	sf::RenderWindow* m_gameContainer = new sf::RenderWindow(sf::VideoMode(1280, 720), "Sfml");
	ResourceLoader* m_resourceLoader = new ResourceLoader();

	void initStateList();
};