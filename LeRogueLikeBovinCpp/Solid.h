#pragma once

#include "SFML/Graphics/Rect.hpp"

class Solid
{
public:
	Solid(float x, float y, float w, float h);
	~Solid();

	virtual void onCollide(Solid &other) = 0;
	virtual bool isColliding(Solid &other);
	
	/*GETTERS*/
	float getX();
	float getY();
	float getWidth();
	float getHeight();
	float getCenterX();
	float getCenterY();
	float getRight();
	float getBottom();
	
	/*SETTERS*/
	void setLocation(float x, float y);
	void moveBy(float x, float y);
	void setSize(float w, float h);

private:
	sf::FloatRect m_boundingBox;
};

