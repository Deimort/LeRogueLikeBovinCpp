#pragma once

#include "SFML/Window.hpp"
#include <iostream>
#include <math.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();

	float getXAxisValue();
	//bool isJumping();
	//bool isMovingDown();

private:
	sf::Keyboard::Key up = sf::Keyboard::Z;
	sf::Keyboard::Key down = sf::Keyboard::S;
	sf::Keyboard::Key left = sf::Keyboard::Q;
	sf::Keyboard::Key right = sf::Keyboard::D;
	sf::Keyboard::Key jump = sf::Keyboard::Space;
	sf::Keyboard::Key use = sf::Keyboard::E;

};

