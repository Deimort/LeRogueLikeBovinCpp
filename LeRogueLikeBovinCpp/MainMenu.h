#pragma once
#include "GameState.h"
#include <string>
#include "InputConfig.h" //TODO Remove

class MainMenu : public GameState
{
public:
	MainMenu(sf::RenderWindow* gameContainer);
	~MainMenu();

protected:
	void init() override;
	void update() override;
	void render() override;
	sf::Text m_homeMessage;

};

