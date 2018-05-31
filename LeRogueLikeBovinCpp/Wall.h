#pragma once
#include "SolidHandled.h"
#include "DrawableHandled.h"
#include "SFML/Graphics/RectangleShape.hpp"

class Wall : public SolidHandled, public DrawableHandled
{
public:
	Wall(float x, float y, float w, float h, DrawableHandler &drawableHandler, SolidHandler &solidHandler);
	~Wall();

	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;
	void onCollide(Solid &other) override;

private:
	sf::RectangleShape m_rectangle;
};

