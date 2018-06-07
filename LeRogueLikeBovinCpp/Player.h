#pragma once

#include "Entity.h"
#include "InputHandler.h"
#include "Animation.h"
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
	void setAnimation(Animation a);

private:
	InputHandler m_inputHandler;
	sf::RectangleShape player; // TODO remove
	Animation m_animation;

	void applyGravity();

	bool m_isOnGround, m_wasOnGround, m_flip;
};

