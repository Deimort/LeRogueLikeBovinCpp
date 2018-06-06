#include "Room.h"

Room::Room()
{
	// Construct an empty room
}

Room::Room(unsigned int columns, unsigned int rows, int** backgroundLayer, int** miscLayer, int** platformsLayer, sf::Image& textureImage) :
	m_vArray(sf::Quads, rows*columns*4U)
{
	m_tileSet.loadFromImage(textureImage);

	m_arrayMap["background"] = sf::VertexArray(sf::Quads, rows*columns * 4U);
	m_arrayMap["misc"] = sf::VertexArray(sf::Quads, rows*columns * 4U);
	m_arrayMap["platform"] = sf::VertexArray(sf::Quads, rows*columns * 4U);

	buildLayer("background", rows, columns, backgroundLayer);
	// TODO add 2 for loops to handle misc and platforms layers
}


Room::~Room()
{
}

void Room::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	drawLayer("background", target, states);
}

void Room::drawLayer(std::string layerName, sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileSet;
	target.draw(m_arrayMap.at(layerName), states);
}

void Room::buildAllLayers(int rows, int columns, int** backgroundLayer, int** miscLayer, int** platformsLayer)
{
	buildLayer("background", rows, columns, backgroundLayer);
	buildLayer("misc", rows, columns, miscLayer);
	buildLayer("platforms", rows, columns, platformsLayer);
}

void Room::buildLayer(std::string layerName, int rows, int columns, int ** layerMap)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int a = 4 * (j + i * columns);
			sf::Vertex* quad = &m_arrayMap[layerName][a];

			quad[0].position = sf::Vector2f(j * 64, i * 64);
			quad[0].texCoords = makeTextureCoordsFromId(layerMap[i][j], 0);

			quad[1].position = sf::Vector2f(j * 64 + 64, i * 64);
			quad[1].texCoords = makeTextureCoordsFromId(layerMap[i][j], 1);

			quad[2].position = sf::Vector2f(j * 64 + 64, i * 64 + 64);
			quad[2].texCoords = makeTextureCoordsFromId(layerMap[i][j], 2);

			quad[3].position = sf::Vector2f(j * 64, i * 64 + 64);
			quad[3].texCoords = makeTextureCoordsFromId(layerMap[i][j], 3);
		}
	}
}

sf::Vector2f Room::makeTextureCoordsFromId(int id, int cornerId) //CornerId is numeroted from 0 to 3 clockwise
{
	int tileSetWidth = m_tileSet.getSize().x / 64;
	int tu = 64*(id % tileSetWidth);
	int tv =  64*(id / tileSetWidth);
	if (cornerId == 1 || cornerId == 2)
	{
		tu += 64;
	}
	if (cornerId == 3 || cornerId == 2)
	{
		tv += 64;
	}
	return sf::Vector2f(tu, tv);
}
