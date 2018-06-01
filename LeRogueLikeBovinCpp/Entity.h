#pragma once

#include "DynamicSolidHandled.h"
#include "DrawableHandled.h"

class Entity : public DynamicSolidHandled, public DrawableHandled
{
public:
	Entity(float x, float y, float w, float h, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler);
	~Entity();

};

