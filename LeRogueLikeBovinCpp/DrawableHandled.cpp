#include "DrawableHandled.h"



DrawableHandled::DrawableHandled(DrawableHandler &drawableHandler)
{
	drawableHandler.addDrawable(this);
}


DrawableHandled::~DrawableHandled()
{
}
