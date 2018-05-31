#pragma once

#include "SolidHandler.h"
#include "Solid.h"


class SolidHandled : public Solid
{
public:
	SolidHandled(float x, float y, float w, float h, SolidHandler &solidHandler);
	~SolidHandled();
};

