#include "Summoner.h"



Summoner::Summoner(SolidHandler * sH, DrawableHandler * dH, UpdatableHandler * uH) : 
	m_updatableHandler(uH), 
	m_solidHandler(sH),
	m_drawableHandler(dH)
{
}

Summoner::~Summoner()
{
}
