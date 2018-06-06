#pragma once
#include "SFML/Graphics.hpp"
class Room : public sf::Drawable, public sf::Transformable
{
public:
	Room();
	Room(unsigned int columns, unsigned int rows, int** backgroundLayer, int** miscLayer, int** platformsLayer, sf::Image &textureImage);
	~Room();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::VertexArray m_vArray;
	sf::Texture m_tileSet;
	sf::Sprite spr;

	sf::Vector2f makeTextureCoordsFromId(int id, int cornerId);
};

