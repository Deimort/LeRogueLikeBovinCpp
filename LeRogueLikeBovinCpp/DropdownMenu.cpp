#include "DropdownMenu.h"



DropdownMenu::DropdownMenu(float x, float y, float w, float h, sf::Font& font, std::string placeholder, int defaultValue) :
	m_font(font),
	m_base(sf::Vector2f(w,h)),
	m_currentText(placeholder, font, 16U),
	m_bounds(x,y,w,h)
{
	m_base.setPosition(x, y);
	m_currentText.setOrigin(m_currentText.getLocalBounds().width / 2, m_currentText.getLocalBounds().height / 2);
	m_currentText.setPosition(x + w / 2, y + h / 2);
	m_currentText.setFillColor(sf::Color(0, 0, 0));
	m_currentValue = defaultValue;
}


DropdownMenu::~DropdownMenu()
{
}

void DropdownMenu::addValue(std::string label, int value)
{
	DropdownItem item;

	item.bounds = sf::FloatRect(m_bounds.left, m_bounds.top + m_items.size() * m_bounds.height, m_bounds.width, m_bounds.height);
	
	item.graphicRect = sf::RectangleShape(sf::Vector2f(m_bounds.width, m_bounds.height));
	item.graphicRect.setPosition(sf::Vector2f(m_bounds.left, m_bounds.top + m_items.size() * m_bounds.height));
	item.graphicRect.setOutlineThickness(2);
	item.graphicRect.setOutlineColor(sf::Color(255, 0, 0));
	item.graphicRect.setFillColor(sf::Color(200, 200, 200));

	item.text = sf::Text(label, m_font, 16U);
	item.text.setOrigin(item.text.getLocalBounds().width / 2, item.text.getLocalBounds().height / 2);
	item.text.setPosition(item.bounds.left + item.bounds.width / 2, item.bounds.top + item.bounds.height / 2);
	item.text.setFillColor(sf::Color(0, 0, 0));

	item.label = label;
	item.value = value;

	m_items.push_back(item);
}

void DropdownMenu::onClick(float x, float y)
{
	if (!isOpen && m_bounds.contains(x,y))
	{
		isOpen = true;
	}
	else
	{
		for (unsigned int i = 0; i < m_items.size(); i++)
		{
			if (m_items[i].bounds.contains(x, y))
			{
				m_currentValue = m_items[i].value;
				m_currentText.setString(m_items[i].label);
				m_currentText.setOrigin(m_currentText.getLocalBounds().width / 2, m_currentText.getLocalBounds().height / 2);
				m_currentText.setPosition(m_bounds.left + m_bounds.width / 2, m_bounds.top + m_bounds.height / 2);
				break;
			}
		}
		isOpen = false;
	}
}

void DropdownMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (!isOpen)
	{
		target.draw(m_base, states);
		target.draw(m_currentText, states);
	}
	else
	{
		for (unsigned int i = 0; i < m_items.size(); i++)
		{
			target.draw(m_items[i].graphicRect, states);
			target.draw(m_items[i].text, states);
		}
	}

}

int DropdownMenu::getSelectedValue()
{
	return m_currentValue;
}
