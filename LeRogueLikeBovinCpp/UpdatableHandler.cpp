#include "UpdatableHandler.h"



UpdatableHandler::UpdatableHandler()
{
}


UpdatableHandler::~UpdatableHandler()
{
}

void UpdatableHandler::addUpdatable(Updatable* updatable) 
{
	m_updatableList.push_back(updatable);
}

void UpdatableHandler::updateAll()
{
	for (int i(0); i < m_updatableList.size(); i++) 
	{
		m_updatableList.at(i)->update();
	}
}