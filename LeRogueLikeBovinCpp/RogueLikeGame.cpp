#include "RogueLikeGame.h"



RogueLikeGame::RogueLikeGame()
{
	initStateList();
}


RogueLikeGame::~RogueLikeGame()
{
	delete m_gameContainer;
}


void RogueLikeGame::enterState(int id)
{
	m_currentState = m_statesList.at(id);
	int nextState = m_currentState->start();
	if (nextState == -1)
	{
		// TODO détruire le jeu proprement
		return;
	}
	else
	{
		enterState(nextState);
	}
}

void RogueLikeGame::initStateList()
{
	m_statesList.push_back(new MainMenu(m_gameContainer));
	m_statesList.push_back(new InGame(m_gameContainer));
	m_statesList.push_back(new InputOptionMenu(m_gameContainer));
}
