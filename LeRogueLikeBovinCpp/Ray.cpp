#include "Ray.h"


Ray::Ray(float x1, float y1, float x2, float y2)
{
	m_x1 = x1;
	m_y1 = y1;
	m_x2 = x2;
	m_y2 = y2;
}

Ray::~Ray()
{
}

float Ray::getLength()
{
	return std::sqrt(((m_x2 - m_x1) * (m_x2 - m_x1)) + ((m_y2 - m_y1) * (m_y2 - m_y1)));
}

float Ray::getXAt(float y)
{
	return (y - getOriginY()) / getAngularK();
}

float Ray::getYAt(float x)
{
	return getAngularK()*x + getOriginY();
}

bool Ray::intersects(sf::FloatRect boundingBox)
{
	sf::Vector2f leftI;
	sf::Vector2f topI;
	sf::Vector2f rightI;
	sf::Vector2f bottomI;

	leftI = sf::Vector2f(boundingBox.left, getYAt(boundingBox.left));
	rightI = sf::Vector2f(boundingBox.left + boundingBox.width, getYAt(boundingBox.left + boundingBox.width));
	topI = sf::Vector2f(getXAt(boundingBox.top), boundingBox.top);
	bottomI = sf::Vector2f(getXAt(boundingBox.top+boundingBox.height), boundingBox.top + boundingBox.height);

	std::cout << "Left I : " << leftI.x << ", " << leftI.y << std::endl;
	std::cout << "Right I : " << rightI.x << ", " << rightI.y << std::endl;
	std::cout << "Top I : " << topI.x << ", " << topI.y << std::endl;
	std::cout << "Bottom I : " << bottomI.x << ", " << bottomI.y << std::endl;

	return ((leftI.y >= boundingBox.top && leftI.y <= boundingBox.top + boundingBox.height
			&& leftI.y <= std::fmaxf(m_y1, m_y2) && leftI.y >= std::fminf(m_y1, m_y2)
			&& leftI.x <= std::fmaxf(m_x1, m_x2) && leftI.x >= std::fminf(m_x1, m_x2))
			|| 
			(rightI.y >= boundingBox.top && rightI.y <= boundingBox.top + boundingBox.height
			&& rightI.y <= std::fmaxf(m_y1, m_y2) && rightI.y >= std::fminf(m_y1, m_y2)
			&& rightI.x <= std::fmaxf(m_x1, m_x2) && rightI.x >= std::fminf(m_x1, m_x2))
			||
			(topI.x >= boundingBox.left && topI.x <= boundingBox.left + boundingBox.width
		    && topI.y <= std::fmaxf(m_y1, m_y2) && topI.y >= std::fminf(m_y1, m_y2)
		    && topI.x <= std::fmaxf(m_x1, m_x2) && topI.x >= std::fminf(m_x1, m_x2))
			||
			(bottomI.x >= boundingBox.left && bottomI.x <= boundingBox.left + boundingBox.width
		    && bottomI.y <= std::fmaxf(m_y1, m_y2) && bottomI.y >= std::fminf(m_y1, m_y2)
		    && bottomI.x <= std::fmaxf(m_x1, m_x2) && bottomI.x >= std::fminf(m_x1, m_x2))
		);
}

float Ray::getAngularK()
{
	return (m_y2 - m_y1) / (m_x2 - m_x1);
}

float Ray::getOriginY()
{
	return m_y1 - getAngularK()*m_x1;
}
