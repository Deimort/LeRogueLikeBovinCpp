#include "Player.h"

Player::Player(float x, float y, DrawableHandler & drawableHandler, UpdatableHandler & updatableHandler, SolidHandler & solidHandler, InputHandler &inputHandler):
	Entity(x, y, 64, 64, drawableHandler, updatableHandler, solidHandler),
	m_inputHandler(inputHandler),
	player(sf::Vector2f(64, 64))
{
	player.setPosition(x, y);
}

Player::~Player()
{
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	sf::Sprite sprite = m_animations.at(m_currentState).getCurrentFrame();
	states.transform.translate(getX(), getY());
	if (m_flip)
	{
		states.transform.scale(-1, 1);
		states.transform.translate(-64, 0); // Correction du décalage produit par le scale
	}
	
	//target.draw(player);
	target.draw(sprite, states);
	
}

void Player::update()
{
	Entity::update();

	/// Updating animation & states///
	m_stateFrameTimer++;
	m_lastFrameState = m_currentState; //memory of the old state

	m_animations[m_currentState].update();

	if (m_isOnGround && !m_wasOnGround)
	{
		m_currentState = "postjump";
		m_stateFrameTimer = 0;
		m_xVel = 0;
	}

	if (m_inputHandler.isJumping() && m_isOnGround && m_currentState != "prejump")
	{
		m_currentState = "prejump";
		m_stateFrameTimer = 0;
		m_xVel = 0;
	}

	if (m_currentState == "prejump")
	{
		if (m_stateFrameTimer >= 19)
		{
			m_yVel = -10;
			m_currentState = "idle";
		}
			

	}
	else if (m_currentState == "postjump")
	{
		if (m_stateFrameTimer >= 8)
			m_currentState = "idle";
	}
	else
	{
		if (m_xVel > 0)
		{
			m_currentState = "running";
			m_flip = false;
		}
		else if (m_xVel < 0)
		{
			m_currentState = "running";
			m_flip = true;
		}
		else
			m_currentState = "idle";

		if (m_yVel < 0 && !m_isOnGround)
		{
			m_currentState = "ascend";
		}

		if (m_yVel >= 0 && !m_isOnGround)
		{
			m_currentState = "descend";
		}

		/// Updating movement ///
		m_xVel = m_inputHandler.getXAxisValue() * 5;
		applyGravity();
	}
	
	if (m_currentState != m_lastFrameState)
		m_animations.at(m_currentState).reset();

	/// Resetting onTheGround ///
	m_wasOnGround = m_isOnGround;
	m_isOnGround = false;

	std::cout << m_isOnGround << " - " << m_currentState << std::endl;
}

void Player::onCollide(Solid &other)
{

}

void Player::applyGravity()
{
	if (m_yVel > 0 && m_wasOnGround && !m_isOnGround) // Si le joueur tombe d'une plateforme
	{
		m_yVel = 0;
	}
	if (m_yVel < 10)
	{
		m_yVel += 0.5f;
	}
	if(m_yVel >= 10)
	{
		m_yVel = 10;
	}
}

void Player::moveBy(float x, float y)
{
	// Move to the top and get stopped
	if (y > 0 && m_yVel < 0)
	{
		m_yVel = 0;
	}

	// Move to the bottom and get stopped -> isOnTheGround
	if (y < 0 && m_yVel > 0)
	{
		m_isOnGround = true;
	}

	Solid::moveBy(x, y);
	player.move(x, y);
}

void Player::loadAnimations(ResourceLoader& rsLoader)
{

	/// Idle ///
	Animation idleAnimation;
	std::vector<int> idleAnimationLength;
	idleAnimationLength.push_back(30);
	idleAnimationLength.push_back(30);
	idleAnimation.build(64, 2, idleAnimationLength, rsLoader.getTexture("philippe_idle"));
	m_animations["idle"] = idleAnimation;

	/// Running ///
	Animation runningAnimation;
	std::vector<int> runningAnimationLength;
	runningAnimationLength.push_back(5);
	runningAnimationLength.push_back(5);
	runningAnimationLength.push_back(5);
	runningAnimationLength.push_back(5);
	runningAnimationLength.push_back(5);
	runningAnimationLength.push_back(5);
	runningAnimation.build(64, 6, runningAnimationLength, rsLoader.getTexture("philippe_running"));
	m_animations["running"] = runningAnimation;

	/// Pre-jump ///
	Animation prejumpAnimation;
	std::vector<int> prejumpAnimationLength;
	prejumpAnimationLength.push_back(10);
	prejumpAnimationLength.push_back(10);
	prejumpAnimation.build(64, 2, prejumpAnimationLength, rsLoader.getTexture("philippe_prejump"));
	m_animations["prejump"] = prejumpAnimation;

	/// Ascend ///
	Animation ascendAnimation;
	std::vector<int> ascendAnimationLength;
	ascendAnimationLength.push_back(1000); //just one frame
	ascendAnimation.build(64, 1, ascendAnimationLength, rsLoader.getTexture("philippe_ascend"));
	m_animations["ascend"] = ascendAnimation;

	/// Descend ///
	Animation descendAnimation;
	std::vector<int> descendAnimationLength;
	descendAnimationLength.push_back(10);
	descendAnimationLength.push_back(15);
	descendAnimationLength.push_back(10);
	descendAnimation.build(64, 3, descendAnimationLength, rsLoader.getTexture("philippe_descend"));
	m_animations["descend"] = descendAnimation;

	/// Post-jump ///
	Animation postjumpAnimation;
	std::vector<int> postjumpAnimationLength;
	postjumpAnimationLength.push_back(5);
	postjumpAnimationLength.push_back(5);
	postjumpAnimation.build(64, 2, postjumpAnimationLength, rsLoader.getTexture("philippe_postjump"));
	m_animations["postjump"] = postjumpAnimation;
}
