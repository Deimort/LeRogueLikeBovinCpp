#pragma once

#include "Solid.h"
#include "Updatable.h"

class DynamicSolid : public Solid, public Updatable
{
public:
	DynamicSolid(float x, float y, float w, float h);
	~DynamicSolid();

	virtual void update() override;

private:

	float xVel = 0, yVel = 0;
};

