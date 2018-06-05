#include "InputConfig.h"



InputConfig::InputConfig()
{
}


InputConfig::~InputConfig()
{
}

int InputConfig::getCurrentController()
{
	return m_currentController;
}

sf::Keyboard::Key InputConfig::getKeyFor(std::string inputName)
{
	return m_keyboardInput.at(inputName);
}

int InputConfig::getButtonFor(std::string inputName)
{
	return m_gamePadInput.at(inputName);
}

void InputConfig::setKey(std::string inputName, sf::Keyboard::Key input)
{
	m_keyboardInput[inputName] = input;
}

void InputConfig::setButton(std::string buttonName, int value)
{
	m_gamePadInput[buttonName] = value;
}

void InputConfig::setCurrentController(int controllerIndex)
{
	m_currentController = controllerIndex;
}

void InputConfig::loadInputConfig(std::string path)
{
	std::string line;
	std::ifstream myfile(path);

	if (myfile.is_open())
	{
		while (std::getline(myfile, line)) 
		{
			line = line.substr(0, line.find_last_of(";"));
			loadConfigLine(line);
		}
	}

}

void InputConfig::saveInputConfig(std::string path)
{
	std::ofstream myFile;
	myFile.open(path);
	
	myFile << "//CONTROLLER_ID" << std::endl;
	myFile << CONTROLLER_ID_PREFIX << " " << m_currentController << ";" << std::endl;

	myFile << "//KEYBOARD" << std::endl;
	for (std::map<std::string, sf::Keyboard::Key>::iterator it = m_keyboardInput.begin(); it != m_keyboardInput.end(); ++it)
	{
		myFile << KEY_CONFIG_PREFIX << " " << it->first << " " << it->second << ";" << std::endl;
	}

	myFile << "//GAMEPAD" << std::endl;
	for (std::map<std::string, int>::iterator it = m_gamePadInput.begin(); it != m_gamePadInput.end(); ++it)
	{
		myFile << BUTTON_CONFIG_PREFIX << " " << it->first << " " << it->second << ";" << std::endl;
	}

	myFile.close();
}

std::string InputConfig::getInputFromKey(int keyValue)
{
	switch (keyValue) 
	{
		case 0:
			return "A";
		case 1:
			return "B";
		case 2:
			return "C";
		case 3:
			return "D";
		case 4:
			return "E";
		case 5:
			return "F";
		case 6:
			return "G";
		case 7:
			return "H";
		case 8:
			return "I";
		case 9:
			return "J";
		case 10:
			return "K";
		case 11:
			return "L";
		case 12:
			return "M";
		case 13:
			return "N";
		case 14:
			return "O";
		case 15:
			return "P";
		case 16:
			return "Q";
		case 17:
			return "R";
		case 18:
			return "S";
		case 19:
			return "T";
		case 20:
			return "U";
		case 21:
			return "V";
		case 22:
			return "W";
		case 23:
			return "X";
		case 24:
			return "Y";
		case 25:
			return "Z";

		default:
			return "NONE";
	}
}

void InputConfig::loadConfigLine(std::string line)
{
	std::string firstWord = line.substr(0, line.find_first_of(" "));
	line = line.substr(line.find_first_of(" ") + 1);
	if (firstWord == KEY_CONFIG_PREFIX)
	{
		handleKeyConfig(line);
	}
	else if (firstWord == BUTTON_CONFIG_PREFIX)
	{
		handleButtonConfig(line);
	}
	else if (firstWord == CONTROLLER_ID_PREFIX)
	{
		handleControllerId(line);
	}

}

void InputConfig::handleKeyConfig(std::string line)
{
	std::string firstWord = line.substr(0, line.find_first_of(" "));
	int keyValue = std::stoi(line.substr(line.find_first_of(" ")));

	sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(keyValue);

	m_keyboardInput.insert(std::pair<std::string, sf::Keyboard::Key>(firstWord, key));
}

void InputConfig::handleButtonConfig(std::string line)
{
	std::string firstWord = line.substr(0, line.find_first_of(" "));
	int buttonValue = std::stoi(line.substr(line.find_first_of(" ")));

	m_gamePadInput.insert(std::pair<std::string, int>(firstWord, buttonValue));
}

void InputConfig::handleControllerId(std::string line)
{
	setCurrentController(std::stoi(line));
}
