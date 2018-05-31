#pragma once
#include "GameState.h"
#include "UpdatableHandler.h"
#include "DrawableHandler.h"
#include "Ball.h"

class InGame : public GameState
{
public:
	InGame(sf::RenderWindow* gameContainer);
	~InGame();

protected:
	void init() override;
	void update() override;
	void render() override;

	UpdatableHandler m_updatableHandler;
	DrawableHandler m_drawableHandler;

};
