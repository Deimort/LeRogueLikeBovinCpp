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
	loadRoom("room0001", "assets/rooms/room_0001.room");
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
			std::cout << lineHead << std::endl;
			line = line.substr(line.find_first_of(" ") + 1);

			// Line handling
			if (lineHead == "dim")
			{
				columns = std::stoi(line.substr(0, line.find_first_of(" ")));
				rows = std::stoi(line.substr(line.find_first_of(" ") + 1));
				std::cout << rows << " - " << columns << std::endl;
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

		Room room = Room(columns, rows, backgroundLayer, miscLayer, platformsLayer, getImage("lv1_tileset"));
		m_roomMap[roomName] = room;
	}
}

sf::Font* ResourceLoader::getFont(std::string fontName)
{
	return &m_fontMap[fontName];
}

sf::Image* ResourceLoader::getImage(std::string imageName)
{
	return &m_imageMap[imageName];
}

Room * ResourceLoader::getRoom(std::string roomName)
{
	return &m_roomMap[roomName];
}

void ResourceLoader::handleRoomFileLine(Room& room, std::string line)
{

}