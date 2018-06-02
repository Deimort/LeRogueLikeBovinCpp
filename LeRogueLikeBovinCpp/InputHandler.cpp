#include "InputHandler.h"



InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

float InputHandler::getXAxisValue()
{
	float axisValue(0);

	if (sf::Keyboard::isKeyPressed(left))
	{
		axisValue -= 1;
	}
	if (sf::Keyboard::isKeyPressed(right))
	{
		axisValue += 1;
	}
	if (sf::Joystick::isConnected(2)) {
		axisValue = sf::Joystick::getAxisPosition(2, sf::Joystick::X) / 100;

		if (abs(axisValue) < 0.1) {
			axisValue = 0;
		}
		//std::cout << sf::Joystick::getAxisPosition(2, sf::Joystick::X) << std::endl;
	}


	return axisValue;
}

float InputHandler::getYAxisValue()
{
	float axisValue(0);

	if (sf::Joystick::isConnected(2)) {
		axisValue = sf::Joystick::getAxisPosition(2, sf::Joystick::Y) / 100;

		if (abs(axisValue) < 0.1) {
			axisValue = 0;
		}
		//std::cout << sf::Joystick::getAxisPosition(2, sf::Joystick::Y) << std::endl;
	}

	return axisValue;
}

bool InputHandler::isJumping()
{
	return sf::Joystick::isButtonPressed(2, 0) && getYAxisValue() <= 0;
}

bool InputHandler::isMovingDown()
{
	return sf::Joystick::isButtonPressed(2, 0) && getYAxisValue() > 0;
}

