#include "InGame.h"

InGame::InGame(sf::RenderWindow* gameContainer) : GameState(gameContainer)
{
	Ball* ball = new Ball(0,0,5,5,m_drawableHandler, m_updatableHandler, m_solidHandler);
	m_createdInstance.push_back(ball); // TODO trouver un meilleur moyen de g�rer les delete
	Wall* wall = new Wall(0, 480, 30, 10, m_drawableHandler, m_solidHandler);
	m_createdInstance.push_back(wall);
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
	m_solidHandler.collideAll();
}

void InGame::render()
{
	m_gameContainer->clear();
	m_drawableHandler.drawAll(m_gameContainer);
	m_gameContainer->display();
}