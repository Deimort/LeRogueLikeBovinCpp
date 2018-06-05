#pragma once
#include "GameState.h"
#include "UpdatableHandler.h"
#include "DrawableHandler.h"
#include "SolidHandler.h"
#include "Ball.h"
#include "Wall.h"
#include "Player.h"
#include <iostream>

class InGame : public GameState
{
public:
	InGame(sf::RenderWindow* gameContainer, ResourceLoader* resourceLoader);
	~InGame();

protected:
	void init() override;
	void update() override;
	void render() override;

private:
	UpdatableHandler m_updatableHandler;
	DrawableHandler m_drawableHandler;
	SolidHandler m_solidHandler;
	std::vector<void*> m_createdInstance;
	Player* m_player;
	sf::View m_gameView;
	sf::View m_minimap;

	void deleteAll();
};

