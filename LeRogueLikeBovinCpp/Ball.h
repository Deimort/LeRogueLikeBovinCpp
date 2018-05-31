#pragma once

#include "UpdatableHandled.h"
#include "DrawableHandled.h"
#include "SFML/Graphics.hpp"

class Ball : public UpdatableHandled, DrawableHandled
{
public:
	Ball(DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler);
	~Ball();

	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

	void update() override;

private:
	sf::CircleShape m_circle;
};

