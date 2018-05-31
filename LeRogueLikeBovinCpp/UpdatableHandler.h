#pragma once

#include <vector>
#include "Updatable.h"

class UpdatableHandler
{
public:
	UpdatableHandler();
	~UpdatableHandler();

	void addUpdatable(Updatable* updatable);
	void updateAll();

private:
	std::vector<Updatable*> m_updatableList;
};

