#pragma once

#include "GameState.h"
#include "InputConfig.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "ButtonInput.h"
#include "DropdownMenu.h"

class InputOptionMenu : public GameState
{
public:
	InputOptionMenu(sf::RenderWindow* gameContainer, ResourceLoader* resourceLoader);
	~InputOptionMenu();

protected:

	void init() override;
	void update() override;
	void render() override;

private :
	std::vector<ButtonInput> m_buttonList;
	DropdownMenu m_controllerSelector;

	ButtonInput* m_currentButton;

	void selectButtonInput(float x, float y);
};

