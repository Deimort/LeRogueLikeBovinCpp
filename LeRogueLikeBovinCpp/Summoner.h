#pragma once
#include "SolidHandler.h"
#include "DrawableHandler.h"
#include "UpdatableHandler.h"

class Summoner
{
public:
	Summoner(SolidHandler* sH, DrawableHandler* dH, UpdatableHandler* uH);
	~Summoner();

protected:
	SolidHandler* m_solidHandler;
	DrawableHandler* m_drawableHandler;
	UpdatableHandler* m_updatableHandler;
};

