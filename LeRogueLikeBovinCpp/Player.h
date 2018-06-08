#pragma once

#include "Entity.h"
#include "InputHandler.h"
#include "Animation.h"
#include "ResourceLoader.h"
#include "SFML/Graphics.hpp"

class Player : public Entity
{
public:
	Player(float x, float y, DrawableHandler &drawableHandler, UpdatableHandler &updatableHandler, SolidHandler &solidHandler, InputHandler &inputHandler);
	~Player();

	void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	void update() override;
	void onCollide(Solid &other) override;
	void moveBy(float x, float y) override;
	void loadAnimations(ResourceLoader& rsLoader);

private:
	InputHandler m_inputHandler;
	sf::RectangleShape player; // TODO remove
	std::map<std::string, Animation> m_animations;
	std::string m_currentState = "idle", m_lastFrameState = "idle";
	int m_stateFrameTimer = 0;

	void applyGravity();

	bool m_isOnGround, m_wasOnGround, m_flip;
};

