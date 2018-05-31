#include "DynamicSolidHandled.h"



DynamicSolidHandled::DynamicSolidHandled(float x, float y, float w, float h, SolidHandler &solidHandler, UpdatableHandler &updatableHandler):
	DynamicSolid(x,y,w,h)
{
	solidHandler.addDynamicSolid(this);
	updatableHandler.addUpdatable(this);
}


DynamicSolidHandled::~DynamicSolidHandled()
{
}
