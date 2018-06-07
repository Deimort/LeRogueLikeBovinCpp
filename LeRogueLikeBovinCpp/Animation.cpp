#include "Animation.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::build(int frameWidth, int frameCount, std::vector<int> &frameLength, sf::Texture* texture)
{
	m_frameWidth = frameWidth;
	m_frameCount = frameCount;
	m_frameLength = frameLength;
	m_texture = texture;
}

void Animation::update()
{
	m_refreshCount++;
	if (m_refreshCount >= m_frameLength[m_currentFrame])
	{
		m_currentFrame++;
		if (m_currentFrame == m_frameCount)
			m_currentFrame = 0;
		m_refreshCount = 0;
	}
}

sf::Sprite Animation::getCurrentFrame() const
{
	return getFrame(m_currentFrame);
}

sf::Sprite Animation::getFrame(int frameId) const
{
	return sf::Sprite(*m_texture, sf::IntRect(frameId * m_frameWidth, 0, m_frameWidth, m_texture->getSize().y));
}
