#include "DynamicSolid.h"



DynamicSolid::DynamicSolid(float x, float y, float w, float h, SolidHandler &solidHanlder, UpdatableHandler &updatableHandler) :
	SolidHandled(x, y, w, h, solidHanlder),
	UpdatableHandled(updatableHandler)
{
}


DynamicSolid::~DynamicSolid()
{
}

void DynamicSolid::update()
{
	moveBy(xVel, yVel);
}