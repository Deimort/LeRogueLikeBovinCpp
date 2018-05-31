#pragma once

#include <iostream>
#include "DrawableHandled.h"
#include "SFML/Graphics.hpp"
#include "DynamicSolid.h"

class Ball : public DynamicSolid, DrawableHandled
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

