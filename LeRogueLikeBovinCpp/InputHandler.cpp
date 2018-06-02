#include "InputHandler.h"



InputHandler::InputHandler(InputConfig &config):
	m_inputConfig(&config)
{
}


InputHandler::~InputHandler()
{
}

float InputHandler::getXAxisValue()
{
	float axisValue(0);

	if (sf::Keyboard::isKeyPressed(m_inputConfig->getKeyFor("left")))
	{
		axisValue -= 1;
	}
	if (sf::Keyboard::isKeyPressed(m_inputConfig->getKeyFor("right")))
	{
		axisValue += 1;
	}

	return axisValue;
}

float InputHandler::getYAxisValue()
{
	float axisValue(0);

	return axisValue;
}

bool InputHandler::isJumping()
{
	return sf::Keyboard::isKeyPressed(m_inputConfig->getKeyFor("jump"));
}

bool InputHandler::isMovingDown()
{
	return sf::Joystick::isButtonPressed(2, 0) && getYAxisValue() > 0;
}

