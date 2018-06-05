#pragma once
#include "GameState.h"
#include <string>
#include "InputConfig.h" //TODO Remove
#include "WidgetButton.h"

class MainMenu : public GameState
{
public:
	MainMenu(sf::RenderWindow* gameContainer, ResourceLoader* resourceLoader);
	~MainMenu();

protected:
	void init() override;
	void update() override;
	void render() override;
	sf::Text m_startMessage;
	sf::Text m_optionMessage;

private:
	std::vector<WidgetButton> m_buttonsList;

	int m_currentButton;

	sf::Clock m_buttonCooldown;
};

