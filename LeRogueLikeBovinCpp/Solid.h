#pragma once

#include "SFML/Graphics/Rect.hpp"
#include "Attack.h"

class Solid
{
public:
	Solid(float x, float y, float w, float h);
	~Solid();


	virtual void onHit(Attack attack) = 0;
	virtual bool isHit(Attack attack);
	virtual void onCollide(Solid &other) = 0;
	virtual bool isColliding(Solid &other);
	
	/*GETTERS*/
	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	float getCenterX() const;
	float getCenterY() const;
	float getRight() const;
	float getBottom() const;
	float getLastX() const;
	float getLastY() const;
	float getLastRight() const;
	float getLastBottom() const;


	/*SETTERS*/
	virtual void setLocation(float x, float y);
	virtual void moveBy(float x, float y);
	virtual void setSize(float w, float h);

private:
	sf::FloatRect m_boundingBox;
	float m_lastXPosition, m_lastYPosition;
};

