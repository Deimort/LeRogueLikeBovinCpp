#pragma once

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include <vector>

class DrawableHandler
{
public:
	DrawableHandler();
	~DrawableHandler();

	void addDrawable(sf::Drawable* drawable);
	void drawAll(sf::RenderWindow* gameContainer);

private:
	std::vector<sf::Drawable*> m_drawableList;
};

