#include "Ball.h"



Ball::Ball(DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler) : UpdatableHandled(updatableHandler), DrawableHandled(drawableHandler)
{
	m_circle = sf::CircleShape(5);
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
	m_circle.move(1, 1);
}