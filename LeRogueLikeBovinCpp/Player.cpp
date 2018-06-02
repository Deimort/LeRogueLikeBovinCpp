#include "Player.h"



Player::Player(float x, float y, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler, InputConfig &config) :
	Entity(x, y, 64, 64, drawableHandler, updatableHandler, solidHandler),
	m_inputHandler(config),
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

	xVel = m_inputHandler.getXAxisValue();
	if (m_inputHandler.isJumping()) 
	{
		yVel = -5;
	}
	else
	{
		applyGravity();
	}
}

void Player::onCollide(Solid &other)
{
	std::cout << "Player entered in collision" << std::endl;
}

void Player::applyGravity()
{
	if (yVel <= 3)
	{
		yVel += 0.3f;
	}
}

void Player::moveBy(float x, float y)
{
	Solid::moveBy(x, y);
	player.move(x, y);
}
