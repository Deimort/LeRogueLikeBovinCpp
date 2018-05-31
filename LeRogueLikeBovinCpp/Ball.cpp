#include "Ball.h"



Ball::Ball(float x, float y, float w, float h, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler) :
	DynamicSolid(x, y, w, h, solidHandler, updatableHandler), 
	DrawableHandled(drawableHandler)
{
	m_circle = sf::CircleShape(w);
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
	m_circle.move(0, 1);
}

void Ball::onCollide(Solid &other)
{
	std::cout << "Collide" << std::endl;
}