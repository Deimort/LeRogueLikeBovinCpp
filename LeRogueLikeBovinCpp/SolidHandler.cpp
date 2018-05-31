#include "SolidHandler.h"



SolidHandler::SolidHandler()
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
}