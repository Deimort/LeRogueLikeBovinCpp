#include "Entity.h"



Entity::Entity(float x, float y, float w, float h, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler) :
	DynamicSolidHandled(x, y, w, h, solidHandler, updatableHandler),
	DrawableHandled(drawableHandler)
{
}


Entity::~Entity()
{
}

