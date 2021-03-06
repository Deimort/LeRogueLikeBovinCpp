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
	int controllerId = m_inputConfig->getCurrentController();
	float axisValue(0);

	/*
		Keyboard section
	*/
	if (controllerId == -1 || !sf::Joystick::isConnected(controllerId))
	{
		if (sf::Keyboard::isKeyPressed(m_inputConfig->getKeyFor("left")))
		{
			axisValue -= 1;
		}
		if (sf::Keyboard::isKeyPressed(m_inputConfig->getKeyFor("right")))
		{
			axisValue += 1;
		}
	}

	/*
		Joystick section
	*/
	else
	{
		axisValue = (sf::Joystick::getAxisPosition(controllerId, sf::Joystick::X) + sf::Joystick::getAxisPosition(controllerId, sf::Joystick::PovX)) / 100;
		if (axisValue > 1)
			axisValue = 1;

		if (axisValue < -1)
			axisValue = -1;

		if (abs(axisValue) <= 0.1f)
		{
			axisValue = 0;
		}
	}

	return axisValue;
}

float InputHandler::getYAxisValue()
{
	int controllerId = m_inputConfig->getCurrentController();
	float axisValue(0);

	/*
	Keyboard section
	*/
	if (controllerId == -1 || !sf::Joystick::isConnected(controllerId))
	{
		if (sf::Keyboard::isKeyPressed(m_inputConfig->getKeyFor("up")))
		{
			axisValue -= 1;
		}
		if (sf::Keyboard::isKeyPressed(m_inputConfig->getKeyFor("down")))
		{
			axisValue += 1;
		}
	}

	/*
	Joystick section
	*/
	else
	{
		axisValue = (sf::Joystick::getAxisPosition(controllerId, sf::Joystick::Y) - sf::Joystick::getAxisPosition(controllerId, sf::Joystick::PovY)) / 100; // PoV Y est invers�
		if (axisValue > 1)
			axisValue = 1;

		if (axisValue < -1)
			axisValue = -1;

		if (abs(axisValue) <= 0.1f)
		{
			axisValue = 0;
		}
	}

	return axisValue;
}

bool InputHandler::isJumping()
{
	int controllerId = m_inputConfig->getCurrentController();

	/*
	Keyboard section
	*/
	if (controllerId == -1 || !sf::Joystick::isConnected(controllerId))
	{
		return sf::Keyboard::isKeyPressed(m_inputConfig->getKeyFor("jump"));
	}

	/*
	Joystick section
	*/
	else
	{
		return sf::Joystick::isButtonPressed(controllerId, m_inputConfig->getButtonFor("jump"));
	}
}

bool InputHandler::isAttacking()
{
	int controllerId = m_inputConfig->getCurrentController();

	/*
	Keyboard section
	*/
	if (controllerId == -1 || !sf::Joystick::isConnected(controllerId))
	{
		return sf::Keyboard::isKeyPressed(m_inputConfig->getKeyFor("attack"));
	}

	/*
	Joystick section
	*/
	else
	{
		return sf::Joystick::isButtonPressed(controllerId, m_inputConfig->getButtonFor("attack"));
	}
}

bool InputHandler::isMovingDown()
{
	return sf::Joystick::isButtonPressed(2, 0) && getYAxisValue() > 0;
}
