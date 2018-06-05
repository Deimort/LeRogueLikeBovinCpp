#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "SFML/Window.hpp"

class InputConfig
{
public:
	InputConfig();
	~InputConfig();

	/*GETTERS*/
	int getCurrentController();
	sf::Keyboard::Key getKeyFor(std::string inputName);
	int getButtonFor(std::string inputName);
	

	/*SETTERS*/
	void setKey(std::string inputName, sf::Keyboard::Key input);
	void setButton(std::string buttonName, int value);
	void setCurrentController(int controllerIndex);

	void loadInputConfig(std::string path);
	void saveInputConfig(std::string path);
	static std::string getInputFromKey(int keyValue);

private:
	int m_currentController;
	const std::string KEY_CONFIG_PREFIX = "keyConfig";
	const std::string BUTTON_CONFIG_PREFIX = "buttonConfig";
	const std::string CONTROLLER_ID_PREFIX = "controllerId";
	
	std::map<std::string, sf::Keyboard::Key> m_keyboardInput;
	std::map<std::string, int> m_gamePadInput;

	void loadConfigLine(std::string line);
	void handleKeyConfig(std::string line);
	void handleButtonConfig(std::string line);
	void handleControllerId(std::string line);

};

