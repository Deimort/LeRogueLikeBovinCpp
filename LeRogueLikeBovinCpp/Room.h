#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <map>
class Room : public sf::Drawable, public sf::Transformable
{
public:
	Room();
	Room(unsigned int columns, unsigned int rows, int** backgroundLayer, int** miscLayer, int** platformsLayer, sf::Image &textureImage);
	~Room();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void drawLayer(std::string layerName, sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const;

	void buildAllLayers(int rows, int columns, int ** backgroundLayer, int ** miscLayer, int ** platformsLayer);

private:
	std::map<std::string, sf::VertexArray> m_arrayMap;
	sf::VertexArray m_vArray; // TODO add the other layers
	sf::Texture m_tileSet;
	sf::Sprite spr;


	void buildLayer(std::string layerName, int rows, int columns, int** layerMap);
	sf::Vector2f makeTextureCoordsFromId(int id, int cornerId);
};

