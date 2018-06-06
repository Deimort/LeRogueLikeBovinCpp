#pragma once
#include <string>
#include "SFML/Graphics.hpp"

class TileSet
{
public:
	TileSet();
	~TileSet();

	void loadFromFile(std::string path);

};

