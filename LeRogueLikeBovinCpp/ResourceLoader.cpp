#include "ResourceLoader.h"



ResourceLoader::ResourceLoader()
{
}


ResourceLoader::~ResourceLoader()
{
}

void ResourceLoader::loadAll()
{
	loadFont("MainFont", "assets/fonts/dpcomic.ttf");
}

void ResourceLoader::loadFont(std::string fontName, std::string path)
{
	sf::Font font;
	font.loadFromFile(path);
	m_fontMap[fontName] = font;
}

sf::Font* ResourceLoader::getFont(std::string fontName)
{
	return &m_fontMap[fontName];
}
