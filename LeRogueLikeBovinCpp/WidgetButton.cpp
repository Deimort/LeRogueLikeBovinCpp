#include "WidgetButton.h"
#include <iostream> // TODO remove

WidgetButton::WidgetButton(float x, float y, float w, float h, std::string buttonName, sf::Font &font, int value) :
	m_bounds(x, y, w, h),
	m_cell(sf::Vector2f(w, h)),
	m_text(buttonName, font, 30U),
	m_value(value)
{
	m_cell.setPosition(x,y);

	m_cell.setFillColor(sf::Color(0, 122, 204));
	m_cell.setOutlineColor(sf::Color(255, 0, 0));

	m_text.setOrigin(m_text.getLocalBounds().width / 2, m_text.getLocalBounds().height / 2);
	m_text.setPosition(x + w / 2, y + h / 3);
}

WidgetButton::~WidgetButton()
{
}

void WidgetButton::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_cell);
	target.draw(m_text);
}

void WidgetButton::setSelected(bool isSellected)
{
	if (isSellected) 
	{
		m_cell.setOutlineThickness(3);
	}
	else 
	{
		m_cell.setOutlineThickness(0);
	}
}

int WidgetButton::getValue()
{
	return m_value;
}
