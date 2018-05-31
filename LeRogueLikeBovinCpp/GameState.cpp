#include "GameState.h"



GameState::GameState(sf::RenderWindow* gameContainer)
{
	m_gameContainer = gameContainer;
}


GameState::~GameState()
{
}

int GameState::start()
{
	m_continue = true;
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


void GameState::init()
{
	m_clock.restart();
}
/*
void GameState::update()
{

}

void GameState::render()
{

}*/