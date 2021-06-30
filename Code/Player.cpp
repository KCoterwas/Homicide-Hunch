//#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	// Associate a texture with the sprite
	// !!Watch this space!!
	m_Texture.loadFromFile("Graphics/HenrySheet.png");
	m_Sprite.setTexture(m_Texture);

	// Set the position
	m_Sprite.setPosition(1000, 300);

	select.x = 1;
	select.y = Right;
}


FloatRect Player::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Sprite Player::getSprite()
{
	return m_Sprite;
}

void Player::moveLeft()
{
	m_LeftPressed = true;
	select.y = Left;
	++select.x;
	if(select.x * HenryWidth >= m_Texture.getSize().x)
	{
		select.x = 0;
	}
}

void Player::moveRight()
{
	m_RightPressed = true;
	select.y = Right;
	++select.x;
	if(select.x * HenryWidth >= m_Texture.getSize().x)
	{
		select.x = 0;
	}
}

void Player::moveUp()
{
	m_UpPressed = true;
	select.y = Up;
	++select.x;
	if(select.x * HenryWidth >= m_Texture.getSize().x)
	{
		select.x = 0;
	}
}

void Player::moveDown()
{
	m_DownPressed = true;
	select.y = Down;
	++select.x;
	if(select.x * HenryWidth >= m_Texture.getSize().x)
	{
		select.x = 0;
	}
}

void Player::stopLeft()
{
	m_LeftPressed = false;
}

void Player::stopRight()
{
	m_RightPressed = false;
}

void Player::stopUp()
{
	m_UpPressed = false;
}

void Player::stopDown()
{
	m_DownPressed = false;
}

void Player::update()
{	
	if (m_UpPressed)
	{
		m_Position.y -= 2;
	}

	if (m_DownPressed)
	{
		m_Position.y += 2;
	}
	if (m_RightPressed)
	{
		m_Position.x += 2;
	}

	if (m_LeftPressed)
	{
		m_Position.x -= 2;
	}

	m_Sprite.setTextureRect(sf::IntRect(select.x * HenryWidth, select.y * HenryHeight, HenryWidth, HenryHeight));

	// Keep the player in the arena
	if (m_Position.x >  1700)
	{
  //  std::cout << "You're too far right" << std::endl;
		m_Position.x = 1700;
	}

	if (m_Position.x < 20)
	{
   // std::cout << "You're too far left" << std::endl;
		m_Position.x = 20;
	}

	if (m_Position.y > 700)
	{
  //  std::cout << "You're too low" << std::endl;
		m_Position.y = 700;
	}

	if (m_Position.y < 20)
	{
   // std::cout << "You're too high" << std::endl;
		m_Position.y = 20;
	}

	m_Sprite.setPosition(m_Position);

}


