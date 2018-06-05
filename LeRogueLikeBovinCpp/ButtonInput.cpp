#include "ButtonInput.h"



ButtonInput::ButtonInput(std::string inputName, float x, float y, float w, float h, InputConfig &inputConfig, sf::Font &font) :
	m_bounds(x, y, w, h),
	m_nameCell(sf::Vector2f(w / 3, h)),
	m_keyCell(sf::Vector2f(w / 3, h)),
	m_buttonCell(sf::Vector2f(w / 3, h)),
	m_inputName(inputName),
	m_nameText(inputName, font, 16U),
	m_keyText(InputConfig::getInputFromKey(inputConfig.getKeyFor(inputName)), font, 16U),
	m_buttonText(std::to_string(inputConfig.getButtonFor(inputName)), font, 16U)

{
	m_nameCell.setPosition(x, y);
	m_keyCell.setPosition(x + w / 3, y);
	m_buttonCell.setPosition(x + 2*(w / 3), y);

	m_nameCell.setFillColor(sf::Color(150, 50, 250));
	m_nameCell.setOutlineColor(sf::Color(0, 0, 250));
	m_keyCell.setFillColor(sf::Color(150, 50, 250));
	m_buttonCell.setFillColor(sf::Color(150, 50, 250));
	
	m_nameText.setOrigin(m_nameText.getLocalBounds().width / 2, m_nameText.getGlobalBounds().height / 2);
	m_keyText.setOrigin(m_keyText.getLocalBounds().width / 2, m_keyText.getGlobalBounds().height / 2);
	m_buttonText.setOrigin(m_buttonText.getLocalBounds().width / 2, m_buttonText.getGlobalBounds().height / 2);

	m_nameText.setPosition(x+w/6, y+h/2);
	m_keyText.setPosition(x+w/2, y+h/2);
	m_buttonText.setPosition(x + 5*(w / 6), y + h / 2);
}

ButtonInput::~ButtonInput()
{
}

bool ButtonInput::isClicked(float x, float y)
{
	return m_bounds.contains(x,y);
}

void ButtonInput::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_nameCell);
	target.draw(m_keyCell);
	target.draw(m_buttonCell);

	target.draw(m_nameText);
	target.draw(m_keyText);
	target.draw(m_buttonText);

}

void ButtonInput::setKey(InputConfig & inputConfig, sf::Keyboard::Key key)
{
	inputConfig.setKey(m_inputName, key);
	std::cout << m_inputName << ": " << key << std::endl;
	m_keyText.setString(InputConfig::getInputFromKey(key));
}

void ButtonInput::setButton(InputConfig & inputConfig, int button)
{
	inputConfig.setButton(m_inputName, button);
	std::cout << button << std::endl;
	m_buttonText.setString(std::to_string(button));
}
