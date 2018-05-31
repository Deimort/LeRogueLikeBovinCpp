#pragma once

#include "DynamicSolid.h"
#include <vector>
#include "Quadtree.h"

class SolidHandler
{
public:
	SolidHandler();
	~SolidHandler();

	void addStaticSolid(Solid* staticSolid);
	void addDynamicSolid(DynamicSolid* dynamicSolid);

	void collideAll();

private:
	std::vector<Solid*> m_solidList;
	std::vector<DynamicSolid*> m_dynamicSolidList;

	Quadtree m_quadtree;
};

