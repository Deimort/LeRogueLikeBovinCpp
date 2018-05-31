#include "SolidHandled.h"



SolidHandled::SolidHandled(float x, float y, float w, float h, SolidHandler &solidHandler) :
	Solid(x, y, w, h)
{
	solidHandler.addStaticSolid(this);
}


SolidHandled::~SolidHandled()
{
}
