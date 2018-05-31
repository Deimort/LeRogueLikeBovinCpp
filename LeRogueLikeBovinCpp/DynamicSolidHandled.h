#pragma once
#include "DynamicSolid.h"
#include "UpdatableHandler.h"
#include "SolidHandler.h"

class DynamicSolidHandled : public DynamicSolid
{
public:
	DynamicSolidHandled(float x, float y, float w, float h, SolidHandler &solidHandler, UpdatableHandler &updatableHandler);
	~DynamicSolidHandled();
};

