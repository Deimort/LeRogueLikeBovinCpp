#include "DynamicSolid.h"



DynamicSolid::DynamicSolid(float x, float y, float w, float h) :
	Solid(x, y, w, h)
{
}


DynamicSolid::~DynamicSolid()
{
}

void DynamicSolid::update()
{
	moveBy(m_xVel, m_yVel);
}