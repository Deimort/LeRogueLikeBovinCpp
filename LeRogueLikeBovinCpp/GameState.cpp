#include "GameState.h"



GameState::GameState(sf::RenderWindow* gameContainer, ResourceLoader* resourceLoader):
	m_inputHandler(m_inputConfig),
	m_resourceLoader(resourceLoader)

{
	m_gameContainer = gameContainer;
}


GameState::~GameState()
{
}

int GameState::start()
{
	m_continue = true;
	m_clock.restart();

	m_inputConfig.loadInputConfig("config/input.cfg");

	init();
	while (m_continue)
	{
		m_timeBuffer += m_clock.restart().asMicroseconds();
		while (m_timeBuffer >= FRAME_LENGTH)
		{
			m_timeBuffer -= FRAME_LENGTH;
			update();
		}
		render();
	}
	return m_nextState; // return -1 to Exit
}