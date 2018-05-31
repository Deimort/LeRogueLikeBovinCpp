#include "Quadtree.h"



Quadtree::Quadtree(int pLevel, sf::FloatRect pBounds)
{
	m_level = pLevel;
	m_bounds = pBounds;
}


Quadtree::~Quadtree()
{
	clear();
}

void Quadtree::clear()
{
	m_objects.clear();

	for (int i(0); m_nodes.size(); i++)
	{
		if (m_nodes.at(i) != nullptr)
		{
			m_nodes.at(i)->clear();
			delete m_nodes.at(i);
		}
	}
}

void Quadtree::split()
{
	int subWidth = (int)(m_bounds.width / 2);
	int subHeight = (int)(m_bounds.height / 2);
	int x = (int)m_bounds.left;
	int y = (int)m_bounds.top;

	m_nodes.push_back(new Quadtree(m_level + 1, sf::FloatRect(x + subWidth, y, subWidth, subHeight)));
	m_nodes.push_back(new Quadtree(m_level + 1, sf::FloatRect(x, y, subWidth, subHeight)));
	m_nodes.push_back(new Quadtree(m_level + 1, sf::FloatRect(x, y + subHeight, subWidth, subHeight)));
	m_nodes.push_back(new Quadtree(m_level + 1, sf::FloatRect(x + subWidth, y + subHeight, subWidth, subHeight)));
}

int Quadtree::getIndex(Solid  &solid)
{
	int index = -1;
	float verticalMidpoint = m_bounds.left + m_bounds.width / 2;
	float horizontalMidpoint = m_bounds.top + m_bounds.height / 2;

	bool topQuadrant = (solid.getY() < horizontalMidpoint) && (solid.getBottom() < horizontalMidpoint);
	bool bottomQuadrant = (solid.getY() > horizontalMidpoint);

	if (solid.getX() < verticalMidpoint && solid.getRight() < verticalMidpoint)
	{
		if (topQuadrant) 
		{
			index = 1;
		}
		else if (bottomQuadrant) 
		{
			index = 2;
		}
	}
	else
	{
		if (topQuadrant)
		{
			index = 0;
		}
		else if (bottomQuadrant)
		{
			index = 3;
		}
	}
	return index;
}

void Quadtree::insert(Solid &solid)
{
	if (m_nodes.size() != 0) // Old: if (m_nodes.at(0) != nullptr)
	{
		int index = getIndex(solid);

		if (index != -1)
		{
			m_nodes.at(index)->insert(solid);

			return;
		}
	}
	Solid* ptr = &solid;
	m_objects.push_back(ptr);

	if (m_objects.size() > MAX_OBJECTS && m_level < MAX_LEVELS) 
	{
		if (m_nodes.at(0) == nullptr)
		{
			split();
		}

		int i = 0;
		while (i < m_objects.size()) 
		{
			int index = getIndex(*(m_objects.at(i)));
			if (index != -1) 
			{
				Solid* temp = m_objects.at(i);
				m_objects.erase(m_objects.begin() + i);
				m_nodes.at(i)->insert(*temp);
			}
			else
			{
				i++;
			}
		}
	}
}

std::vector<Solid*> Quadtree::retrieve(std::vector<Solid*> &returnObjects, Solid &solid)
{
	int index = getIndex(solid);
	if (index != -1 && m_nodes.size() != 0)
	{
		m_nodes.at(index)->retrieve(returnObjects, solid);
	}

	for (int i(0); i < m_objects.size(); i++)
	{
		returnObjects.push_back(m_objects.at(i));
	}
	
	return returnObjects;
}