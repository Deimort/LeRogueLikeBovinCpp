#pragma once

#include <string>
#include "InputConfig.h"
#include "SFML/Graphics.hpp"
#include <iostream>

class ButtonInput : public sf::Drawable
{
public:
	ButtonInput(std::string inputName, float x, float y, float w, float h, InputConfig &inputConfig, sf::Font &font);
	~ButtonInput();

	bool isClicked(float x, float y);
	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;
	void setKey(InputConfig &inputConfig, sf::Keyboard::Key key);
	void setButton(InputConfig &inputConfig, int button);

private:
	std::string m_inputName;
	sf::FloatRect m_bounds;
	sf::Font m_font;

	sf::RectangleShape m_nameCell;
	sf::RectangleShape m_keyCell;
	sf::RectangleShape m_buttonCell;

	sf::Text m_nameText;
	sf::Text m_keyText;
	sf::Text m_buttonText;
};

