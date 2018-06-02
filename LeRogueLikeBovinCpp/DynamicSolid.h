#pragma once

#include "Solid.h"
#include "Updatable.h"

class DynamicSolid : public Solid, public Updatable
{
public:
	DynamicSolid(float x, float y, float w, float h);
	~DynamicSolid();

	virtual void update() override;

protected:

	float m_xVel = 0, m_yVel = 0;
};

