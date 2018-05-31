#pragma once

#include <iostream>
#include "DrawableHandled.h"
#include "DynamicSolidHandled.h"
#include "SFML/Graphics.hpp"

class Ball : public DynamicSolidHandled, DrawableHandled
{
public:
	Ball(float x, float y, float w, float h, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler);
	~Ball();

	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

	void update() override;
	void onCollide(Solid &other) override;

private:
	sf::CircleShape m_circle;
};

