#pragma once
#include "GameState.h"
#include <string>

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
	sf::Font m_font;

};

