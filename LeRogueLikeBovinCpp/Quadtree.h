#pragma once
#include <vector>
#include "SFML/Graphics/Rect.hpp"
#include "Solid.h"

class Quadtree
{
public:
	Quadtree(int pLevel, sf::FloatRect pBounds);
	~Quadtree();

	void clear();
	void insert(Solid &solid);
	std::vector<Solid*> retrieve(std::vector<Solid*> &returnObjects, Solid &solid);

private:
	const int MAX_OBJECTS = 10;
	const int MAX_LEVELS = 5;

	int m_level;
	std::vector<Solid*> m_objects;
	sf::FloatRect m_bounds;
	std::vector<Quadtree*> m_nodes;

	void split();
	int getIndex(Solid &solid);

};

