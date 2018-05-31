#include "InGame.h"

InGame::InGame(sf::RenderWindow* gameContainer) : GameState(gameContainer)
{
	Ball* ball = new Ball(m_drawableHandler, m_updatableHandler);
}

InGame::~InGame()
{

}

void InGame::init()
{
	GameState::init();
}

void InGame::update()
{
	sf::Event e;
	while (m_gameContainer->pollEvent(e))
	{
		if (e.type == sf::Event::EventType::Closed)
		{
			m_nextState = -1; // Exit
			m_continue = false;
		}
	}

	m_updatableHandler.updateAll();
}

void InGame::render()
{
	m_gameContainer->clear();
	m_drawableHandler.drawAll(m_gameContainer);
	m_gameContainer->display();
}