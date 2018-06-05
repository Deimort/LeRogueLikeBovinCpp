#include "GameState.h"



GameState::GameState(sf::RenderWindow* gameContainer)
{
	m_gameContainer = gameContainer;
	m_font.loadFromFile("assets/fonts/dpcomic.ttf");
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



/*
void GameState::update()
{

}

void GameState::render()
{

}*/