#include "InGame.h"

InGame::InGame(sf::RenderWindow* gameContainer) : GameState(gameContainer)
{
	Ball* ball = new Ball(m_drawableHandler, m_updatableHandler);
	m_createdInstance.push_back(ball); // TODO trouver un meilleur moyen de gérer les delete
}

InGame::~InGame()
{
	for (int i(0); i < m_createdInstance.size(); i++)
	{
		delete m_createdInstance.at(i);
	}
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