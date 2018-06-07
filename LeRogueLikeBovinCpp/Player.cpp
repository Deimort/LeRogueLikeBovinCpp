#include "Player.h"

Player::Player(float x, float y, DrawableHandler & drawableHandler, UpdatableHandler & updatableHandler, SolidHandler & solidHandler, InputHandler &inputHandler):
	Entity(x, y, 64, 64, drawableHandler, updatableHandler, solidHandler),
	m_inputHandler(inputHandler),
	player(sf::Vector2f(64, 64))
{
	player.setPosition(x, y);
}

Player::~Player()
{
}

void Player::setAnimation(Animation a)
{
	m_animation = a;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::Sprite sprite = m_animation.getCurrentFrame();
	states.transform.translate(getX(), getY());
	if (m_flip)
	{
		states.transform.scale(-1, 1);
		states.transform.translate(-64, 0); // Correction du décalage produit par le scale
	}
	
	target.draw(player);
	target.draw(sprite, states);
	
}

void Player::update()
{
	Entity::update();

	/// Updating animation ///
	m_animation.update();
	if (m_xVel > 0)
		m_flip = false;
	if (m_xVel < 0)
		m_flip = true;

	m_xVel = m_inputHandler.getXAxisValue() * 5;
	if (m_inputHandler.isJumping() && m_isOnGround) 
	{
		m_yVel = -10;
	}
	else
	{
		applyGravity();
	}
	/// Resetting onTheGround ///
	m_wasOnGround = m_isOnGround;
	m_isOnGround = false;
}

void Player::onCollide(Solid &other)
{

}

void Player::applyGravity()
{
	if (m_yVel > 0 && m_wasOnGround && !m_isOnGround) // Si le joueur tombe d'une plateforme
	{
		m_yVel = 0;
	}
	if (m_yVel < 10)
	{
		m_yVel += 0.5f;
	}
	if(m_yVel >= 10)
	{
		m_yVel = 10;
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
