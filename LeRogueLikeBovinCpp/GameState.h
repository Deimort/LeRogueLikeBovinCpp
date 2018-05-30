#pragma once
#include "SFML/Graphics.hpp"

class GameState
{
public:
	GameState(sf::RenderWindow* gameContainer);
	~GameState();

	int start();

protected:
	sf::RenderWindow* m_gameContainer;
	bool m_continue = true;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;
};

