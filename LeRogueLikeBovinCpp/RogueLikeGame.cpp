#include "RogueLikeGame.h"



RogueLikeGame::RogueLikeGame()
{
	m_resourceLoader->loadAll();
	initStateList();	
}


RogueLikeGame::~RogueLikeGame()
{
	delete m_gameContainer;
	delete m_resourceLoader;
	m_statesList.clear();
}


void RogueLikeGame::enterState(int id)
{
	m_currentState = m_statesList.at(id);
	int nextState = m_currentState->start();
	if (nextState == -1)
	{
		// TODO détruire le jeu proprement
		m_gameContainer->close();
		return;
	}
	else
	{
		enterState(nextState);
	}
}

void RogueLikeGame::initStateList()
{
	m_statesList.push_back(new MainMenu(m_gameContainer, m_resourceLoader));
	m_statesList.push_back(new InGame(m_gameContainer, m_resourceLoader));
	m_statesList.push_back(new InputOptionMenu(m_gameContainer, m_resourceLoader));
}
