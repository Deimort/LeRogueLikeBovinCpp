#pragma once

#include <vector>
#include "DynamicSolid.h"
#include "Quadtree.h"
#include <iostream>

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

