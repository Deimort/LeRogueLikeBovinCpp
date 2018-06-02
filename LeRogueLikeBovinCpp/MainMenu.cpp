#include "MainMenu.h"



MainMenu::MainMenu(sf::RenderWindow* gameContainer) : GameState(gameContainer)
{
	m_homeMessage = sf::Text("<Press -space- to launch>", m_font);
	m_homeMessage.setOrigin(sf::Vector2f(m_homeMessage.getLocalBounds().width / 2, m_homeMessage.getLocalBounds().height / 2));
	m_homeMessage.setPosition(m_gameContainer->getSize().x / 2, m_gameContainer->getSize().y / 2);
}


MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
	InputConfig testConfig;
	testConfig.loadInputConfig("config/config.txt");
	testConfig.saveInputConfig("config/config.txt");
}

void MainMenu::update()
{
	sf::Event e;
	while (m_gameContainer->pollEvent(e))
	{
		if (e.type == sf::Event::EventType::KeyPressed)
		{
			if (e.key.code == sf::Keyboard::Space)
			{
				m_nextState = 1; // InGame
				m_continue = false;
			}
			else if (e.key.code == sf::Keyboard::O)
			{
				m_nextState = 2;
				m_continue = false;
			}
		}
	}
}

void MainMenu::render()
{
	m_gameContainer->clear();
	m_gameContainer->draw(m_homeMessage);
	m_gameContainer->display();
}
