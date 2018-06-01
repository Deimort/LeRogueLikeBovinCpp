#pragma once

#include "Entity.h"
#include "InputHandler.h"
#include "SFML/Graphics.hpp"

class Player : public Entity
{
public:
	Player(float x, float y, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler);
	~Player();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void update() override;
	void onCollide(Solid &other) override;

private:
	InputHandler input;
	sf::RectangleShape player;
};

