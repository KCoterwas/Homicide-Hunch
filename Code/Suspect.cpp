//#include "stdafx.h"
#include "Suspect.h"

Suspect::Suspect()
{
	
	// Associate a texture with the sprite
	// !!Watch this space!!
	butcher_Texture.loadFromFile("Graphics/ButcherSheet.png");
	suspectButcher.setTexture(butcher_Texture);

	friend_Texture.loadFromFile("Graphics/Friend.png");
	suspectFriend.setTexture(friend_Texture);

	// Set the position
	suspectButcher.setPosition(900, 500);

	// Set the position
	suspectFriend.setPosition(700, 200);
	
	select.x = 0;
	select.y = Closed;

}

FloatRect Suspect::getPositionB()
{
	return suspectButcher.getGlobalBounds();
}

Sprite Suspect::getSpriteB()
{
	return suspectButcher;
}

void Suspect::update()
{
		if(select.x * butcherWidth >= butcher_Texture.getSize().x)
		{
			select.x = 0;
		}
		++select.x;
		

	suspectButcher.setTextureRect(sf::IntRect(select.x, select.y * butcherHeight, butcherWidth, butcherHeight));
}

FloatRect Suspect::getPositionF()
{
	return suspectFriend.getGlobalBounds();
}

Sprite Suspect::getSpriteF()
{
	return suspectFriend;
}


