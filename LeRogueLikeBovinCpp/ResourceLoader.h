#pragma once
#include <map>
#include <string>
#include <fstream>
#include "SFML/Graphics.hpp"
#include "Room.h"

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
	sf::Texture* getTexture(std::string textureName);
	Room* getRoom(std::string roomName);

private:
	std::map<std::string, sf::Font> m_fontMap;
	std::map<std::string, sf::Texture> m_textureMap;
	std::map<std::string, Room> m_roomMap; // used to pre-load rooms
	
	void loadFont(std::string fontName, std::string path);
	void loadTexture(std::string textureName, std::string path);
	void loadRoom(std::string roomName, std::string path);

	void handleRoomFileLine(Room& room, std::string line);
};

