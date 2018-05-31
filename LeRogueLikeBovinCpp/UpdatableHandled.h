#pragma once

#include "Updatable.h"
#include "UpdatableHandler.h"

class UpdatableHandled : public Updatable
{
public:
	UpdatableHandled(UpdatableHandler &updatableHandler);
	~UpdatableHandled();


};

