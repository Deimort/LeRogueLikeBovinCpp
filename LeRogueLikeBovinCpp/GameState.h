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
	int m_nextState = -1;

	virtual void init();
	virtual void update() = 0;
	virtual void render() = 0;

private:
	sf::Clock m_clock;
	int m_timeBuffer = 0;

	const int FRAME_LENGTH = 16000; // 16000�s == 16ms == 60FPS
};
