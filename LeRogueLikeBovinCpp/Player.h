#pragma once

#include "Entity.h"
#include "InputHandler.h"
#include "SFML/Graphics.hpp"

class Player : public Entity
{
public:
	Player(float x, float y, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler, InputHandler &inputHandler);
	~Player();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void update() override;
	void onCollide(Solid &other) override;
	void moveBy(float x, float y) override;

private:
	InputHandler m_inputHandler;
	sf::RectangleShape player;

	void applyGravity();

	bool m_isOnGround, m_wasOnGround;
};

