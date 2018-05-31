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
	float getX() const;
	float getY() const;
	float getWidth() const;
	float getHeight() const;
	float getCenterX() const;
	float getCenterY() const;
	float getRight() const;
	float getBottom() const;
	
	/*SETTERS*/
	void setLocation(float x, float y);
	void moveBy(float x, float y);
	void setSize(float w, float h);

private:
	sf::FloatRect m_boundingBox;
};

