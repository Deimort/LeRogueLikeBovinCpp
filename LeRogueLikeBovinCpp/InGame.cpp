#include "InGame.h"

InGame::InGame(sf::RenderWindow* gameContainer) : GameState(gameContainer)
{
}

InGame::~InGame()
{

}

void InGame::init()
{

}

void InGame::update()
{
	sf::Event e;
	while (m_gameContainer->pollEvent(e))
	{
		if (e.type == sf::Event::EventType::Closed)
		{
			m_continue = false;
		}
	}
}

void InGame::render()
{
	m_gameContainer->clear();
	m_gameContainer->display();
}