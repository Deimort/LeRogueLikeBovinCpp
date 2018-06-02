#include "Player.h"



Player::Player(float x, float y, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler) :
	Entity(x, y, 64, 64, drawableHandler, updatableHandler, solidHandler), 
	player(sf::Vector2f(64,64))
{
	player.setPosition(x, y);
}


Player::~Player()
{
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(player, states);
}

void Player::update()
{
	Entity::update();

	player.move(xVel, yVel);
	xVel = input.getXAxisValue();
	if (input.isJumping()) 
	{
		moveBy(0, -10);
		player.move(xVel, -10);
	}
	else if (input.isMovingDown())
	{
		moveBy(0, 10);
		player.move(xVel, 10);
	}
}

void Player::onCollide(Solid &other)
{

}