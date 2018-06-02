#include "Ball.h"



Ball::Ball(float x, float y, float w, float h, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler) :
	DynamicSolidHandled(x, y, w, h, solidHandler, updatableHandler), 
	DrawableHandled(drawableHandler)
{
	m_circle = sf::CircleShape(w/2);
	m_circle.setPosition(x, y);
}


Ball::~Ball()
{
}

void Ball::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_circle, states);
}

void Ball::update() 
{
	moveBy(0, 1);
}

void Ball::onCollide(Solid &other)
{
	std::cout << "Collide" << std::endl;
}

void Ball::moveBy(float x, float y)
{
	Solid::moveBy(x, y);
	m_circle.move(x, y);
}