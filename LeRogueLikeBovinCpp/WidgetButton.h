#pragma once

#include "SFML/Graphics.hpp"
#include <string>

class WidgetButton : public sf::Drawable
{
public:
	WidgetButton(float x, float y, float w, float h, std::string buttonName, sf::Font &font, int value);
	~WidgetButton();


	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;
	void setSelected(bool isSellected);
	int getValue();

private :
	sf::FloatRect m_bounds;

	sf::RectangleShape m_cell;

	sf::Text m_text;

	const int m_value;
};

