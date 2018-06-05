#include "SolidHandler.h"

SolidHandler::SolidHandler():
	m_quadtree(0, sf::FloatRect(0, 0, 800, 600))
{
}


SolidHandler::~SolidHandler()
{
}

void SolidHandler::addStaticSolid(Solid* staticSolid)
{

	m_solidList.push_back(staticSolid);
}

void SolidHandler::addDynamicSolid(DynamicSolid* dynamicSolid)
{
	addStaticSolid(dynamicSolid);
	m_dynamicSolidList.push_back(dynamicSolid);

}

void SolidHandler::collideAll()
{
	m_quadtree.clear();
	for (int i(0); i < m_solidList.size(); i++) 
	{
		m_quadtree.insert(*(m_solidList.at(i)));
	}

	std::vector<Solid*> nearObjects;
	for (int i(0); i < m_dynamicSolidList.size(); i++) 
	{
		nearObjects.clear();
		nearObjects = m_quadtree.retrieve(nearObjects, *(m_dynamicSolidList.at(i)));

		for (int j(0); j < nearObjects.size(); j++) 
		{
			if (m_dynamicSolidList.at(i)->isColliding(*nearObjects.at(j)))
			{
				m_dynamicSolidList.at(i)->onCollide(*nearObjects.at(j));
				(nearObjects.at(j))->onCollide(*m_dynamicSolidList.at(i));
			}
		}
	}

	for (int i(0); i < m_dynamicSolidList.size(); i++)
	{
		
	}
}

void SolidHandler::clear()
{
	m_dynamicSolidList.clear();
	m_solidList.clear();
}
