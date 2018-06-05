#pragma once
#include <map>
#include <string>
#include "SFML/Graphics.hpp"

class ResourceLoader
{
public:
	ResourceLoader();
	~ResourceLoader();
	// AddTileImage -> tileSet
	// Load+Get MappedImage
	// Load+Get Animation
	// Load+Get Room

	void loadAll();

	// TODO make private
	
	sf::Font* getFont(std::string fontName);

	//NB: desactivate AA
private:
	std::map<std::string, sf::Font> m_fontMap;
	
	void loadFont(std::string fontName, std::string path);
};

