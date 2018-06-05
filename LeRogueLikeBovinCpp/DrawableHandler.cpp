#include "DrawableHandler.h"



DrawableHandler::DrawableHandler()
{
}


DrawableHandler::~DrawableHandler()
{
}

void DrawableHandler::addDrawable(sf::Drawable* drawable) 
{
	m_drawableList.push_back(drawable);
}

void DrawableHandler::drawAll(sf::RenderWindow* gameContainer)
{
	for (int i(0); i < m_drawableList.size(); i++)
	{
		gameContainer->draw(*(m_drawableList.at(i)));
	}
}

void DrawableHandler::clear()
{
	m_drawableList.clear();
}
