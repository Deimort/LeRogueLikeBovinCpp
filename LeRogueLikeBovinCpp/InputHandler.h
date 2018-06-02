#pragma once

#include "SFML/Window.hpp"
#include <iostream>
#include <math.h>
#include "InputConfig.h"

class InputHandler
{
public:
	InputHandler(InputConfig &config);
	~InputHandler();

	float getXAxisValue();
	float getYAxisValue();
	bool isJumping();
	bool isMovingDown();

private:
	InputConfig* m_inputConfig;

};

