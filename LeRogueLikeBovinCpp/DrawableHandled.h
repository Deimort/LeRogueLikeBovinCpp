#pragma once

#include "SFML/Graphics/Drawable.hpp"
#include "DrawableHandler.h"

class DrawableHandled : public sf::Drawable
{
public:
	DrawableHandled(DrawableHandler &drawableHandler);
	~DrawableHandled();
};

