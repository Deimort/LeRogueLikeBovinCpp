#include "MainMenu.h"



MainMenu::MainMenu(sf::RenderWindow* gameContainer, ResourceLoader* resourceLoader) :
	GameState(gameContainer, resourceLoader)
{
	sf::Font* font = m_resourceLoader->getFont("MainFont");
	m_buttonsList.push_back(WidgetButton(100 , (float)gameContainer->getSize().y / 3, 200, 60, "Start Game", *font, 1));
	m_buttonsList.push_back(WidgetButton(100, (float)gameContainer->getSize().y / 3 + 60 + 10, 200, 60, "Options", *font, 2));
	m_buttonsList.push_back(WidgetButton(100, (float)gameContainer->getSize().y / 3 + 60 + 10 + 60 + 10, 200, 60, "Quitter", *font, -1));

	m_backgroundTexture = resourceLoader->getTexture("mainMenu_background");
	m_backgroundSprite = sf::Sprite(*m_backgroundTexture);
	m_backgroundSprite.setScale(((float)m_gameContainer->getSize().x) / m_backgroundTexture->getSize().x, ((float)m_gameContainer->getSize().y) / m_backgroundTexture->getSize().y);

	m_music = resourceLoader->getMusic("mainMenu");
}

MainMenu::~MainMenu()
{
}

void MainMenu::init()
{
	InputConfig testConfig;
	m_currentButton = 0;
	m_buttonsList[0].setSelected(true);
	m_music->play();
}

void MainMenu::update()
{
	sf::Event e;
	while (m_gameContainer->pollEvent(e))
	{
	}

	if (m_buttonCooldown.getElapsedTime().asMilliseconds() > 100) {
		m_buttonCooldown.restart();
		if (m_inputHandler.getYAxisValue() > 0 || m_inputHandler.getXAxisValue() > 0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			m_buttonsList[m_currentButton].setSelected(false);

			m_currentButton++;
			if (m_currentButton >= m_buttonsList.size())
			{
				m_currentButton = 0;
			}
			m_buttonsList[m_currentButton].setSelected(true);
		}

		if (m_inputHandler.getYAxisValue() < 0 || m_inputHandler.getXAxisValue() < 0 || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			m_buttonsList[m_currentButton].setSelected(false);

			m_currentButton--;
			if (m_currentButton < 0)
			{
				m_currentButton = m_buttonsList.size() - 1;

			}
			m_buttonsList[m_currentButton].setSelected(true);
		}
	}

	if (m_inputHandler.isJumping() || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		m_buttonsList[m_currentButton].setSelected(false);
		m_nextState = m_buttonsList[m_currentButton].getValue();
		m_continue = false;
		m_music->stop();
	}
}

void MainMenu::render()
{
	m_gameContainer->clear();
	m_gameContainer->draw(m_backgroundSprite);
	for (unsigned int i(0); i < m_buttonsList.size(); i++)
	{
		m_gameContainer->draw(m_buttonsList[i]);
	}
	m_gameContainer->display();
}
