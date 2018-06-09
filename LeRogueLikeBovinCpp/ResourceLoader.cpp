#include "ResourceLoader.h"

ResourceLoader::ResourceLoader()
{
}


ResourceLoader::~ResourceLoader()
{
}

void ResourceLoader::loadAll()
{
	/// MAIN MENU BACKGROUND ///

	//TODO load main menu background

	/// FONTS ///
	loadFont("MainFont", "assets/fonts/dpcomic.ttf");

	/// TILESETS ///
	loadTexture("lv1_tileset", "assets/tilesets/lv1_tileset.png");

	/// PHILIPPE ANIMATIONS ///
	loadTexture("philippe_idle", "assets/player/philippe_idle.png");
	loadTexture("philippe_running", "assets/player/philippe_walk.png");
	loadTexture("philippe_prejump", "assets/player/philippe_impulse.png");
	loadTexture("philippe_ascend", "assets/player/philippe_ascend.png");
	loadTexture("philippe_descend", "assets/player/philippe_descend.png");
	loadTexture("philippe_postjump", "assets/player/philippe_land.png");

	/// BAT ANIMATIONS ///

	//TODO load bat animations

	/// ROOMS ///
	loadRoom("room0001", "assets/rooms/room_0001.room");
}

void ResourceLoader::loadFont(std::string fontName, std::string path)
{
	sf::Font font;
	font.loadFromFile(path);
	m_fontMap[fontName] = font;
}

void ResourceLoader::loadTexture(std::string textureName, std::string path)
{
	sf::Texture texture;
	texture.loadFromFile(path);
	m_textureMap[textureName] = texture;
}

void ResourceLoader::loadRoom(std::string roomName, std::string path)
{
	std::string line;
	std::ifstream file(path);

	unsigned int rows, columns;
	std::string tileSet;

	std::vector<std::vector<int>> backgroundLayer;
	std::vector<std::vector<int>> miscLayer;
	std::vector<std::vector<int>> platformsLayer;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			// Line parsing
			while (line.find(";") == std::string::npos)
			{
				std::string nextLine; 
				std::getline(file, nextLine);
					line = line.substr(0, line.find_last_of("\n")) + nextLine;
			}
			line = line.substr(0, line.find_last_of(";"));
			
			std::string lineHead = line.substr(0, line.find_first_of(" "));
			line = line.substr(line.find_first_of(" ") + 1);

			// Line handling
			if (lineHead == "dim")
			{
				columns = std::stoi(line.substr(0, line.find_first_of(" ")));
				rows = std::stoi(line.substr(line.find_first_of(" ") + 1));
			}
			
			if (lineHead == "background")
			{
				for (int i = 0; i < rows; i++)
				{
					std::vector<int> vecLine;
					for (int j = 0; j < columns; j++)
					{
						vecLine.push_back(std::stoi(line.substr(0, line.find_first_of(","))));
						line = line.substr(line.find_first_of(",") + 1);
					}
					backgroundLayer.push_back(vecLine);
					if( i != rows - 1)
						line = line.substr(line.find_first_of(".") + 1);
				}
			}
			if (lineHead == "misc")
			{
				for (int i = 0; i < rows; i++)
				{
					std::vector<int> vecLine;
					for (int j = 0; j < columns; j++)
					{
						vecLine.push_back(std::stoi(line.substr(0, line.find_first_of(","))));
						line = line.substr(line.find_first_of(",") + 1);
					}
					miscLayer.push_back(vecLine);
					if (i != rows - 1)
						line = line.substr(line.find_first_of(".") + 1);
				}
			}
			if (lineHead == "platforms")
			{
				for (int i = 0; i < rows; i++)
				{
					std::vector<int> vecLine;
					for (int j = 0; j < columns; j++)
					{
						vecLine.push_back(std::stoi(line.substr(0, line.find_first_of(","))));
						line = line.substr(line.find_first_of(",") + 1);
					}
					platformsLayer.push_back(vecLine);
					if (i != rows - 1)
						line = line.substr(line.find_first_of(".") + 1);
				}
			}
		}

		Room room = Room(columns, rows, backgroundLayer, miscLayer, platformsLayer, getTexture("lv1_tileset"));
		m_roomMap[roomName] = room;
	}
}

sf::Font* ResourceLoader::getFont(std::string fontName)
{
	return &m_fontMap[fontName];
}

sf::Texture* ResourceLoader::getTexture(std::string textureName)
{
	return &m_textureMap[textureName];
}

Room * ResourceLoader::getRoom(std::string roomName)
{
	return &m_roomMap[roomName];
}

void ResourceLoader::handleRoomFileLine(Room& room, std::string line)
{

}