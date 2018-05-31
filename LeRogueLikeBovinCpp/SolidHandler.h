#pragma once

#include "DynamicSolid.h"
#include <vector>

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
};

