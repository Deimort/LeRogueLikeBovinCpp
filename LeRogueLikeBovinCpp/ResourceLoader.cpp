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
	loadImage("lv1_tileset", "assets/tilesets/lv1_tileset.png");
}

void ResourceLoader::loadFont(std::string fontName, std::string path)
{
	sf::Font font;
	font.loadFromFile(path);
	m_fontMap[fontName] = font;
}

void ResourceLoader::loadImage(std::string imageName, std::string path)
{
	sf::Image image;
	image.loadFromFile(path);
	m_imageMap[imageName] = image;
}

sf::Font* ResourceLoader::getFont(std::string fontName)
{
	return &m_fontMap[fontName];
}

sf::Image* ResourceLoader::getImage(std::string imageName)
{
	return &m_imageMap[imageName];
}