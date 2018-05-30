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
		// TODO framerate
		update();
		render();
	}
	return -1; // return -1 to Exit
}

/*
void GameState::init()
{

}

void GameState::update()
{

}

void GameState::render()
{

}*/