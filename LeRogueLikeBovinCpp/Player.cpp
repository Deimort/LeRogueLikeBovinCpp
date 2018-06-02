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
	m_xVel = m_inputHandler.getXAxisValue() * 5;
	if (m_inputHandler.isJumping() && m_isOnGround) 
	{
		m_yVel = -7;
	}
	else
	{
		applyGravity();
	}
	std::cout << m_isOnGround << std::endl;

	/// Resetting onTheGround ///
	m_wasOnGround = m_isOnGround;
	m_isOnGround = false;
}

void Player::onCollide(Solid &other)
{

}

void Player::applyGravity()
{
	if (m_yVel > 0 && m_wasOnGround && !m_isOnGround)
	{
		m_yVel = 0;
	}
	if (m_yVel < 7)
	{
		m_yVel += 0.3f;
	}
	if(m_yVel >= 7)
	{
		m_yVel = 7;
	}
}

void Player::moveBy(float x, float y)
{
	// Move to the top and get stopped
	if (y > 0 && m_yVel < 0)
	{
		m_yVel = 0;
	}

	// Move to the bottom and get stopped -> isOnTheGround
	if (y < 0 && m_yVel > 0)
	{
		m_isOnGround = true;
	}

	Solid::moveBy(x, y);
	player.move(x, y);
}
