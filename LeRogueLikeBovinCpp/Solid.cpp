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
	return m_boundingBox.intersects(other.m_boundingBox);
}

float Solid::getX() 
{
	return m_boundingBox.left;
}

float Solid::getY()
{
	return m_boundingBox.top;
}

float Solid::getWidth()
{
	return m_boundingBox.width;
}

float Solid::getHeight()
{
	return m_boundingBox.height;
}

float Solid::getCenterX()
{
	return m_boundingBox.left + m_boundingBox.width / 2;
}

float Solid::getCenterY()
{
	return m_boundingBox.top + m_boundingBox.height / 2;
}

float Solid::getRight()
{
	return m_boundingBox.left + m_boundingBox.width;
}

float Solid::getBottom()
{
	return m_boundingBox.top + m_boundingBox.height;
}

void Solid::setLocation(float x, float y)
{
	m_boundingBox.left = x;
	m_boundingBox.top = y;
}

void Solid::moveBy(float x, float y)
{
	m_boundingBox.left += x;
	m_boundingBox.top += y;
}

void Solid::setSize(float w, float h)
{
	m_boundingBox.width = w;
	m_boundingBox.height = h;
}