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
	sf::Font* getFont(std::string fontName);
	sf::Image* getImage(std::string imageName);

	//NB: desactivate AA
private:
	std::map<std::string, sf::Font> m_fontMap;
	std::map<std::string, sf::Image> m_imageMap;
	
	void loadFont(std::string fontName, std::string path);
	void loadImage(std::string imageName, std::string path);
};

