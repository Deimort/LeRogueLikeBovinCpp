#include "Solid.h"



Solid::Solid(float x, float y, float w, float h) :
	m_boundingBox(x, y, w, h)
{

}


Solid::~Solid()
{
}

bool Solid::isColliding(Solid &other)
{
	return m_boundingBox.intersects(other.m_boundingBox) && &other != this;
}

float Solid::getX() const
{
	return m_boundingBox.left;
}

float Solid::getY() const
{
	return m_boundingBox.top;
}

float Solid::getWidth() const
{
	return m_boundingBox.width;
}

float Solid::getHeight() const
{
	return m_boundingBox.height;
}

float Solid::getCenterX() const
{
	return m_boundingBox.left + m_boundingBox.width / 2;
}

float Solid::getCenterY() const
{
	return m_boundingBox.top + m_boundingBox.height / 2;
}

float Solid::getRight() const
{
	return m_boundingBox.left + m_boundingBox.width;
}

float Solid::getBottom() const
{
	return m_boundingBox.top + m_boundingBox.height;
}

float Solid::getLastX() const
{
	return m_lastXPosition;
}

float Solid::getLastY() const
{
	return m_lastYPosition;
}

float Solid::getLastRight() const
{
	return getLastX() + getWidth();
}

float Solid::getLastBottom() const
{
	return getLastY() + getHeight();
}

void Solid::setLocation(float x, float y)
{
	m_boundingBox.left = x;
	m_boundingBox.top = y;
}

void Solid::moveBy(float x, float y)
{
	m_lastXPosition = m_boundingBox.left;
	m_lastYPosition = m_boundingBox.top;
	m_boundingBox.left += x;
	m_boundingBox.top += y;
}

void Solid::setSize(float w, float h)
{
	m_boundingBox.width = w;
	m_boundingBox.height = h;
}