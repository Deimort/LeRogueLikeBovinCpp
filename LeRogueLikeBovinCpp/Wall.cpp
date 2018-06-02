#include "Wall.h"



Wall::Wall(float x, float y, float w, float h, DrawableHandler &drawableHandler, SolidHandler &solidHandler):
	SolidHandled(x,y,w,h,solidHandler),
	DrawableHandled(drawableHandler)
{
	m_rectangle = sf::RectangleShape(sf::Vector2f(w, h));
	m_rectangle.setPosition(x, y);
}


Wall::~Wall()
{
}

void Wall::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(m_rectangle, states);
}

void Wall::onCollide(Solid &other)
{
	if (other.getLastBottom() <= getY())
	{
		other.moveBy(0, getY() - other.getBottom());
	}

	if (other.getLastY() >= getBottom())
	{
		other.moveBy(0, getBottom() - other.getY());
	}

	if (other.getLastRight() <= getX())
	{
		other.moveBy(getX() - other.getRight(), 0);
	}

	if (other.getLastX() >= getRight())
	{
		other.moveBy(getRight() - other.getX(), 0);
	}
}