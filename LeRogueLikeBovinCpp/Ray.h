#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"
#include <iostream>

class Ray
{
public:
	Ray(float x1, float y1, float x2, float y2);
	~Ray();
	float m_x1, m_y1, m_x2, m_y2; //TODO Renvoyer en private
	float getLength();
	float getXAt(float y);
	float getYAt(float x);

	bool intersects(sf::FloatRect boundingBox);

private:
	

	float getAngularK();
	float getOriginY();
};

