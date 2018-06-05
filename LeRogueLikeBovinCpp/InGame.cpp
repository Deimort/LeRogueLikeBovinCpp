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
	m_player = new Player(100, 200, m_drawableHandler, m_updatableHandler, m_solidHandler, m_inputHandler);
	m_createdInstance.push_back(m_player);

	m_gameView = sf::View(sf::Vector2f(m_player->getCenterX(), m_player->getCenterY()), sf::Vector2f(1280, 720));
	m_minimap = sf::View(sf::Vector2f(m_player->getCenterX(), m_player->getCenterY()), sf::Vector2f(2560, 1440));
	m_minimap.setViewport(sf::FloatRect(sf::Vector2f(0.85, 0), sf::Vector2f(0.10, 0.10)));

	m_inputConfig.loadInputConfig("config/input.cfg");
	std::cout << m_inputConfig.getCurrentController() << std::endl;
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
	m_gameView.setCenter(m_player->getCenterX(), m_player->getCenterY());
	m_minimap.setCenter(m_player->getCenterX(), m_player->getCenterY());
}

void InGame::render()
{
	m_gameContainer->clear();
	m_gameContainer->setView(m_gameView); // Affichage du jeu
	m_drawableHandler.drawAll(m_gameContainer);
	m_gameContainer->setView(m_minimap); // Affichage de la carte
	m_drawableHandler.drawAll(m_gameContainer);
	m_gameContainer->display();
}