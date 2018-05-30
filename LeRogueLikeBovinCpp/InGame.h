#pragma once
#include "GameState.h"

class InGame : public GameState
{
public:
	InGame(sf::RenderWindow* gameContainer);
	~InGame();

protected:
	void init() override;
	void update() override;
	void render() override;
};

