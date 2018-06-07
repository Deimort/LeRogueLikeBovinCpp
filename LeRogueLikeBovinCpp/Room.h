#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <vector>
#include <map>
class Room : sf::Transformable
{
public:
	Room();
	Room(unsigned int columns, unsigned int rows, std::vector<std::vector<int>> backgroundLayer, std::vector<std::vector<int>> miscLayer, std::vector<std::vector<int>> platformsLayer, sf::Texture *texture);
	~Room();

	void drawLayerAt(float x, float y, std::string layerName, sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

	void buildAllLayers(int rows, int columns, std::vector<std::vector<int>> backgroundLayer, std::vector<std::vector<int>> miscLayer, std::vector<std::vector<int>> platformsLayer);
	void buildLayer(std::string layerName, int rows, int columns, std::vector<std::vector<int>> backgroundLayer);

	int getWidth();
	int getHeight();

private:
	std::map<std::string, sf::VertexArray> m_arrayMap;
	sf::Texture* m_tileSet;
	sf::Sprite spr;

	sf::Vector2f makeTextureCoordsFromId(int id, int cornerId);

	int m_width, m_height;
};

