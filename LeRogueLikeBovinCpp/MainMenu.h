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

private:
	std::vector<WidgetButton> m_buttonsList;

	int m_currentButton;
	sf::Texture* m_backgroundTexture;
	sf::Sprite m_backgroundSprite;
	sf::Clock m_buttonCooldown;
	sf::Music* m_music;
};

