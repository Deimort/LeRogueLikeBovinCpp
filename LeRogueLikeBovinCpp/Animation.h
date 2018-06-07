#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Animation
{
public:
	Animation();
	~Animation();
	void build(int frameWidth, int frameCount, std::vector<int> &frameLength, sf::Texture* texture);
	void update();
	sf::Sprite getCurrentFrame() const;
	sf::Sprite getFrame(int frameId) const;
private:
	int m_frameWidth;
	int m_currentFrame;
	int m_refreshCount;
	int m_frameCount;
	std::vector<int> m_frameLength; // keep the length of each frame of the animation (in number of refresh -> 60 = 1s)
	sf::Texture* m_texture;
};

