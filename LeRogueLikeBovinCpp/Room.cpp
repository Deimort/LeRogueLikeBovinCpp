#include "Room.h"
#include <iostream> //TODO remove

Room::Room()
{

}

Room::Room(unsigned int columns, unsigned int rows, int** backgroundLayer, int** miscLayer, int** platformsLayer, sf::Image& textureImage) :
	m_vArray(sf::Quads, rows*columns*4U)
{
	m_tileSet.loadFromFile("assets/tilesets/lv1_tileset.png");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int a = 4 * (j + i * columns);
			std::cout << "a: " <<  a << std::endl;
			sf::Vertex* quad = &m_vArray[a];

			quad[0].position = sf::Vector2f(j*64, i*64);
			//m_vArray[a].color = sf::Color(255,255,255);
			quad[0].texCoords = makeTextureCoordsFromId(backgroundLayer[i][j], 0);

			quad[1].position = sf::Vector2f(j * 64 + 64, i * 64);
			//m_vArray[a+1].color = sf::Color(255, 255, 255);
			quad[1].texCoords = makeTextureCoordsFromId(backgroundLayer[i][j], 1);

			quad[2].position = sf::Vector2f(j * 64 + 64, i * 64 + 64);
			//m_vArray[a+2].color = sf::Color(255, 255, 255);
			quad[2].texCoords = makeTextureCoordsFromId(backgroundLayer[i][j], 2);

			quad[3].position = sf::Vector2f(j * 64, i * 64 + 64);
			//m_vArray[a+3].color = sf::Color(255, 255, 255);
			quad[3].texCoords = makeTextureCoordsFromId(backgroundLayer[i][j], 3);
		}
	}
}


Room::~Room()
{
}

void Room::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	states.texture = &m_tileSet;
	target.draw(m_vArray, states);
	//target.draw(spr, states);
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
	
	std::cout << id << "(" << cornerId << ")" << "-> " << tu << " / " << tv << std::endl;

	return sf::Vector2f(tu, tv);
}
