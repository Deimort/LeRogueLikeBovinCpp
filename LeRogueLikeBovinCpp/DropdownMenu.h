#pragma once
#include <vector>
#include <iostream> //TODO remove
#include <string>
#include "SFML/Graphics.hpp"

typedef struct DropdownItem 
{
	sf::FloatRect bounds;
	sf::RectangleShape graphicRect;
	sf::Text text;
	std::string label;
	int value;
} DropDownItem;

class DropdownMenu : public sf::Drawable
{
public:
	DropdownMenu(float x, float y, float w, float h, sf::Font& font, std::string placeholder);
	~DropdownMenu();

	void addValue(std::string label, int value);
	void onClick(float x, float y);
	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;
	int getSelectedValue();
private:
	sf::Font m_font;
	sf::FloatRect m_bounds;
	sf::Text m_currentText;
	sf::RectangleShape m_base;
	int m_currentValue = -1;
	
	std::vector<DropdownItem> m_items;

	bool isOpen = false;
};

