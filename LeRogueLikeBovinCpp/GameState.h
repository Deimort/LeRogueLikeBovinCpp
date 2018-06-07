#pragma once
#include "SFML/Graphics.hpp"
#include "InputConfig.h"
#include "InputHandler.h"
#include "ResourceLoader.h"

class GameState
{
public:
	GameState(sf::RenderWindow* gameContainer, ResourceLoader* resourceLoader);
	~GameState();

	int start();

protected:
	sf::RenderWindow* m_gameContainer;
	ResourceLoader* m_resourceLoader;

	bool m_continue = true;
	int m_nextState = -1;

	InputConfig m_inputConfig;
	InputHandler m_inputHandler;

	
	//sf::Font m_font;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

private:
	sf::Clock m_clock;
	sf::Int64 m_timeBuffer = 0;

	const int FRAME_LENGTH = 16000; // 16000µs == 16ms == 60FPS
};

