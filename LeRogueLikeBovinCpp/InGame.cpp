#include "InGame.h"

InGame::InGame(sf::RenderWindow* gameContainer, ResourceLoader* resourceLoader) :
	GameState(gameContainer, resourceLoader)
{
}

InGame::~InGame()
{
	for (unsigned int i(0); i < m_createdInstance.size(); i++)
	{
		delete m_createdInstance.at(i);
	}
}

void InGame::init()
{
	Wall* wall = new Wall(0, 480, 640, 48, m_drawableHandler, m_solidHandler);
	m_createdInstance.push_back(wall);
	Wall* wall2 = new Wall(0, 320, 300, 48, m_drawableHandler, m_solidHandler);
	m_createdInstance.push_back(wall);
	Wall* wall3 = new Wall(340, 320, 100, 48, m_drawableHandler, m_solidHandler);
	m_createdInstance.push_back(wall);
	Wall* wall4 = new Wall(540, 320, 100, 48, m_drawableHandler, m_solidHandler);
	m_createdInstance.push_back(wall);

	m_player = new Player(100, 200, m_drawableHandler, m_updatableHandler, m_solidHandler, m_inputHandler);
	m_player->loadAnimations(*m_resourceLoader);
	m_createdInstance.push_back(m_player);

	m_gameView = sf::View(sf::Vector2f(m_player->getCenterX(), m_player->getCenterY()), sf::Vector2f(1280, 720));
	m_minimap = sf::View(sf::Vector2f(m_player->getCenterX(), m_player->getCenterY()), sf::Vector2f(2560, 1440));
	m_minimap.setViewport(sf::FloatRect(sf::Vector2f(0.85f, 0), sf::Vector2f(0.10f, 0.10f)));

	m_inputConfig.loadInputConfig("config/input.cfg");
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

		if (e.type == sf::Event::EventType::KeyReleased)
		{
			if (e.key.code == sf::Keyboard::Key::Escape)
			{
				m_nextState = 0; // Goto mainMenu
				deleteAll();
				m_continue = false;
				
			}
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
	m_resourceLoader->getRoom("room0001")->drawLayerAt(0, 0, "background", *m_gameContainer); // Background drawing
	m_drawableHandler.drawAll(m_gameContainer);
	m_resourceLoader->getRoom("room0001")->drawLayerAt(0, 0, "misc", *m_gameContainer); // Misc. drawing
	m_resourceLoader->getRoom("room0001")->drawLayerAt(0, 0, "platforms", *m_gameContainer); // Platforms and walls drawing;

	
	//END

	m_gameContainer->setView(m_minimap); // Affichage de la carte
	m_resourceLoader->getRoom("room0001")->drawLayerAt(0, 0, "background", *m_gameContainer); // Background drawing
	m_drawableHandler.drawAll(m_gameContainer);
	m_resourceLoader->getRoom("room0001")->drawLayerAt(0, 0, "misc", *m_gameContainer); // Misc. drawing
	m_resourceLoader->getRoom("room0001")->drawLayerAt(0, 0, "platforms", *m_gameContainer); // Platforms and walls drawing;
	m_gameContainer->display();

	m_gameContainer->setView(m_gameContainer->getDefaultView());
}

void InGame::deleteAll()
{
	m_drawableHandler.clear();
	m_solidHandler.clear();
	m_updatableHandler.clear();
}