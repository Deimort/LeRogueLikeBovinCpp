#pragma once

#include <vector>
#include "DynamicSolid.h"
#include "Quadtree.h"
#include  "Attack.h"
#include <iostream>

class SolidHandler
{
public:
	SolidHandler();
	~SolidHandler();

	void addStaticSolid(Solid* staticSolid);
	void addDynamicSolid(DynamicSolid* dynamicSolid);
	void attack(Attack attack);
	void collideAll();
	void clear();

private:
	std::vector<Solid*> m_solidList;
	std::vector<DynamicSolid*> m_dynamicSolidList;

	Quadtree m_quadtree;
};

