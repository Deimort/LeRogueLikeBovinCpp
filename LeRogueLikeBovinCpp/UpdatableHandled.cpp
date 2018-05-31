#include "UpdatableHandled.h"



UpdatableHandled::UpdatableHandled(UpdatableHandler &updatableHandler)
{
	updatableHandler.addUpdatable(this);
}


UpdatableHandled::~UpdatableHandled()
{
}
