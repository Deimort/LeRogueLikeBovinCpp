#include "InGame.h"

InGame::InGame(sf::RenderWindow* gameContainer) : GameState(gameContainer)
{
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
	for (int i(0); i < 8; i++) {
		std::cout << i << " : " << sf::Joystick::isConnected(i) << std::endl;
	}

	Wall* wall = new Wall(0, 480, 640, 48, m_drawableHandler, m_solidHandler);
	m_createdInstance.push_back(wall);
	Wall* wall2 = new Wall(0, 320, 300, 48, m_drawableHandler, m_solidHandler);
	m_createdInstance.push_back(wall);
	Wall* wall3 = new Wall(340, 320, 100, 48, m_drawableHandler, m_solidHandler);
	m_createdInstance.push_back(wall);
	Wall* wall4 = new Wall(540, 320, 100, 48, m_drawableHandler, m_solidHandler);
	m_createdInstance.push_back(wall);
	Player* player = new Player(100, 200, m_drawableHandler, m_updatableHandler, m_solidHandler, m_inputConfig);
	m_createdInstance.push_back(player);
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