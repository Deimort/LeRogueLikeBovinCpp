#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
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
	sf::Image* getImage(std::string imageName);
	Room* getRoom(std::string roomName);

	//NB: desactivate AA
private:
	std::map<std::string, sf::Font> m_fontMap;
	std::map<std::string, sf::Image> m_imageMap;
	std::map<std::string, Room> m_roomMap; // used to pre-load rooms
	
	void loadFont(std::string fontName, std::string path);
	void loadImage(std::string imageName, std::string path);
	void loadRoom(std::string roomName, std::string path);

	void handleRoomFileLine(Room& room, std::string line);
};

