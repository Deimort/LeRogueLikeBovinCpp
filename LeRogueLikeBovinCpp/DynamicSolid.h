#pragma once

#include "SolidHandled.h"
#include "UpdatableHandled.h"

class DynamicSolid : public SolidHandled, UpdatableHandled
{
public:
	DynamicSolid(float x, float y, float w, float h, SolidHandler &solidHandler, UpdatableHandler &updatableHandler);
	~DynamicSolid();

	virtual void update() override;

private:

	float xVel = 0, yVel = 0;
};

