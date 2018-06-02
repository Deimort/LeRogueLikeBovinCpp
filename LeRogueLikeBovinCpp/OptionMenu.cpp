#include "OptionMenu.h"



OptionMenu::OptionMenu(sf::RenderWindow* gameContainer):
	GameState(gameContainer)
{	
}


OptionMenu::~OptionMenu()
{
}

void OptionMenu::init()
{
	m_buttonList.push_back(ButtonInput("jump", m_gameContainer->getSize().x/2 -150, 0, 300, 50, m_inputConfig, m_font));
	m_buttonList.push_back(ButtonInput("up", m_gameContainer->getSize().x/2 -150, 50, 300, 50, m_inputConfig, m_font));
	m_buttonList.push_back(ButtonInput("down", m_gameContainer->getSize().x/2 -150, 100, 300, 50, m_inputConfig, m_font));
	m_buttonList.push_back(ButtonInput("left", m_gameContainer->getSize().x / 2 - 150, 150, 300, 50, m_inputConfig, m_font));
	m_buttonList.push_back(ButtonInput("right", m_gameContainer->getSize().x / 2 - 150, 200, 300, 50, m_inputConfig, m_font));
}

void OptionMenu::update()
{
	sf::Event e;
	while (m_gameContainer->pollEvent(e))
	{
		if (e.type == sf::Event::EventType::MouseButtonPressed)
		{
			selectButtonInput(e.mouseButton.x, e.mouseButton.y);
		}

		else if (e.type == sf::Event::EventType::KeyPressed)
		{
			if (m_currentButton != nullptr)
			{
				m_currentButton->setKey(m_inputConfig, e.key.code);
				std::cout << m_inputConfig.getKeyFor("jump") << std::endl;
				m_currentButton = nullptr;
			}
			else if (e.key.code == sf::Keyboard::Space)
			{
				m_inputConfig.saveInputConfig("config/input.cfg");
				m_nextState = 0;
				m_continue = false;
			}
		}

		else if (e.type == sf::Event::EventType::JoystickButtonPressed)
		{
			
			if (m_currentButton != nullptr)
			{
				m_currentButton->setButton(m_inputConfig, e.joystickButton.button);
				m_currentButton = nullptr;
			}
		}
	}
}

void OptionMenu::render()
{
	m_gameContainer->clear();
	for (int i(0); i < m_buttonList.size(); i++)
	{
		m_gameContainer->draw(m_buttonList.at(i));
	}
	m_gameContainer->display();
}

void OptionMenu::selectButtonInput(float x, float y)
{
	for (int i(0); i < m_buttonList.size(); i++)
	{
		if (m_buttonList.at(i).isClicked(x, y))
		{
			m_currentButton = &m_buttonList.at(i);
			return;
		}
	}
}
